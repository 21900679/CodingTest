#include <istream>

int main(){

    int N;
    int * num = new int[1000000];
    int * f = new int[1000000];
    int * g = new int[1000000];

    scanf("%d", &N);

    int max = 0;

    for(int i = 0; i < N; i++){
        scanf("%d", &num[i]);
        if(max < num[i])
            max = num[i];
    }

    for(int i = 1; i <= max; i++){
        for(int j = 1; j <= i; j++){
            if(i % j == 0){
                f[i-1] += j;
            }
            if(i > 1)
                g[i-1] = g[i-2] + f[i-1];
            else
                g[i-1] = f[i-1];
        }
    }

    for(int i = 0; i < N; i++){
        printf("%d\n", g[num[i]-1]);
    }

    return 0;
}