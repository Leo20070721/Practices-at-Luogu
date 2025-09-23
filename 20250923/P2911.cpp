#include <bits/stdc++.h>
using namespace std;

int s1,s2,s3,bucket[85],ans=1,pos=1,maxnum;
signed main(){
    cin>>s1>>s2>>s3;

    for(int i=1;i<=s1;i++)
    for(int j=1;j<=s2;j++)
    for(int k=1;k<=s3;k++)
        bucket[i+j+k]++;

    while(bucket[pos+1]>=maxnum){
        pos++;
        if(bucket[pos]>maxnum){
            ans=pos;
            maxnum=bucket[pos];
        }
    }
    cout<<ans<<"\n";
    return 0;
}