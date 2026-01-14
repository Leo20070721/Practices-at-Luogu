#include <bits/stdc++.h>
using namespace std;
#define lli long long
//#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
const bool _QuickStream=false;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------
int N;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		char cget;scanf(" %c",&cget);
		cget=int('a')+int(cget)-int('0');
		printf("%c",cget);
	}
	

	return 0;
}


