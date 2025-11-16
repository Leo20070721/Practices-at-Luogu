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
stack <int> a,b;
bool flag=true;
int type=1;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	
	{
		char cget=getchar();
		while(('0'<=cget&&cget<='9')||cget=='.'||cget=='%'||cget=='/'){
			if('0'<=cget&&cget<='9'){
				if(flag) a.push(cget-'0');
				else     b.push(cget-'0');
			}
			else if(cget=='.'){
				type=2;
				flag=false;
			}
			else if(cget=='/'){
				type=3;
				flag=false;
			}
			else if(cget=='%') type=4;
			
			cget=getchar();
		}
	}
	
	while(a.top()==0 && a.size()>1)
		a.pop();
	while(!a.empty()){
		cout<<a.top();a.pop();
	}
	
	switch(type){
		case 1:
			cout<<"\n";
			return 0;
		case 4:
			cout<<"%\n";
			return 0;
		case 2:
			cout<<'.';
			while(!b.empty()){
				a.push(b.top());b.pop();
			}
			while(a.top()==0 && a.size()>1)
				a.pop();
			while(!a.empty()){
				b.push(a.top());a.pop();
			}
			while(!b.empty()){
				cout<<b.top();b.pop();
			}				
			return 0;
		case 3:
			cout<<'/';
			while(b.top()==0 && b.size()>1)
				b.pop();
			while(!b.empty()){
				cout<<b.top();b.pop();
			}	
			return 0;		
	}
	
	return 0;
}


