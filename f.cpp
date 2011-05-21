#include <iostream>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	if (N/2 < K) {
		cout << -1 << endl;
		return 0;
	}
	
	int a[20000];
	for (int j = 0; j < N/2; ++ j) {
		a[2*j] = 1;
		a[2*j+1] = j+2;
	}
	for (int j = N/2; j < N-1; ++ j) {
		a[2*j] = N/2+1;
		a[2*j+1] = j+2;
	}
	
	for (int i = 0; i < K; ++ i) {
		if (i) cout << endl;
		for (int j = 0; j < N-1; ++ j) {
			cout << a[2*j] << " "  << a[2*j+1] << endl;
			a[2*j] = a[2*j]%N + 1;
			a[2*j+1] = a[2*j+1]%N + 1;
		}
	}
}
