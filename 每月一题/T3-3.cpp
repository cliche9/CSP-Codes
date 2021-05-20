#include <iostream>
#include <vector>
using namespace std;

vector<string> page(1);
bool shift_on = false;
bool selected = false;
vector<string> copy_string;
pair<int, int> cursor(0, 0);
pair<int, int> log_point(0, 0);

void _remove() {
    pair<int, int> from = min(cursor, log_point), to = max(cursor, log_point);
    if (from.first == to.first)
        page[from.first].erase(from.second, to.second - from.second);
    else {
        page[from.first].erase(from.second);
        page[from.first] += page[to.first].substr(to.second);
        for (int i = to.first; i > from.first; --i)
            page.erase(page.begin() + i);
    }
    cursor = from;
    selected = false;
}

void _move(const string &cmd) {
    if (selected) {
        selected = false;
    }
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
        if ((cursor.first == page.size() - 1) && (cursor.second == page[page.size() - 1].length()))
            return;
        if (cursor.second == page[cursor.first].length()) {
            ++cursor.first;
            cursor.second = 0;
        } else
            ++cursor.second;
    }
}

void insert(const string &cmd) {
    if (cmd == "Paste" && copy_string.empty())
        return;
    if (selected)
        _remove();
    if (cmd == "Enter") {
        string t = page[cursor.first].substr(cursor.second);
        page[cursor.first].erase(cursor.second);
        // 改变光标位置
        ++cursor.first;
        page.insert(page.begin() + cursor.first, t);
        cursor.second = 0;
    } else if (cmd == "Space") {
        page[cursor.first].insert(cursor.second, " ");
        ++cursor.second;
    } else if (cmd == "Paste") {
        if (copy_string.size() == 1) {
            page[cursor.first].insert(cursor.second, copy_string[0]);
            cursor.second += copy_string[0].size();
        }
        else {
            string t = page[cursor.first].substr(cursor.second);
            page[cursor.first].erase(cursor.second);
            page[cursor.first] += copy_string[0];
            for (int i = 1; i < copy_string.size(); ++i)
                page.insert(page.begin() + cursor.first + i, copy_string[i]);
            cursor.first += copy_string.size() - 1;
            page[cursor.first] += t;
            cursor.second = copy_string[copy_string.size() - 1].length();
        }
    } else {
        string c;
        cin >> c;
        page[cursor.first].insert(cursor.second, c);
        ++cursor.second;
    }
}

void remove(const string &cmd) {
    if (selected) {
        _remove();
        return;
    }
    if (cmd == "Del") {
        if ((cursor.first == page.size() - 1) && (cursor.second == page[page.size() - 1].length()))
            return;
        if (cursor.second == page[cursor.first].length()) {
            page[cursor.first] += page[cursor.first + 1];
            page.erase(page.begin() + cursor.first + 1);
        } else 
            page[cursor.first].erase(cursor.second, 1);
    } else {
        if (cursor.first == 0 && cursor.second == 0)
            return;
        if (cursor.second == 0) {
            cursor.second = page[cursor.first - 1].length();
            page[cursor.first - 1] += page[cursor.first];
            page.erase(page.begin() + cursor.first);
            --cursor.first;
        } else {
            page[cursor.first].erase(cursor.second - 1, 1);
            --cursor.second;
        }
    }
}

void shift() {
    shift_on = !shift_on;
    if (shift_on) {
        if (selected)
            selected = false;
        else
            log_point = cursor;
    }
    else {
        if (log_point != cursor)
            selected = true;
    }
}

void find(const string &word) {
    int res = 0;

    int length = word.length();
    if (selected) {
        pair<int, int> from = min(cursor, log_point), to = max(cursor, log_point);
        if (from.first == to.first) {
            if (to.second - from.second >= length) {
                for (int i = from.second; i <= to.second - length; ++i) {
                    if (page[from.first].substr(i, length) == word)
                        ++res;
                }
            }
        }
        else {
            // 头
            if (page[from.first].length() - from.second >= length) {
                for (int i = from.second; i <= page[from.first].length() - length; ++i) {
                    if (page[from.first].substr(i, length) == word)
                        ++res;
                }
            } 
            // 中间
            for (int i = from.first + 1; i < to.first; ++i) {
                if (page[i].length() >= length) {
                    for (int j = 0; j <= page[i].length() - length; ++j) {
                        if (page[i].substr(j, length) == word)
                            ++res;
                    }
                }
            }
            // 尾
            if (to.second >= length) {
                for (int i = 0; i <= to.second - length; ++i) {
                    if (page[to.first].substr(i, length) == word)
                        ++res;
                }
            }
        }
    } 
    else {
        for (int i = 0; i < page.size(); ++i) {
            if (page[i].length() >= length) {
                for (int j = 0; j <= page[i].length() - length; ++j) {
                    if (page[i].substr(j, length) == word)
                        ++res;
                }
            }
        }
    }
    cout << res << '\n';
}

void count() {
    int res = 0;
    if (selected) {
        pair<int, int> from = min(cursor, log_point), to = max(cursor, log_point);
        if (from.first == to.first) {
            for (int i = from.second; i < to.second; ++i)
                if (page[from.first][i] != ' ')
                    ++res;
        }
        else {
            // 头
            for (int i = from.second; i < page[from.first].length(); ++i) {
                if (page[from.first][i] != ' ')
                    ++res;
            }
            // 中间
            for (int i = from.first + 1; i < to.first; ++i) {
                for (auto c : page[i])
                    if (c != ' ')
                        ++res;
            }
            // 尾
            for (int i = 0; i < to.second; ++i) {
                if (page[to.first][i] != ' ')
                    ++res;
            }
        }
    }
    else {
        for (int i = 0; i < page.size(); ++i)
            for (auto c : page[i])
                if (c != ' ')
                    ++res;
    }
    cout << res << '\n';
}

void copy() {
    if (selected) {
        copy_string.clear();
        pair<int, int> from = min(cursor, log_point), to = max(cursor, log_point);
        if (from.first == to.first)
            copy_string.push_back(page[from.first].substr(from.second, to.second - from.second));
        else {
            copy_string.push_back(page[from.first].substr(from.second));
            for (int i = from.first + 1; i < to.first; ++i)
                copy_string.push_back(page[i]);
            copy_string.push_back(page[to.first].substr(0, to.second));
        }
    }
    else if (!page[cursor.first].empty()) {
       copy_string.clear();
       copy_string.push_back(page[cursor.first]);
    }
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