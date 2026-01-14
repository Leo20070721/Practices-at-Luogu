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
const signed _TEST=0;
//------------------------------------------
bool amap[6][6];
int score[6][6];
bool flag =false;

void _chk(){
	if(_TEST>5){
		for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){
			cout<<score[i][j]<<" ";
		}cout<<"\n";
		}
		cout<<"-------------\n";
	}
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	
	for(int i=1;i<=5;i++){
		string sget;cin>>sget;
		for(int j=0;j<5;j++){
			amap[i][j+1]=(sget[j]=='1'?true:false);
		}
	}
	
	for(int i=1;i<=5;i++){
		int j=1,start=1;bool ing=false;
		while(j<=5){
			if(!ing){
				while(!amap[i][j] && j<=5) j++;
				ing=true;
			}
			else{
				start=j;
				while(amap[i][j] && j<=5) j++;
				for(int k=start;k<j;k++){
					switch(j-start){
						case 5:
							flag=true;
							break;
						case 4:
							score[i][k]=max(score[i][k],3);
							break;
						case 3:
							score[i][k]=max(score[i][k],2);
							break;
						default:
							score[i][k]=max(score[i][k],1);
							break;
					}					
				}
				start=j+1;
				ing=false;
			}
		}
	} 
	_chk();
	for(int i=1;i<=5;i++){//colomn
		int j=1,start=1;bool ing=false;
		while(j<=5){
			if(!ing){
				while(!amap[j][i] && j<=5) j++;
				ing=true;
			}
			else{
				start=j;
				while(amap[j][i] && j<=5) j++;
				for(int k=start;k<j;k++){
					switch(j-start){
						case 5:
							flag=true;
							break;
						case 4:
							score[k][i]=max(score[k][i],3);
							break;
						case 3:
							score[k][i]=max(score[k][i],2);
							break;
						default:
							score[k][i]=max(score[k][i],1);
							break;
					}					
				}
				start=j+1;
				ing=false;
			}
		}
	} 
	_chk();
	for(int j=1;j<=5;j++){
		for(int k=1;k<=5;k++){
			for(int i=0;i<5;i++){//right angle
			
		int start=1;bool ing=false;
		while(j+i<=5 && k+i<=5){
			if(!ing){
				while(!amap[j+i][k+i] && j+i<=5 && k+i<=5) i++;
				ing=true;
			}
			else{
				start=i;
				while(amap[j+i][k+i] && j+i<=5 && k+i<=5) i++;
				for(int l=start;l<i;l++){
					switch(i-start){
						case 5:
							flag=true;
							break;
						case 4:
							score[j+l][k+l]=max(score[j+l][k+l],3);
							break;
						case 3:
							score[j+l][k+l]=max(score[j+l][k+l],2);
							break;
						default:
							score[j+l][k+l]=max(score[j+l][k+l],1);
							break;
					}					
				}
				start=i+1;
				ing=false;
			}
		}
	}
			for(int i=0;i<5;i++){//left angle
			
		int start=1;bool ing=false;
		while(j+i<=5 && k-i>=1){
			if(!ing){
				while(!amap[j+i][k-i] && j+i<=5 && k-i>=1) i++;
				ing=true;
			}
			else{
				start=i;
				while(amap[j+i][k-i] && j+i<=5 && k-i>=1) i++;
				for(int l=start;l<i;l++){
					switch(i-start){
						case 5:
							flag=true;
							break;
						case 4:
							score[j+l][k-l]=max(score[j+l][k-l],3);
							break;
						case 3:
							score[j+l][k-l]=max(score[j+l][k-l],2);
							break;
						default:
							score[j+l][k-l]=max(score[j+l][k-l],1);
							break;
					}					
				}
				start=i+1;
				ing=false;
			}
		}
	}
		}
	}
	
	_chk();
	
	if(flag){
		cout<<"Bingo!\n";
		return 0;
	}
	else{
		int sum=0;
		for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			sum+=score[i][j];
			
		cout<<sum<<"\n";
		return 0;
	}

	return 0;
}

