#include <iostream>
using namespace std;

struct movie {
    int a;
    int b;
    bool operator<(const movie &mv) const {
        return a + max(mv.a, b) + mv.b < mv.a + max(a, mv.b) + b;
    }
};

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    cin >> n;
    movie members[n];

    for (int i = 0; i < n; i++) 
        cin >> members[i].a;
    for (int i = 0; i < n; i++)
        cin >> members[i].b;
    
    sort(members, members + n);

    int a_end = 0, b_end = 0;
    for (int i = 0; i < n; i++) {
        if (b_end < a_end + members[i].a)
            b_end = a_end + members[i].a;
        b_end += members[i].b;
        a_end += members[i].a;
    }

    cout << b_end << endl;

    return 0;
}