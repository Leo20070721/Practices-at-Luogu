#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
const bool _QuickStream=false;
const bool _FILE=false;
const signed _TEST=5;
//------------------------------------------
int N,minval=INT_MAX,val[27],mid,ans;
string S;
int wnum[27][27];
vector <int> wpos[27][27];

int mov1,mov2,bigger=INT_MAX,smaller=0,ok=INT_MAX,bpos,spos;
int dob=0,dpos1,dpos2;
int sing=0,singpos1,singpos2;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	cin>>N>>S;
	for(int i=0;i<26;i++){
		cin>>val[i];
		minval=min(minval,val[i]);	
	} 
	
	
	if(N%2==0){
		mid=(N>>1)-1; 
	} 
	else{
		mid=N>>1; 		
	} 
	
	
	//find wrong, smallest bigger  and  biggest smaller
	for(int i=0;i<=mid;i++){
		int a=S[i]-'a',b=S[N-i-1]-'a';
		if(_TEST>=5)cout<<val[a]<<" "<<val[b]<<"\n";
		if(a==b){
			ok=min(ok,val[a]);
		}
		if(a!=b){
			ans+=min(minval*(()),min(val[a],val[b]));
			wnum[a][b]++;
			wnum[b][a]++;
			wpos[a][b].push_back(i);
			wpos[b][a].push_back(i);
			
			if( val[a] > val[b] ){
				if(bigger > val[a]){
					bigger = val[a];
					bpos=i;
				}
				if(smaller < val[b]){
					smaller = val[b];
					spos=i;
				}
			}else{
				if(bigger > val[b]){
					bigger = val[b];
					bpos=i;
				}
				if(smaller < val[a]){
					smaller = val[a];
					spos=i;
				}
			}
		}
	}
	if(bigger!=INT_MAX && smaller!=0 && bpos!=spos){
		mov1=smaller-bigger;
	}
	if(ok!=INT_MAX && smaller!=0){
		mov2=smaller-ok*2;
	}
	
	//double
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			if(wnum[i][j]>1){
				if(dob<min(val[i],val[j])){
					dob=min(val[i],val[j]);
					dpos1=wpos[i][j][0];
					dpos2=wpos[i][j][1];
				}
			}
		}
	}
	
	//single
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			for(int k=j+1;k<26;k++){
				if(wnum[i][j] && wnum[i][k]){
					int cut=(min(val[i],val[j])+min(val[i],val[k])) - (min(val[j],val[k]));
					if(sing<cut){
						sing=cut;
						singpos1=wpos[i][j][0];
						singpos2=wpos[i][k][0];
					}
				}
			}
		}
	}
	if(_TEST>=5){
		cout<<"smaller:"<<smaller<<"  bigger"<<bigger<<"  ok:"<<ok<<"\n";
		cout<<"ans:"<<ans<<"  single:"<<sing<<"  double:"<<dob<<"  move1:"<<mov1<<"  move2:"<<mov2<<"\n";
	}
	
	cout<<ans-max(0ll,max(max(sing,dob),max(mov1,mov2)))<<"\n";
	
	return 0;
}

