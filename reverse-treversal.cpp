#include <iostream>
using namespace std;

int main() {
  int n;
  int target;
  bool found = false;
  cout<<"Enter the Number : ";
  cin>>n;

  int arr[n];
  for(int i=0; i<n; i++){
    cout<<"Enter Array Value "<<(i+1)<<" : ";
    cin>>arr[i];
  }

   for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
    cout<<endl;
   for(int i = n-1; i>=0; i--){
    cout<<arr[i]<<" ";
  }
  return 0;
}
