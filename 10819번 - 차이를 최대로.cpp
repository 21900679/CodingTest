#include <iostream>
#include <algorithm>

using namespace std;

int N;
int input[8];
int result = 0;

int nextValue(){
    int count = N-1;
    while(count >= 1 && input[count] <= input[count-1])
        count--;
    if(count == 0){
        return 0;
    }
    else{
        int index = count;
        while(index <= N-1 && input[count-1] <= input[index])
            index++;
        swap(input[count-1], input[index-1]);
        sort(input + count, input + N);
        return 1;
    }
}

void maxValue(){
    int calculate = 0;
    for(int i = 0; i < N - 1; i++){
        calculate += abs(input[i]-input[i+1]);
    }
    if(result < calculate)
        result = calculate;
}

int main(){

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> input[i];
    sort(input, input+N);

    maxValue();
    
    while(nextValue() == 1)
        maxValue();

    cout << result;

    return 0;
}