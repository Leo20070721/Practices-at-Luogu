#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
const bool _QuickStream=true;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------
int N,M,ans=0;
int Fin[100005],week[100005],now[100005];
vector <signed> addpos[100005];

void chg(int from,int to){
	if(from==to) return;
	else if(from<to) {
		for(int i=from;i<=to;i++){
			int end=addpos[i].size();
			for(int j=0;j<end;j++){
				now[addpos[i][j]]++;
			}
		}
		return ;
	}
	else{
		for(int i=from;i>to;i--){
			int end=addpos[i].size();
			for(int j=0;j<end;j++){
				now[addpos[i][j]]--;
			}
		}
		return ;
	}
}

bool chk(){
	for(int i=1;i<=N;i++){
		if(now[i]<Fin[i]) return false;
	}
	return true;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		cin>>Fin[i];
		
	}
	for(int i=1;i<=M;i++){
		int c,pos=0;cin>>c;
		for(int j=1;j<=c;j++){
			cin>>pos;
			week[pos]++;
			addpos[i].push_back(pos);
		}
	}
	
	for(int i=1;i<=N;i++){
		if(ceil( double( Fin[i])/double(week[i]) )*M >ans)
			ans=ceil( double( Fin[i])/double(week[i]) )*M;
	}
	for(int i=1;i<=N;i++){
		now[i]=ans/M*week[i];
	}
	
	int l=0,r=M,mid,cur=M;
	while(l<r){
		if(_TEST>7)cout<<l<<" "<<r<<"\n";
		mid=(l+r)>>1;//l=mid<=r 
		chg(cur,mid);
		cur=mid;
		if(chk()){			
			if(_TEST>5)cout<<"Day"<<mid<<"£ºPassed r("<<r<<")->mid("<<mid<<")\n";
			r=mid; 
		} 
		else{			
			if(_TEST>5)cout<<"Day"<<mid<<"£ºFalsed l("<<l<<")->mid("<<mid<<")\n";
			l=mid+1;
		} 
		if(_TEST>5){
			for(int i=1;i<=N;i++) cout<<now[i]<<" ";
			cout<<"\n\n";
		}
	}
	cout<<ans-M+l<<"\n";

	return 0;
}


