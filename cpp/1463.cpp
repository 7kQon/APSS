#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

const int _max_ = 1000001;
array<int, _max_> cache{0,};

int sol(int n){
    if(n == 1) return 0; // base
    int ret = cache[n];
    if(ret != 0) return ret;
    
    if(n % 6 == 0){
        int v0 = sol(n / 3) + 1;
        int v1 = sol(n / 2) + 1;
        ret = min(v0, v1);
    }
    else if(n % 3 == 0){
        int v0 = sol(n - 1) + 1;
        int v1 = sol(n / 3) + 1;
        ret =  min(v0, v1);
    }
    else if(n % 2 == 0){
        int v0 = sol(n - 1) + 1;
        int v1 = sol(n / 2) + 1;
        ret = min(v0, v1);
    }
    else ret = sol(n - 1) + 1;

    cache[n] = ret;
    return ret;
}

int main(){
    int n; cin >> n;
    int ans = sol(n);
    cout << ans << "\n";
}