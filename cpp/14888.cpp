#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int N;
int x;
int MAX = -1000000001;
int MIN = 1000000001;

vector<int> ops(4);
vector<int> nums(11);

int calculate(int lhs, int rhs, int op) {
	switch (op) {
	case 0: return lhs + rhs;
	case 1: return lhs - rhs;
	case 2: return lhs * rhs;
	case 3: return lhs / rhs;
	}
}

void backtrack(int k) {
	if (k == N - 1) {
		if (nums[k] <= MIN) MIN = nums[k];
		if (nums[k] >= MAX) MAX = nums[k];
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (ops[i] <= 0) continue;
		int tmp = nums[k + 1];
		x = calculate(nums[k], nums[k + 1], i);
		nums[k + 1] = x;
		ops[i]--;

		backtrack(k + 1);

		ops[i]++;
		nums[k + 1] = tmp;
	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) cin >> nums[i];
	for (int i = 0; i < 4; i++) cin >> ops[i];

	backtrack(0);

	cout << MAX << "\n";
	cout << MIN << "\n";
}