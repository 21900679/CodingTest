#include <istream>

int main(){
    int N;
    int result = 0;

    scanf("%d", &N);

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            if(i % j == 0)
                result += j;
        }
    }

    printf("%d", result);

    return 0;
}