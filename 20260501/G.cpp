#include <bits/stdc++.h>
using namespace std;
#define lli long long
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
const int MOD = 998244353;
//------------------------------------------
int a[5005];
bool check(int n)
{
	bool flag = 1;
	a[0] = a[(1 << n)];
	//for (int i = 1; i <= (1 << n); i++) cout << a[i] <<' ';
	//cout << endl;
	for (int i = 1; i <= (1 << n); i++)
	{
		//cout << ((a[i] & ((1 << n) - 2))>> 1) <<' ' << (((a[i-1] << 1) &((1 << n)-1) )>>1) << endl; 
		if (((a[i] & ((1 << n) - 2))>> 1) == (((a[i-1] << 1) &((1 << n)-1) )>>1))
			flag = 1;
		else return 0;	
	}
	return 1;
}
int fast_power(int a, int p, int M)
{
	int res = 1, tmp = a;
	while(p)
	{
		if (p & 1) res = res * tmp % M;
		tmp = tmp * tmp % M;
		p >>= 1;
	}
	return res;
}
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	int n;
	cin >> n;
	n %= (MOD- 1);
	//int m = (fast_power(2, n - 1), MOD - 1);
	//m = (m + MOD)
	int m = (fast_power(2, n - 1, MOD - 1) + (MOD - 1 - n) % (MOD - 1)) % (MOD - 1);
	cout << fast_power(2, m, MOD) <<"\n";
	return 0;
}



