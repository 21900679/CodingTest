#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int value[9];
    int result = 0;
    int num1 = -1, num2 = -1;

    for(int i = 0; i < 9; i++){
        cin >> value[i];
        cin.clear();
    }

    sort(value, value + 9);

    for(int i = 0; i < 9; i++){
        for(int j = i; j < 9; j++){
            for(int x = 0; x < 9; x++){
                if(x != i && x != j)
                    result += value[x];
            }
            if(result != 100)
                result = 0;
            else{
                num2 = j;
                break;
            }
                
        }
        if(num2 != -1){
            num1 = i;
            break;
        }
    }

    for(int i = 0; i < 9; i++){
        if(i != num1 && i != num2)
            printf("%d\n", value[i]);
    }

    return 0;
}