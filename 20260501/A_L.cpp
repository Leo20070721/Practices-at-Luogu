#include <bits/stdc++.h>
using namespace std;
#define lli long long
//#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
inline void _OpenFiles(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
const bool _QuickStream=true;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------
int Fin_in;
int start_x,start_y,start_in;
int M,N;

struct points{
	bool vis;
	int Type;
	bool flag[4];
	char Fin;
}point[52][52];

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin>>M>>N;
	bool Start=false;
	
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			char c_get;cin>>c_get;
			if(c_get == 'u'|| c_get=='o' || c_get=='l' || c_get=='r'){
				if(Start){
					point[i][j]->Type=4;
					if(c_get == 'u') Fin_
				}
			}
		}
	}
	

	return 0;
}



