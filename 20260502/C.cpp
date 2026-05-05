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

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	int T;
	cin >> T;
	while(T--)
	{
		int x0, x1, x2, y0, y1, y2;
		cin >> x0 >> x1 >> x2 >> y0 >> y1 >> y2;
		int sumx = x0 + x1 + x2;
		if (y0 % 2 == 0 && y1 % 2 == 0 && y2 % 2 == 0 && sumx % 2 == 1)
		{
			cout << "-1\n";
			continue;
		}
		long long ans = (1ll <<60);
		for (int i = 0; i <= 2500; i++)
		{
			for (int j = 0; j <= 2500; j++)
			{
				if (y2 % 2 == 0 && (j * y1 + i * y0 + sumx) % 2 == 1) continue;
				int t1 = j * y1 - i * y0 + x0 - x1 - x2;
				int t2 = i * y0 - j * y1 + x1 - x0 - x2;
				int t3 = i * y0 + j * y1 + x2 - x0 - x1;
				int k = 0, tmp2 = 0, tmp3 = 0;
				if (t1 < 0)
				{
					k = (-t1 + (y2 - 1)) / y2;
				}if ((t1 + k * y2) % 2 == 1) k++;
				if(t2 < 0)
				{
					tmp2 = (-t2 + (y2 - 1)) / y2;
				}if ((t2 + tmp2 * y2) % 2 == 1) tmp2++;
				if (y2 % 2 == 1)
				{
					if (k % 2 == tmp2 % 2) k = max(k, tmp2);
					else continue;
				}
				else
				{
					k = max(k, tmp2);
				}
				if (t3 - k * y2 < 0) continue;
				t1 = (t1 + k * y2); t2 = (t2 + k * y2);t3 = (t3 - k * y2);
				if (t1 % 2 == 1 || t2 % 2 == 1 || t3 % 2 == 1) continue;
				t1 = t1 / 2; t2 /= 2; t3 /= 2;
				ans = min(ans, 1ll * (t1 + t2 + t3));
				//if(ans<10)
				//{
				// cout<<t1<<" "<<t2<<" "<<t3<<"\n";// && t1>=0 && t2>=0 && t3>=0
				// if (t1 < 0 || t2 < 0 || t3 < 0) return 0;
				//}
			}
		}
		if (ans < (1ll <<60)) cout << ans <<"\n";
		else cout <<"-1\n";
	}
	return 0;
}



