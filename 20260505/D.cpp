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
int N; 

bool isSquare(int q){
	int _q=sqrt(q);
	return _q*_q==q;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin>>N;
	
	int n=N,sum=0;
	while(n>0){
		sum+=(n%10);n/=10;
	}
	
	if(isSquare(N) && isSquare(sum)) cout<<"Yes\n";
	else cout<<"No\n"; 

	return 0;
}



