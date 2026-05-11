#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int tmp = n / 2;
	for (int i = 1; i <= n; i++)
	{
		if (i + tmp > n) cout << (i + tmp - n) << ' ';
		else cout << i + tmp << ' ';
	}
	return 0;
}
