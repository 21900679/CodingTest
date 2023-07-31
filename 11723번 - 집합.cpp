#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
void Sadd(int num);
void Sremove(int num);
void Stoggle(int num);
void Sall();
void Scheck(int num);
int output[3000000];
int i = 0;

int main(){

    
    string abc;
    int num;
    

    int M;
    
    cin >> M;

    for(int i = 0; i < M; i++){
        cin >> abc >> num;
        if(abc.compare("add") == 0)
            Sadd(num);
        else if(abc.compare("remove") == 0)
            Sremove(num);
        else if(abc.compare("empty") == 0)
            v.clear();
        else if(abc.compare("toggle") == 0)
            Stoggle(num);
        else if(abc.compare("all") == 0)
            Sall();
        else if(abc.compare("check") == 0)
            Scheck(num);        
    }

    for(int j = 0; j < i; j++)
        cout << output[j] << endl;
        
    return 0;
}

void Sadd(int num){
    if(find(v.begin(), v.end(), num) == v.end()){   // 존재하지 않음
        v.push_back(num);
    }
}

void Sremove(int num){
    if(find(v.begin(), v.end(), num) != v.end()){       // 존재함
        v.erase(remove(v.begin(), v.end(), num), v.end());
    }
}

void Stoggle(int num){
    if(find(v.begin(), v.end(), num) == v.end())
        v.erase(remove(v.begin(), v.end(), num), v.end());
    else
        v.push_back(num);
}

void Sall(){
    v.clear();
    for(int i = 1; i <= 20; i++)
        v.push_back(i);
}

void Scheck(int num){
    if(find(v.begin(), v.end(), num) != v.end())
        output[i] = 1;
    else
        output[i] = 0;
    i++;
}