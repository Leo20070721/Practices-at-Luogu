#include <bits/stdc++.h>
using namespace std;


int N;
string number[10][5]={
"XXX","X.X","X.X","X.X","XXX",
"..X","..X","..X","..X","..X",
"XXX","..X","XXX","X..","XXX",
"XXX","..X","XXX","..X","XXX",
"X.X","X.X","XXX","..X","..X",
"XXX","X..","XXX","..X","XXX",
"XXX","X..","XXX","X.X","XXX",
"XXX","..X","..X","..X","..X",
"XXX","X.X","XXX","X.X","XXX",
"XXX","X.X","XXX","..X","XXX",
};
string need;

signed main(){
    cin>>N>>need;

    for(int i=0;i<5;i++){
        for(int j=0;j<N;j++){
            cout<<number[need[j]-'0'][i];
            if(j!=N-1)cout<<".";
        }cout<<"\n";
    }
    
    return 0;
}
