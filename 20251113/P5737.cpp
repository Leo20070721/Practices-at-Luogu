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
int beginY,endY;
queue <int> ans;
int num;

bool isLeapYear(int ques){
	if(ques%400==0) return true;
	if(ques%100!=0 && ques%4==0) return true;
	return false; 
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	cin>>beginY>>endY;
	
	for(int i=beginY;i<=endY;i++){
		if(isLeapYear(i)){
			num++;
			ans.push(i);
		}
	}
	
	cout<<num<<"\n";
	while(!ans.empty()){
		cout<<ans.front()<<" ";
		ans.pop();
	}cout<<"\n";
	
	return 0;
}


