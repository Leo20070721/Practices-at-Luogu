#include <bits/stdc++.h>
using namespace std;
//           a,b,c, d,e,f, g,h,i, j,k,l, m,n,o, p,q,r,s, t,u,v, w,x,y,z
int num[30]={1,2,3, 1,2,3, 1,2,3, 1,2,3, 1,2,3, 1,2,3,4, 1,2,3, 1,2,3,4};
string Ques;
int ans=0;
signed main(){
    getline(cin,Ques);
    for(int i=0;i<Ques.size();i++){
        if(Ques[i]==' ') ans++;
        else ans+=num[ int(Ques[i])-int('a') ];
    }

    cout<<ans<<"\n";

    return 0;
}