#include <iostream>

using namespace std;

int main(){
    int E, S, M;
    int result;

    cin >> E >> S >> M;

    if(E == 15){
        E = 0;
    }
    if(S == 28){
        S = 0;
    }
    if(M == 19){
        M = 0;
    }

    for(int i = 1; ; i++){
        // printf("%d\n", i);
        if(i % 15 == E && i % 28 == S && i % 19 == M){
            result = i;
            break;
        }
    }

    printf("%d", result);

    return 0;
}