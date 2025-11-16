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
int mem[3];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	cin>>sget;
	int slen=sget.length();
	for(int i=0;i<slen;i++){
		if('a'<=sget[i] && sget[i]<='c'){
			int nget=0,pos=sget[i]-'a';
			i+=3;
			if('0'<=sget[i] && sget[i]<='9'){
				while(sget[i]!=';'){
					nget=nget*10+sget[i]-'0';
					i++;
				}
				mem[pos]=nget;
			}
			else{
				mem[pos]=mem[sget[i]-'a'];
			}
		}
	}
	
	for(int i=0;i<3;i++){
		cout<<mem[i]<<" ";
	}cout<<"\n";

	return 0;
}


