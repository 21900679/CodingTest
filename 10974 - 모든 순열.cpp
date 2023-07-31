#include <iostream>
#include <algorithm>

using namespace std;

int N;
int input[8];

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

int main(){

    cin >> N;

    for(int i = 0; i < N; i++){
        input[i] = i+1;
        cout << input[i] << " ";
    }
  
    cout << "\n";
    
    while(nextValue() == 1){
        for(int i = 0; i < N; i++)
            cout << input[i] << " ";
        cout << "\n";
    }

    return 0;
}