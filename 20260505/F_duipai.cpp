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

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	while(1)
	{
		system("F_data.exe > F_in.txt");
		system("F.exe < F_in.txt > F.txt");
		system("F2.exe < F_in.txt > F2.txt");
		if (system("fc F.txt F2.txt")) break;
	}

	return 0;
}



