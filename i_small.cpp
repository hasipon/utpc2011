#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int a[8] = {0};
	for (int i = 0; i < N; ++ i) {
		int x, y;
		cin >> x >> y;
		for (int j = 0; j < 8; ++ j) {
			if ((x>>j)&1) {
				if ((y>>j)&1) {
					a[j] |= 8;
				} else {
					a[j] |= 4;
				}
			} else {
				if ((y>>j)&1) {
					a[j] |= 2;
				} else {
					a[j] |= 1;
				}
			}
		}
	}
	cout << "(((((((";
	for (int j = 0; j < 8; ++ j) {
		if (j != 0) cout << "|";
		switch (a[j]) {
		case 2:
		case 8:
		case 10:
			cout << (1<<j);
			break;
		case 9:
			cout << "(x&"<<(1<<j)<<")";
			break;
		case 6:
			cout << "((x^"<<(1<<j)<<")&"<<(1<<j)<<")";
			break;
		default: cout << 0; break;
		}
		if (j != 0) cout << ")";
	}
	cout << endl;
}
