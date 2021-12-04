#include <cstdio>

int main() {
    int num = 0;
    int money = 0;

    scanf("%d", &money);
    num += money / 50 * 7;
    money %= 50;
    num += money / 30 * 4;
    money %= 30;
    num += money / 10;

    printf("%d", num);
    return 0;
}