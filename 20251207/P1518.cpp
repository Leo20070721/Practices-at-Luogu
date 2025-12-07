#include <bits/stdc++.h>
using namespace std;
#define lli long long
//#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
const bool _QuickStream=true;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------
int gforward[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
bool amap[12][12];
struct thing{
	int x;
	int y;
	int direction; 
	
	thing(){
		this->x=0;this->y=0;this->direction=0;
	}
	
	void go(){
		if(amap[this->x+gforward[this->direction][0]][this->y+gforward[this->direction][1]]){
			this->x+=gforward[this->direction][0];
			this->y+=gforward[this->direction][1];
		}
		else{
			this->direction=(this->direction+1)%4;
		}	
	}
}cow,fj;
bool buck[1000005];
int bhash(thing a,thing b){
	return (a.x%10)*100000+(a.y%10)*10000+a.direction*1000+(b.x%10)*100+(b.y%10)*10+b.direction;
}

int ans;

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	
	for(int i=1;i<=10;i++){
		string sget;cin>>sget;
		for(int j=1;j<=10;j++){
			if(sget[j-1]=='.'){
				amap[i][j]=true;
			}else if(sget[j-1]=='C'){
				amap[i][j]=true;
				cow.x=i;cow.y=j;
			}else if(sget[j-1]=='F'){
				amap[i][j]=true;
				fj.x=i;fj.y=j;
			}
		}
	}
	
	while(!buck[bhash(cow,fj)]){
		buck[bhash(cow,fj)]=true;
		ans++;
		//cout<<ans<<":cow("<<cow.x<<","<<cow.y<<")."<<cow.direction<<" fj("<<fj.x<<","<<fj.y<<")."<<fj.direction<<" "<<bhash(cow,fj)<<"\n";
		cow.go();
		fj.go();
		if(cow.x==fj.x && cow.y==fj.y){
			cout<<ans<<"\n";
			return 0;
		}		
	}
	cout<<"0\n";

	return 0;
}


