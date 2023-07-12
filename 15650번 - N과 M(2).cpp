#include <iostream>

using namespace std;

int N, M;
int arr[8];
bool visit[8] = {false};

void DFS(int depth){

    if(depth == M){
        for(int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    for(int i = 1; i <= N; i++){
        if(visit[i] == false && i > arr[depth-1]){
            visit[i] = true;
            arr[depth] = i;
            DFS(depth + 1);
            visit[i] = false;
        }
    }
}

int main(){
    cin >> N >> M;
    DFS(0);
    return 0;
}