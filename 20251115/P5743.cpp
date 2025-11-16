#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
const bool _QuickStream=true;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------
int N,ans=1;
void addDay(){
	ans=(ans+1)*2;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	
	cin>>N;
	for(int i=1;i<N;i++) addDay();
	cout<<ans<<"\n";

	return 0;
}


