#include <iostream>

using namespace std;

int N, M;
int arr[8];
bool visit[8] = {false};

void DFS(int depth){

    if(depth == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= N; i++){
        if(visit[i] == false){
            arr[depth] = i;
            DFS(depth+1);
        }
    }

}

int main(){

    cin >> N >> M;

    DFS(0);

    return 0;
}