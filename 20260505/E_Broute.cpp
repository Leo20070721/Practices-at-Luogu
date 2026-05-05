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
const bool _QuickStream=false;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------

string languages[100005];

bool isBinLegal(int _N,int _I){
	int sum=0;
	while(_I>0){
		if(_I&1) sum++;
		_I>>=1;
	}
	return sum==_N;
}



int calc(int _N,int _I){
	vector<string> from,to;
	for(int i=0;i<2*_N;i++){
		if(_I&1) to.push_back(languages[i]);
		else from.push_back(languages[i]);
		_I>>=1;
	}
	
	int re=0;
	for(int i=0;i<_N;i++){
	for(int j=0;j<_N;j++){
		for(unsigned int k=0;k<min(from[i].size(),to[j].size());k++){
			if(from[i][k]==to[j][k]) continue;
			re+=k+1;break;
		}
	}}
	
	return re;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	int N;cin>>N;	
	for(int i=1;i<=2*N;i++){cin>>languages[i];}

	int ans=0;
	for(int i=0;i<=(1<<(2*N-1));i++){cout<<"i:"<<i<<"\n";
		if(!isBinLegal(N,i)) continue;
		
		ans=max(ans,calc(N,i));
	}
	
	cout<<ans<<"\n";
	return 0;
}



