#include <iostream>
#include <list>
#include <sstream>
using namespace std;

const int less_max = 32767, more_min = -32768;

// first -- morethan, second -- lessthan
list<pair<int, int> > res;

bool inputAndDealwith() {
    pair<int, int> temp(more_min, less_max);
    string inputstr;
    getline(cin, inputstr);
    stringstream inputstrstream(inputstr);
    string lstr;
    bool tag = false;
    int t1 = more_min, t2 = less_max;
    while (inputstrstream >> lstr) {
        tag = true;
        if (lstr == ">=")
            inputstrstream >> t1;
        else if (lstr == "<=")
            inputstrstream >> t2;
    }
    if (t1 > more_min)
        temp.first = t1;
    if (t2 < less_max)
        temp.second = t2;
    if (!tag)
        return false;
    if (temp.first == more_min && temp.second == less_max)
        return true;
    if (temp.first <= temp.second)
        res.emplace_back(temp);
    return true;
}

void output() {
    if (res.empty()) {
        cout << "false";
        return;
    }
    res.sort();

    bool tag = true;
    while (tag) {
        tag = false;
        auto iter1 = res.begin(), iter2 = res.begin();
        ++iter2;
        while (iter2 != res.end()) {
            if (iter1->second >= iter2->first) {
                if (iter1->second >= iter2->second) {
                    iter2->first = iter1->first;
                    iter2->second = iter1->second;
                }
                else
                    iter2->first = iter1->first;
                res.erase(iter1);
                tag = true;
                break;
            }
            else if (iter1->second == iter2->first - 1){
                iter2->first = iter1->first;
                res.erase(iter1);
                tag = true;
                break;
            }
            ++iter1;
            ++iter2;
        } 
    }
    
    if (res.size() == 1) {
        if (res.begin()->first == more_min && res.begin()->second == less_max) {
            cout << "true";
            return;
        }
        if (res.begin()->first == more_min) {
            cout << "x <= " << res.begin()->second;
            return;
        }
        if (res.begin()->second == less_max) {
            cout << "x >= " << res.begin()->first;
            return;
        }
        cout << "x >= " << res.begin()->first << " && x <= " << res.begin()->second;
        return;
    }

    auto intv = res.begin();
    if (intv->first != more_min) 
        cout << "x >= " << intv->first << " && x <= " << intv->second << " ||\n";
    else
        cout << "x <= " << intv->second << " ||\n";
    ++intv;
    auto test = intv;
    ++test;
    while (test != res.end()) {
        cout << "x >= " << intv->first << " && x <= " << intv->second << " ||\n";
        ++intv;
        ++test;
    }
    if (intv->second != less_max)
        cout << "x >= " << intv->first << " && x <= " << intv->second;
    else
        cout << "x >= " << intv->first;
}

int main() {
    freopen("每月一题/a.in", "r", stdin);
    freopen("每月一题/a.out", "w", stdout);
    while (inputAndDealwith());
    // output the answer
    output();

    return 0;
}