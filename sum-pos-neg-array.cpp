#include <iostream>
using namespace std;

int main() {
  int n;
  int posSum = 0;
  int negSum = 0;
  cout<<"Enter the Number : ";
  cin>>n;

  int arr[n];
  for(int i=0; i<n; i++){
    cout<<"Enter Array Value "<<(i+1)<<" : ";
    cin>>arr[i];
  }

   for(int i=0; i<n; i++){
    if(arr[i] > 0){
         posSum+=arr[i];
    }

    else if(arr[i] < 0){
        negSum+=arr[i];
    }
  }
     cout<<"Positive Sum: "<<posSum<<endl;
     cout<<"Negative Sum: "<<negSum<<endl;

  return 0;
}
