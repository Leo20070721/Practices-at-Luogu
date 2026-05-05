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
const int MAXN = 2e5 + 5;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int n;
bool check(int x)
{
	long long sum = 0, sb = 0;
	for (int i = 1; i <= n; i++)
	{
		d[i] = x / c[i];
		sum += d[i];
		sb += b[i];
	}
	if (sb > sum) return 0;
	for (int i = 1; i <= n; i++)
	{
		if (b[i] > sum - d[a[i]]) return 0;
	}
	return 1;
}
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	int T;
	cin >>T;
	while(T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) cin >> b[i];
		for (int i = 1; i <= n; i++) cin >> c[i];
		int l = 1, r = 1e18;
		int ans = r;
		while(l <= r)
		{
			int mid = l + r >>1;
			if (check(mid))
			{
				ans = mid;
				r = mid - 1;
			}
			else l = mid +1;
		}
		cout << ans <<"\n";
	}
	return 0;
}
/*
2
2
1 2
3 4
1 2
5
1 2 3 4 5
5 4 3 2 1
2 1 4 3 5*/


