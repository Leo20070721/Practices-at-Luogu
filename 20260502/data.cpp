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
	srand(time(0));
	int n = rand() % 20, q = rand() % 20;
	cout << n << ' ' <<q << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << rand() % 2;
	}
	cout << endl;
	for (int i = 1; i <= q; i++)
	{
		int op = rand() % 2;
		if (op) cout << "M ";
		else cout <<"Q ";
		int l = rand() % n + 1, r = rand() % n + 1;
		if (l > r) swap(l, r);
		cout << l <<' ' << r << endl;
	}
	return 0;
}



