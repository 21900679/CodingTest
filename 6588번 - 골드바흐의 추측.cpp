#include <iostream>

using namespace std;
bool tf(int b);

int main(){

    int * input = new int[100001];
    int end;
    int * output = new int[100001]{};
    int b;

    for(int i = 0; i < 100001; i++){
        cin >> input[i];
        cin.clear();
        if(input[i] == 0){
            end = i;
            break;
        }
    }

    for(int i = 0; i < end; i++){
        for(int j = 3; j <= input[i]/2; j += 2){
            b = input[i] - j;
            if(b % 2 == 1 && tf(b) && tf(j)){
                output[i] = j;
                break;
            }
        }
    }   

    for(int i = 0; i < end; i++){
        if(output[i] == 0)
            printf("Goldbach's conjecture is wrong.\n");
        else
            printf("%d = %d + %d\n", input[i], output[i], input[i]-output[i]);
    }

    return 0;
}

bool tf(int b){     // 소수알아내는 함수
    if(b < 3)
        return false;
    for(int i = 2; i < b; i++){
        if(b % i == 0)
            return false;
    }
    return true;
}
