#include <bits/stdc++.h>
using namespace std;

signed main(){

	while(1)
	{
		system("data.exe > in.txt");
		system("B.exe < in.txt > B.txt");
		system("B_Broute.exe < in.txt > B_Broute.txt");
		if (system("fc B_Broute.txt B.txt"))
			break;
	}
	return 0;
}



