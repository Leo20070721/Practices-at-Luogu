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
int N,ans,sum;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	cin>>N;
	while(N--){
		int x,y;
		cin>>x>>y;
		if(x>=500 && y<500){
			ans++;sum+=y;
		}
	}
	
	cout<<ans<<" "<<sum<<"\n";

	return 0;
}


