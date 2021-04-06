#include<bits/stdc++.h>
using namespace std;
#define ll long long

// 1到100有25个质数
ll a[100100][26];
int zhishu[26] = { 1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
ll p = 1e9 + 7;
int n, m;
ll minPower[26];

// 快速幂
ll qpow(ll a, ll b,ll s)
{
	ll ans = s;
	for (a %= p; b; a = a * a % p, b >>= 1)
	{
		if (b & 1)
			ans = ans * a % p;
	}
	return ans;
}

// 记录每个c能转化成怎样的质数
void writePower(ll l, ll r, ll c, ll b)
{

	for (int i = 1; i <= 25; i++)
	{
		while (c % zhishu[i] == 0)
		{
			c = c / zhishu[i];
			a[l][i] += b;
			a[r + 1][i] -= b;
		}
	}
}

int main()
{
	ll l, r, c, b, t = 0, ans = 1;

	//初始化 
	for (int i = 1; i <= 25; i++)
		minPower[i] = 1e20;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < 26; j++)
			a[i][j] = 0;
	}

	cin >> n >> m;

	// m次操作 
	for (int i = 1; i <= m; i++)
	{
		cin >> l >> r >> c >> b;
		writePower(l, r, c, b);
	}

	// 找到每一个质数项的最小数 
	for (int i = 1; i <= 25; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[j][i] += a[j - 1][i];
			if (a[j][i] < minPower[i])
				minPower[i] = a[j][i];
		}
	}

	for (int i = 1; i <= 25; i++)
	{
		if (minPower[i] != 0)
		{
			ans = qpow(zhishu[i], minPower[i],ans)%p;
		}
	}

	cout << ans;
}