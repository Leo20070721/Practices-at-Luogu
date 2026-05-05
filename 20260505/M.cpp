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
const int MAXN = 1e6 + 6;
int fa[MAXN];
int Find(int x)
{
	if (x == fa[x]) return x;
	return fa[x] = Find(fa[x]);
}
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) fa[i] = i;
	long long ans = 0;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		int Fu = Find(u), Fv = Find(v);
		if (Fu!= Fv)
		{
			fa[Fu] = Fv;
		}
		else ans++;
	 } 
	 for (int i = 1; i < n; i++)
	 {
	 	if (Find(i) != Find(i+1))
	 	{
	 		fa[Find(i)] = Find(i+1);
	 		ans++;
		 }
	 }
	 cout << ans;
	return 0;
}
/*
5 5
1 2
2 1
5 4
5 4
2 5
*/


