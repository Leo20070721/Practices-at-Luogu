#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
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
int T;
int x0,y0,x1,y1,x2,y2;

Ld calcAngle(int sH,int sM,int eH,int eM){
	Ld rightCircle,leftCircle;
	if(eH<sH) eH+=12;
	
}

bool isEarlierThan(int aH,int aM,int bH,int bM){
	return (
		(aH*60+aM) < (bH*60+bM)
	);
}

bool isLegalAnswer(int sH,int sM,int eH,int eM,int tH,int tM){
	return(
	  (sH*60+sM) <= (tH*60+tM)
	&&(tH*60+tM) <= (eH*60+eM)	
	);
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>T;
	while(T--){
		cin>>x0>>y0>>x1>>y1>>x2>>y2;
		
		int ansh=INT_MAX,ansm=INT_MAX;
		Ld ansAngel=1e5;
		int tryh,trym=y1;
		
		if(x1>x2) x2+=12;
		
		for(int tryh=x1;tryh<=x2;tryh++){
			for(int trym=0;trym<=59;trym++){
				if(!isLegalAnswer(x1,y1,x2,y2,tryh,trym)) continue;
				
				Ld newAngle=calcAngle(x0,y0,tryh,trym);
				if(ansAngel > newAngle){
					ansAngel=newAngle;
					ansh=tryh,ansm=trym;
				}else if(ansAngel == newAngle){
					if(isEarlierThan(tryh,trym,ansh,ansm)){
						ansh=tryh,ansm=trym;
					}
				}
			}
		}
		
		if(ansh>12)ansh-=12;
		cout<<ansh<<" "<<ansm<<"\n";		
	}

	return 0;
}
/*
2
1 0 2 10 2 40
2 30 8 30 9 40


*/ 


