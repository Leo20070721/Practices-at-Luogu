#include <bits/stdc++.h>
#define int long long

std::unordered_map<int, bool> m;
signed main() {
	int p, x, k;
	std::cin >> p >> x >> k;
	std::vector<int> f;
	for (int i = 1; i * i <= p; i++) {
		if (p % i == 0) {
			f.push_back(i);
			if (p != i * i)
				f.push_back(p / i);
		}
	}
	std::vector<int> t;
	int K = k;
	for (int i = 2; i * i <= k; i++) {
		if (K % i == 0) {
			t.push_back(i);
			while (K % i == 0)
				K /= i;
		}
	}
	if (K != 1)
		t.push_back(K);
	int ans = 0;
//	for (int i = 0; i < t.size(); i++) {
//		std::cout << t[i] << ' ';
//	}
//	std::cout << '\n';
	for (int i = 0; i < f.size(); i++) {
		for (int j = 0; j < t.size(); j++) {
			int mul = t[j];
			int temp = f[i];
			while (temp <= x) {
				if (!m[temp]) {
					m[temp] = true;
					ans++;
					std::cout << temp << ' ';
				}
				
				temp *= mul;
			}
		}
	}
	std::cout << '\n';
	std::cout << ans << '\n';
}
