#include<iostream>

using namespace std;

void transform(float arr[4][5], int src, int dest, float factor){
  for(int i=0; i<5; i++)
    arr[dest][i] = arr[dest][i]+arr[src][i]*factor;
}

int main(){
  float arr[4][5] = {10, -7, 3, 5, 6,
    -6, 8, -1, -4, 5,
    3, 1, 4, 11, 2,
    5, -9, -2, 4, 7};
  transform(arr, 0, 1, -arr[1][0] / arr[0][0]);
  transform(arr, 0, 2, -arr[2][0] / arr[0][0]);
  transform(arr, 0, 3, -arr[3][0] / arr[0][0]);
  transform(arr, 1, 2, -arr[2][1] / arr[1][1]);
  transform(arr, 1, 3, -arr[3][1] / arr[1][1]);
  transform(arr, 2, 3, -arr[3][2] / arr[2][2]);


  for(int i=0; i<4; i++){
    for(int j=0; j<5; j++)
      cout<<arr[i][j]<< " ";
    cout<<endl;
  }
  float fin[4];
  for(int i=3; i>=0; i--){
    cout<<"x"<<i+1<<":";
    float ans = arr[i][4];
    for(int j=0; j<4; j++){
      if(j != i)
        ans -= arr[i][j]*fin[j];
    }
    ans /= arr[i][i];
    fin[i] = ans;
    cout<<ans<<endl;
  }
  return 0;
}
