#include <iostream>
#include <vector>
using namespace std;

vector<string> page(1);
bool shift_on = false;
bool selected = false;
string selected_string;
string copy_string;
pair<int, int> cursor(0, 0);
pair<int, int> start_point(0, 0);
pair<int, int> end_point(0, 0);

void _move(const string &cmd) {
    selected = false;
    if (cmd == "Home")
        cursor.second = 0;
    else if (cmd == "End")
        cursor.second = page[cursor.first].length();
    else if (cmd == "Up") {
        if (cursor.first == 0)
            return;
        --cursor.first;
        if (page[cursor.first].length() < cursor.second)
            cursor.second = page[cursor.first].length();
    }
    else if (cmd == "Down") {
        if (cursor.first == page.size() - 1)
            return;
        ++cursor.first;
        if (page[cursor.first].length() < cursor.second)
            cursor.second = page[cursor.first].length();
    }
    else if (cmd == "Left") {
        if (cursor.first == 0 && cursor.second == 0)
            return;
        if (cursor.second == 0) {
            --cursor.first;
            cursor.second = page[cursor.first].length();
        } else
            --cursor.second;
    }
    else {
        if ((cursor.first == page.size() - 1) && (cursor.second == page[cursor.first].length()))
            return;
        if (cursor.second == page[cursor.first].length()) {
            ++cursor.first;
            cursor.second = 0;
        } else
            ++cursor.second;
    }
}

void insert(const string &cmd) {
    if (selected) {
        page[start_point.first] = page[start_point.first].substr(0, start_point.second) + page[end_point.first].substr(end_point.second);
        for (int i = end_point.first; i >= start_point.first + 1; --i)
            page.erase(page.begin() + i);
        cursor = start_point;
        selected = false;
    }
    if (cmd == "Enter") {
        // 新建一行
        page.push_back("");
        // 不动的行下移
        for (int i = page.size() - 1; i > cursor.first + 1; --i)
            page[i] = page[i - 1];
        // 处理动的行
        page[cursor.first + 1] = page[cursor.first].substr(cursor.second);
        page[cursor.first] = page[cursor.first].substr(0, cursor.second);
        // 改变光标位置
        ++cursor.first;
        cursor.second = 0;
    } else if (cmd == "Space") {
        page[cursor.first] = page[cursor.first].substr(0, cursor.second) + ' ' + page[cursor.first].substr(cursor.second);
        ++cursor.second;
    } else if (cmd == "Paste") {
        page[cursor.first] = page[cursor.first].substr(0, cursor.second) + copy_string + page[cursor.first].substr(cursor.second);
        cursor.second += copy_string.size();
    } else {
        char c;
        cin >> c;
        page[cursor.first] = page[cursor.first].substr(0, cursor.second) + c + page[cursor.first].substr(cursor.second);
        ++cursor.second;
    }
}

void remove(const string &cmd) {
    if (selected) {
        page[start_point.first] = page[start_point.first].substr(0, start_point.second) + page[end_point.first].substr(end_point.second);
        for (int i = end_point.first; i >= start_point.first + 1; --i)
            page.erase(page.begin() + i);
        cursor = start_point;
        selected = false;
        return;
    }
    if (cmd == "Del") {
        if ((cursor.first == page.size() - 1) && (cursor.second == page[cursor.first].length()))
            return;
        if (cursor.second == page[cursor.first].length()) {
            page[cursor.first] += page[cursor.first + 1];
            page.erase(page.begin() + cursor.first + 1);
        } else 
            page[cursor.first] = page[cursor.first].substr(0, cursor.second) + page[cursor.first].substr(cursor.second + 1);
    } else {
        if (cursor.first == 0 && cursor.second == 0)
            return;
        if (cursor.second == 0) {
            page[cursor.first - 1] += page[cursor.first];
            page.erase(page.begin() + cursor.first);
            --cursor.first;
            cursor.second = page[cursor.first].length();
        } else {
            page[cursor.first] = page[cursor.first].substr(0, cursor.second - 1) + page[cursor.first].substr(cursor.second);
            --cursor.second;
        }
    }
}

void shift() {
    shift_on = !shift_on;
    if (shift_on) {
        start_point = cursor;
        selected = false;
    }
    else {
        end_point = cursor;
        if (start_point != end_point)
            selected = true;
        if (start_point > end_point) {
            pair<int, int> temp(start_point);
            start_point = end_point;
            end_point = temp;
        }
        selected = true;
        // 更新选中的string
        if (start_point.first == end_point.first)
            selected_string = page[start_point.first].substr(start_point.second, end_point.second - start_point.second);
        else {
            selected_string = page[start_point.first].substr(start_point.second);
            for (int i = start_point.first + 1; i < end_point.first; ++i)
                selected_string += page[i];
            selected_string += page[end_point.first].substr(0, end_point.second);
        }
    }
}

void find(const string &word) {
    int res = 0;
    if (selected) {
        int pos = 0;
        while (pos < selected_string.size()) {
            pos = selected_string.find(word, pos);
            if (pos == string::npos)
                break;
            ++res;
            pos += selected_string.size();
        }
    } else {
        for (int i = 0; i < page.size(); ++i) {
            int pos = 0;
            while (pos < page[i].size()) {
                pos = page[i].find(word, pos);
                if (pos == string::npos)
                    break;
                ++res;
                pos += page[i].size();
            }
        }
    }
    cout << res << '\n';
}

void count() {
    int res = 0;
    if (selected) {
        for (auto c : selected_string)
            if (c != ' ')
                ++res;
    }
    else
        for (int i = 0; i < page.size(); ++i)
            for (auto c : page[i])
                if (c != ' ')
                    ++res;
    cout << res << '\n';
}

void copy() {
    if (selected)
        copy_string = selected_string;
    else if (!page[cursor.first].empty())
       copy_string = page[cursor.first];
}

void print() {
    for (int i = 0; i < page.size(); ++i)
        cout << page[i] << '\n';
}

int main() {
    freopen("每月一题/a.in", "r", stdin);
    freopen("每月一题/a.out", "w", stdout);
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string inst, cmd;
        cin >> inst;
        if (inst == "MOVE") {
            cin >> cmd;
            _move(cmd);
        } else if (inst == "INSERT") {
            cin >> cmd;
            insert(cmd);
        } else if (inst == "REMOVE") {
            cin >> cmd;
            remove(cmd);
        } else if (inst == "SHIFT") {
            shift();
        } else if (inst == "FIND") {
            cin >> cmd;
            find(cmd);
        } else if (inst == "COUNT") {
            count();
        } else if (inst == "COPY") {
            copy();
        } else {
            print();
        }
    }

    return 0;
}