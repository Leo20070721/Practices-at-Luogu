#include <bits/stdc++.h>
const long long MAXN = 1e6 + 6;
using namespace std;
int a[MAXN];
bool vis[MAXN];
int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		for (int i = 1; i <= n; i++) a[i] = 0, vis[i] = 0;
		int tmp = n / 3;
		int now = 3;
		a[1] = 1;
		vis[1] = 1;
		for (int i = 1; i <= tmp; i++)
		{
			a[i*3] = now;
			if (i * 3 + 1 <= n) a[i*3+1] = now - 1, vis[now-1] = 1;
			vis[now] = 1;
			now += 2;
			if (now > n - 2) now = n - 2;
		}
		int l = 1; 
		a[3*tmp-1] = n; vis[n] = vis[n-1] = 1;
		a[2] = n-1;
		for (int i = 4; i <= n; i++)
		{
			if (a[i] == 0) 
			{
				while(vis[l]) l++;
				a[i] = l; vis[l] = 1;
			}
		}
		//cout << ":" << vis[6] << endl;
		for (int i = 1; i <= n; i++) std::cout << a[i] << ' ';
		std::cout << "\n";
	}
	return 0;
}

