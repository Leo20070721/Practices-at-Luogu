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
const int MAXN = 2e5 +5;
int st[MAXN][21];
int lg[MAXN];
int a[MAXN];
int n;
void init()
{
	int log2n = log2(n);
	for (int i = 1; i <= n; i++) st[i][0] = a[i];
	for (int i =1 ; i <= log2n; i++)
	{
		for (int j = 1; j + (1 << i) - 1 <= n; j++)
		{
			st[j][i] = min(st[j][i-1], st[j + (1 << (i - 1))][i-1]);
		}
	}
	lg[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		lg[i] = lg[i/2] + 1;
	}
}
int query(int l, int r)
{
	int j = lg[(r - l + 1)];
	int i = r - (1 << j) + 1;
	return min(st[l][j], st[i][j]);
}
struct invert
{
	int l, r, g;
}q[MAXN];
invert p[MAXN];
int cnt = 0;
long long ans = 0;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	init();
	for (int i = 1; i <= n; i++)
	{
		q[++cnt] = {i, i, a[i]};
		int tmp = a[i];
		for (int j = cnt; j >= 1; j--) 
		{
			tmp = __gcd(q[j].g, tmp);
			q[j].g = tmp;
		}
		p[1] = q[1];
		int tot = 1;
		for (int j = 2; j <= cnt; j++)
		{
			if (q[j].g == p[tot].g)
			{
				p[tot].r = q[j].r;
			}
			else p[++tot] = q[j];
		}
		cnt = tot;
		for (int j = 1; j <= cnt; j++) q[j] = p[j];
		for (int j = 1; j <= cnt; j++)
		{
			int l = q[j].l, r = q[j].r, g = q[j].g;
			int pl = -1 , pr = -1;
			while(l <= r)
			{
				int mid = l + r >> 1;
				int res = query(mid, i);
				if (res == g)
				{
					pr = mid;
					l = mid + 1;
				}
				else if (res < g) l = mid +1;
				else if (res > g) r = mid - 1;
			}
			l = q[j].l, r = q[j].r, g = q[j].g;
			while(l <= r)
			{
				int mid = l + r >> 1;
				int res = query(mid, i);
				if (res == g)
				{
					pl = mid;
					r = mid - 1;
				}
				else if (res < g) l = mid +1;
				else if (res > g) r = mid -1;
			}
			if (pr == pl && pl == -1)
			{
				ans += 0;
			}
			else ans += pr - pl + 1;
			//cout << i << ":" << pr <<' ' << pl << endl; 
		}
		//cout << 
	}cout << ans <<"\n";
	return 0;
}



