#include <iostream>

int main(){
    int N;
    int count = 0;
    int num[100];
    int result = 0;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &num[i]);
        // printf("%d", num[i]);
        for(int j = 1; j < num[i]; j++){
            if(num[i] % j == 0)
                count++;
        }
        if(count == 1){
            result ++;
        }
        count = 0;
    }

    printf("%d", result);

    return 0;
}
