#include <iostream>
using namespace std;

int n, m;
string s;
int ch[26];//每个字母在该区间出现的次数
int res[500100];//每个节点的最小右节点，保证出现了26个字母的情况下

int main() {
	cin >> n >> s >> m;

	fill(res, res + 500100, 1 << 30);
	int l = 0, r = 0, cnt = 0;

	while (l < n) {
		while (cnt < 26 && r < n) {
			if (ch[s[r] - 'A'] == 0)
				cnt++;
			ch[s[r] - 'A']++;
			if (cnt == 26)
				break;
			r++;
		}
		if (cnt == 26)
			res[l] = r - 1;
		if (ch[s[l] - 'A'] != 0) {
			ch[s[l] - 'A']--;
			if (ch[s[l] - 'A'] == 0)
				cnt--;
		}
		l++;
	}

	for (int i = 0; i < m; i++) {
		cin >> l >> r;
		l--, r--;
		cout << (res[l] <= r ? "YES\n" : "NO\n");
	}

	return 0;
}