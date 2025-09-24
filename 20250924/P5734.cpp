#include <bits/stdc++.h>
using namespace std;

int Q;string str;

signed main(){
    cin>>Q>>str;
    while(Q--){
        int flag;
        cin>>flag;
        switch (flag)
        {
            case 1:{
                string getStr;
                cin>>getStr;
                str+=getStr;
                cout<<str<<"\n";
                break;
            }     
            case 2:{
                int a,b;string midStr;
                cin>>a>>b;
                for(int i=0;i<b;i++){
                    midStr.push_back(str[a+i]);
                }
                //cout<<"TEST:midStr="<<midStr<<"\n";
                str=midStr;
                cout<<str<<"\n";
                break;
            }
            case 3:{
                int a;string getStr;
                cin>>a>>getStr;
                str.insert(a,getStr);
                cout<<str<<"\n";
                break;
            }
            case 4:{
                string getStr;
                size_t mid;
                cin>>getStr;
                mid=str.find(getStr);
                //cout<<"TEST:str="<<str<<" getStr="<<getStr<<" mid="<<mid<<"\n";
                if(mid!=string::npos){
                    cout<<mid<<"\n";   
                }
                else{
                    cout<<"-1\n";          
                }
                break;
            }
       }
    }

    return 0;
}