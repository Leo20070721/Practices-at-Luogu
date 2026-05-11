#include <bits/stdc++.h>
#define maxn 20

int main() {
	int a[maxn];
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		a[i] = i;
	int ans = 10000;
	int t = 0;
	do {
		t++;
		int sum = 0;
		std::map<int, int> s;
		for (int i = 1; i <= n - 2; i++) {
			int A = a[i], B = a[i + 1], C = a[i + 2];
			int mid = A + B + C - std::min({A, B, C}) - std::max({A, B, C});
			s[mid]++;
			if (s[mid] == 1)
				sum++; 
			// std::cout << mid << ' ';
		}
		int A = a[n - 1], B = a[n], C = a[1];
		int mid = A + B + C - std::min({A, B, C}) - std::max({A, B, C});
			s[mid]++;
			if (s[mid] == 1)
				sum++; 
		// std::cout << mid << ' ';
		A = a[n], B = a[1], C = a[2];
		mid = A + B + C - std::min({A, B, C}) - std::max({A, B, C});
			s[mid]++;
			if (s[mid] == 1)
				sum++; 
		// std::cout << mid <<'\n';
		
//		for (int i = 1; i <= n; i++)
//				std::cout << a[i] << ' ';
//			std::cout << '\n';
		ans = std::min(ans, sum);
//		if (ans == 3)
//			break;
	}while (std::next_permutation(a + 1, a + n + 1));
	for (int i = 1; i <= n; i++)
		a[i] = i;
	do {
		int sum = 0;
		std::map<int, int> s;
		for (int i = 1; i <= n - 2; i++) {
			int A = a[i], B = a[i + 1], C = a[i + 2];
			int mid = A + B + C - std::min({A, B, C}) - std::max({A, B, C});
			s[mid]++;
			if (s[mid] == 1)
				sum++; 
		}
		int A = a[n - 1], B = a[n], C = a[1];
		int mid = A + B + C - std::min({A, B, C}) - std::max({A, B, C});
			s[mid]++;
			if (s[mid] == 1)
				sum++; 
		A = a[n], B = a[1], C = a[2];
		mid = A + B + C - std::min({A, B, C}) - std::max({A, B, C});
			s[mid]++;
			if (s[mid] == 1)
				sum++; 
		if (ans == sum) {
			for (int i = 1; i <= n; i++)
				std::cout << a[i] << ' ';
			std::cout << '\n';
			break;
		}
	}while (std::next_permutation(a + 1, a + n + 1));
	std::cout << ans << '\n';
	std::map<int, int> s;
    int cnt = 0;
    int sum = 0;
	for (int i = 1; i <= n; i += 2)
		a[++cnt] = i;
	for (int i = 2; i <= n; i += 2)
		a[++cnt] = i; 
	 for (int i = 1; i <= n - 2; i++) {
			int A = a[i], B = a[i + 1], C = a[i + 2];
			int mid = A + B + C - std::min({A, B, C}) - std::max({A, B, C});
			s[mid]++;
			if (s[mid] == 1)
				sum++; 
			// std::cout << mid << ' ';
		}
		int A = a[n - 1], B = a[n], C = a[1];
		int mid = A + B + C - std::min({A, B, C}) - std::max({A, B, C});
			s[mid]++;
			if (s[mid] == 1)
				sum++; 
		// std::cout << mid << ' ';
		A = a[n], B = a[1], C = a[2];
		mid = A + B + C - std::min({A, B, C}) - std::max({A, B, C});
			s[mid]++;
			if (s[mid] == 1)
				sum++; 
	std::cout << sum << '\n';
} 
