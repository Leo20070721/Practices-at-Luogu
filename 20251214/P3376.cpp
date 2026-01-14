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

int N,M,S,T;
lli ans = 0;
int dep[205], cur[10005];
//--------------
struct edge {
    int v, nxt, cap, flow;
} e[10005];

int nxt[10005], cnt = 0;
void init() {
	memset(nxt, -1, sizeof nxt);
	cnt = 0;
}

void addedge(int u, int v, int w) {
    e[cnt] = {v, nxt[u], w, 0};
    nxt[u] = cnt++;
    e[cnt] = {u, nxt[v], 0, 0};
    nxt[v] = cnt++;
}
//--------------
bool bfs() {
	queue<int> q;
    memset(dep, 0, sizeof(int) * (N + 1));

    dep[S] = 1;
    q.push(S);
    while (!q.empty()) {
      int u = q.front();      
      q.pop();
      for (int i = nxt[u]; ~i; i = e[i].nxt) {
        int v = e[i].v;
        if ((!dep[v]) && (e[i].cap > e[i].flow)) {
          dep[v] = dep[u] + 1;
          q.push(v);
        }
      }
    }
    return dep[T];
}

int dfs(int u, int flow) {
    if ((u == T) || (!flow)) return flow;

    int ret = 0;
    for (int& i = cur[u]; ~i; i = e[i].nxt) {
      int v = e[i].v, d;
      if ((dep[v] == dep[u] + 1) &&
          (d = dfs(v, min(flow - ret, e[i].cap - e[i].flow)))) {
        ret += d;
        e[i].flow += d;
        e[i ^ 1].flow -= d;
        if (ret == flow) return ret;
      }
    }
    return ret;
}

//------------------------------------------

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	cin>>N>>M>>S>>T;
	
	init();
	for(int i=1;i<=M;i++){
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
	}
	
	int cnt=0;
    while (bfs()) {
      memcpy(cur, nxt, sizeof(int) * 2 * (N + 1));
      ans += dfs(S, INT_MAX);
    }
    
    cout<<ans<<"\n";

	return 0;
}


