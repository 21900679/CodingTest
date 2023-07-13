#include <iostream>
#include <string.h>

using namespace std;

string N;
string arr1, arr2;
int Nlength;
int M;
bool index[10];
int input;
int start = 0;
int small = 9;
int large = 0;;

int main(){

    memset(index, true, sizeof(index));

    cin >> N;
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> input;
        index[input] = false;
    }

    for(int i = 0; i < 10; i++){        // ���� ū ��, ���� �� ã��
        if(index[i] && small > i)   
            small = i;
        if(index[i] && large < i)
            large = i;
    }

    Nlength = N.length();
    for(int i = 0; i < Nlength; i++){
        if(!index[N[i] - '0']){
            start = i;
            // cout << "���� : " << start;
            break;
        }
        arr1 += N[i];
        arr2 += N[i];
        // cout << "arr1 �� arr2 �� : " << arr1[i] << "��" << arr2[i] << endl;
        cout << "arr1 : " << arr1 << endl;
    }

    int startInt = N[start] - '0';
    if(start == 0){
        cout << "dkdk\n";
    }
    else{
        int part1 = 10;
        int part2 = 10;
        for(int i = 0; i < startInt; i++){  // ���� ��
            if(index[i]){
                int temp = startInt - i;
                if(part1 > temp)
                    part1 = temp;
            }
        }
        for(int i = startInt + 1; i < 10; i++){   // ū ��
            if(index[i]){
                int temp = i - startInt;
                if(part2 > temp)
                    part2 = temp;
            }
        }
        arr1 += (startInt - part1) + '0';
        arr2 += (startInt + part2) + '0';
        for(int i = start + 1; i < Nlength; i++){
            arr1 += large + '0';
            arr2 += small + '0';
        }
    }
    // cout << "���� ���� �� : " << small << "���� ū �� : " << large << endl;
    cout << arr1 << endl;
    cout << arr2 << endl;

    return 0;
}