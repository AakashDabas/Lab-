#include<iostream>

using namespace std;

float multiply(float a, float b){
    return a * b;
}

float multiply(float a, float b, float c){
    return a * b * c;
}

class base{
    public:
        virtual void disp(){}
};

class der1 : public base{
    public:
        void disp(){
            cout << "Derived Class 1 is called!\n";
        }
};

class der2 : public base{
    public:
        void disp(){
            cout << "Derived Class 2 is called!\n";
        }
};

int main(){
    cout << "Product of 10 * 5.5 is : " << multiply(10, 5.5) << endl;
    cout << "Product of 10 * 5.5 * 9.2 is : " << multiply(10, 5.5, 9.2) << endl;
    base *ptr;
    der1 obj1;
    der2 obj2;
    ptr = &obj1;
    ptr->disp();
    ptr = &obj2;
    ptr->disp();
    return 0;
}
