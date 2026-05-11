#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define lld long long
#define ulld unsigned long long
#define Ld long double

const bool _QuickStream=false;
inline void _QuickStreamOpen(){
	if(!_QuickStream) return;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}


int calc(int x) {
	int M = 0;
	while (x) {
		M = std::max(M, x % 10);
		x /= 10; 
	}
	return M;
}
int cmp(int a) {
	int w = 0;
	while (a != 0) {
		w++;
		a /= 10;
	}
	return w;
}
int T,N,M; 
signed main()
{
    _QuickStreamOpen();
    cin>>T;
    while(T--){
    	int l,r;cin>>l>>r;
    	int M = 0;
    	for (int i = l; i <= r; i++) {
    		M = std::max(M, calc(i));
			if (M == 9)
				break; 
		}
		std::cout << M << ' ';
		if (M != 9) { 
			for (int i = l; i <= r; i++) {
				if (calc(i) == M) {
					std::cout << i << '\n';
					break;
				}
			}
			continue;
		}
		//M==9
		int wl = cmp(l), wr = cmp(r);
		if (wl == wr) {
			for (int i = l; i <= r; i++) {
				if (calc(i) == M) {
					std::cout << i << '\n';
					break;
				}
			}
			continue;
		}
		bool flag = 0;
		int X = std::pow(10, wr - 1);
		int temp = X + 9;
		while (temp >= l) {		
			if (temp <= r) {
				flag = 1;
				std::cout << temp << '\n';
				break;
			}
			X /= 10;
			if(X>1)temp = X + 9;
			else temp=9;
		}
		if (flag)
			continue;
		for (int i = l; i <= r; i++) {
			if (calc(i) == M) {
				std::cout << i << '\n';
				break;
			    }
		}
	}

    return 0;
}
