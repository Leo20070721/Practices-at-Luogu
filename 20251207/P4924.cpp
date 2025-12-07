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
//------------------------------------------
int N,M;
int F[505][505],temp[505][505];
void init(){
	cin>>N>>M;
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++)
		F[i][j]=(i-1)*N+j;
} 

void solve(int x,int y,int r,int z){
	if(z){//ÄæÊ±Õë 
		for(int i=x-r;i<=x+r;i++)
		for(int j=y-r;j<=y+r;j++)
			temp[x+y-j][y-x+i]=F[i][j];
	} 
	else{
		for(int i=x-r;i<=x+r;i++)
		for(int j=y-r;j<=y+r;j++)
			temp[x-y+j][x+y-i]=F[i][j];
	}
	
	for(int i=x-r;i<=x+r;i++)
	for(int j=y-r;j<=y+r;j++)
		F[i][j]=temp[i][j];
}

void out(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout<<F[i][j]<<" ";
		}cout<<"\n";		
	}
	
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	
	init();
	for(int i=1;i<=M;i++){
		int x,y,r,z;
		cin>>x>>y>>r>>z;
		solve(x,y,r,z);
	}	
	out();

	return 0;
}


