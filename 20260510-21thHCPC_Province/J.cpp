#include <bits/stdc++.h>
#define int long double
using namespace std;
signed main()
{
	int T;
	cin >> T;
	while(T--)
	{
		long long n, tmp = 0, k;
		cin >> n >> k;
		for (int i = 1;i < n; i++)
		{
			long long x;
			cin >> x;
			tmp += x;
		}
		if (k % 4 == 1) cout << (tmp + k / 4) << ".250000000\n";
		else if (k % 4 == 2) cout << (tmp + k / 4) << ".500000000\n"; 
		else if (k % 4 == 3) cout << (tmp + k / 4) << ".750000000\n";
		else cout << (k/4 + tmp) << ".000000000\n";
	}
	return 0;
}
