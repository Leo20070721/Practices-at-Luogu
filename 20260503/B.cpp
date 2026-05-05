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
int N,K,A1;
int _temp=0;
stack<int> lst,Q;
queue<int> ans; 
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin>>N>>K;
	
	for(int i=1;i<=N;i++){
		int iget;cin>>iget;Q.push(iget);
		if(i==1) A1=iget;
	}
	
	while(!Q.empty()){
		if(_temp<Q.top()){
			if(_temp!=0)lst.push(_temp);//·ÀÖ¹ÖÃÈë0 
			_temp=Q.top();Q.pop(); 
		}else{
			K--;Q.pop();
			if(K==0){
				lst.push(_temp);
				while(!Q.empty()){
					lst.push(Q.top());Q.pop();
				}
			}
		}
	}
	if(K!=0) lst.push(_temp);
	
	{
		if(K!=0){
			stack<int> deBug;
			deBug.push(lst.top());int HUH=lst.top();lst.pop();
			while(!lst.empty()){
				if(HUH<=lst.top()) assert(false);
				deBug.push(lst.top());int HUH=lst.top();lst.pop();
			}
			while(!deBug.empty()){
				lst.push(deBug.top()) ;
				deBug.pop();
			}
		}
			
	}
	/*{
		stack<int> deBug;cout<<"debug:\n";
		cout<<"_temp:"<<_temp<<"\nQ.size()="<<Q.size()<<"\nK="<<K<<"\n\nlst:";
		while(!lst.empty()){
			cout<<lst.top()<<" ";
			deBug.push(lst.top()) ;
			lst.pop();
		}cout<<"\n";
		while(!deBug.empty()){
			lst.push(deBug.top()) ;
			deBug.pop();
		}cout<<"\n\n";
	}*/
	
	if(K>0){
		ans.push(lst.top());lst.pop();
		for(int i=1;i*2<=K && !lst.empty();i++){
			lst.pop();
		}
	}
	
	while(!lst.empty()){
		ans.push(lst.top());lst.pop();
	}
	
	cout<<ans.size()<<"\n";
	if(K%2==1 && ans.size()>1){
		if(A1==N){
			int _out_temp=ans.front();ans.pop();
			cout<<ans.front()<<" "<<_out_temp<<" ";
			ans.pop();
		}else{
			int _out_temp=ans.front();ans.pop();
			cout<<min(A1,ans.front())<<" "<<_out_temp<<" ";
			ans.pop();
		}
	}
	while(!ans.empty()){
		cout<<ans.front()<<" ";ans.pop();
	}cout<<"\n";


	return 0;
}

/*
5 2
1 2 3 4 5

10 8
10 6 7 8 9 5 1 2 3 4


10 8
1 2 4 6 7 10 9 8 5 3

*/

