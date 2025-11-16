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
	
	bool chk(Student a){
		if(abs(chg-a.chg)>5) return false;
		if(abs(mth-a.mth)>5) return false;
		if(abs(eng-a.eng)>5) return false;
		if(abs(chg+mth+eng-a.chg-a.mth-a.eng)>10) return false;
		return true;
	}
}stuts[1005];
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
		cin>>stuts[i].name>>stuts[i].chg>>stuts[i].mth>>stuts[i].eng;
	}
	
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;j++){
			if(stuts[i].chk(stuts[j])){
				cout<<stuts[i].name<<" "<<stuts[j].name<<"\n";
			}
		}
	}
	
	return 0;
}


