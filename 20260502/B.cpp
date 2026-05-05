#include <bits/stdc++.h>
using namespace std;
#define lli long long
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
//------------------------------------------
const int MAXN= 1e6 + 6;
int tr[MAXN<<2][4];
char s[MAXN];
// 0-0in 1-0out 2-1in 3-1out
bool lzy[MAXN<<2];
struct four
{
	int in0, out0, in1, out1;
};
void push_up(int rt)
{
	tr[rt][0] = tr[rt<<1][0]; tr[rt][2] = tr[rt<<1][2]; tr[rt][1] = tr[rt<<1|1][1]; tr[rt][3] = tr[rt<<1|1][3];
	if (tr[rt<<1][1] > tr[rt<<1|1][2])
	{
		tr[rt][1] += tr[rt<<1][1] - tr[rt<<1|1][2];
		tr[rt][2] += 0;
	}
	else
	{
		tr[rt][1] += 0;
		tr[rt][2] += tr[rt<<1|1][2] - tr[rt<<1][1];
	}
	if (tr[rt<<1][3] > tr[rt<<1|1][0])
	{
		tr[rt][3] += tr[rt<<1][3] - tr[rt<<1|1][0];
		tr[rt][0] += 0;
	}
	else
	{
		tr[rt][3] += 0;
		tr[rt][0] += tr[rt<<1|1][0] - tr[rt<<1][3]; 
	}
}
void push_down(int l, int r, int rt)
{
	if (lzy[rt])
	{
		swap(tr[rt<<1][0], tr[rt<<1][2]);
		swap(tr[rt<<1][1], tr[rt<<1][3]);
		swap(tr[rt<<1|1][0], tr[rt<<1|1][2]);
		swap(tr[rt<<1|1][1], tr[rt<<1|1][3]);
		lzy[rt<<1] = !lzy[rt<<1];
		lzy[rt<<1|1] = !lzy[rt<<1|1]; 
		lzy[rt] = 0;
	}
}
void build(int l, int r, int rt)
{
	if (l == r)
	{
		if (s[l] == '1')
		{
			tr[rt][2] = tr[rt][3] = 1; tr[rt][0] = tr[rt][1] = 0;
		}
		else tr[rt][2] = tr[rt][3] = 0, tr[rt][0] = tr[rt][1] = 1;
		return;
	}
	int mid = l + r >> 1;
	build(lson); build(rson);
	push_up(rt);
}
void update(int L, int R, int l, int r, int rt)
{
	if (L <= l && r <= R)
	{
		swap(tr[rt][0], tr[rt][2]);
		swap(tr[rt][1], tr[rt][3]);
		//cout << ":" << l <<' ' << r <<' ' << tr[rt][0] << ' ' << tr[rt][1] << ' ' << tr[rt][2] << ' ' << tr[rt][3] << endl;
		lzy[rt] = !lzy[rt];
		return;
	}
	int mid = l + r >> 1;
	push_down(l, r, rt);
	if (mid >= L) update(L, R, lson);
	if (mid < R) update(L, R, rson);
	push_up(rt);
}
four query(int L, int R, int l, int r, int rt)
{
	//cout << l << ' ' << r <<' ' << rt << endl;
	if (L <= l && r <= R)
	{
		return {tr[rt][0], tr[rt][1], tr[rt][2], tr[rt][3]};
	}
	int mid = l + r >>1;
	push_down(l, r, rt);
	four tmpl = {0, 0, 0, 0}, tmpr = {0, 0, 0, 0};
	if (mid >= L)tmpl = query(L, R, lson);
	if (mid < R) tmpr = query(L, R, rson);
	four res = {tmpl.in0, tmpr.out0, tmpl.in1, tmpr.out1};
	if (tmpl.out0 > tmpr.in1)
	{
		res.out0 += tmpl.out0 - tmpr.in1;
	}
	else
	{
		res.in1 += tmpr.in1 - tmpl.out0;
	}
	if (tmpl.out1 > tmpr.in0)
	{
		res.out1 += tmpl.out1 - tmpr.in0;
	}
	else
	{
		res.in0 += tmpr.in0 - tmpl.out1;
	}
	return res; 
}
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s[i];
	build(1, n, 1);
	//cout << "Done\n";
	for (int i = 1; i <= q; i++)
	{
		char op;
		cin >> op;//cout << "FJ\n";
		if (op == 'Q')
		{
			int l, r;
			cin >> l >> r;
			four res = query(l, r, 1, n, 1);
			cout << res.out0 + res.out1 << "\n";
		}
		else
		{
			int l, r;
			cin >> l >>r;
			update(l, r, 1, n, 1);
		}
	}
	
	return 0;
}



