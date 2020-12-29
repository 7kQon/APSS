#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g(9, vector<int>(9));
vector<pair<int, int>> e;
bool isDone = false;
int N;

bool isValid(int num, int row, int col) {
	for (int i = 0; i < 9; i++) {
		if (g[row][i] == num) return false;
	} // row checking

	for (int i = 0; i < 9; i++) {
		if (g[i][col] == num) return false;
	} // col checking

	int x, y, n;
	for ( n = 0; n < 3; n++) {
		if (3 * n > row) break;
	}
	y = 3 * (n - 1);

	for ( n = 0; n < 3; n++) {
		if (3 * n > col) break;
	}
	x = 3 * (n - 1);

	for (int i = y; i < y + 3; i++) {
		for (int j = x; j < x + 3; j++) {
			if (g[i][j] == num) return false;
		}
	} // box checking

	return true;
}

void backtrack(int i) {
	if (isDone)
		return;

	if (i == N) {
		for (auto r : g) {
			for (auto e : r) {
				cout << e << " ";
			} cout << "\n";
		}
		isDone = true;
		return;
	}

	for (int num = 1; num <= 9; num++) {
		int r = e[i].first;
		int c = e[i].second;
		if (!isValid(num, r, c)) continue;
		g[r][c] = num;
		backtrack(i + 1);
		g[r][c] = 0;
	}
}


int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) cin >> g[i][j];
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) if (g[i][j] == 0) e.emplace_back(make_pair(i, j));
	}

	N = e.size();
	backtrack(0);
}