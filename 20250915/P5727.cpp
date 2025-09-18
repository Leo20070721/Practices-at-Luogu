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
int n; 

void bingbao(int a){
	if(a==1){
		cout<<"1 ";
		return;
	}
	else if(a%2==1){
		bingbao(a*3+1);
		cout<<a<<" ";
		return;	
	}
	else{
		bingbao(a/2);
		cout<<a<<" ";
		return;
	}
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	
	cin>>n;
	bingbao(n);
	cout<<endl;
	
	return 0;
}


