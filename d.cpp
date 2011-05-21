#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int R, C;
vector<string> s;
bool memo[20][20][4][16];
bool func(int x, int y, int d, int m) {
	if (memo[x][y][d][m]) return false;
	memo[x][y][d][m] = true;
	switch (s[y][x]) {
	case '<': d = 1; break;
	case '>': d = 0; break;
	case '^': d = 3; break;
	case 'v': d = 2; break;
	case '_': d = (m == 0 ? 0 : 1); break;
	case '|': d = (m == 0 ? 2 : 3); break;
	case '@': return true;
	case '+': m = (m+1)&15; break;
	case '-': m = (m-1)&15; break;
	}
	if ('0' <= s[y][x] && s[y][x] <= '9') m = s[y][x] - '0';
	if (s[y][x] == '?') {
		int xx = x, yy = y;
		for (d = 0; d < 4; ++ d) {
			x = xx;
			y = yy;
			switch (d) {
			case 0: x = (x+1)%C; break;
			case 1: x = (x+C-1)%C; break;
			case 2: y = (y+1)%R; break;
			case 3: y = (y+R-1)%R; break;
			}
			if (func(x, y, d, m)) return true;
		}
		return false;
	}
	switch (d) {
	case 0: x = (x+1)%C; break;
	case 1: x = (x+C-1)%C; break;
	case 2: y = (y+1)%R; break;
	case 3: y = (y+R-1)%R; break;
	}
	return func(x, y, d, m);
}
int main() {
	cin >> R >> C;
	s = vector<string>(R);
	for (int i = 0; i < R; ++ i) {
		cin >> s[i];
	}
	cout << (func(0, 0, 0, 0) ? "YES" : "NO") << endl;
}
