#include <bits/stdc++.h>
using namespace std;
vector<int> e; 
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	double delta = sqrt(b*b - 4*a*c);
	printf("%.6f", (-b + delta) / (2*a));
	return 0;
 } 
