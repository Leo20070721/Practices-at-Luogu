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
string sget;
int ansb,ansg;

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	cin>>sget;
	int N=sget.length();
	for(int i=0;i<N;i++){
		if(sget[i]=='b' || sget[i+1]=='o' || sget[i+2]=='y') ansb++;
		if(sget[i]=='g' || sget[i+1]=='i' || sget[i+2]=='r' || sget[i+3]=='l') ansg++;
	}
	
	cout<<ansb<<"\n"<<ansg<<"\n";

	return 0;
}


