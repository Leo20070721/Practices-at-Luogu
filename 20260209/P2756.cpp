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

struct Map{
	static const int MAXN=105,MAXL=10005;
	int head[MAXN],nxt[MAXL],to[MAXL],val[MAXL],cnt;
	
	Map(){		
		this->cnt=-1;
		memset(this->head,-1,MAXN);
		memset(this->nxt,0,MAXL);
		memset(this->to,0,MAXL);
		memset(this->val,0,MAXL);
	}
	
	void addEdge(int from,int to,int val){
		this->nxt[++this->cnt]=this->head[from];
		this->to[cnt]=to;
		this->val[cnt]=val;
		this->head[from]=cnt;
	}
};
struct EK{
	int N,M;
	Map amap;	
	
	void init(){
		cin>>M>>N;
		while(true){
			int u,v;
			cin>>u>>v;
			amap.addEdge(u,v,1);
			amap.addEdge(v,u,0);
		}
		for(int i=1;i<=M;i++){
			amap.addEdge(0,i,1);
		}
		for(int i=M+1;i<=N;i++){
			amap.addEdge(i,N+1,1);
		}
	}
	
	int solve(){
		
	}
};
 
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	
	EK solve;

	return 0;
}


