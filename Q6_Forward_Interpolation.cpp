#include<iostream>
#include<vector>

using namespace std;

vector<float> x, y;
int n = 0;
float ans = 0, p;

float factorial(int n){
	if(n <= 1)	return 1;
	return factorial(n-1) * n;
}

void forwardInterpolate(int k){
	if(k == n)	return;
	float prod = y[0];
	for(int i=0; i<k; i++)
		prod *= p-i;
	prod /= factorial(k);
	ans += prod;
	for(int i=0; i<n-k; i++)
		y[i] = y[i+1] - y[i];
	forwardInterpolate(k+1);
}

int main(){
	cout<<"Enter the nos of element: ";
	cin>>n;
	x.resize(n);
	y.resize(n);
	for(int i=0; i<n; i++)
		cin>>x[i]>>y[i];
	float reqVal;
	cout<<"Enter the postiion: ";
	cin>>reqVal;
	p = (reqVal - x[0])/(x[1] - x[0]);
	forwardInterpolate(0);
	cout<<"Answer is :"<<ans;
	return 0;
}
