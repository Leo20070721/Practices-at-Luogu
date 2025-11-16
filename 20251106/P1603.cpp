#include <bits/stdc++.h>
using namespace std;
#define lli long long
//#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
const bool _QuickStream=false;
const bool _FILE=false;
const int  _TEST=0;
const int _OUT=0;
//------------------------------------------
string dic[30]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","a","both","another","first","second","third"} ;//"zero"
int dnum[30]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,1,2,1,1,2,3};//0
const int numNums=26;
//26个 
priority_queue < int , vector<int> , greater<int> > nums;

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	
	char sget[20],cget;int pos=0;
	cget=getchar();
	while(cget!='.'){
		if(cget==' '){
			for(int i=0;i<numNums;i++){//遍历字典
			bool flag=true; 
				if(dic[i].length() == pos){//若长度相等 
					for(int j=0;j<pos;j++){
						if(dic[i][j]!=sget[j]){flag=false;break;}
					}
					if(flag){
						if(_TEST>=5){
							for(int k=0;k<pos;k++) cout<<sget[k];
							cout<<" "<<dic[i]<<"\n";
						}
						nums.push(dnum[i]*dnum[i]);
						break;
					}
				}
			}
			pos=0;			
		}
		else{
			 if('A'<=cget && cget<='Z'){cget=cget-'A'+'a';}
			 sget[pos++]=cget;
		}
		
		cget=getchar();
	}
	
	if(_TEST>=2 && _OUT==1){
		while(!nums.empty()){
			cout<<nums.top()<<" ";
			nums.pop();
		}
	}
	
	bool isFirst=true;
	if(nums.empty()){
		cout<<"0\n";
		return 0;
	}
	while(!nums.empty()){
		if(isFirst){
			printf("%d",nums.top());
			nums.pop();
			isFirst=false;
		}
		printf("%02d",nums.top());
		nums.pop();
	}printf("\n");
	
	 

	return 0;
}


