#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
#define int long long
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
int p=0, x=0, k=0, ans=0;
vector<int> fk,fp,fpn;
unordered_map<int, bool> fkmap;

inline bool defend(int a,int b){
	int _temp=a*b;
	return ((_temp/a)!=b)||(_temp<0);
}

inline void kDFS(int now,int kpos){
	if(kpos==fk.size()) {
//		cout<<"new ans:"<<now<<"\n";
		ans++;
		return;
	}
//	cout<<"kDFS:"<<now<<" "<<kpos<<"\n";
	int times=1;
	
	for(int i=0;now*times<=x;i++){
		if(defend(now,times)) break;	
		kDFS(now*times,kpos+1);
		times*=fk[kpos];
	}
	return;
}

inline void pDFS(int now,int ppos){	
	if(ppos==fp.size()){
		kDFS(now,0);
		return;
	}
//	cout<<"pDFS:"<<now<<" "<<ppos<<"\n";
	int times=1;
	for(int i=0;now*times<=x && i<=fpn[ppos];i++){
		if(defend(now,times)) break;
		pDFS(now*times,ppos+1);
		times*=fp[ppos];		
	}
	return;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	std::cin >> p >> x >> k;
	{//pre
		int K=k;
		for (int i = 2; i * i <= k; i++) {
			if (K % i == 0) {
				fk.push_back(i);
				fkmap[i]=true;
				while (K % i == 0){
					K /= i;
				}					
			}
		}
		if(K!=1){
			fk.push_back(K);
			fkmap[K]=true;
		}
		
		int P=p;
		for (int i = 2; i * i <= p; i++) {
			if (P % i == 0) {
				int sum=0;
				while (P % i == 0){
					P /= i;
					sum++;
				}		
				if(!fkmap[i]){
					fp.push_back(i);
					fpn.push_back(sum);
				}			
			}
		}
		if(P!=1 && !fkmap[P]){
			fp.push_back(P);
			fpn.push_back(1);
		}
	}
	
//	cout<<"fk:"; 
//	for(int i=0;i<fk.size();i++){
//		cout<<fk[i]<<" ";
//	}cout<<"\n";
//	cout<<"fp:"; 
//	for(int i=0;i<fp.size();i++){
//		cout<<fp[i]<<"-"<<fpn[i]<<"  ";
//	}cout<<"\n";
	pDFS(1,0);
	
	cout<<ans<<"\n";

	return 0;
}
/*
1000000000000 1000000000000 1000000000000
*/


