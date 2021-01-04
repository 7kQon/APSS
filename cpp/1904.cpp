#include <iostream>
#include <vector>
using namespace std;

vector<int> cache(1000001, { 0, });

int a(int n) {
    if (cache[n] != 0) return cache[n];

    if (n == 1) { cache[n] = 1; }
    else if (n == 2) { cache[n] = 2; }
    else {
        cache[n] = (a(n - 2) % 15746) + (a(n - 1) % 15746);
    }
    return cache[n] % 15746;
}

int main() {
    int n;
    cin >> n;

    int ans = a(n);
    cout << ans << "\n";
}