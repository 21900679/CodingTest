#include <iostream>
#include <algorithm>

#define MAX 10000

using namespace std;

int main(){

    int input[MAX];
    int N;  
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input[i];
    }
    int deorder = N-1;
    while (deorder >= 1 && input[deorder] <= input[deorder - 1]) {
        deorder--;
    }

    if(deorder == 0)
        cout << -1;
    else{
        int index = N-1;
        while (input[index] <= input[deorder - 1]) {
            index--;
        } 
        swap(input[index], input[deorder - 1]);
        sort(input+deorder,input+N);

        for(int i = 0; i < N; i++){
            cout << input[i] << " ";
        }
    }
        
    return 0;
}