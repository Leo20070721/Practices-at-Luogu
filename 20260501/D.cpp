#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN= 1e5 + 5;
const int INF = (1ll <<60);
int a[MAXN], b[MAXN];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n, hpa, hpb;
		cin >> n >> hpa >> hpb;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> b[i];
			if (b[i] == -1) b[i] = INF;
		}
		sort(a+1, a+n+1, greater<int>());
		sort(b+1, b+n+1);
		bool flag = 0;
		for (int i = 1; i <= n; i++)
		{
			if (hpb == INF && hpb > 0 || hpa == -1 && hpb > 0)
			{
				flag = 0; break;
			}
			hpa -= b[i];
			hpb -= a[i];
			if (hpa > 0 && hpb <= 0)
			{
				flag = 1; break;
			}
			if (hpa <= 0) 
			{
				flag = 0; break;
			}
		}
		if (flag) cout << "yes\n";
		else cout <<"no\n";
	}
	return 0;
}
