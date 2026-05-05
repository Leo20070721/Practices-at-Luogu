#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
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
const int MAXN = 4e5 + 5;
//------------------------------------------
struct node
{
	int l, d;
	bool operator<(const node &x) const
	{
		return l < x.l;
	}
};
int tr[MAXN<<2][2];
int lzy[MAXN<<2];
// 0-p 1-cnt
set<node> st;
int a[MAXN];
int cnt[MAXN];
void push_up(int rt)
{
	if (tr[rt<<1][1] >= tr[rt<<1|1][1]) tr[rt][0] = tr[rt<<1][0], tr[rt][1] = tr[rt<<1][1];
	else tr[rt][0] = tr[rt<<1|1][0], tr[rt][1] = tr[rt<<1|1][1];
}
void push_down(int l, int r, int rt)
{
	if (lzy[rt])
	{
		tr[rt<<1][1] += lzy[rt];
		tr[rt<<1|1][1] += lzy[rt];
		lzy[rt<<1] += lzy[rt];
		lzy[rt<<1|1] += lzy[rt];
		lzy[rt] = 0;
	}
}
void build(int l, int r, int rt)
{
	if (l == r)
	{
		tr[rt][0] = l;
		tr[rt][1] = cnt[l];
		lzy[rt] = 0;
		return;
	}
	int mid = l + r >> 1;
	lzy[rt] = 0;
	build(lson);
	build(rson);
	push_up(rt);
}
void update(int L, int R, int x, int l, int r, int rt)
{
	if (L <= l && r <= R)
	{
		tr[rt][1] += x;
		lzy[rt] += x;
		return;
	}
	int mid = l + r >> 1;
	push_down(l, r, rt);
	if (mid >= L) update(L, R, x, lson);
	if (mid < R) update(L, R, x, rson);
	push_up(rt);
}
pair<int, int> query(int p, int l, int r, int rt)
{
	if (l == r)
	{
		return {tr[rt][0], tr[rt][1]};
	}
	int mid = l + r >> 1;
	push_down(l, r, rt);
	if (mid >= p) return query(p , lson);
	if (mid < p) return query(p, rson);
}
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	int T;
	cin >> T;
	while(T--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			cnt[a[i]]++;
			st.insert({i, a[i]});
		}
		build(1, 2*n, 1);
		cout << tr[1][0] << ' ' << tr[1][1] <<"\n";
		for (int i = 1; i <= m; i++)
		{
			int l, r, d;
			cin >> l >> r >> d;
			auto plr = st.lower_bound({l, 0});
			if (plr != st.begin())
			{
				auto pll = plr; pll--;
				int r1 = min(r, plr != st.end()?(*plr).l - 1:r), l1 = l;
				if (l1 <= r1)
				{
					int L = (*pll).d + l1 - (*pll).l, R = (*pll).d + r1 - (*pll).l;
					//cout << "::" << (*pll).d << ' ' << (*pll).l << ' ' << l1 << ' ' << r1 << endl;
					//cout << "-:" << L << ' ' << R << endl; 
					update(L, R, -1, 1, 2*n, 1);
				}
			}
			auto prr = st.upper_bound({r, 0});
			for (plr; plr != prr; plr++)
			{
				auto prl = plr; 
				prl++;
				int R;
				if (prl == st.end() || (*prl).l > r)
				{
					R = r;
				 } 
				else R = (*prl).l-1;
				int L = (*plr).d;
				R = (*plr).d + R - (*plr).l;
				//cout << ":" << L << ' ' << R << ' ' << (*plr).d << ' ' << (*plr).l << endl;
				//cout << "-:" << L << ' ' << R << endl; 
				update(L, R, -1, 1, 2*n, 1); 
			}
			auto tmp = st.lower_bound({l, 0});
			if (!(tmp != st.end() && (*tmp).l >= l && (*tmp).l <= r))
			{
				auto lst = tmp; lst--;
				int D = (*lst).d, L = (*lst).l;
				if (r != n)
				{
					auto nxt = st.lower_bound({r+1, 0});
					if ((*nxt).l != r+1)
					{
						st.insert({r+1, D - L + r+1}); 
						//cout << "In:" << r+1 << ' ' << D - L +r+1 << endl;
					}
				}
			}
			while(tmp != st.end() && (*tmp).l >= l && (*tmp).l <= r)
			{
				auto lst = tmp; lst++;
				if (lst == st.end() || (*lst).l > r)
				{
					int D = (*tmp).d, L = (*tmp).l;
					//cout << "P:" << L << ' ' << D << endl;
					st.erase(tmp);
					if (r != n)
					{
						auto nxt = st.lower_bound({r+1, 0});
						if ((*nxt).l != r+1)
						{
							st.insert({r+1, D - L + r+1}); 
							//cout << "In:" << r+1 << ' ' << D - L +r+1 << endl;
						}
					 } 
					break;
				}
				//cout << "P:" << (*tmp).l << ' ' << (*tmp).d << endl;
				st.erase(tmp);
				tmp = st.lower_bound({l, 0});
			}
			st.insert({l, d});
			//cout << "+:" << d << ' ' << d + r - l << endl;
			update(d, d + r - l, 1, 1, 2*n, 1);
			//cout << "7:" << query(7, 1, n, 1).first << ' ' << query(7, 1, n, 1).second << endl;
			cout << tr[1][0] <<' ' << tr[1][1] << "\n";
		}
		for (int i = 1; i <= 2*n; i++) cnt[i] = 0;
		st.clear();
	}
	return 0;
}
/*
1
5 6
1 3 4 3 2 
1 5 1
2 2 5
3 4 5
4 4 4
2 3 4
1 2 3
*/


