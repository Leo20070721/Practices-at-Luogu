#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
vector<int> e[MAXN];
int main()
{
	srand(time(0));
	int n = rand() % 10 + 1, m = rand() % 10 + 1;
	cout << n << ' ' << m << endl;
	for (int i = 2; i <= n; i++)
	{
		int j = rand() % (i - 1) + 1;
		cout << i <<' ' << j << endl;
		e[i].push_back(j);
		e[j].push_back(i);
	}
	int now = 1;
	for (int i = 1; i <= m; i++)
	{
		int l = rand() % 2 + 1, r = rand() % n + 1;
		if (l == 1)cout << l <<' ' << r << endl;
		
		if (l == 2)
		{
			int v = rand() % e[now].size();
			v = e[now][v];
			cout << l << ' ' << v <<"\n";
			now = v;
		 } 
		
	}
	return 0;
}
