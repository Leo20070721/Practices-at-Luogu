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
int holes_cnt[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
string Q;
int words[26];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>Q;
	
	for(int i=0;i<Q.size();i++){
		words[Q[i]-'A']++;
	}
	
	int ans=0;
	for(int k=0;k<=26;k++){
		int sum=0;
		for(int i=0;i<26;i++){
			sum+=words[i]*holes_cnt[(i+k)%26];
		}
		ans=max(sum,ans);
	}
	
	cout<<ans<<"\n";

	return 0;
}



