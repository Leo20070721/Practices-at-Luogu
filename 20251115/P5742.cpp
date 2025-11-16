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
int N;

struct Student{
	int no;
	double score;
	double score_exec;
	double score_integrated;
	
	void calcScoreIntegrated(){
		score_integrated = score*70+score_exec*30;
	}
	
	double getScore(){
		return score+score_exec;
	}
}stuts[1005];

void isStudentExcellent(Student _a){
	if(_a.getScore() > 140 && _a.score_integrated>=8000 ) 
		cout<<"Excellent\n";
	else
		cout<<"Not excellent\n";
	return ;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>stuts[i].no>>stuts[i].score>>stuts[i].score_exec;
		stuts[i].calcScoreIntegrated(); 
	}
	
	for(int i=1;i<=N;i++){
		isStudentExcellent(stuts[i]);
	}

	return 0;
}


