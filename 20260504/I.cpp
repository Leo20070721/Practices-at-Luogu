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
const int MAXN = 1e5 + 5;
const int MOD = 998244353;
int n, k;
int ans = 0;
int f[100005];
int fact[100005];
int inv[100005];
int finv[100005];
int A(int n, int m)
{
	return fact[n] * finv[n - m] % MOD;
}
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin >> n >> k;
	if (n < k)
	{
		cout << "0\n";
		return 0;
	}
	fact[0] = fact[1] = 1; finv[0] = finv[1] = 1; inv[1] = 1;
	for (int i = 1; i <= n; i++) fact[i] = fact[i- 1] * i % MOD;
	for (int i = 2; i <= n; i++)
	{
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
	}
	f[k] = fact[k];
	for (int i = k+1; i <= n; i++)
	{
		f[i] += f[i-1]; f[i] %= MOD;
		long long sum = 1;
		cout << ":\n";
		for (int j  = i - 2, cnt = 2; j >= max(i - k, 0ll); j--, cnt++)
		{
			f[i] += f[j] * ((fact[i - j] - sum)  % MOD) % MOD;
			f[i] %= MOD;
			sum = sum * 4 % MOD + MOD - 1; sum %= MOD;
			cout << sum << ' ';
		}
		cout << endl;
		cout << f[i] << ' ';
	}
	//cout << endl;
	cout << f[n];
	return 0;
}



