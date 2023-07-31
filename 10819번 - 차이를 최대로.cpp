#include <iostream>
#include <algorithm>

using namespace std;

int N;
int input[8];
int num[8] = {0,1,2,3,4,5,6,7};
int result = 0;

int nextValue(){
    int count = N-1;
    while(count >= 1 && num[count] <= num[count-1])
        count--;
    if(count == 0){
        return 0;
    }
    else{
        int index = count;
        while(index <= N-1 && num[count-1] <= num[index])
            index++;
        swap(num[count-1], num[index-1]);
        sort(num + count, num + N);
        return 1;
    }
}

void maxValue(){
    int calculate = 0;
    for(int i = 0; i < N - 1; i++){
        calculate += abs(input[num[i]]-input[num[i+1]]);
    }
    if(result < calculate)
        result = calculate;
}

int main(){

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> input[i];

    maxValue();
    
    while(nextValue() == 1){
        maxValue();
    }

    cout << result << endl;

    return 0;
}