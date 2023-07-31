#include <iostream>
#include <algorithm>
#define MAX 10000

using namespace std;

int main(){
    int N;
    int input[MAX];

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> input[i];

    int count = N-1;
    while(count >= 1 && input[count] >= input[count-1])
        count--;

    // cout << count << endl;
    
    if(count == 0)
        cout << -1;
    else{
        int index = count;
        // cout << count << endl;
        while(index <= N-1 && input[count-1] >= input[index])
            index++;
            
        // cout << index << " " << count << endl;
        swap(input[index-1], input[count-1]);
        sort(input + count,input + N, greater<int>());

        for(int i = 0; i < N; i++)
            cout << input[i] << " ";
    }

    return 0;
}