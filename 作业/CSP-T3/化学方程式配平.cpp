#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct elementSet {
    map<string, int> mapping;
    void operator*=(int times) {
        for (auto &m : mapping)
            m.second *= times;
    }
    bool operator==(const elementSet& els) {
        return mapping == els.mapping;
    }
    void operator+=(const elementSet& els) {
        for (auto &m : els.mapping)
            mapping[m.first] += m.second;
    }
};

vector<string> split(const string &s, char x) {
    vector<string> res;
    string temp;
    for (auto c : s) {
        if (c == x) {
            res.emplace_back(temp);
            temp = "";
        } else temp += c;
    }
    if (!temp.empty())
        res.emplace_back(temp);
    
    return res;
}

int r_int(const string &s, int &p) {
    int res = 0;
    while (p < s.length() && isdigit(s[p])) {
        res = res * 10 + s[p] - '0';
        ++p;
    }
    return res == 0 ? 1 : res;
}

string r_symbol(const string &s, int &p) {
    string res;
    if (isupper(s[p])) {
        res += s[p];
        ++p;
    }
    if (islower(s[p])) {
        res += s[p];
        ++p;
    }
    return res;
}

elementSet str2set(const string &s, int &p) {
    elementSet res;
    int times = r_int(s, p);
    while (p < s.length()) {
        if (s[p] == '(')
            res += str2set(s, ++p);
        else if (s[p] == ')') {
            res *= r_int(s, ++p);
            break;
        }
        else {
            string temp = r_symbol(s, p);
            res.mapping[temp] += r_int(s, p);
        }
    }
    res *= times;

    return res;
} 

void solve(const string &s) {
    vector<string> equations = split(s, '=');
    vector<string> ls = split(equations[0], '+');
    vector<string> rs = split(equations[1], '+');
    elementSet left, right;
    int p = 0;
    for (auto &sl : ls) {
        left += str2set(sl, p);
        p = 0;
    }
    for (auto &sr : rs) {
        right += str2set(sr, p);
        p = 0;
    }
    if (left == right)
        cout << "Y\n";
    else
        cout << "N\n";
}

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        solve(s);
    }

    return 0;
}