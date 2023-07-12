#include <iostream>
#include <algorithm>
#define MAX 9

using namespace std;

int input[MAX][MAX];
int blank[MAX*MAX][2];
int n = 0;

int backtracking(int k){
    int check[9] = {0};     // true 0, false 1
    int x = blank[k][0];
    int y = blank[k][1];
    int result = 0;

    if(k == n)
        return 1;

    for(int i = 0; i < MAX; i++){
            check[input[x][i]-1] = 1;       // 가로
            check[input[i][y]-1] = 1;       // 세로
    }

    for(int i = x - x % 3; i < x - x % 3 + 3; i++){     // 사각형
        for(int j = y - y % 3; j < y - y % 3 + 3; j++){
                check[input[i][j]-1] = 1;
        }
    }

    for(int i = 0; i < MAX; i++){
        if(check[i] == 0){
            input[x][y] = i + 1;
            result = backtracking(k+1);
            if(result == 1) break;      // 스토쿠가 정상적으로 되었을 경우
            input[x][y] = 0;            // 스토쿠의 값이 잘못들어갔을 경우
        }
    }
    return result;
}

int main(){

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            cin >> input[i][j];   
            if(input[i][j] == 0){
                blank[n][0] = i;
                blank[n][1] = j;
                n++;
            }
        }
    }

    backtracking(0);     

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            cout << input[i][j] << " ";
        }       
        cout << "\n"; 
    }
    return 0;
}