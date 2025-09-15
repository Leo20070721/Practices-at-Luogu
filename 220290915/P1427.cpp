#include <bits/stdc++.h>
using namespace std;
#define lli long long
//#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
const bool _QuickStream=true;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------
signed a[105],n;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}

	do{
		n++;
		cin>>a[n];
	}while(a[n]!=0);
	
	
	while(n>1){
		n--;
		cout<<a[n]<<" ";
	}cout<<endl;

	return 0;
}


