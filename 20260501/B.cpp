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
char sta[MAXN];
int top;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		sta[++top] = s[i];
		while(top >= 3 && sta[top] == sta[top - 1] && sta[top - 1] == sta[top - 2])
		{
			top -= 3;
		}
		//if (i == 6) cout << sta[top] << ' ' << sta[top - 1] << ' ' << sta[top - 2] << endl;
	}
	if (!top) cout << "NAN\n";
	else for (int i = 1; i <= top; i++) cout << sta[i];
	return 0;
}



