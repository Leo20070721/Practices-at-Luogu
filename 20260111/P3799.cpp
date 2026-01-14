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
lli ans,buck[5005];
int n,bmax; 
const lli MOD = 1e9+7;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	
	cin>>n;
	for(int i=1;i<=n;i++){
		int iget;cin>>iget;
		buck[iget]++;
		bmax=max(bmax,iget);
	}
	
	for(int i=1;i<=bmax;i++){
		if(buck[i]<2) continue;
		lli temp=buck[i]*(buck[i]-1)/2;
		for(int j=1;j*2<i;j++){
			if(!buck[j] || !buck[i-j]) continue;
			ans=(ans+((((temp*buck[j])%MOD)*buck[i-j])%MOD))%MOD;
		}
		if(i%2==0 && buck[i/2]>1){
			ans=(ans+((temp*((buck[i/2]*(buck[i/2]-1)/2)%MOD))%MOD))%MOD;
		}
	}
	
	cout<<(ans%MOD)<<"\n";
	

	return 0;
}


