#include <bits/stdc++.h>
#define maxn 2010

struct node {
	int id, cnt;
}s[maxn];
int p[maxn][maxn];
int f[maxn];
int vis[maxn];
bool cmp(node a, node b) {
	return a.cnt > b.cnt;
}
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			std::cin >> p[i][j];
			s[j].id = 0, s[j].cnt = 0, f[j] = 1;
		}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			if (i == 1)
				s[j].id = p[i][j], s[j].cnt = 1;
			else {
			    if (p[i][j] == s[j].id && f[j])
					s[j].cnt++;
				if (p[i][j] != s[j].id)
					f[j] = 0;
				}
		}
	}
	std::sort(s + 1, s + m + 1, cmp);
//	for (int j = 1; j <= m; j++)
//		std::cout << s[j].id << ' ' << s[j].cnt << '\n';
//	
	int ans = 0;
	for (int j = 1; j <= m; j++) {
		if (!vis[s[j].id]) {
			vis[s[j].id] = 1;
			ans += n - s[j].cnt;
		}
		else
			ans += n;
	}
	std::cout << ans << '\n';
}

/*
4 4
1 4 2 2
2 4 3 2
3 3 3 1
1 4 4 1

4 4
1 4 2 2
2 4 3 2
3 3 3 1
4 1 4 1

5 5
1 1 2 3 5
1 1 2 4 5
1 4 2 4 5
4 4 2 3 5
3 3 2 3 5
*/
