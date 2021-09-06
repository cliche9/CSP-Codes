#include <iostream>
#include <vector>
using namespace std;

const int inf = 5e5 + 10;

vector<pair<int, int> > u(inf);
vector<pair<int, int> > v(inf);

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 0; i < a; i++)
        cin >> u[i].first >> u[i].second;
    for (int i = 0; i < b; i++)
        cin >> v[i].first >> v[i].second;

    auto iter_of_u = u.begin();
    auto iter_of_v = v.begin();

    long long res = 0;
    while (iter_of_u != u.end() && iter_of_v != v.end()) {
        if (iter_of_u->first < iter_of_v->first) {
            ++iter_of_u;
        } else if (iter_of_u->first == iter_of_v->first) {
            res += iter_of_u->second * iter_of_v->second;
            ++iter_of_u;
            ++iter_of_v;
        } else {
            ++iter_of_v;
        }
    }
    
    cout << res;

    return 0;
}