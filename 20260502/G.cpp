#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define maxn 100010
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
const bool _QuickStream=false;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------
struct node{
	int x, y;
}a[maxn];
bool cmp1(node a, node b) {
	if (a.x == b.x)
		return a.y < b.y;
	return a.x > b.x;
}
bool cmp2(node a, node b) {
	if (a.y == b.y)
		return a.x < b.x;
	return a.y > b.y;
}
long double sx[maxn], sy[maxn]; 
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	int n;
	std::cin >> n;
	long double ans = 0;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i].x >> a[i].y;
	std::sort(a + 1, a + n + 1, cmp1);
	for (int i = 1; i <= n; i++) {
		sx[i] = sx[i - 1] + a[i].x;
		sy[i] = sy[i - 1] + a[i].y;
	}
	for (int i = 1; i <= n - 1; i++) {
		long double xa = (sx[i] / i), ya = (sy[i] / i);
		long double xb = (sx[n] - sx[i]) / (n - i), yb = (sy[n] - sy[i]) / (n - i);
		ans = std::max(ans, std::fabs(xa * yb - xb * ya) / 2);
	}
	std::sort(a + 1, a + n + 1, cmp2);
	for (int i = 1; i <= n; i++) {
		sx[i] = sx[i - 1] + a[i].x;
		sy[i] = sy[i - 1] + a[i].y;
	}
	for (int i = 1; i <= n - 1; i++) {
		long double xa = (sx[i] / i), ya = (sy[i] / i);
		long double xb = (sx[n] - sx[i]) / (n - i), yb = (sy[n] - sy[i]) / (n - i);
		ans = std::max(ans, std::fabs(xa * yb - xb * ya) / 2);
	}
	printf("%.12Lf\n", ans);
	return 0;
}



