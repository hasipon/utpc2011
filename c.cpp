#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
string a, b;
map<pair<int,int>, int> memo;
int func(int p, int q) {
	if (p >= a.length() || q >= b.length()) return 0;
	if (memo.find(make_pair(p, q)) != memo.end()) return memo[make_pair(p,q)];
	int r = func(p+1, q+1) + (a[p] == b[q] ? 1 : 0);
	r = max(r, func(p+1, q));
	r = max(r, func(p, q+1));
	return memo[make_pair(p,q)] = r;
}
int main() {
	string s;
	cin >> s;
	int L = s.length();
	bool f = true;
	for (int i = 0; i < L; ++ i) {
		if (s[i] == 'i' || s[i] == 'w') {
			f = false;
		} else if (f) {
			a = a + s[i];
		} else {
			b = s[i] + b;
		}
	}
	for (int i = 0; i < b.length(); ++ i) {
		if (b[i] == '(') b[i] = ')';
		else if (b[i] == ')') b[i] = '(';
		else if (b[i] == '{') b[i] = '}';
		else if (b[i] == '}') b[i] = '{';
		else if (b[i] == '[') b[i] = ']';
		else if (b[i] == ']') b[i] = '[';
	}
	cout << (3 + func(0, 0)*2) << endl;
}
