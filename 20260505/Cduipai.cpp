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
		system("C-data.exe > C-in.txt");
		system("C2.exe < C-in.txt > C2.txt");
		system("C.exe < C-in.txt > C.txt");
		if (system("fc C.txt C2.txt")) break;
	}

	return 0;
}



