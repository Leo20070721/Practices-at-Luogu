#include <bits/stdc++.h>
using namespace std;
#define lli long long
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
int N,M;
const int MAXN = 1e5 +5;
int a[100005],b[100005];
vector <int>start;

int in[100005];
vector<int > e[MAXN];
queue<int> q;

bool 
bool DFS(int pos,int sum,int nowA){
	
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>N>>M;
	for(int i=1;i<=N;i++) cin>>a[i];
	for(int i=1;i<=N;i++) cin>>b[i];
	
	for(int i=1;i<=M;i++){
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		in[v]++
	}
	
	for(int i=1;i<=N;i++){
		if(in[i]==0) start.push_back(i);
	}
	
	int l=0,r=1e9;
	int ans=l;
	while(l<=r){
		int mid=(l+r)>>1;
		bool flag=true;
		for(auto v:start){
			if(!DFS(v,0,mid)){
				flag=false;
				break;
			}
		}
		
		if(flag){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	
	cout<<ans<<" "<<maxA<<"\n";
	for(int i=1;i<=N;i++){
		if(vis[i])cout<<i<<" ";
	}

	return 0;
}



