#include <cstdio>
#include <cmath>
#define PI 3.14159265358979323846

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    double a, b, h, m;
    scanf("%lf%lf%lf%lf", &a, &b, &h, &m);
    printf("%.20f" ,sqrt(a * a + b * b - 2 * a * b * cos( 2 * PI * (30 * h - 5.5 * m) / 360 ))); 
    return 0;
}
