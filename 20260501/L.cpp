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
int maxA=1e9;
int N,M;
const int MAXN = 1e5 +5;
int a[100005],b[100005];
vector <int>start;

int in[100005];
vector<int > e[MAXN];
bool vis[100005];
queue<int> q;
void top_sort()
{
	for (int i = 1; i <= N; i++)
	{
		if (in[i] == 0) q.push(i);
	}
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for (auto v:e[u])
		{
			in[v]--;
			if (in[v] == 0)
			{
				q.push(v);
			}
		}
	}
	for (int i = 1; i <= N; i++) if (in[i] > 0) vis[i] = 1;
}

bool DFS(int pos,int sum,int nowA){
	if(vis[pos]){//在环上 
		if(sum>b[pos]) return false;
		for(auto v:e[pos]){
			if(vis[v]) continue;
			return DFS(v,sum,nowA);
		}
	}else{//不在环上 
		if(nowA>=a[pos]) sum+=a[pos];
		if(sum>b[pos]) return false;
		for(auto v:e[pos]){
			return DFS(v,sum,nowA);
		}
	}
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
		in[v]++;
	}
	
	for(int i=1;i<=N;i++){
		if(in[i]==0) start.push_back(i);
	}
	
	top_sort();
	for(int i=1;i<=N;i++){
		if(vis[i]){ 
			maxA=min(maxA,a[i])	;
		}
	} 
	maxA--;
	
	int l=0,r=maxA;
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



