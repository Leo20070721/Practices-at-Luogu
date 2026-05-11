#include <bits/stdc++.h>
using namespace std;
#define int long long

int mem[1000005],val[1000005],N;
int sum,ans=0;
signed main()
{
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>mem[i];
		sum+=mem[i];
	}for(int i=1;i<=N-1;i++){
		cin>>val[i];
	}
	
	if(sum%N!=0){
		cout<<"-1\n";
		return 0;
	}else{
		int fin=sum/N;
		for(int i=1;i<=N;i++){
			if(mem[i]==fin){
				continue;
			}else if(mem[i]>=fin){
				ans+=(mem[i]-fin)*val[i];
				mem[i+1]+=(mem[i]-fin);
			}else{
				ans+=(fin-mem[i])*val[i];
				mem[i+1]-=(fin-mem[i]);
			}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
 } 
