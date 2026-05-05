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
int N,ans=0;
int buck[100005];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin>>N;
	for(int i=1;i<=N-1;i++){
		int i_get;cin>>i_get;buck[i_get]++;
	}
	for(int i=1;i<=N;i++){
		if(buck[i]>0)ans+=(buck[i]-1);
	}
	cout<<ans<<"\n";
	
	


	return 0;
}



