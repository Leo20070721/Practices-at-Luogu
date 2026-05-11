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
void push_up(int rt)
{
	tr[rt] = min(tr[rt<<1], tr[rt<<1|1]);
}
void push_down(int l, int r, int rt)
{
	if (lzy[rt])
	{
		tr[rt<<1] += lzy[rt];
		tr[rt<<1|1] += lzy[rt];
		lzy[rt<<1] += lzy[rt];
		lzy[rt<<1|1] += lzy[rt];
		lzy[rt] = 0;
	}
}
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
void build(int l, int r, int rt)
{
	if (l == r)
	{
		lzy[rt] = 0; tr[rt] = INF; return;
	}
	int mid = (l + r )>> 1;
	build(lson); build(rson);
	push_up(rt);
}
void update(int L, int R, int x, int l, int r, int rt)
{
	if (L <= l && r <= R)
	{
		tr[rt] += x;
		lzy[rt] += x;
		return;
	}
	int mid = (l + r) >> 1;
	push_down(l, r, rt);
	if (mid >= L) update(L, R, x, lson);
	if (mid < R) update(L, R, x, rson);
	push_up(rt);
	//cout << ":" << tr[rt] << ' ' << l << ' ' << r << endl;
}
int query(int p, int l, int r, int rt)
{
	if (l == r)
	{
		return tr[rt];
	}
	int mid = (l + r) >> 1;
	push_down(l, r, rt);
	if (mid >= p) return query(p, lson);
	else return query(p, rson);
	
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
	build(1, n, 1);
	//cout << ":" << tr[1] << endl;
	//cout << "FKJS\n";
	int now = 1;
	for (int i = 1; i <= m; i++)
	{
		int op, x;
		cin >> op >> x;
		//cout << ":" << dfn[2] << endl;
		if (op == 1)
		{
			int tmp = query(dfn[x], 1, n, 1);
			if (tmp < 1e6)
			{
				update(dfn[x], dfn[x], INF - tmp, 1, n, 1);
			}
			else
			{
				//cout << ":" << -tmp + dist(now, x) << endl;
				update(dfn[x], dfn[x], -tmp + dist(now, x), 1, n, 1);
			}
		}
		else
		{
			if (f[now][0] == x)
			{
				//cout << "!!!\n";
				//cout << "::" << query(5, 1, n, 1) << "\n";
				update(dfn[now], dfn[now] + siz[now] - 1, 1, 1, n, 1);
				if (dfn[now] > 1) update(1, dfn[now]-1, -1, 1, n, 1);
				if (dfn[now] + siz[now] <= n) update(dfn[now] + siz[now], n, -1, 1, n, 1);
				//now = x;
				//cout << "::" << query(5, 1, n, 1) << "\n";
				//cout <<now << ":" << dfn[now] << ' ' << dfn[now] + siz[now] - 1 << endl;
				//cout << "::" << query(5, 1, n, 1) << "\n";
			}
			else
			{
				update(dfn[x], dfn[x] + siz[x] - 1, -1, 1, n, 1);
				if (dfn[x] - 1 >= 1) update(1, dfn[x]-1, 1, 1, n, 1);
				if (dfn[x] + siz[x] <= n) update(dfn[x] + siz[x], n, 1,  1, n, 1);
			}
			now = x;
			
		}
		//cout << ":" << tr[1] << endl;
		if (tr[1] > 1e6) cout << "2147483648\n";
		else cout << tr[1] << "\n";
	}
	return 0;
 } 
 /*
5 8
2 1
3 1
4 2
5 4
2 3
2 1
2 3
1 3
1 2
1 2
2 1
2 3
*/
