#include <iostream>
using namespace std;

class unionFind {
public:
    unionFind(int n) {
        for (int i = 0; i < n; i++)
            unions[i] = i;
        _size = n;
    }
    
    int find(int x) {
        if (unions[x] == x)
            return x;
        return unions[x] = find(unions[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        unions[x] = y;
        _size--;
        return true;
    }
    
    int size() const { return _size; }

private:
    int _size;
    int unions[100001];
};

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0, m = 0;
    cin >> n >> m;
    unionFind uf(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        uf.unite(a, b);
        cout << uf.size() - 1 << endl;
    }
    return 0;
}