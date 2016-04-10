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
  int i = 1;
  while(counter < b){
    if( i%2 == 0)
      sum += 2*log(counter);
    else 
      sum += 4*log(counter);
    counter += h;
    i++;
  }
  sum += log(a);
  sum += log(b);
  cout<<"Answer is : "<<sum*h/3;
  return 0;
}


