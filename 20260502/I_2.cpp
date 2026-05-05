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
Ld f[5005][5005];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	int n, m;
	cin >> n >> m;
	int k=n/m,l=n%m;
	int a=m-l,b=l;
	
	f[a][b]=0;
	for(int i=a;i>=0;i--){
	for(int j=b;j>=0;j--){
		if(i==a&&j==b) continue;
		
		f[i][j]=((a-i)*k*f[i+1][j]+(b-j)*(k+1)*f[i][j+1]+n)/(n-i*k-j*(k+1));
	}}
	
	printf("%.8Lf\n",f[0][0]);	

	return 0;
}



