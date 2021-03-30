#include <cstdio>
#include <iostream>
#include <cstring>
using std::string;

int main(){
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int sum = 0;
    char *a;
    char c;
    while(scanf("%s", a)) {
        string s(a);
        sum += stoi(s);
        if (scanf("%c", &c) == EOF) {
            printf("%d\n", sum);
            return 0;
        }
        if (c == '\n') {
            printf("%d\n", sum);
            sum = 0;
            continue;
        }
    }
}