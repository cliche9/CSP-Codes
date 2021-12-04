#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int cnt = 0;
int n; int k;
bool vis[8];     //记录某一列 是否用过
bool g[8][8];    //可以放棋子的地方
//总共n列
void permutation(int num, int line)
{//num是当前 填了几个棋子
    
    if (num == k) { cnt++; return; }
    
    if (k - num > n - line)
        return;

    for (int j = 0; j < n; j++)
    {
        if (g[line][j] && vis[j])
        {//第i列 能用 且 不冲突
            g[line][j] = false;
            vis[j] = false;//对应的列标记为用过               
            permutation(num + 1, line + 1);
            vis[j] = true;//恢复
            g[line][j] = true;
        }
    }
    permutation(num, line + 1);
}
int main()
{
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    while (cin >> n >> k && n != -1 && k != -1)
    {     
        for (int i = 0; i < n; i++) {
            vis[i] = true;
            for (int j = 0; j < n; j++)
            {
                char c;
                cin >> c;
                if (c == '#')
                    // false表示不能放棋子，true表示可以放
                    g[i][j] = true;
                else 
                    g[i][j] = false;
            }
        }
        permutation(0, 0);
        cout << cnt << endl;
        cnt = 0;
    }
    return 0;
}
/*8 8
##......
..##....
..#.##..
########
.....###
.#.#.#.#
#.#.#.#.
....####
-1 -1
90*/