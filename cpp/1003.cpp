#include <iostream>
#include <vector>
#include <array>

using namespace std;

array<pair<int, int>, 41> cache;
int zero = 0;
int one = 0;

void fibo(int n){
    if(cache[n].first != 0 || cache[n].second != 0){
        zero += cache[n].first;
        one += cache[n].second;
        return;
    }
    if(n == 0){zero++; return;}
    if(n == 1){one++; return;}
    fibo(n - 1);
    fibo(n - 2);
    cache[n].first = zero;
    cache[n].second = one;
    return;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        zero = one = 0;
        int n;
        cin >> n;
        fibo(n);
        cout << zero << " " << one << "\n";
    }
}