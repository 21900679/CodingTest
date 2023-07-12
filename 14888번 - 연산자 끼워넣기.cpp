#include <iostream>
#define MAX 100

using namespace std;

int N, M = 0;
int input[MAX];
int cal[4];
int make[MAX-1];
int arr[MAX-1];
bool visit[MAX-1] = {false};
int big = -1000000000, nbig = 1000000000;

void DFS(int depth){
    int sum = 0;

    if(depth == M){
        if(arr[0] == 1)
            sum = input[0] + input[1];
        else if(arr[0] == 2)
            sum = input[0] - input[1];
        else if(arr[0] == 3)
            sum = input[0] * input[1];
        else if(arr[0] == 4)
            sum = input[0] / input[1];

        for(int i = 1; i < M; i++){
            if(arr[i] == 1)
                sum = sum + input[i+1];
            else if(arr[i] == 2)
                sum = sum - input[i+1];
            else if(arr[i] == 3)
                sum = sum * input[i+1];
            else if(arr[i] == 4)
                sum = sum / input[i+1];
        }
        if(big < sum)
            big = sum;
        if(nbig > sum)
            nbig = sum;
        return;

        for(int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = 0; i < M; i++){
        if(visit[i] == false){
            arr[depth] = make[i];
            visit[i] = true;
            DFS(depth+1);
            visit[i] = false;
        }
    }
}

int main(){

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> input[i];
    for(int i = 0; i < 4; i++){
        cin >> cal[i];
        for(int j = M; j < M + cal[i]; j++)
            make[j] = i + 1;
        M += cal[i];
    }

    DFS(0);

    cout << big << endl << nbig;

    return 0;
}