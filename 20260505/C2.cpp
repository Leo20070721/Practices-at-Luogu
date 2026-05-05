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
int n, m;
int a[200005];
int cnt[400005];
void solve()
{
	for (int i = 1; i <= 2*n; i++)
	{
		cnt[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		cnt[a[i]]++;
	}
	int pos = 1;
	for (int i = 1; i <= 2*n; i++)
	{
		if (cnt[pos] < cnt[i]) pos = i;
	}
	cout << pos << ' ' << cnt[pos] << "\n";
}
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> a[i];
		solve();
		for (int i = 1; i <= m; i++)
		{
			int l, r, d;
			cin >> l >> r >> d;
			for (int k = l, j = d; k <= r; k++, j++)
			{
				a[k] = j;
			}
			solve();
		}
	}
	return 0;
}
/*
1
7 5
4 6 4 7 7 1 4 
1 5 4
4 5 6
1 3 5
3 3 4
1 6 2
*/


