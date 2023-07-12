#include <iostream>

using namespace std;

int N, M;
int input[20][20];
int arr[20];
int miniarr[10];
int result = 1000000000;
bool check[20] = {false};
bool mcheck[10] = {false};

int miniDFS(int depth, int start, int end){
    if(depth == 2){
        for(int i = 0; i < 2; i++)
            cout << miniarr
    }
    for(int i = start; i < 2; i++){
        if(mcheck[i] == false){
            mcheck[i] = true;
            miniarr[depth] = arr[i];
            miniDFS(depth + 1, start, end);
            mcheck[i] = false;
        }
    }

}

void DFS(int depth){
    if(depth == N){
        int n1 = miniDFS(0, 0, M);
        int n2 = miniDFS(0, M, N);
        if(result > abs(n1-n2))
            result = abs(n1-n2);
    }
    for(int i = 0; i < N; i++){
        if(check[i] == false){
            check[i] = true;
            arr[depth] = i + 1;
            DFS(depth + 1);
            check[i] = false;
        }
    }
}

int main(){

    cin >> N;
    M = N/2;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> input[i][j];

    DFS(0);

    cout << result;

    return 0;
}