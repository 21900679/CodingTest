#include <iostream>

using namespace std;

int candy(char board[][50], int N);

int main(){

    int N;
    char board[50][50];
    int max = 1;
    int value;

    cin >> N;
    cin.clear();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    max = candy(board, N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(j + 1 < N && board[i][j] != board[i][j+1]){
                swap(board[i][j], board[i][j+1]);
                value = candy(board, N);
                if(value > max) 
                    max = value;
                swap(board[i][j], board[i][j+1]);
            }
            if(i + 1 < N && board[i][j] != board[i+1][j]){
                swap(board[i][j], board[i+1][j]);
                value = candy(board, N);
                if(value > max) 
                    max = value;
                swap(board[i][j], board[i+1][j]);
            }
        }
    }

    printf("%d\n", max);

    return 0;
}

int candy(char board[][50], int N){
    int max = 1;
    int result = 1;

    for(int i = 0; i < N; i++){     
        for(int j = 1; j < N; j++){     // °¡·Î
            if(board[i][j-1] == board[i][j]){
                result++;
            }
            else
                break;
        }
        if(result > max)
            max = result;
        result = 1;
        for(int j = 1; j < N; j++){
            if(board[j-1][i] == board[j][i])
                result ++;
            else
                break;
        }
        if(result > max)
            max = result;
        result = 1;
    }
    
    return max;
}