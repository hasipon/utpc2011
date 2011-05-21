#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int,int> > X;
	for (int i = 0; i < N; ++ i) {
		int x, y;
		cin >> x >> y;
		X.push_back(make_pair(y, x));
	}
	sort(X.begin(), X.end());
	vector<int> a;
	int t = 0;
	for (int i = 0; i < N; ++ i) {
		if (t + X[i].second <= X[i].first) {
			a.push_back(X[i].second);
			t += X[i].second;
		} else {
			vector<int>::iterator it = max_element(a.begin(), a.end());
			if (it != a.end() && X[i].second < *it) {
				t -= *it - X[i].second;
				*it = X[i].second;
			}
		}
	}
	cout << a.size() << endl;
}
