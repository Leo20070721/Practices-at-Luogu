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

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		if (n == 4)
		{
			cout << "-1\n";
			continue;
		}
		else if (n == 2)
		{
			cout << "1 2\n";
			continue;
		}
		else if (n == 3)
		{
			cout << "1 2\n2 3\n";
			continue;
		}
		int d = n - 1, cnt2 = 1, l1 = n - 2, sum = (n + 1) / 2;
		//d直径 cnt2 下面独立点 
		for (int i = 1; i < n - 1; i++)
		{
			d--;
			cnt2++;
			l1--;
			sum = cnt2 + (l1 + 1) / 2;
			if (sum == d)
			{
				cout << n - 1 <<' ' << n <<endl;
				for (int i = 1; i < cnt2; i++)
				{
					cout << n - 1 <<' ' << i << endl;
				}
				for (int i = cnt2; i + 1 <= n - 1; i++)
				{
					cout << i <<' ' << i + 1 << endl;
				}
				break;
			}
			else if (sum > d)
			{
				cout << cnt2 - 1 <<' ' << n - 2 << endl;
				cout << n - 1 <<' ' << n << endl;
				for (int i = 1; i < cnt2-1; i++)
				{
					cout << n - 1 <<' ' << i << endl;
				}
				for (int i = cnt2; i + 1 <= n - 1; i++)
				{
					cout << i <<' ' << i+1 << endl;
				}
				break;
			}
		}
	}
	return 0;
}



