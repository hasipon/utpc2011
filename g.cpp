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
	vector<pair<int, long long> > b;
	for (int i = N-3; i >= 0; -- i) {
		if (a[i]+a[i+1] > a[i+2]) {
			b.push_back(make_pair(i,a[i]+a[i+1]+a[i+2]));
		}
	}
	for (unsigned i = 0; i < b.size(); ++ i) {
		unsigned j = i+1;
		for (; j < b.size(); ++ j) {
			if (b[i].first - b[j].first >= 3) break;
		}
		if (j < b.size()) {
			r = max(r, b[i].second + b[j].second);
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
