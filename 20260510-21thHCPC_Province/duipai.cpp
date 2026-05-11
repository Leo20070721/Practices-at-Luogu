#include <bits/stdc++.h>
using namespace std;
int main()
{
	while(1)
	{
		system("data.exe > in.txt");
		system("E.exe < in.txt > std.txt");
		system("E2.exe < in.txt > baoli.txt");
		if (system("fc std.txt baoli.txt"))
		break;
	}
}
