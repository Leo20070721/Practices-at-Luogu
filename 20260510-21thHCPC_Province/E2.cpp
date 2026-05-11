#include <bits/stdc++.h>
#define int long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
int tot;
const int MAXN = 1e5 + 5;
const int maxlog = 20;
const int INF = 2147483648;
int tr[MAXN << 2], lzy[MAXN<<2];
int f[MAXN][20];
int dep[MAXN];
int dfn[MAXN], siz[MAXN], rf[MAXN];
vector<int> e[MAXN];
int a[MAXN];
int moveup(int x, int d)
{
	for (int i = 0; d >> i; i++)
	{
		if (d >> i & 1)
		{
			x = f[x][i];
		}
	}
	return x;
}
int lca(int x, int y)
{
	if (dep[x] < dep[y])
	{
		swap(x, y);
	}
	x = moveup(x, dep[x] - dep[y]);
	if (x == y) return x;
	for (int i = maxlog - 1; i >= 0; i--)
	{
		if (f[x][i] != f[y][i])
		{
			x = f[x][i], y = f[y][i];
		}
	}
	return f[x][0];
}
int dist(int x, int y)
{
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
void dfs(int u, int p)
{
	dfn[u] = ++tot; rf[tot] = u;
	siz[u] = 1;
	for (auto v:e[u])
	{
		if (v == p) continue;
		dep[v] = dep[u] + 1;
		f[v][0] = u;
		dfs(v, u);
		siz[u] += siz[v];
	}
}
void preprocess(int n)
{
	for (int j = 1; j < maxlog; j++)
	{
		for (int i = 0; i <= n; i++)
		{
			f[i][j] = 0;
		}
	}
	for (int j = 1; j < maxlog; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			f[i][j] = f[f[i][j-1]][j-1];
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	//cout << dfn[1] << ' '<< dfn[2] << ' ' << dfn[3] << endl;
	preprocess(n);
	long long now = 1;
	for (int i = 1; i <= m; i++)
	{
		int op, x;
		cin >> op >> x;long long ans = INF;
		if (op == 1)
		{
			a[x] = !a[x];
		}
		else
		{
			now = x;
		}
		for (int j = 1; j <= n; j++)
		{
			if (a[j])
			{
				ans = min(ans, dist(now, j));
			}
		}
		cout << ans << "\n";
	}
	return 0;
 } 
