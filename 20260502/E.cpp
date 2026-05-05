#include <bits/stdc++.h>
using namespace std;
#define lli long long
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
const int MAXN = 1e5 + 5;
int a[MAXN];
bool vis[MAXN];
int n, m;
unsigned long long cnt = 0, tot = 0;
void dfs(int i)
{
	if (i == n)
	{
		tot++;
		if (!vis[n]) cnt++;
		return;
	}
	if (i <= m)
	{
		for(int j = 1; j <= n; j++)
		{
			if (!vis[j])
			{
				vis[j] = 1;
				dfs(i+1);
				vis[j] = 0;
			}
		}
	}
	else
	{
		if (!vis[i]) vis[i] = 1, dfs(i+1), vis[i] = 0;
		else
		{
			for (int j = 1; j <= n; j++)
			{
				if (!vis[j]){
					vis[j] = 1;
					dfs(i+1);
					vis[j] = 0; 
				}
			}
		}
	}
}
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin >> n >> m;
	if (m == n)
	{
		printf("%.7f", 1.0 / n);
		return 0;
	}
	dfs(1);
	printf("%.7lf", 1.0*cnt / tot);
	return 0;
}



