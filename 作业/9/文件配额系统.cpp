#include <iostream>
#include <map>
#include <vector>
#define ll long long
#define outy (cout << "Y\n")
#define outn (cout << "N\n")
using namespace std;

struct file {
    // 文件类型 0 - file, 1 - dir
    int file_type;
    // 文件大小
    ll file_size;
    // 目录配额, 后代配额
    ll dir_all_max, dir_des_max;
    // 目录使用, 后代使用
    ll dir_all_used, dir_des_used;
    // 目录内信息
    map<string, file *> childSet;
    // 构造函数
    file(int type, ll size = 0): file_type(type), file_size(size), dir_all_max(0), dir_des_max(0), dir_all_used(0), dir_des_used(0) {}
    ~file() {
        for (auto &it : childSet)
            delete it.second;
    }
    // 预先分配, last标识是否为目录末尾, 处理dir_son_used
    bool pre_add_size(ll size, bool last = false) {
        if (dir_des_max && dir_des_used + size > dir_des_max)
            return false;
        if (last && dir_all_max && dir_all_used + size > dir_all_max)
            return false;
        return true;
    }
    // 分配
    void add_size(ll size, bool last = false) {
        if (last)
            dir_all_used += size;
        dir_des_used += size;
    }
    // 返回大小
    ll get_size() const {
        if (file_type == 0)
            return file_size;
        return dir_des_used;
    }
    // 设置配额
    bool set_size(ll all_max, ll des_max) {
        if ((all_max && dir_all_used > all_max) || (des_max && dir_des_used > des_max))
            return false;
        dir_all_max = all_max;
        dir_des_max = des_max;
        return true;
    }
};

struct file_system {
    file *root;
    // 当前路径
    vector<string> path_now;
    // 当前文件
    string dir;

    // 构造函数
    file_system() { root = new file(1); };
    ~file_system() { delete root; }
    // 设置当前路径
    void set_path(const string &path) {
        path_now.clear();
        string temp;
        for (auto c : path) {
            // 设置当前路径
            if (c == '/') {
                if (!temp.empty())
                    path_now.push_back(temp), temp = "";
            }
            else
                temp += c;
        }
        // 录入当前文件
        dir = temp;
    }
    // 路径测试，看路径状态
    pair<file *, int> find() const {
        file *now = root;
        for (auto &next_point : path_now) {
            if (!now->childSet.count(next_point))
                // 不存在当前路径--路径不完整
                return make_pair(nullptr, 1);
            if (now->childSet[next_point]->file_type == 0)
                // 存在当前路径，但是路径为具体文件，不是目录--路径错误
                return make_pair(nullptr, 2);
            now = now->childSet[next_point];
        }
        // 如果dir为空，则是根目录
        if (!dir.empty()) {
            // 不是根目录
            if (!now->childSet.count(dir)) {
                // now此时是最后一层目录，检测一下dir是否在now目录下
                // 不在，则路径不完整
                return make_pair(nullptr, 1);
            }
            now = now->childSet[dir];
        }
        // 终于找到了正确文件，返回指向它的指针
        return make_pair(now, 0);
    }
    // 新建文件，同时检查看是否满足配额
    bool create(ll size) const {
        file *now = root;
        // 先进行配额检查，顺便创建不存在的目录
        for (auto &next_point : path_now) {
            if (!now->pre_add_size(size))
                // 预处理失败
                return false;
            if (!now->childSet.count(next_point))
                now->childSet[next_point] = new file(1);
            now = now->childSet[next_point];
        }
        // 预处理最终孩子失败
        if (!now->pre_add_size(size, true))
            return false;
        // 预处理合法，正式分配
        now = root;
        for (auto &next_point : path_now) {
            now->add_size(size);
            now = now->childSet[next_point];
        }
        now->add_size(size, true);
        now->childSet[dir] = new file(0, size);
        return true;
    }
    // 删除文件
    void remove(ll size) const {
        file *now = root;
        for (auto &np : path_now) {
            now->add_size(-size);
            now = now->childSet[np];
        }
        // 只有删除的是普通文件，才更新使用的孩子大小
        if (now->childSet[dir]->file_type == 0)
            now->add_size(-size, true);
        else
            now->add_size(-size);
        
        delete now->childSet[dir];
        now->childSet.erase(dir);
    }
};

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n = 0;
    cin >> n;
    file_system fs;
    char opt;
    string path;
    /*
    res.second:
    0 -- 成功
    1 -- 路径不完整
    2 -- 路径错误
    */
    for (int i = 0; i < n; i++) {
        cin >> opt >> path;
        fs.set_path(path);
        auto res = fs.find();
        if (opt == 'C') {
            ll file_size;
            cin >> file_size;
            // 成功找到
            if (res.second == 0) {
                // 目录
                if (res.first->file_type == 1)
                    outn;
                // 是具体文件
                else {
                    ll old_size = res.first->get_size();
                    fs.remove(old_size);
                    // 创建成功
                    if (fs.create(file_size))
                        outy;
                    // 不成功，将原来的创建回去，复原
                    else {
                        fs.create(old_size);
                        outn;
                    }
                }
            }
            // 路径不完整
            else if (res.second == 1) {
                if (fs.create(file_size))
                    outy;
                else
                    outn;
            }
            // 路径错误
            else 
                outn;
        } else if (opt == 'R') {
            if (res.second == 0)
                fs.remove(res.first->get_size());
            // 始终认为成功
            outy;
        } else if (opt == 'Q') {
            ll max_dir, max_des;
            cin >> max_dir >> max_des;
            if (res.second == 0 && res.first->file_type == 1) {
                // 路径正确且是目录文件
                if (res.first->set_size(max_dir, max_des))
                    outy;
                else
                    outn;
            }
            // 否则输出失败
            else 
                outn;
        }
    }

    return 0;
}