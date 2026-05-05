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
string s;

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	int T;
	cin >> T;
	while(T--)
	{
		int n, k;
		cin >> n >> k;
		cin >> s;
		int a = 0, b = 0;
		long long ans = (1 << 30);
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '1')
				a++;
		}
		for (int i = 0; i <= k; i++)
		{
			int d = a + i;
			d = (d & ((1 << k)-1));
			b = d;
			int cnt = 0;
			while(d)
			{
				if (d & 1) cnt++;
				d >>=1;
			}
			if (cnt == i) ans = min(ans, b*1ll);
		}
		if (ans == (1 << 30)) cout << "None\n";
		else
		{
			stack<int> sta;
			for (int i = 1; i <= k; i++)
			{
				sta.push(ans&1);
				ans >>= 1;
			}
			while(!sta.empty())
			{
				cout << sta.top();
				sta.pop();
			 } 
			cout << "\n";
		}
		
	}
	return 0;
}
/*
2
1 1
1
1 2
1
*/


