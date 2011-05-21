#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<long long> a(N);
	for (int i = 0; i < N; ++ i) scanf("%lld",&a[i]);
	sort(a.begin(), a.end());
	long long r = 0;
	for (int i = N-3; i >= 0; -- i) {
		if (a[i]+a[i+1] > a[i+2]) {
			for (int j = i-3; j >= 0; -- j) {
				if (a[j]+a[j+1] > a[j+2]) {
					r = max(r, a[i]+a[i+1]+a[i+2]+a[j]+a[j+1]+a[j+2]);
				}
			}
		}
	}
	for (int i = N-6; i >= 0; -- i) {
		if (
			(a[i+0]+a[i+1] > a[i+3] && a[i+2]+a[i+4] > a[i+5]) ||
			(a[i+0]+a[i+2] > a[i+3] && a[i+1]+a[i+4] > a[i+5]) ||
			(a[i+1]+a[i+2] > a[i+3] && a[i+0]+a[i+4] > a[i+5]) ||
			(a[i+0]+a[i+1] > a[i+4] && a[i+2]+a[i+3] > a[i+5]) ||
			(a[i+0]+a[i+2] > a[i+4] && a[i+1]+a[i+3] > a[i+5]) ||
			(a[i+1]+a[i+2] > a[i+4] && a[i+0]+a[i+3] > a[i+5]) ||
			(a[i+0]+a[i+3] > a[i+4] && a[i+1]+a[i+2] > a[i+5]) ||
			(a[i+1]+a[i+3] > a[i+4] && a[i+0]+a[i+2] > a[i+5]) ||
			(a[i+2]+a[i+3] > a[i+4] && a[i+0]+a[i+1] > a[i+5])
		) {
			r = max(r, a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]);
		}
	}
	cout << r << endl;
}
