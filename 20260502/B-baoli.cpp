#include <bits/stdc++.h>
using namespace std;
#define lli long long
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
const int MAXN = 1e6 + 6;
char s[1000005];
char sta[1000005];
int top;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= q; i++)
	{
		char op;int l, r;
		cin >> op >>l >>r;
		if (op == 'M')
		{
			for (int i = l; i <= r; i++) 
			{
				if (s[i] == '1') s[i] = '0';
				else s[i] = '1';
			}
		}
		else
		{
			top = 0;
			long long ans = 0;
			for (int i = l; i <= r; i++)
			{
				if (!top || sta[top] == s[i]) sta[++top] = s[i];
				else
				{
					top--;
					if (top == 0) sta[++top] = s[i];
				}
				ans = max(ans, top * 1ll);
			}
			cout << ans <<"\n";
		}
	}
	return 0;
}




