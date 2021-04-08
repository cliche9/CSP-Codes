#include <cstdio>

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    scanf("%d", &n);
    bool tag = true;
    char c;
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%c", &c);
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            printf("%c", c);
            tag = true;
        }
        else {
            if (tag) {
                printf("%c", c);
                tag = false;
            }
        }
    }
    printf("\n");

    return 0;
}