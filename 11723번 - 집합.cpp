#include <iostream>
#include <vector>

using namespace std;

bool check[20] = {false};
vector<int> output;

int main(){

    string abc;
    int num;

    int M;
    
    cin >> M;

    for(int i = 0; i < M; i++){
        cin >> abc >> num;
        if(abc.compare("add") == 0){
            check[num-1] = true;
        }
        else if(abc.compare("remove") == 0){
            check[num-1] = false;
        }
        else if(abc.compare("empty") == 0){
            fill_n(check, 20, false);
        }
        else if(abc.compare("toggle") == 0){
            check[num-1] = !check[num-1];
        }
        else if(abc.compare("all") == 0){
            fill_n(check, 20, true);
        }
        else if(abc.compare("check") == 0){
                output.push_back(check[num-1]);
        }        
    }

    for(int i = 0; i < output.size(); i++){
        cout << output[i] << endl;
    }

    return 0;
}