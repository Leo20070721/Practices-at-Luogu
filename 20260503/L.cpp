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
	int t;
	std::cin >> t;
	while (t--) {
		double x0, y0, x1, y1, x2, y2;
		std::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
		int h = x1, m = y1;
		double angle = 1e9;
		int H = 0, M = 0;
		while (1) {
			double temp = fabs(h - x0) / 12.0 + fabs(h - x0) / 60.0;
			if (temp < angle) {
				H = h;
				M = m;
				angle = temp;
			}
			if (h == x2 && m == y2)
				break;
			m++;
			if (m == 60)
				m = 0, h++;
		}
		std::cout << (int)H <<' ' <<(int)M <<'\n';
	} 


	return 0;
}
/*
2
1 0 2 10 2 40
2 30 8 30 9 40


*/


