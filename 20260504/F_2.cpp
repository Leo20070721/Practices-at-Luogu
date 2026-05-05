#include <bits/stdc++.h>
#define int long long

int p, x, k, ans;
vector<int> fk,fp,fpn;
map<int, bool> fkmap;

void kDFS(int now,int kpos){
	if(kpos==fk.size()) return;
	int times=1;
	
	for(int i=1;now*times<=x;i++){
		times*=fk[kpos];
		ans++;
		pDFS(now*times,kpos+1);
	}
	return;
}

void pDFS(int now,int ppos){
	if(ppos==fp.size()) kDFS(now,0);
	int times=1;
	
	for(int i=1;now*times<=x && i<=fpn[ppos];i++){
		times*=fp[ppos];
		ans++;
		pDFS(now*times,ppos+1);
	}
	return;
}

signed main() {
	std::cin >> p >> x >> k;
	
	{//pre
		int K=k;
		for (int i = 2; i * i <= k; i++) {
			if (K % i == 0) {
				fk.push_back(i);
				fkmap[i]=true;
				while (K % i == 0){
					K /= i;
				}					
			}
		}
		
		int P=p;
		for (int i = 2; i * i <= p; i++) {
			if (P % i == 0) {
				int sum=0;
				while (K % i == 0){
					K /= i;
					sum++;
				}		
				if(!fkmap[i]){
					fp.push_back(i);
					fpn.push_back(sum);
				}			
			}
		}
	}
	
	
	
	pDFS(1,0);
	
	cout<<ans<<"\n";
}
