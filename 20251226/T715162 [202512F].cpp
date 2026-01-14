#include <bits/stdc++.h>
using namespace std;
#define lli long long
//#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
const bool _QuickStream=false;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------
const int MAXN = 500000;
const int turn=130;
int M,N;
int nxt[MAXN],head[MAXN],to[MAXN],val[MAXN],cnt=-1;
void add(int u, int v,int c) {
  nxt[++cnt] = head[u]; 
  head[u] = cnt;         
  to[cnt] = v;           
  val[cnt] = c;
}
/*
}*/

struct node {
  int dis,point;
  bool operator> (const node& _a) const {return dis > _a.dis;}
};

priority_queue< node, vector<node>, greater<node> > Q;
int dis[2005];bool vis[2005];
int dijkstra(int begin){
	node x;
	for(int i=0;i<2005;i++){
		dis[i]=INT_MAX;
		vis[i]=false;
	}
	
	dis[begin]=0;
	x.dis=0;x.point=0;
	Q.push(x);
	while(!Q.empty()){
		node f;f=Q.top();Q.pop();
		if(vis[f.point]) continue;
		vis[f.point] =true;
		cout<<"from:"<<f.point<<"  dis:"<<dis[f.point]<<"\n";
		
		for (int i = head[f.point]; ~i; i = nxt[i]) {
  			if(dis[to[i]] > dis[f.point]+val[i]){
  				dis[to[i]] = dis[f.point]+val[i];
  				x.dis=dis[to[i]];x.point=to[i];
				Q.push(x);
				cout<<"to:"<<to[i]<<" dis:"<<dis[to[i]]<<"\n";
			}
		}
		cout<<"--------------\n";
	}
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	for(int i=0;i<MAXN;i++) head[i]=-1;
	
	cin>>M>>N;
	
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			for(int k=1;k<=N;k++){
				int _g;cin>>_g;
				if(_g == -1) continue;
				add(j*11+i, k*11+i+1+turn, _g);
				add(j*11+i+turn, k*11+i+1+2*turn, _g);
			}
		}
	}
	
	for(int i=1;i<=N;i++){
		int _g;cin>>_g;
		add(0, i*11, _g);
	}
	for(int i=1;i<=N;i++){
		int _g;cin>>_g;
		add(i*11+M+2*turn, 1, _g);
	}

	for(int i=1;i<=N;i++){
		for(int j=0;j<M;j++){
			add(i*11+j, i*11+j+1, 0);
			add(i*11+j+turn, i*11+j+1+turn, 0);
			add(i*11+j+2*turn, i*11+j+1+2*turn, 0);
		}		
	}
	
	dijkstra(0);
	cout<<dis[1]<<"\n";

	return 0;
}


