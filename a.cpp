#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	int r = 0;
	for (int i = 0; i < N; ++ i) {
		int c = 0;
		for (int j = 0; j < M; ++ j) {
			int n;
			cin >> n;
			c += n;
		}
		r = max(r, c);
	}
	cout << r << endl;
}
