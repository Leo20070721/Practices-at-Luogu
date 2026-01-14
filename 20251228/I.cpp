#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <bitset>
#include <cstdio>
#include <queue>

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
int N;
struct node{
	public:
	int ans,val,fa,fin;
	priority_queue < int,vector<int>,greater<int> > unuse;
	vector <int> sons;
}nodes[500005];
bitset <500005> notson;
vector <int> isson;

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		//freopen(".in","r",stdin);
		//freopen(".out","w",stdout);
	}
	
	cin>>N;
	for(int i=2;i<=N;i++){
		int fa;cin>>fa;
		nodes[fa].sons.push_back(i);
		nodes[fa].fin++;
		nodes[i].fa=fa;
		notson[fa]=true;
		if(_TEST>=20){
			cout<<"nodes["<<i<<"].fa="<<fa<<"\n";
		}
	} //
	for(int i=1;i<=N;i++){
		cin>>nodes[i].val;
	}
	for(int i=1;i<=N;i++){
		if(notson[i]) continue;
		isson.push_back(i);
	}
	
	for(int _i=0;_i<isson.size();_i++){
		int now=isson[_i];
		if(_TEST>=10)cout<<"debug: now="<<now<<"\n";
		
		if(!notson[now]){//leaf,no son
			if(nodes[now].val==0){
				nodes[now].ans=1;
				nodes[nodes[now].fa].fin--;
			}else{
				nodes[now].ans=0;
				nodes[now].unuse.push(nodes[now].val);
				nodes[nodes[now].fa].fin--;
			}
			if(_TEST>=10)cout<<"nodes["<<now<<"].ans="<<nodes[now].ans<<"\n";
			
			if(nodes[nodes[now].fa].fin==0) isson.push_back(nodes[now].fa);
		}else{//not leaf,have son
			int bottom=0;
			for(int i=0;i<nodes[now].sons.size();i++){
				int t=nodes[nodes[now].sons[i]].ans;
				bottom=max(bottom,t);
			}
			if(_TEST>=8)cout<<"now:"<<now<<".bottom="<<bottom<<"\n";
			
			set <int> get_unuse;
			for(int i=0;i<nodes[now].sons.size();i++){				
				while(!nodes[nodes[now].sons[i]].unuse.empty()){
					int a;a=nodes[nodes[now].sons[i]].unuse.top();nodes[nodes[now].sons[i]].unuse.pop();
					if(a>=bottom) get_unuse.insert(a);
				}				
			}
			if(nodes[now].val>=bottom) get_unuse.insert(nodes[now].val);
						
			if(_TEST>=9) cout<<"now:"<<now<<".unuse:";
			for(auto i:get_unuse){
				if(_TEST>=9)cout<<i<<" ";
				nodes[now].unuse.push(i);
			}
			if(_TEST>=9) cout<<"\n";

			nodes[now].ans=bottom;
			while(!nodes[now].unuse.empty()){
				if(_TEST>=9)cout<<"nodes["<<now<<"].ans="<<nodes[now].ans<<"  nodes["<<now<<"].unuse.top()="<<nodes[now].unuse.top()<<"\n";
				if(nodes[now].ans!=nodes[now].unuse.top()) break;
				nodes[now].ans++;nodes[now].unuse.pop();
			}
			
			if(_TEST>=8) cout<<"nodes["<<now<<"].ans="<<nodes[now].ans<<"\n\n";
			if(now==1) break;
			nodes[nodes[now].fa].fin--;
			if(nodes[nodes[now].fa].fin==0) isson.push_back(nodes[now].fa);
		}
	}

	for(int i=1;i<=N;i++){
		cout<<nodes[i].ans<<" ";
	}cout<<"\n";

	return 0;
}

