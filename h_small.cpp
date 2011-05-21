#include <iostream>
#include <vector>
#include <map>
using namespace std;

int M, N, K;
vector<int> w, a;
map<pair<int,vector<int> >, int > memo;

int func(int p, const vector<int>& c) {
	if (p == K) return 0;
	if (memo.find(make_pair(p,c)) != memo.end()) {
		return memo.find(make_pair(p,c))->second;
	}
	for (int i = 0; i < c.size(); ++ i) {
		if (c[i] == a[p]) return func(p+1, c);
	}
	if ((int)c.size() < M) {
		vector<int> cc = c;
		cc.push_back(a[p]);
		return func(p+1, cc) + w[a[p]];
	}
	int r = 1<<30;
	for (int i = 0; i < M; ++ i) {
		vector<int> cc = c;
		cc[i] = a[p];
		r = min(r, func(p+1, cc) + w[a[p]]);
	}
	return memo[make_pair(p,c)] = r;
}

int main() {
	cin >> M >> N >> K;
	w = vector<int>(N);
	for (int i = 0; i < N; ++ i) {
		cin >> w[i];
		w[i];
	}
	a = vector<int>(K);
	for (int i = 0; i < K; ++ i) {
		cin >> a[i];
		-- a[i];
	}
	
	cout << func(0, vector<int>()) << endl;
}
