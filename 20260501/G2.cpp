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
const int MAXN = 1e5 + 4;
bool vis[MAXN];
int path[MAXN];
int len;
int n;
long long ans = 0;
void dfs(int i)
{
	//cout << ":::" << i << endl;
	if (i == (1 << n) + 1)
	{
		//for (int i = 1; i <= (1 << n); i++) cout << path[i] <<' ';
		//cout << endl;
		if ((path[(1 << n)] & ((1 << (n-1)) - 1)) == (path[1] >> 1))
			ans++;
		return;
	}
	//cout <<":\n";
	//for (int j = 1; j < i; j++) cout << path[j] <<' ';
	
	int tmp = ((path[i-1] & ((1 << (n-1)) - 1)) << 1);
	//cout << tmp;
	//cout << endl;
	if (!vis[tmp]) vis[tmp] = 1, path[i] = tmp, dfs(i+1), vis[tmp] = 0;
	if (!vis[tmp +1]) vis[tmp+1] = 1, path[i] = tmp+1, dfs(i+1), vis[tmp+1] = 0;
}
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	for (n = 2; n <= 10; n++)
	{
		ans = 0;
		path[1] = 0;
		vis[0] = 1;
		dfs(2);
		cout << n <<":" << ans << endl;
	}

	return 0;
}



