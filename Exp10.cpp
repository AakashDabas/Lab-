#include<iostream>

using namespace std;

class base{
    public:
        int data = 0;
};

class der1 : public virtual base{
    public:
        der1(){
            data = 10;
        }
};

class der2 : virtual public base{
    public:
        der2(){
            data = 20;
        }
};

class der_1 : public der1, public der2{
};
class der_2 : public der2, public der1{
};

int main(){
    der_1 obj1;
    der_2 obj2;
    cout << obj1.data << endl << obj2.data;
    return 0;
}
