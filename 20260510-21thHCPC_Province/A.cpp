#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define lld long long
#define ulld unsigned long long
#define Ld long double

const bool _QuickStream=false;
inline void _QuickStreamOpen(){
	if(!_QuickStream) return;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int N,M;

vector <int> amap[3005];
struct _people{
	int id,op,t;
	bool hp;
	vector<int> path;
}people[3005];

struct _node{
	int dep,fa;
	vector<_people> persons[4];
}node[3005];

bool check(int u, int T) {
	if (T % people[u].t == 0)
		return 1;
	return 0;
}
void DFS(int pos,int fa){
	node[pos].dep=node[fa].dep+1;
	node[pos].fa=fa;
	
	for(unsigned int i=0;i<amap[pos].size();i++){
		if(amap[pos][i] == fa) continue;
		DFS(amap[pos][i],pos);
	}
}

void LCA_path(int id,int s,int t){
	stack<int> path_back;
	if(node[s].dep<node[t].dep){
		for(int i=1;i<=node[t].dep-node[s].dep;i++){
			people[id].path.push_back(s);
			s=node[s].fa; 
		}
	}else if(node[s].dep>node[t].dep){
		for(int i=1;i<=node[s].dep-node[t].dep;i++){
			path_back.push(t);
			t=node[t].fa; 
		}
	}
	
	while(s!=t){
		people[id].path.push_back(s);
		path_back.push(t);
		s=node[s].fa; 
		t=node[t].fa; 
	}
	people[id].path.push_back(s);
	while(!	path_back.empty()){
		people[id].path.push_back(path_back.top());
		path_back.pop();
	}
	
	return;
}


signed main()
{
    _QuickStreamOpen();
    
    cin>>N>>M;
    for(int i=1;i<N;i++){
    	int x,y;cin>>x>>y;
    	amap[x].push_back(y); 
    	amap[y].push_back(x);
	}
	
	DFS(1,0);
	
	for(int i=1;i<=M;i++){
		int s,t;
    	cin>>people[i].op>>people[i].t>>s>>t;
    	LCA_path(i,s,t);
	}
	int T = 0;
	std::queue<int> q;
	std::vector<int> winner;
	for (int i = 1; i<=n; i++)
		q.push(i);
	while (!q.empty()) {
		T++;
		std::vector<int> Q;
		std::vector<int> vis (3005, 0);
		while (!q.empty()) {
			int u = q.top();
			q.pop();
			if (T >= (int)people[u].path.size() - 1) {
				winner.push_back(u);
				continue;
			}
			int pos = people[u].path[T];
			if (!vis[pos])
				Q.push_back(pos);
			vis[pos] = 1;
			node[pos].persons[people[u].op].push_back(u);
		}
		for (int i = 0; i < Q.size(); i++) {
			int u = Q[i];
			int cnt = 0;
			for (int j = 0; j < node[u].persons[3].size(); j++) {
				int v = node[u].persons[3][j];
				if (check(v,  T)) {
					for(int _k=1;_k<=2;_k++){
						for (int k = 0; k < node[u].persons[_k].size(); k++) 
						people[node[u].persons[_k][k]].hp = 0;
					}
					cnt++;						 
				}
				if (cnt == 2)
					break; 
			}
			for (int j = 0; j < node[u].persons[1].size(); j++) {
				int v = node[u].persons[1][j];
				if (check(v,  T)) {
					for(int _k=0;_k<=0;_k++){
						for (int k = 0; k < node[u].persons[_k].size(); k++) 
						people[node[u].persons[_k][k]].hp = 0;
					}		
					break; 			 
				}	
			}for (int j = 0; j < node[u].persons[2].size(); j++) {
				int v = node[u].persons[2][j];
				if (check(v,  T)) {
					for(int _k=1;_k<=1;_k++){
						for (int k = 0; k < node[u].persons[_k].size(); k++) 
						people[node[u].persons[_k][k]].hp = 0;
					}		
					break; 			 
				}	
			}
			for (int j = 0; j < node[u].persons[0].size(); j++) {
				int v = node[u].persons[0][j];
				if ()
			}
		}
	}

    return 0;
}
