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
	int T = 3;
	cout << 3 << endl;
	srand(time(0));
	while(T--)
	{
		int n = rand() % 15 + 1, m = rand() % 15 + 1;
		cout << n <<' ' << m << endl;
		for (int i = 1; i <= n; i++)
		{
			cout << rand() % n + 1 << ' ';
		}
		cout << endl;
		for (int i = 1; i <= m; i++)
		{
			int l = rand() % n + 1, r = rand() % n + 1;
			if (r < l) swap(l, r);
			cout << l << ' ' << r << ' ' << rand() % n + 1 << "\n";
		 } 
	}
	return 0;
}



