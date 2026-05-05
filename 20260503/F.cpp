#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define int long double
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
	int t;
	std::cin >> t;
	while (t--) {
		int x0, y0, x1, y1, x2, y2;
		std::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
		int h = x1, m = y1;
				break;
			m++;
			if (m == 60)
				m = 0, h++;
			if (h == 12)
		int angle = 1e9;
		int H = 0, M = 0;
		while (1) {
			int h0 = x0 * 30 + y0 * 0.5;
			int m; 
			if (temp < angle) {
				H = h;
				M = m;
				angle = temp;
			}
			if (h == x2 && m == y2)
				h = 0; 
		}
		std::cout << H <<' ' << M <<'\n';
	} 


	return 0;
}
/*
2
1 0 2 10 2 40
2 30 8 30 9 40


*/

