#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
inline void _OpenFiles(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
const bool _QuickStream=true;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------
int f[5005][5];
int g[5005][5];
// 0-1st 1-2nd 2-3rd 3-4th
int a[5005];
vector<int> e[5005];
void update(int u, int w, int p)
{
	if (w > f[u][0])
	{
		f[u][3] = f[u][2], f[u][2] = f[u][1], f[u][1] = f[u][0], f[u][0] = w;
		g[u][3] = g[u][2], g[u][2] = g[u][1], g[u][1] = g[u][0], g[u][0] = p;
	 } 
	else if (w > f[u][1])
	{
		f[u][3] = f[u][2], f[u][2] = f[u][1], f[u][1] = w;
		g[u][3] = g[u][2], g[u][2] = g[u][1], g[u][1] = p;
	 } 
	else if (w > f[u][2])
	{
		f[u][3] = f[u][2], f[u][2] = w;
		g[u][3] = g[u][2], g[u][2] = p;
	 } 
	else if (w > f[u][3]) f[u][3] = w, g[u][3] = p;
}
bool vis[5005];
bool gg[5005][5005];
signed main(){
	//if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		for (auto v:e[i])
		{
			if (gg[i][v]) continue;
			update(i, a[v] + a[i], v);
			gg[i][v] = 1;
		 } 
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, a[i] + a[g[i][0]] + a[g[i][1]] + a[g[i][2]] + a[g[i][3]]);
		for (auto j:e[i])
		{
			ans = max(ans, a[i] + a[j]);
			for (auto k:e[i])
			{
				if (k == j || k == i || i == j) continue;
				vis[k] = vis[j] = vis[i] = 1;
				if (i == 3 && j == 2 && k == 6) 
				{
					//cout << "FKJDD\n";
					//cout << g[j][1] << ' ' << g[k][1] << endl;
				}
				ans = max(ans, a[i] + a[j] + a[k]);
				for (int x = 0; x < 4; x++)
				{
					if (!vis[g[j][x]] || !g[j][x])
					{
						vis[g[j][x]] = 1;
					}
					else continue;
					for (int y = 0; y < 4; y++)
					{
						if (!vis[g[k][y]] || !g[k][y])
						{
							ans = max(ans, a[i] + a[j] + a[k] + a[g[j][x]] + a[g[k][y]]);
							//cout << j <<' ' << x << ' ' << k << ' ' << y << ":" << a[i] << ' ' << a[j] << ' ' << a[k] << ' ' << a[g[j][x]] << ' ' << a[g[k][y]] << endl;
						}
					}
					ans = max(ans, a[i] + a[j] + a[k] + a[g[j][x]]);
					vis[g[j][x]] = 0;
				}
				vis[k] = vis[j] = vis[i] = 0;
			}
			
		}
	}
	cout << ans <<"\n";
	return 0;
}



