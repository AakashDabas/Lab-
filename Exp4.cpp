#include<iostream>
#include<algorithm>

using namespace std;

class vect{
    int *arr;
    int n;
    public:
        vect(int n){
            this->n = n;
            arr = new int[n];
        }

        void read(){
            for(int i = 0; i < n; i++)  cin >> arr[i];
            sort(arr, arr + n);
        }

        void display(){
            for(int i = 0; i < n; i++)  cout << arr[i] << " ";
        }
};

int main(){
    vect obj(10);
    obj.read();
    obj.display();
    return 0;
}
