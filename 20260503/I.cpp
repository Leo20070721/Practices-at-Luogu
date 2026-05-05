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
const int MAXN= 5e5 +4;
int a[MAXN];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	int T;
	cin >>T;
	while(T--)
	{
		int n, s, t;
		cin >> n >> s >> t;
		for (int i = 1; i <= n; i++)
		{
			cin >>a[i];
		 } 
		if (s > t) swap(s, t);
		if (s == t)
		{
			cout << "Yes\n";
			continue;
		}
		if (s <= n && a[s] == t)
		{
			cout <<"No\n";
			continue;
		}
		else
		{
			if (n >= 3)
			{
				cout << "Yes\n";
			}
			else
			{
				if (s <= n && t <= n || s > n && t > n)
				{
					cout << "No\n";
				}
				else cout << "Yes\n";
			}
		}
	}
	return 0;
}



