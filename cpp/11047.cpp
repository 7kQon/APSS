#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

array<int, 11> v{0,}; // value

int sol(int n, int k){
    if(k == 0) return 0;
    if(v[n] > k) return sol(n - 1, k);
    int t = k / v[n];
    k = k % v[n];
    return t + sol(n - 1, k);
}

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i < n + 1; i++){
        cin >> v[i];
    }
    int ans = sol(n, k);
    cout << ans << "\n";
}