#include <iostream>
#include <array>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> cache;

string make_key(int a, int b, int c){
    string key;
    key.append(to_string(a));
    key.append(" ");
    key.append(to_string(b));
    key.append(" ");
    key.append(to_string(c));
    return key;
}

int w(int a, int b, int c){
    std::string key = make_key(a, b, c);
    if(cache.find(key) != cache.end()){
        return cache[key];
    }
    int ret;
    if(a <= 0 || b <= 0 || c <= 0){
        ret = 1;
        cache[key] = ret;
        return ret;
    }

    if(a > 20 || b > 20 || c > 20){
        ret = w(20, 20, 20);
        cache[key] = ret;
        return ret;
    }

    if(a < b && b < c){
        ret = w(a, b, c-1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        cache[key] = ret;
        return ret;
    }
    
    ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    cache[key] = ret;
    return ret;
}

int main(){
    bool flag = true;
    while(flag){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1){ flag = false; continue;}
        int ans = w(a, b, c);
        printf("w(%d, %d, %d) = %d\n",a, b, c, ans);
    }

}