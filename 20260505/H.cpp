#include <bits/stdc++.h>
#define int long long
 
bool check(int a) {
	int temp = a + 1;
	int root = (int)(std::sqrt(temp));
	if (root * root == temp)
		return true;
	return false;
}
signed main() {
	int t;
	std::cin >> t;
	while (t--) {
		int s, l, r;
		std::cin >> s >> l >> r;
		// std::cout << c << ' ' << d << '\n';
		std::cout << r - l + 1 << std::endl;
	}
}
