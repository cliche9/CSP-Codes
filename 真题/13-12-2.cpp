#include <cstdio>
#include <cstring>

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    char s[13];
    scanf("%s", s);
    int sum = s[0] - '0';

    for (int i = 2; i < 5; i++)
        sum += (s[i] - '0') * i;
    for (int i = 6; i < 11; i++)
        sum += (s[i] - '0') * (i - 1);
    
    sum %= 11;
    if (sum == 10)
        sum = 'X' - '0';
    if (s[12] - '0' == sum)
        printf("Right\n");
    else {
        s[12] = sum + '0';
        printf("%s\n", s);
    }

    return 0;
}
