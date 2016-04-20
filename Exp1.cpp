#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

class Employee {
	int Eno, Basic;
	char Ename[20];
	
	class gross {
		float DA, HRA, TA;
	public :
		void calc(float val)
		{
			DA = 0.5 * val;
			HRA = 0.3*val;
			TA = 800;
		}
		float net()
		{
			return DA + HRA + TA;
		}
		void display()
		{
			cout << "DA:" << DA << "\nHRA:" << HRA << "\nTA:" << TA<<endl;
		}
	}grossObj;

	class deduct {
		float PF, IT;
	public:
		void calc(float val, gross obj)
		{
			PF = 0.05*val;
			if (obj.net() - PF + val > 1100000)
				IT = 0.3*(obj.net() - PF + val);
			else
				IT = 0;
		}
		float net()
		{
			return PF + IT;
		}
		void display()
		{
			cout << "PF:" << PF << "\nIT:" << IT << endl;
		}
	}deductObj;
public:
	Employee()
	{
		cout << "Enter the Eno: ";
		cin >> Eno;
		cout << "Enter the Ename : ";
		cin >> Ename;
		cout << "Enter the Basic : ";
		cin >> Basic;
		grossObj.calc(Basic);
		deductObj.calc(Basic, grossObj);
	}
	void display() 
	{
		cout << "Net salary of "<<Ename<<" ("<<Eno<<") "<<"is : " << Basic + grossObj.net() - deductObj.net()<<endl;
	}
};

int main()
{
	Employee empObj;
	empObj.display();
	return 0;
}
