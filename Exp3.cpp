#include<iostream>
#include<vector>
#define limit 10000001
#pragma optimize( "", off )

using namespace std;

class vect
{
	vector<float> component;
	int nos;
public:
	vect (int n)
	{
		nos = n;
		component.resize (n, 0);
	}
	void disp ()
	{
		bool key = false;
		for (int i = 0; i < nos; i++)
			if (component[i] != 0)
			{
				if (key && component[i] > 0)		cout << " + ";
				cout << component[i] << "*X" << i;
				key = true;
			}
	}
	void modify (int idx, int val)
	{
		component[idx] = val;
	}
	vect operator + (vect obj)
	{
		vect tmp = *this;
		if (nos != obj.nos)
			cout << "INVALID OPERATION";
		else
			for (int i = 0; i < nos; i++)
				tmp.component[i] += obj.component[i];
		return tmp;
	}
};

int main ()
{
	/*ios::sync_with_stdio (0);
	ios_base::sync_with_stdio (0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		long long int n;
		cin >> n;
		cout << 11 - ((n % 11)*8) % 11<<endl;
	}*/
	vect v1 (3);
	v1.modify (0, 1);
	v1.modify (2, 5);
	v1.modify (1, 3);

	vect v2 (3);
	v2.modify (0, 1);
	v2.modify (2, 5);
	v2.modify (1, 3);
	//v1.add (v2);
	v1 = v1 + v2;
	v1.disp ();
	return 0;
}
