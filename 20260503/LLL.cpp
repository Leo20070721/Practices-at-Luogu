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
int mx[2005];
bool good[1005][2005];
bool goodcol[2005];
vector<int> nxt;
int mi[1005];
bool vis[1005][5005];
pair<int, int> a[300005];
int n, m, q;
void update(int col)
{
	for (int i = 1; i <= n; i++)
	{
		mi[i] = n;
	}
	int lst = -n;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i][col])
		{
			if (col % 2 == 1) good[i][col] = good[i][col+1] = 0;
			else good[i][col] = good[i][col-1] = 0;
			lst = i;
		}
		else 
		{
			if (col % 2 == 1 && !vis[i][col+1]) good[i][col] = good[i][col+1] = 1;
			else if (col % 2 == 0 && !vis[i][col-1]) good[i][col] = good[i][col-1] = 1;
		}
		mi[i] = min(mi[i], i - lst);
	}
	lst = 2*n;
	for (int i = n; i >= 1; i--)
	{
		if (vis[i][col]) lst = i;
		mi[i] = min(mi[i], lst - i);
	}
//	cout << endl;
//	if (col == 3)
//	{
//		for (int i = 1; i <= n; i++) cout << mi[i] <<' ';
//	}
//	cout << endl;
	mx[col] = 0;
	for (int i = 1; i <= n; i++) mx[col] = max(mx[col], mi[i]);
	goodcol[col] = 0;
	for (int i = 1; i <= n; i++) goodcol[col] |= good[i][col];
}
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin >> n >> m >>q;
	for (int i = 1; i <= 2*m; i++)
	{
		goodcol[i] = 1; mx[i] = n;
	}
	for (int i = 1; i <= 2*m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			good[j][i] = 1;
			
		}
	}
	for (int z = 1; z <= q; z++)
	{
		int op, x;
		cin >> op >> x;
		if (op == 1)
		{
			nxt.clear();
			nxt.push_back(1);
			for (int i = 2; i <= 2*m; i++)
			{
				if (mx[nxt[0]] == mx[i])
				{
					nxt.push_back(i);
				}
				else if (mx[nxt[0]] < mx[i])
				{
					nxt.clear();
					nxt.push_back(i);
				}
			}
			int p = nxt[0];
			for (auto i:nxt)
			{
				if (goodcol[i])
				{
					p = i;
					break;
				}
			}
			int q = 1;
			for (int i = 1; i <= n; i++)
			{
				mi[i] = n;
			}
			int lst = -n;
			for (int i = 1; i <= n; i++)
			{
				if (vis[i][p])
				{
					lst = i;
				}
				mi[i] = min(mi[i], i - lst);
			}
			lst = 2*n;
			for (int i = n; i >= 1; i--)
			{
				if (vis[i][p])
				{
					lst = i;
				}
				mi[i] = min(mi[i], lst - i);
			}
			for (int i = 1; i <= n; i++)
			{
				if (mi[q] < mi[i] || (mi[q] == mi[i] && good[i][p] && !good[q][p])) q = i;
			}
			if (vis[q][p]) cout << -1 <<' ' << -1 << "\n";
			else
			{
				vis[q][p] = 1;
				a[x] = {q, p};
				cout << p << ' ' << q << "\n";
				update(p);
				if (p % 2 == 1) update(p+1);
				else update(p - 1);
			}
		}
		if (op == 2)
		{
			vis[a[x].first][a[x].second] = 0;
			int p = a[x].second;
			update(p);
			if (p % 2 == 1) update(p+1);
			else update(p - 1);
		}
	}
	return 0;
}
/*
1 1
3
1 1
1 2
1 3
*/


