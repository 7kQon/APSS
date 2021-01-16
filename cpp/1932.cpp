#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
const size_t __max_size__ = 500;

array<array<int, __max_size__>, __max_size__> t;

int sol(int level){
    int ans = t[0][0];
    for(int i = 1; i < level; i++){
        for(int j = 0; j < i + 1; j++){
            if(j == 0) { t[i][j] += t[i - 1][j]; continue;}
            if(j == i){t[i][j] += t[i - 1][j - 1]; continue;}
            t[i][j] = max(t[i - 1][j - 1], t[i - 1][j]) + t[i][j];
        }
    }

    int l = level - 1;
    for(int k = 0; k < level; k++){
        if(ans < t[l][k]) ans = t[l][k];
    }
    return ans;
}

int main(){
    int l; // level
    cin >> l;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < i + 1; j++){
            int input; cin >> input;
            t[i][j] = input;
        }
    }

    int ans = sol(l);
    cout << ans << "\n";
}