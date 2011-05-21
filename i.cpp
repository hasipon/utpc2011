#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, x[8], y[8];
	cin >> N;
	for (int i = 0; i < N; ++ i) cin >> x[i] >> y[i];
	
	int a[8] = {0};
	for (int i = 0; i < N; ++ i) {
		for (int j = 0; j < 8; ++ j) {
			if ((x[i]>>j)&1) {
				if ((y[i]>>j)&1) a[j] |= 8;
				else a[j] |= 4;
			} else {
				if ((y[i]>>j)&1) a[j] |= 2;
				else a[j] |= 1;
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
		case 3:
		case 7:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			{
				vector<int> a1;
				for (int k = 0; k < N; ++ k) {
					if ((y[k]>>j)&1) a1.push_back(x[k]&((1<<(j+1))-1));
				}
				sort(a1.begin(), a1.end());
				a1.erase(unique(a1.begin(), a1.end()), a1.end());
				for (int k = 0; k < a1.size(); ++ k) {
					cout << "(";
				}
				for (int k = 0; k < a1.size(); ++ k) {
					if (k != 0) cout << "|";
					for (int l = 0; l < j; ++ l) {
						cout << "(";
					}
					for (int l = 0; l <= j; ++ l) {
						if (l != 0) cout << "&";
						if ((a1[k]>>l)&1) {
							cout << "(x*" << (1<<(j-l)) << ")";
						} else {
							cout << "((x*" << (1<<(j-l)) << ")^" << (1<<j) << ")";
						}
						if (l != 0) cout << ")";
					}
					if (k != 0) cout << ")";
				}
				cout << "&"<<(1<<j)<<")";
			}
			break;
		default: cout << 0; break;
		}
		if (j != 0) cout << ")";
	}
	cout << endl;
}
