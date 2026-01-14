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
int A,B,C,ans;

bool chk(int x){
	if(30<=x && x<=70) return true;
	return false;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	cin>>A>>B>>C;
	if(chk(A)){
		ans=A;
	}
	else{
		if(chk(B)||chk(C)){
			if(chk(B)&&chk(C)) ans=min(B,C);
			else ans=(chk(B)?B:C);
		}
		else{
			ans=0;
		}
	}
	
	cout<<ans<<"\n";

	return 0;
}


