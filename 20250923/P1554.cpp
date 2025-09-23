#include <bits/stdc++.h>
using namespace std;

int M,N,ans[10];

void solve(int ques){
    while(ques>0){
        ans[ques%10]++;
        ques/=10;
    }
    return ;
}

signed main(){
    cin>>M>>N;
    for(int i=M;i<=N;i++){
        solve(i);
    }

    for(int i=0;i<=9;i++)
        cout<<ans[i]<<" ";

    return 0;
}