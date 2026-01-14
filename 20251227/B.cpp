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
const int MAXN=205;
int N;string S;
int ans,mid[MAXN];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	cin>>N>>S;
	
	int cnt=0;
	for(int i=N-1;i>=0;i--){
		if(S[i]=='t') cnt++;
		if(S[i]=='i') mid[i]=cnt;
	}
	cnt=0;
	for(int i=N-1;i>=0;i--){
		if(S[i]=='i') cnt+=mid[i];
		if(S[i]=='h') ans+=cnt;
	}
	
	cout<<ans<<"\n";

	return 0;
}


