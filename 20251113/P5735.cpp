#include <bits/stdc++.h>
using namespace std;
#define lli long long
//#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
const bool _QuickStream=false;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------
double dis(double x1,double y1,double x2,double y2){
	double re=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	return re;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	double x1,x2,x3,y1,y2,y3,ans=0;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	ans=dis(x1,y1,x2,y2)+dis(x1,y1,x3,y3)+dis(x3,y3,x2,y2);
	printf("%.2lf\n",ans); 
	return 0;
}


