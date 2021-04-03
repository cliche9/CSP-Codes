#include <iostream>
using namespace std;
const int expo = 1e9 + 7;
int nums[100000] = {1};
bool primes[expo] = {false};
int prime[expo] = {0};

int quickMulti(int a, int b) {
    int ans = 0;
    a %= expo;
    while (b) {
        if (b & 1)
            ans = (a + ans) % expo;
        a = (a + a) % expo;
        b >>= 1;
    }
    return ans % expo;
}

int quickMod(int c, int b) {
    int ans = 1;
    while (b) {
		if (b & 1)
			ans = (ans * c) % expo;
		b /= 2;
		c = (c * c) % expo;
	}
	return ans;
}

void multi(int l, int r, int c, int b) {
    for (int i = l; i < r; i++)
        nums[i] = quickMulti(nums[i], quickMod(c, b));
}

int gcd(int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        for (int k = sqrt(nums[i]); k >= 2; k--) {
            if (primes[k] && k < num) {
                if (prime[k] == 0)
                    prime[k] = (int)(num / k == 0 ? sqrt(num) : num / (num % k) / k);
                else
                    prime[k] = min(prime[k], (int)(num / k == 0 ? sqrt(num) : num / (num % k) / k));
                num %= k;
            }
        }
    }

    for (int i = 2; i <= sqrt(expo); i++)
        ans += pow(i, prime[i]);

    return ans;
}

int main() {
    for (int i = 0; i < expo; i++)
        if (i & 1)
            primes[i] = true;
    primes[2] = true;

    for (int i = 3; i <= sqrt(expo); i += 2)
        if (primes[i])
            for (int j = 2*i; j <= expo; j += i)
                primes[j]=false;
    
    int n = 0, m = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    for (int i = 0; i < m; i++) {
        int l, r, c, b;
        cin >> l >> r >> c >> b;
        multi(l, r, c, b);
    }
    cout << gcd(n) << endl;

    return 0;
}