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
const signed _TEST=0;
//------------------------------------------
signed T;

const lli MAXN=100000;
bitset <MAXN>  vis;
int prime[MAXN],cnt;
void init(){
	for(int i=2;i<MAXN;i++){
		if(!vis[i]) prime[cnt++]=i;
		for(int j=2;j<cnt && i*prime[j]<MAXN;j++){
			int t=i*prime[j];
			vis[t]=true;
			if(i%prime[j]==0) break;
		}
	}
}

int divide(lli X){
	int re=1;
	for(int i=0;i<cnt;i++){
		while(X%prime[i]==0){
			re++;
			X/=prime[i];
		}
	}
	if(X!=1) re++;
	return re;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	init();
	cin>>T;
	while(T--){
		lli A,B;cin>>A>>B;
		if(divide(A)!=divide(B)) cout<<"Yes\n";
		else cout<<"No\n";
	}


	return 0;
}

