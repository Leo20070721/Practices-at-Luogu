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
double f[100005];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	int n, m;
	cin >> n >> m;
	f[m] = 0;
	for (int i = m-1; i >= 0; i--)
	{
		f[i] = f[i+1] + 1.0 * n / (m - i);
		
	}
	printf("%.8f", f[0]);
	return 0;
}



