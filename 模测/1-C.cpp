#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    // first - 制作完成时间点/ second - 配料
    list<pair<int, int> > noddles(n);
    // first - 到店时间/ second - 需要配料
    vector<pair<int, int> > guests(m);

    for (auto &iter : noddles)
        cin >> iter.first;

    for (auto &iter : noddles) {
        int k = 0;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int ki;
            cin >> ki;
            // 二进制表示哪个配料有1 没有0
            iter.second |= (1 << (ki - 1));
        }
    }

    for (int i = 0; i < m; i++)
        cin >> guests[i].first;
    
    for (int i = 0; i < m; i++) {
        int c = 0;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int ci;
            cin >> ci;
            // 记录需要什么配料
            guests[i].second |= (1 << (ci - 1));
        }
    }
    
    // 从最晚完成的开始选，这样是让顾客选到完成时间最近的面
    noddles.reverse();
    for (int i = 0; i < m; i++) {
        auto theChosen = noddles.begin();
        // tag标记有没有满足需求的面
        bool tag = false;
        // 遍历整个noddles
        for (auto iter = noddles.begin(); iter != noddles.end(); iter++) {
            // and运算，如果小于guest[i].second，说明面配料不能完全包括顾客需要的配料
            if ((iter->second & guests[i].second) < guests[i].second)
                continue;
            theChosen = iter;
            tag = true;
            break;
        }
        if (!tag)
            cout << "Angry" << endl;
        else {
            // 输出差值，删除选走的面条
            cout << guests[i].first - theChosen->first << endl;
            noddles.erase(theChosen);
        }
    }
    
    return 0;
}