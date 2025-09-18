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
int w,x,h,q,ans;
bool block[25][25][25]; 
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	
	cin>>w>>x>>h>>q;
	for(int i=1;i<=w;i++)
	for(int j=1;j<=x;j++)
	for(int k=1;k<=h;k++)
		block[i][j][k]=true;
	
	
	for(int i=1;i<=q;i++){
		int X1,Y1,Z1,X2,Y2,Z2;
		cin>>X1>>Y1>>Z1>>X2>>Y2>>Z2;
		for(int i=X1;i<=X2;i++)
		for(int j=Y1;j<=Y2;j++)
		for(int k=Z1;k<=Z2;k++)
			block[i][j][k]=false;
	}
	
	for(int i=1;i<=w;i++)
	for(int j=1;j<=x;j++)
	for(int k=1;k<=h;k++)
	if(block[i][j][k]) ans++;
	
	cout<<ans<<"\n";
	
	return 0;
}


