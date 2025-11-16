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

struct Student{
	string name;
	int chg;
	int mth;
	int eng;
	
	Student(){
		name="";
		chg=-1;
		mth=-1;
		eng=-1;
	}
	
	int sum(){
		return chg+mth+eng;
	}
	void cpy(Student a){
		name=a.name;
		chg=a.chg;
		mth=a.mth;
		eng=a.eng;
	}
}sget,best;
//------------------------------------------
int N;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>sget.name>>sget.chg>>sget.mth>>sget.eng;
		if(sget.sum() > best.sum()){
			best.cpy(sget);
		}
	}
	
	cout<<best.name<<" "<<best.chg<<" "<<best.mth<<" "<<best.eng<<"\n";
	
	return 0;
}


