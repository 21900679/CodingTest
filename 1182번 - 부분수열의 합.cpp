#include <iostream>
#define MAX 20

using namespace std;

int main(){

    int N, S;
    int input[MAX];
    int last = 0;
    int sum = 0;
    int count = 0;

    cin >> N >> S;

    for(int i = 0; i < N; i++){
        cin >> input[i];
    }

    last |= (1<<N) - 1;
    // cout << "last = " << last << "\n";

    for(int i = 1; i <= last; i++){
        for(int j = 0; j < N; j++){
            if(i & (1<<j)){
                // cout << input[j] << ", ";
                sum += input[j];
            }
        }
        if(sum == S)
            count++;
        sum = 0;
    }

    cout << count;

    return 0;
}