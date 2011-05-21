#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A, B;
vector<int> memo;
int func(int x, int y) {
	if (memo[x] >= 0) return memo[x];
	int r = 0;
	for (int i = 0; i < N; ++ i) {
		if (((x>>i)&1)==0) {
			r = max(r, func(x|(1<<i), y+A[i]) + (y+A[i] <= B[i] ? 1 : 0));
		}
	}
	return memo[x] = r;
}
int main() {
	cin >> N;
	memo = vector<int>(1<<N, -1);
	for (int i = 0; i < N; ++ i) {
		int x, y;
		cin >> x >> y;
		A.push_back(x);
		B.push_back(y);
	}
	cout << func(0, 0) << endl;
}
