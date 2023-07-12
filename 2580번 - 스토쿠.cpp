#include <iostream>
#include <algorithm>
#define MAX 9

using namespace std;

int input[MAX][MAX];
int blank[MAX*MAX][2];
int n = 0;
bool check[9][9] = {true};

// void width(int x, int y){
//     for(int i = 0; i < MAX; i++){
//         if(input[x][i] != 0)
//             check[input[x][i]-1] = false;
//     }
// }

// void height(int x, int y){
//     for(int i = 0; i < MAX; i++){
//         if(input[i][y] != 0)
//             check[input[i][y]-1] = false;
//     }
// }

// void rect(int x, int y){
//     for(int i = x - x % 3; i < x - x % 3 + 3; i++){
//         for(int j = y - y % 3; j < y - y % 3 + 3; j++){
//             if(input[i][j] != 0)
//                 check[input[i][j]-1] = false;
//         }
//     }
// }

void backtracking(int k){
    int x = blank[k][0];
    int y = blank[k][1];

    if(k == n)
        return;

    for(int i = 0; i < MAX; i++){
        check[k][input[x][i]-1] = false;       // 가로
        check[k][input[i][y]-1] = false;       // 세로
    }

    for(int i = x - x % 3; i < x - x % 3 + 3; i++){     // 사각형
        for(int j = y - y % 3; j < y - y % 3 + 3; j++){
            check[k][input[i][j]-1] = false;
        }
    }

    for(int i = 0; i < MAX; i++){
        if(check[k][i]){
            input[x][y] = i + 1;
            check[k][i] = false; 
            backtracking(k+1);
        }
    }

    // if(count(check, check + MAX, true) == 1){
    //     for(int i = 0; i < MAX; i++){
    //         if(check[i])
    //             input[x][y] = i + 1;
    //     }
    // }
    // for(int i = 0; i < MAX; i++)
    //     check[i] = true;
    // backtracking(k+1);
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