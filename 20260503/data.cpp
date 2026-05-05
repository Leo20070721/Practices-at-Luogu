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
int cal(int x, int y)
{
	return x * 60 + y;
}
signed main(){
	srand(time(0));
	int T = rand() % 10 + 1;
	cout << T << endl;
	while(T--)
	{
		pair<int, int> a = {rand() % 12, rand() % 60}, b = {rand() % 12, rand() % 60}, c = {rand() % 12, rand() % 60};
//		if (cal(b.first, b.second) > cal(c.first, c.second))
//		{
//			swap(b, c);
//		}
		cout << a.first << ' ' << a.second <<' ' << b.first << ' ' <<b.second <<' ' << c.first <<' ' << c.second << endl;
	}
	return 0;
}



