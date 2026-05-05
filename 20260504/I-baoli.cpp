#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
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
const int MAXN = 1e5 + 5;
const int MOD = 998244353;
int n, k;
int ans = 0;
int f[2][100005];
int fact[100005];
long long cnt[15];
int a[15];
bool vis[15];
void dfs(int i)
{
	if (i == n+1)
	{
		for (int i = 1; i <= n; i++)
		{
			vis[i] = 0;
		}
		for (int i = 1; i + k - 1 <= n; i++)
		{
			for (int j = i; j <= i + k - 1; j++)
			{
				cnt[a[j]]++;
			}
			bool flag = 1;
			for (int j = 1; j <= k; j++)
			{
				if (cnt[j] != 1) 
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				for (int j = i; j <= i + k - 1; j++) vis[j] = 1;
			}
			for (int j = 1; j <= k; j++) cnt[j] = 0;
		}
		for (int i = 1; i <= n; i++) if (!vis[i]) return;
		//for (int i = 1; i <= n; i++) cout <<a[i] << ' ';
		//cout << endl;
		ans++; return;
	}
	for (int j = 1; j <= k; j++)
	{
		a[i] = j;
		dfs(i+1);
	}
}
signed main(){
//	if(_QuickStream){_QuickStreamOpen();}
//	if(_FILE){_OpenFiles();}

	cin >> n >> k;
	//cout << ans << endl;
	//cout << "AAA\n";
	dfs(1);
	cout << ans;
	return 0;
}



