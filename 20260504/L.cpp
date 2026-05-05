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
vector<int> pos;
int op1;
lli ans=1;
const lli MOD = 998244353;

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	string s_get;cin>>s_get;
	bool flag=true;
	for(int i=1;i<s_get.size();i++){
		bool now=(s_get[i]=='('?true:false);
		if(flag ^ now){
			if(flag) op1++;
			flag=now;
		}
		else if(!flag && !now){
			pos.push_back(op1);
		}	
	}
	//cout<<"op1:"<<op1<<" op2:"<<pos.size()<<"\n";
	
	for(int i=pos.size()-1;i>=0;i--){
		ans *= op1-pos[i]+pos.size()-i;
		ans %= MOD;
	}
	
	cout<<ans<<"\n";

	return 0;
}



