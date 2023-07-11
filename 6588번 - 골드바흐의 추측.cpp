#include <iostream>

using namespace std;
bool tf(int b);

int main(){

    int * input = new int[100000];
    int end;
    int * output = new int[100000];
    int b;

    for(int i = 0; i < 100000; i++){
        cin >> input[i];
        cin.clear();
        if(input[i] == 0){
            end = i;
            break;
        }
    }

    for(int i = 0; i < end; i++){
        for(int j = 3; j < input[i]; j += 2){
            b = input[i] - j;
            if(b % 2 == 1 && tf(b)){
                output[i] = j;
                break;
            }
        }
    }   

    for(int i = 0; i < end; i++){
        printf("%d = %d + %d\n", input[i], output[i], input[i]-output[i]);
    }

    return 0;
}

bool tf(int b){
    for(int i = 2; i < b; i++){
        if(b % i == 0)
            return false;
    }
    return true;
}