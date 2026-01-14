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
int A,B,C,T,ans;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	cin>>T;
	while(T--){
		cin>>A>>B>>C;ans=0;
		
		for(int i=A;i>=1;i--){
			if(A%i==0){
				if(C-A/i < B) break;
				if((C-A/i)%B==0){
					ans++;
				}
			}
		}
		
		cout<<ans<<"\n";
	}

	return 0;
}


