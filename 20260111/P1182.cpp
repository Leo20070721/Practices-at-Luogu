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
int N,M,nums[100005],ans,L=INT_MAX,H; 

bool chk(int t){
	int m=0;lli sum=0;
	for(int i=1;i<=N;i++){
		sum+=nums[i];
		if(nums[i]>t) return false;
		if(sum>t){
			sum=nums[i];
			m++;
		} 
	}
	m++;
	return m<=M;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	
	cin >>N>>M;
	for(int i=1;i<=N;i++){
		cin>>nums[i];
		H+=nums[i];L=min(L,nums[i]);
	}
	
	
	int l=L,r=H,mid;
	while(l<r){
		mid=((r-l)>>1)+l;//l<=mid<r 
		//cout<<"debug:"<<l<<" "<<r<<" |"<<chk(mid)<<"| "<<mid<<"\n"; 
		if(!chk(mid)) l=mid+1;
		else r=mid;
	}
	cout<<r<<"\n";

	return 0;
}


