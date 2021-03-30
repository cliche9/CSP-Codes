#include <cstdio>

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int a, b;
    while (scanf("%x%x", &a, &b) != EOF)
        printf("%d\n", a + b);

    return 0;
}