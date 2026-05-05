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
const int mov[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool amap[1005][1005];
bool vis[1005][1005];

struct node{
	int x,y; 
	int step;
	
	node(int x,int y,int s){
		this->x=x;this->y=y;this->step=s;
	}
	
	const bool operator< (const node &a)const{
		if(this->step==a.step){
			if(this->x==a.x){
				return this->y<a.y;
			}
			return this->x<a.x;
		}
		return this->step<a.step;
	}
	const bool operator> (const node &a)const{
		if(this->step==a.step){
			if(this->x==a.x){
				return this->y>a.y;
			}
			return this->x>a.x;
		}
		return this->step>a.step;
	}
};

bool isNodeLegal(node a,int N,int M){
	if(a.x<=0 || a.y<=0) return false;
	if(a.x>N  || a.y>M ) return false;
	return true;
}

bool check(int K,int N,int M){
	memset(vis,0,sizeof(vis));
	priority_queue<node, vector<node>, greater<node> > Q;
	Q.push(node(1,1,0));
	while(!Q.empty()){
		node now=Q.top();Q.pop();
		if(!isNodeLegal(now,N,M)) continue;
		if(vis[now.x][now.y]) continue;
		vis[now.x][now.y]=true;
		
		//cout<<"BFS:"<<now.x<<","<<now.y<<":"<<now.step<<"\n";
		if(now.x==N && now.y==M) return true;
		
		
		if(now.step==0 && K>0){
			for(int i=0;i<4;i++){
				node nextn=node(now.x+mov[i][0],now.y+mov[i][1],0);
				if(amap[nextn.x][nextn.y]) {nextn.step=1;}
				Q.push(nextn);
			}
		}else if(now.step==K){
			for(int i=0;i<4;i++){
				node nextn=node(now.x+mov[i][0],now.y+mov[i][1],K);
				if(!amap[nextn.x][nextn.y]) Q.push(nextn);
			}
		}else{
			for(int i=0;i<4;i++){
				node nextn=node(now.x+mov[i][0],now.y+mov[i][1],now.step+1);
				Q.push(nextn);
			}
		}		
	}
	return false;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	int T,N,M;
	cin>>T;
	
	while(T--){
		cin>>N>>M;
		for(int i=1;i<=N;i++){
			string s_get;cin>>s_get;
			for(int j=1;j<=M;j++){
				amap[i][j]=(s_get[j-1]=='#'?true:false);
			}
		}
		
		int l=0,r=N+M-2,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,N,M)){
				r=mid-1;
				ans=mid;
			}else{
				l=mid+1;
			}
		}
		
		cout<<ans<<"\n";
	}



	return 0;
}

/*
2
3 4
..##
###.
.##.
3 2
..
##
..
*/
