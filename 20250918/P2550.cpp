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
int n;
int medals[10],hit[10];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	cin>>n;
	for(int i=1;i<=7;i++)
		cin>>hit[i];
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=7;j++){
			int a;cin>>a;
			for(int k=1;k<=7;k++){
				if(a==hit[k])sum++;
			}
		}
		medals[sum]++;
	}
	
	for(int i=7;i>=1;i--)  cout<<medals[i]<<" ";
	cout<<"\n";

	return 0;
}


