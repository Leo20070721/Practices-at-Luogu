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

int T,N,M; 
signed main()
{
    _QuickStreamOpen();
    cin>>T;
    while(T--){
    	string s;cin>>s;
    	ulld in1=0,in2=0;
    	bool flag=false;
    	for(ulld i=0;i<s.size();i++){
    		if(s[i]=='.'){
    			flag=true;
			}else if(flag){
				in2*=10;
				in2+=s[i]-'0';
			}else{
				in1*=10;
				in1+=s[i]-'0';
			}
		}
    	ulld start=(ulld)(in1*100+in2);
    	
    	ulld fin=(start*2-100)*2-100;
    	ulld out2=fin%100,out1=fin/100;
    	
    	if(out2<10){
    		cout<<out1<<".0"<<out2<<"\n";
		}else{
			cout<<out1<<"."<<out2<<"\n";
		}
    	
	}

    return 0;
}
