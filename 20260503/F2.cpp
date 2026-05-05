#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
#define int long long
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
int turn(int x1, int y1, int x2, int y2)
{
	return min(abs(x2 - x1), 12 - abs(x2 - x1)) * 30 + min(abs(y2 - y1), 60 - abs(y2-y1)) * 6;
}
int cal(int x, int y)
{
	return x * 60 + y;
}
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	int T;
	cin >> T;
	while(T--)
	{
		int x0, x1, x2, y0, y1, y2;
		cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2; 
		int ansx = -1, ansy = -1;
		for (int i = 0; i <= 11; i++)
		{
			for (int j = 0; j <= 59; j++)
			{
				if (cal(x1, y1) <= cal(i, j) && cal(i, j) <= cal(x2, y2))
				{
					if (ansx == -1 && ansy == -1)
					{
						ansx = i, ansy = j;
					}
					else if (turn(x0, y0, ansx, ansy) > turn(x0, y0, i, j))
					{
						ansx = i, ansy = j;
					}
					else if (turn(x0, y0, ansx, ansy) == turn(x0, y0, i, j) && cal(ansx, ansy) > cal(i, j))
					{
						ansx = i, ansy = j;
					}
				}
			}
		}
		cout << ansx <<' ' << ansy << "\n";
	}
	return 0;
}
/*
2
1 0 2 10 2 40
2 30 8 30 9 40


*/ 


