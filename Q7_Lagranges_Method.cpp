#include<iostream>

using namespace std;

int main(){
  int arr[2][4] = { 7, 8, 9, 10, 3, 1, 1, 9 };
  float ans = 0, val = 1, x = 9.5;
	for(int i=0; i<4; i++){
		float val = 1;
		for(int j =0; j<4; j++)
			if( i!= j)	val *= (x - arr[0][j])/(arr[0][i] - arr[0][j]);
		val *= arr[1][i];
		ans += val;
	}
	cout<<ans;
	return 0;
}
