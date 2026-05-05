#include <bits/stdc++.h>
#define int long long

signed main() {
	int n, m;
	const int INF = 1e18;
	std::cin >> n >> m;
	std::vector<std::vector<int> > a(n + 1, std::vector<int> (m + 1));
	std::vector<std::vector<int> > b(n + 1, std::vector<int> (m + 1));
	std::vector<std::vector<int> > f(n + 1, std::vector<int> (m + 1, INF));		
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			std::cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			std::cin >> b[i][j];
	f[1][1] = b[1][1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1)
				continue;
			int cost = std::min(f[i - 1][j], f[i][j - 1]) + b[i][j];
			if (cost != INF && cost <= a[i][j] - a[1][1]) {
				f[i][j] = cost;
			} 
		}
	int flag = 0;
	for (int i = 1; i <= n; i++)
		if (f[i][m] != INF)
			flag = 1;
	for (int j = 1; j <= m; j++)
		if (f[n][j] != INF)
			flag = 1;
	if (flag)
		std::cout <<"YES\n";
	else
		std::cout <<"NO\n";
}
