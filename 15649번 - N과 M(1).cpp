#include <iostream>

using namespace std;

int N, M;
int arr[8];
bool visited[8] = {false};

void DFS(int depth){

    if(depth == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < N; i++){
        if(visited[i] == false){
            visited[i] = true;
            arr[depth] = i + 1;
            DFS(depth + 1);
            visited[i] = false;
        }
    }
}

int main(){

    cin >> N >> M;

    DFS(0);

    return 0;
}