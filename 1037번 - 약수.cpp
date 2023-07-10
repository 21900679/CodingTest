#include <istream>

int main(){

    int N;
    int num[50];
    int max = 2, min = 1000000;

    scanf("%d", &N);
    
    for(int i = 0; i < N; i++){
        scanf("%d", &num[i]);
        if(max < num[i])
            max = num[i];
        if(min > num[i])
            min = num[i];
    }

    printf("%d", max*min);

    return 0;
}