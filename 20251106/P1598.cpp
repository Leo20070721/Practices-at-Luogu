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
string sget;
int bucket[26],maxn=0;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	
	for(int i=1;i<=4;i++){
		getline(cin,sget);
		for(int j=0;j<sget.length();j++){
			if(sget[j]<'A' || 'Z'<sget[j]) continue;
			bucket[sget[j]-'A']++;
		}
	}
	
	for(int i=0;i<26;i++){
		if(bucket[i]>maxn) maxn=bucket[i];
	}
	
	while(maxn){
		for(int i=0;i<26;i++){
			if(i==25){
				if(bucket[i]>=maxn)cout<<"*\n";
				else cout<<" \n";
			}
			else{
				if(bucket[i]>=maxn)cout<<"* ";
				else cout<<"  ";
			}
		}
		maxn--;
	}
	for(int i=0;i<26;i++){
		if(i==25){
			printf("%c",'A'+i); 
		}
		else{
			printf("%c ",'A'+i);
		}
	}

	return 0;
}


