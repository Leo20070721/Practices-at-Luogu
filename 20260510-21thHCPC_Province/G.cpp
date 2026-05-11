#include <bits/stdc++.h>
#define maxn 110
#define int long long
const int MOD = 998244353;
const int MAXN = 1e6 + 56;
using namespace std;
int w[MAXN];
int tmp = 1;
signed main() {
	int x;
	cin >> x;
	w[0] = 1;
	for (int i = 1; i <= x; i++)
	{
		w[i] = w[i-1] * 10 % MOD;
	}
	long long ans = 0;
	for (int i = 1; i <= x; i++)
	{
		ans = (ans + w[x-1]) % MOD;
	}
	cout << ans <<"\n";
	return 0;
}
