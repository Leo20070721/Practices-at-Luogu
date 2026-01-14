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
int N,M,ans=0;
int Fin[100005],week[100005],now[100005];
bitset <100005> addpos[100005];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		cin>>Fin[i];
		
	}
	for(int i=1;i<=M;i++){
		int c,pos=0,now=0;cin>>c;
		for(int j=1;j<=c;j++){
			cin>>pos;
			week[pos]++;
			while(now<pos) addpos[i][++now]=false;
			addpos[i][++now]=true;
		}
		while(now<N) addpos[i][++now]=false;
	}
	
	for(int i=1;i<=N;i++){
		ans=max(ans,int(ceil( double( Fin[i])/double(week[i]) )*M));
	}
	for(int i=1;i<=N;i++){
		now[i]=ans*week[i];
	}
	
	bool flag=false;
	for(int i=1;i<=M;i++){
		ans--;
		for(int j=1;j<=N;j++){
			if(addpos[i][j]) now[i]--;
		}
		for(int j=1;j<=N;j++){
			if(now[i]<Fin[i]){
				flag=true;
				break;
			}
		}
		
		if(flag) break;
	}
	
	ans++;
	cout<<ans<<"\n";

	return 0;
}


