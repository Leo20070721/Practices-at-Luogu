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
const int MAXN = 1e5 +5;
int cnt[MAXN];
vector<int> q;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		cnt[u]++; cnt[v]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] & 1) q.push_back(i);
	}
	int sz = q.size();
	cout << (sz + 1) / 2 <<"\n";
	for (int i = 0; i < sz; i+=2)
	{
		if (i == sz - 1)
		{
			cout << q[i] <<' ';
		}
		else cout << q[i] <<' ' << q[i+1] <<' ';
	}
	return 0;
}



