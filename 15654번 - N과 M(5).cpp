#include <iostream>
#include <algorithm>
#define MAX 10000

using namespace std;

int N, M;
int input[MAX] = {};
int arr[MAX];
bool visit[MAX] = {false};


void DFS(int depth){

    if(depth == M){
        for(int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = 0; i < N; i++){
        if(visit[i] == false){
            visit[i] = true;
            arr[depth] = input[i];
            DFS(depth + 1);
            visit[i] = false;
        }
    }
}

int main(){

    cin >> N >> M;
    cin.clear();
    for(int i = 0; i < N; i++){
        cin >> input[i];
    }
    sort(input, input + N);
    DFS(0);

    return 0;
}