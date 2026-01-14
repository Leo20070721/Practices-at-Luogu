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
const signed _TEST=0;
//------------------------------------------
int T;
int chk(int C,int S,int D){
	if(C==S && C==D && S==D) return -1;//N N N
	else if(C==S){//X X N
		if(C>D) return 0;
		if(D%2==C%2) return -1;
		else return 3;
	}
	else if(C==D){//X N X
		if(C>S) return 0;
		if(S%2==C%2) return -1;
		else return 2;
	}
	else if(D==S){//N X X
		if(D>C) return 0;
		if(D%2==C%2) return -1;
		else return 1;
	}
	else return 0;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	cin>>T;
	while(T--){
		int C,S,D;cin>>C>>S>>D;
		bool nxt=false;
		while(true){
			int re=chk(C,S,D);
			switch(re){
				case -1:
					cout<<"NO\n";
					nxt=true;
					break;
				case 0:
					if(C>D && S>D){
						C--;S--;D++;
					}else if(C>S && D>S){
						C--;S++;D--;
					}else{//S>C && D>C
						C++;S--;D--;
					}
					break;
				default:
					if(re==1)cout<<"Clubs\n";
					else if(re==2)cout<<"Spades\n";
					else cout<<"Diamonds\n";
					nxt=true;
					break;
			}
			
			if(nxt) break;
		}
	}


	return 0;
}

