#include<iostream>
#include<cmath>

using namespace std;

int main(){
  float a, b;
  cout<<"Enter the limits : ";
  cin>>a>>b;
  float h = 0.01;
  float counter = a + h;
  float sum = 0;
  while(counter < b){
    sum += 2*log(counter);
    counter += h;
  }
  sum += log(a);
  sum += log(b);
  cout<<"Answer is : "<<sum*h/2;
  return 0;
}


