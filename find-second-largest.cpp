#include <iostream>
using namespace std;

int main() {
  int n;
  cout<<"Enter the Number : ";
  cin>>n;

  int arr[n];
  for(int i=0; i<n; i++){
    cout<<"Enter Array Value "<<(i+1)<<" : ";
    cin>>arr[i];
  }

  int largest = arr[0];
  int secondLargest = arr[1];

  for(int i=0; i<n; i++){
     if(arr[i]>largest){
        secondLargest = largest;
        largest=arr[i];        
     }

     else if(arr[i]>secondLargest){
        secondLargest =arr[i];         
     }
  }
  cout<<"Largest: "<<largest<<endl;
  cout<<"Second Largest: "<<secondLargest<<endl;

  return 0;
}
