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
int teamNum=1,ufoNum=1;
string teamName,ufoName;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	cin>>teamName>>ufoName;
	
	for(int i=0;i<teamName.length();i++){
		teamNum=(teamNum*(teamName[i]-'A'+1))%47;
	}
	for(int i=0;i<ufoName.length();i++){
		ufoNum=(ufoNum*(ufoName[i]-'A'+1))%47;
	}
	
	if(teamNum == ufoNum) cout<<"GO\n";
	else cout<<"STAY\n";	

	return 0;
}


