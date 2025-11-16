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
int N,ans=0,cnt=0;
bool flag,chg=false;
string sget;

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	cin>>N>>sget;
	if(N<=1){cout<<"0\n";return 0;}
	
	for(int i=0;i<N;i++){
		//cout<<i<<":"<<sget[i]<<" "<<flag<<" "<<ans<<" "<<chg<<"\n";
		if(i==0){
			flag=(sget[i]=='V'?true:false);
			cnt=1;
			continue;
		} 
		
		if(sget[i]=='K'){//K
			if(flag){//V -> K
				flag=false;
				ans++;
				cnt=0;
				continue;
			}
			else{//K -> K
				cnt++;
				if(cnt>2) chg=true;
				continue;
			}
		}
		else{
			if(!flag){//K -> V
				flag=true;
				if(cnt>1){
					if(i>3){
						if(sget[i-3]!='V') chg=true;
					}
					else{
						chg=true;
					}
				}
				cnt=1;
				continue;
			}
			else{//V -> V
				cnt++;
				if(cnt>2) chg=true;
				continue;
			}
		}
	}
	if(cnt>1) chg=true;
	
	if(chg) ans++;
	
	cout<<ans<<"\n";

	return 0;
}


