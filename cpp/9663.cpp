#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int cnt = 0;
int N;
vector<vector<bool>> occupied(14, vector<bool>(14));

bool isValid(int row, int col){
    for(int i = 0; i < N; i++){
        // checks column
        if(occupied[i][col]) return false;
    }
    int sum = col + row;
    for(int i = 0; i < N; i++){
        int j = sum - i;
        if(j < 0 || j >= N) continue;
        if(occupied[i][j]) return false;
    }
    int dif = col - row;
    for(int i = 0; i < N; i++){
        int j = dif + i;
        if(j < 0 || j >= N) continue;
        if(occupied[i][j]) return false;
    }
    return true;
}

void backtrack(int row){
    if(row == N){
        cnt++;
        return;
    }

    for(int col = 0; col < N; col++){ // iterate columns
        if(!isValid(row, col)) continue;
        occupied[row][col] = true;
        backtrack(row + 1); // next row
        occupied[row][col] = false;
    }
    return;
}

int main(){
    cin >> N;
    for(int i = 0; i < 14; i++){{
        for(int j = 0; j < 14; j++){
            occupied[i][j] = false;
        }
    }
    backtrack(0);
    cout << cnt << "\n";
}