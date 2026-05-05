#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
//#define int long long
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
char s[1005][1005];
int mi[1005][1005][4];
bool vis[1005][1005][2];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;
bool check(int i, int j)
{
	if (i >= 1 && i <= n && j >= 1 && j <= m && s[i][j] == '.') return 1;
	return 0; 
}
void bfs(int x, int y, int t)
{
	queue<pair<int, int> > q;
	q.push({x, y});
	while(!q.empty())
	{
		pair<int, int> now = q.front();
		int u = now.first, v = now.second;
		q.pop();
		vis[u][v][t] = 1;
		for (int i = 0; i < 4; i++)
		{
			int tx = u + dx[i], ty = v + dy[i];
			if (!vis[tx][ty][t] && check(tx, ty))
			{
				vis[tx][ty][t] = 1;
				q.push({tx, ty});
			}
		}
	}
	
}
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> s[i][j];
			 } 
		}
		for (int i = 0; i <= n+1; i++)
		{
			for (int j = 0; j <= m+1; j++)
			{
				mi[i][j][0] = mi[i][j][1] = mi[i][j][2] = mi[i][j][3] = 114514;
				vis[i][j][0] = vis[i][j][1] = 0;
			 } 
		}
		bfs(1, 1, 0);
		bfs(n, m, 1);
		for (int i = n; i >= 1; i--)
		{
			for (int j = 1; j <= m; j++)
			{
				mi[i][j][3] = min(mi[i+1][j][3], mi[i][j-1][3]);
				if (vis[i][j][1]) mi[i][j][3] = min(mi[i][j][3], i-j);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				mi[i][j][2] = min(mi[i-1][j][2], mi[i][j-1][2]);
				if (vis[i][j][1]) mi[i][j][2] = min(mi[i][j][2], -i-j);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = m; j >= 1; j--)
			{
				mi[i][j][1] = min(mi[i-1][j][1], mi[i][j+1][1]);
				if (vis[i][j][1]) mi[i][j][1] = min(mi[i][j][1], -i+j);
			}
		}
		for (int i = n; i >= 1; i--)
		{
			for (int j = m; j >= 1; j--)
			{
				mi[i][j][0] = min(mi[i+1][j][0], mi[i][j+1][0]);
				if (vis[i][j][1]) mi[i][j][0] = min(mi[i][j][0], +i+j);
			}
		}
		int ans = 114514;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (vis[i][j][0])
				{
					ans = min({ans, mi[i][j][0] - i - j - 1, mi[i][j][1] + i - j - 1, mi[i][j][2] + i + j - 1, mi[i][j][3] - i + j - 1});					
				}
			}
		}
		ans = max(ans, 0);
		cout << ans <<"\n";
	}
	return 0;
}
/*
2
3 4
..##
###.
.##.
3 2
..
##
..
*/
