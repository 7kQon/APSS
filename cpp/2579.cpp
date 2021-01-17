#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

const int _max_ = 300;

array<int, _max_> value{0,};
array<int, _max_> sp{0,};

int sol(int idx){
    if(sp[idx] != 0) return sp[idx];

    int ret = 0;
    if(idx == 0) ret = value[idx];
    else if(idx == 1) ret =  value[idx] + value[idx - 1];
    else if(idx == 2) ret = max(value[idx] + value[idx - 1], value[idx] + value[idx - 2]);
    
    if(ret != 0){ sp[idx] = ret; return ret;}

    int v0 = sol(idx - 3) + value[idx - 1] + value[idx];
    int v1 = sol(idx - 2) + value[idx];
    ret = max(v0, v1);
    sp[idx] = ret;
    return ret;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> value[i];
    }
    int ans = 0;
    for(int j = 0; j < n; j++){
        ans = sol(j);
    }
    cout << ans << "\n";
}