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
const lli MAXans = 2000;
int Q;
lli x0,x1,x2,y0,y1,y2,ans;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin>>Q;
	
	while(Q--){
		ans=INT_MAX;
		cin>>x0>>x1>>x2>>y0>>y1>>y2;
		for(lli t0=0;t0<=MAXans;t0++){
		for(lli t1=0;t1<=MAXans;t1++){
		for(lli t2=0;t2<=MAXans;t2++){
		if(t0+t1+t2>ans) continue;
		if((x0+t1+t2)%y0==0 && (x1+t0+t2)%y1==0 && (x2+t1+t0)%y2==0)
			ans=min(ans,t0+t1+t2);
			break;
		}}}
		
		if(ans==INT_MAX)cout<<"-1\n";
		else cout<<ans<<"\n";
	}
	
	


	return 0;
}



