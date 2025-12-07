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
struct lines{
	int K;
	int B;
};
stack <lines> ans,temp;
int N;

int check(lines a,lines b,lines c){//all 2/mid 0/get 1
	double x1,y1,x2,y2,x3,y3,k1,k2,k3,b1,b2,b3;
	k1=a.K;b1=a.B;k2=b.K;b2=b.B;k3=c.K;b3=c.B;
	
	if(k1-k2 != 0){x1=(b2-b1)/(k2-k1);}
	else{x1=0;}
	y1=k1*x1+b1;
	
	if(k2-k3 != 0){x2=(b3-b2)/(k3-k2);}
	else{x2=0;}
	y2=k2*x2+b2;
	
	if(k1-k3 != 0){x3=(b3-b1)/(k3-k1);}
	else{x3=0;}
	y3=k3*x3+b3;
	
	if(k2==k3){return b.B>c.B?0:1;}
	else if(k1==k3){return 2;}
	else{
		
	}
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	cin>>N;
	for(int i=1;i<=N;i++){
		lines get_line,mid_line;
		cin>>get_line.K>>get_line.B;
		while(!ans.empty()){
			if(ans.top().K > get_line.K){
				temp.push(ans.top());
				ans.pop();
			} 
		}
		if(ans.empty()){ans.push(get_line);}
		else{
			while(flag){
				int flag=-1;
				mid_line=ans.top();
				ans.pop();
				if(ans.empty()){
					flag=0;
					if(mid_line.K!=get_line.K){
						ans.push(mid_line);
						ans.push(get_line);
					}
					else{ans.push(mid_line.B>get_line.B?mid_line:get_line);}				
				}
				else{
					flag=check(ans.top(),mid_line,get_line);
					if(flag==2){
						ans.push(mid_line);
						ans.push(get_line);
					}
					else if(flag==0){ans.push(mid_line);}
					else{ans.push(get_line);}
				}
			}
		}
		while(!temp.empty()){
			ans.push(temp.top());
			temp.pop();
		}
	}
	
	
	return 0;
}


