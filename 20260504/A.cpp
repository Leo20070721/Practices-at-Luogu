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

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	long long n, k;
	cin >> n >> k;
	if (n == 1)
	{
		cout <<1;
		return 0;
	}
	long long ans = k+1;
	for (int i = 1; i <= k; i++)
	{
		if (n == 1) break;
		long long tmp = sqrt(n);
		if (tmp == 1)
		{
			ans++; break;
		}
		if (tmp * tmp != n) ans += k - i;
		n = sqrt(n); ans++;
	}
	cout << ans <<"\n";
	return 0;
}



