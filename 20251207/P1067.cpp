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
int N;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	cin>>N;
	for(int i=N;i>=0;i--){
		int nget;cin>>nget;
		if(nget>0 && i!=N){cout<<"+";}
		
		if(nget!=0){
			if(i==0)cout<<nget; 
			else if(nget!=-1 && nget!=1)cout<<nget;
			else if(nget==-1)cout<<"-";
			if(i>1){cout<<"x^"<<i;}
			else if(i==1){cout<<"x";}
		}
	}

	return 0;
}


