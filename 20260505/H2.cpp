#include <bits/stdc++.h>
#define int long long
#define maxn 1010

int a[maxn];
std::map<int, int> m;
signed main() {
	int n = 35; 
	for (int i = 1; i <= n * n; i++) {
		a[i] = i * (i + 1);
		m[a[i]] = i;
		// std::cout << a[i] << ' ' << i << '\n';
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			if (m[a[i] * a[j]]) {
				std::cout << i <<' ' << j << ' ' << m[a[i] * a[j]] << '\n';
			}
		}
}
