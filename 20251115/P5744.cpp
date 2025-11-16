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
struct Student{
	string name;
	int age;
	int score;	
};

Student study(Student _a){
	_a.age++;
	_a.score=_a.score*12/10;
	if(_a.score>600) _a.score=600;
	cout<<_a.name<<" "<<_a.age<<" "<<_a.score<<"\n";
	return _a;
}



int N;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	
	cin>>N;
	for(int i=1;i<=N;i++){
		Student stu; 
		cin>>stu.name>>stu.age>>stu.score;
		study(stu);
	}
	
	return 0;
}


