#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int L = s.length();
	int r = 0;
	for (int i = 0; i <= L-1-i; ++ i) {
		if (i == L-1-i) {
			if (s[i] == '(' || s[i] == ')') ++ r;
		} else if (s[i] == '(') {
			if (')' != s[L-1-i]) ++ r;
		} else if (s[i] == ')') {
			if ('(' != s[L-1-i]) ++ r;
		} else {
			if (s[i] != s[L-1-i]) ++ r;
		}
	}
	cout << r << endl;
}
