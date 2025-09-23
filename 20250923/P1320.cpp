#include <bits/stdc++.h>
using namespace std;

int N;
string got;
string newGot;
std::vector<int> ans; 
int flag;int sum;
signed main(){
    cin>>newGot;N=newGot.length();
    got+=newGot;
    for(int i=2;i<=N;i++){
        cin>>newGot;
        got+=newGot;
    }

    

    for(int i=0;i<N*N;i++){

        if(got[i]-'0' == flag){
            sum++;
        }
        else{
            flag=got[i]-'0';
            ans.push_back(sum);
            sum=1;
        }
    }
    ans.push_back(sum);

    cout<<N<<" ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<"\n";

    return 0;
}