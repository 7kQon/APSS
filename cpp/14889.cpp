#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 2100000000;
int N;

vector<vector<int>> table(21, vector<int>(21));
vector<bool> selected(21);

void backtrack(int cur, int n) {
	if (n == N / 2) {
		vector<int> team_start, team_link;
		int start = 0, link = 0;
		for (int i = 1; i <= N; i++) {
			if (selected[i]) team_start.emplace_back(i);
			else team_link.emplace_back(i);
		}
		for (int i = 0; i < N / 2; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				int sy = team_start[i], sx = team_start[j];
				int ly = team_link[i], lx = team_link[j];
				start += table[sy][sx] + table[sx][sy];
				link += table[ly][lx] + table[lx][ly];
			}
		}
		ans = min(ans, abs(start - link));
		return;
	}

	for (int i = cur + 1; i <= N; i++) {
		if (selected[i]) continue;
		selected[i] = true;
		backtrack(i, n + 1);
		selected[i] = false;
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> table[i][j];
	}

	for (int i = 0; i <= N; i++) selected[i] = false;

	backtrack(0, 0);

	cout << ans << "\n";
}