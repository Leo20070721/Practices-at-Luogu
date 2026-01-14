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
double p[100005],x[100005],E,U,Q;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}

	cin>>N;
	for(int i=1;i<=N;i++) cin>>x[i];
	for(int i=1;i<=N;i++){
		cin>>p[i];Q+=p[i];
	} 
	
	for(int i=1;i<=N;i++){
		E+=(x[i]/Q*p[i]);
	}
	for(int i=1;i<=N;i++){
		U+=(x[i]-E)/Q*(x[i]-E)*p[i];
	}
	
	cout<<E<<"\n"<<U<<"\n";
	
	return 0;
}


