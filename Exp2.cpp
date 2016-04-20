#include<iostream>
using namespace std;

class complex {
public:
	float real;
	float imaginary;
	void read()
	{
		cout << "Enter the real val : ";
		cin >> real;
		cout << "Enter the imaginary val : ";
		cin >> imaginary;
	}
	/*complex() {}
	complex(complex &obj)
	{
		real = obj.real;
		imaginary = obj.imaginary;
	}*/
	void display()
	{
		cout << real << (imaginary>0?"+":"") << imaginary << " i"<<endl;
	}
};

complex operator+(complex c1, complex c2)
{
	complex cTmp;
	cTmp.real = c1.real + c2.real;
	cTmp.imaginary = c1.imaginary + c2.imaginary;
	return cTmp;
}

int main()
{
	complex c1, c2;
	c1.read();
	c2.read();
	complex cFin = c1 + c2;
	cFin.display();
	return 0; 
}
