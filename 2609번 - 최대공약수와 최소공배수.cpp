#include <istream>

int main(){

    int num1, num2;
    int max, min;   // 최대공약수, 최소공배수

    scanf("%d %d", &num1, &num2);

    for(int i = (num1 > num2 ? num1 : num2); i > 0; i--){
        if(num1 % i == 0 && num2 % i == 0){
            max = i;
            break;
        }
    }

    for(int i = (num1 > num2 ? num2 : num1); i <= num1*num2; i++){
        if(i % num1 == 0 && i % num2 == 0){
            min = i;
            break;
        }
    }

    printf("%d\n%d", max, min);

    return 0;
}