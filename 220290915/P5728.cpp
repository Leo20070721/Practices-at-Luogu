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
const int  _TEST=4;
//------------------------------------------
int N,ans;
struct stu{
	int chn,math,eng;
	int sum;
	
	bool operator < (const stu b){
		if(sum < b.sum) return true;
		else return false;
	} 
}students[1005];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>students[i].chn>>students[i].math>>students[i].eng;
		students[i].sum=students[i].chn+students[i].eng+students[i].math;
	}

if(_TEST>=5){cout<<"PRE:\n";
	for(int i=1;i<=N;i++){
		cout<<i<<":"<<students[i].sum<<"="<<students[i].chn<<"+"<<students[i].math<<"+"<<students[i].eng<<"\n";
	}
} 

	sort(students+1,students+1+N);
	
if(_TEST>=5){cout<<"AFT:\n";
	for(int i=1;i<=N;i++){
		cout<<i<<":"<<students[i].sum<<"="<<students[i].chn<<"+"<<students[i].math<<"+"<<students[i].eng<<"\n";
	}
} 
	
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;j++){
			if(abs(students[i].sum-students[j].sum)>10) break;
			
			if(abs(students[i].chn-students[j].chn)>5) continue;
			if(abs(students[i].eng-students[j].eng)>5) continue;
			if(abs(students[i].math-students[j].math)>5) continue;
			
			ans++;
		}
	}
	
	cout<<ans<<"\n";
	return 0;
}


