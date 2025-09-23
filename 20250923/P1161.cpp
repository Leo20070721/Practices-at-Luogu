#include <bits/stdc++.h>
using namespace std;

int ans,N;
signed main(){
    cin>>N;
    while(N--){
        double a;int t;cin>>a>>t;
        for(int i=1;i<=t;i++){
            ans^=(int)(floor(a*i));
        }
    }
    cout<<ans<<"\n";
    return 0;
}