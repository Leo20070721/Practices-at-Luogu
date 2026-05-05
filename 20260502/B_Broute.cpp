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
const bool _QuickStream=true;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------
int N,Q;
bool mem[1000005];

int check(int l,int r){
	int temp[2]={0,0};
	int ans=0;
	for(int i=l;i<=r;i++){
		if(temp[0]==0 && temp[1]==0){
			temp[mem[i]]++;
		}else{
			if(temp[mem[i]]==0 && temp[!mem[i]]!=0){
				temp[!mem[i]]--;
				bool flag=mem[i];i++;
				while(flag!=mem[i]){
					flag=mem[i];i++;
				}i--;
				
				if(temp[!mem[i]]==0) temp[mem[i]]++;
				else ans++;
			}else{
				temp[mem[i]]++;
			}
		}
		//cout<<mem[i]<<":"<<temp[0]<<" "<<temp[1]<<" "<<ans<<"\n";
	} 	
	ans+=temp[0]+temp[1];
	return ans;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin>>N>>Q;
	for(int i=1;i<=N;i++){
		char c_get;cin>>c_get;
		mem[i]=(c_get=='1');
	}
	while(Q--){
		char op;int l,r;
		cin>>op>>l>>r;
		if(op == 'Q'){
			cout<<check(l,r)<<"\n";
		}else{
			for(int i=l;i<=r;i++) mem[i]=!mem[i];
		}
	}


	return 0;
}



