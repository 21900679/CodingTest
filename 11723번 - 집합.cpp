#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string abc;
    int num;
    long long arr = 1;

    int M;
    
    cin >> M;

    while(M--){     // 0 = false, 1 = true
        cin >> abc;
        if(abc.compare("add") == 0){
            cin >> num;
            arr |= (1<<num);
        }
        else if(abc.compare("remove") == 0){
            cin >> num;
            arr &= ~(1<<num);
        }
        else if(abc.compare("empty") == 0){
            arr = 0;
        }
        else if(abc.compare("toggle") == 0){
            cin >> num;
            if((1<<num) & arr){     // 있으면
                arr &= ~(1<<num);
            }
            else        // 없으면
                arr |= (1<<num);
        }
        else if(abc.compare("all") == 0){
            arr |= (1<<21) - 1;
        }
        else if(abc.compare("check") == 0){
            cin >> num;
            if((1<<num) & arr)
                cout << "1\n";
            else
                cout << "0\n";
        }  
    }
    return 0;
}