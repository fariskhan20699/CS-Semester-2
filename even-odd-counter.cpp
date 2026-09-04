#include <iostream>
using namespace std;

int main() {
  int n;
  int even = 0;
  int odd = 0;
  cout<<"Enter the Number : ";
  cin>>n;

  int arr[n];
  for(int i=0; i<n; i++){
    cout<<"Enter Array Value "<<(i+1)<<" : ";
    cin>>arr[i];
  }

   for(int i=0; i<n; i++){
     if(arr[i]%2==0){
        even++;
     }
     else{
        odd++;
     }
  }
  cout<<"Even : "<<even;
  cout<<"\nOdd: "<<odd;
  return 0;
}
