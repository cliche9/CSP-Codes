#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int main() {
    freopen("作业/a.in", "r", stdin);
    freopen("作业/a.out", "w", stdout);
    int n = 0, m = 0;;
    int num = 0, buc = 0;
    scanf("%d%d", &n, &m);
    map<int, vector<int> > buckets;

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &num, &buc);
        buckets[buc].__emplace_back(num);
    }

    for (auto &vec : buckets)
        sort(vec.second.begin(), vec.second.end());

    for (auto &vec : buckets) {
        for (auto i : vec.second)
            printf("%d ", i); 
        printf("\n");
    }
    
    return 0;
}