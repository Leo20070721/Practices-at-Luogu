#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define lld long long
#define ulld unsigned long long
#define Ld long double

const bool _QuickStream=false;
inline void _QuickStreamOpen(){
	if(!_QuickStream) return;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

struct node{
	int from;
	int pos;
	int num;
};

int T,N; 
signed main()
{
    _QuickStreamOpen();
    cin>>T;
    while(T--){
    	cin>>N;
    	int temp=N;
    	map<int,bool>vis;
    	vector <int> ans;
    	if(temp<9){
    		switch(temp){
    			case 1:{
    				cout<<"1\n";
					break;
				}case 2:{
    				cout<<"1 2\n";
					break;
				}case 3:{
    				cout<<"1 2 3\n";
					break;
				}case 4:{
    				cout<<"1 2 3 4\n";
					break;
				}case 5:{
    				cout<<"1 2 3 4 5\n";
					break;
				}case 6:{
    				cout<<"1 3 5 2 4 6\n";
					break;
				}case 7:{
    				cout<<"1 3 5 7 2 4 6\n";
					break;
				}case 8:{
    				cout<<"1 3 5 7 2 4 6 8\n";
					break;
				}
			}
		}else{//temp>=9
			queue<int> add;
			temp-=3;
			while(temp>3){
				add.push(3);
				temp-=3;
			}
			if(temp==3){
				add.push(2);add.push(1);
			}else if(temp==2){
				add.push(2);
			}else if(temp==1){
				add.push(1);
			}			
			
			vector<int>ans;
			deque< node > out;
			out.push_back({1,1,1});
			out.push_back({3,1,2});
			while(!add.empty() || !out.empty()){
				ans.push_back(out.front().from-out.front().pos+1);
				if(out.front().pos<out.front().num){
					out.push_back({out.front().from,out.front().pos+1,out.front().num});
					out.pop_front();
				}else{
					out.pop_front();
					if(!add.empty()){
						//cout<<"new line:"<<out.front().from+3<<" "<<1<<" "<<add.front()<<"\n";
						out.push_back({out.front().from+add.front(), 1, add.front()});
						add.pop();
					}					
				}
			}
			
			for(unsigned int i=0;i<ans.size();i++){
				cout<<ans[i]<<" ";
			}cout<<"\n";
		}
    	
	}
    
    

    return 0;
}
