#include <bits/stdc++.h>
#define maxn 10000010
#define int long long

int nex[maxn][26], cnt, ans;
std::map<int, int> t;
signed main() {
	int n;
	std::cin >> n;
	for (int j = 1; j <= n * 2; j++) {
		std::string s;
		std::cin >> s;
		int p = 0;
		for (int i = 0; i < (int)(s.size()); i++) {
			int c = s[i] - 'a';
			if (!nex[p][c])
				nex[p][c] = ++cnt;
			p = nex[p][c];
			// std::cout << p << ' '; 
			t[p]++;
			if (t[p] >= 2) {
				t[p]--;
				int a = t[p] / 2, b;
				b = t[p] - a;
				ans -= a * b;
				t[p]++;
				a = t[p] / 2, b = t[p] - a;
				ans += a * b;
				// std::cout << ans << '\n';
			}
		}
	}
	std::cout << ans << '\n';
}
/*
3
why
soul
spell
well
weels
whom
*/
