#include <iostream>

int main(){

    int M, N;

    scanf("%d %d", &M, &N);

    for(int i = M; i <= N; i++){
        bool tr = true;
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                tr = false;
                break;
            }
        }
        if(tr)
            printf("%d\n", i);
    }

    return 0;
}