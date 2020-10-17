//Various distances

#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
using namespace std;

int n;
double a[101010];
double r1, r2, r3;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		r1 += abs(a[i]);
		r2 += a[i] * a[i];
		r3 = max(r3, abs(a[i]));
	}
	cout << fixed;
	cout.precision(10);
	cout << r1 << "\n" << sqrt(r2) << "\n" << r3;
	
	return 0;
}
