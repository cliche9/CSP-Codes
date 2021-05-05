#include <bits/stdc++.h>
using namespace std;

const int less_max = 32767, more_min = -32768;
bool intv[65536];

struct expr {
    int less;
    int more;
    expr(): less(less_max), more(more_min) {}
    bool operator<(const expr& ep) {
        if (less != less_max && ep.more != more_min)
            return less < ep.more;
        else if (less == less_max)
            return more < ep.more;
        else if (ep.more == more_min)
            return less < ep.less;
        else
            return more < ep.less;
    }
};

list<expr> res;

bool inputAndDealwith() {
    expr temp;
    string inputstr;
    getline(cin, inputstr);
    stringstream inputstrstream(inputstr);
    string lstr;
    bool tag = false;
    while (inputstrstream >> lstr) {
        tag = true;
        if (lstr == ">=")
            inputstrstream >> temp.more;
        else if (lstr == "<=")
            inputstrstream >> temp.less;
    }
    if (!tag)
        return false;
    if (temp.more == more_min && temp.less == less_max)
        return true;
    if (temp.more <= temp.less)
        res.emplace_back(temp);
    return true;
}

bool check() {
    for (int i = 0; i <= 65535; ++i) {
        if (!intv[i])
            return false;
    }
    return true;
}

void output() {
    if (res.empty()) {
        cout << "false\n";
        return;
    }
    res.sort();
    int left = less_max, right = more_min;
    auto iter = res.begin();
    while (iter != res.end()) {
        fill(intv + iter->more + 32768, intv + iter->less + 32769, true);
        if (iter->more >= left && iter->less <= right)
            iter = res.erase(iter);
        else {
            left = min(left, iter->more);
            right = max(right, iter->less);
            ++iter;
        }
    }
    if (check()) {
        cout << "true\n";
        return;
    }

    int count = res.size();
    for (auto &ep : res) {
        if (ep.less != less_max && ep.more != more_min) {
            cout << "x >= " << ep.more << " && x <= " << ep.less;
            if (count > 1)
                cout << " ||\n";
        }
        else if (ep.less == less_max) {
            cout << "x >= " << ep.more;
            if (count > 1)
                cout << " ||\n";
        }
        else if (ep.more == more_min) {
            cout << "x <= " << ep.less;
            if (count > 1)
                cout << " ||\n";
        }
        --count;
    }
}

int main() {
    string aLine;
    while (inputAndDealwith());
    // output the answer
    output();

    return 0;
}