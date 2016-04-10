#include<iostream>

using namespace std;

float f(float x){
	return x*x*x - 3*x + 1;
}

float f1(float x){
	return 3*x*x - 3;
}

int main(){
	float val = 0, tmp = 10;
	while(1){
		tmp = val - f(val)/f1(val);
		if(tmp == val)	break;
		val = tmp;
	}
	cout<<val;
	return 0;
}
