#include<iostream>
#include<vector>

using namespace std;

vector<int> arr;
int len;

void add(int idx, int val){
    try{
        if(idx >= len)  throw 0;
        arr[idx] = val;
    }
    catch(...){
        cout << "Invalid Memory Address Access Attempted!\n";
    }
}

int main(){
    cout << "Enter the length of the array: ";
    cin >> len;
    arr.resize(len);
    add(10, 5);
    return 0;
}
