#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int _max_= 1000;

vector<int> v;

int main(){
    int n; cin >> n;
    v.reserve(_max_);
    for(int i = 0; i < n; i++){
        int e; cin >> e;
        v.emplace_back(e);
    }

    sort(v.begin(), v.end());

    int ans = 0;
    int sum = 0;
    for(int j = 0; j < n; j++){
        sum += v[j];
        ans += sum;
    }
    cout << ans << "\n";
}