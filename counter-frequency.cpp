#include <iostream>
using namespace std;

int main() {
  int n;
  int target;
  int counter = 0;
  bool found =false;
  cout<<"Enter the Number : ";
  cin>>n;

  int arr[n];
  for(int i=0; i<n; i++){
    cout<<"Enter Array Value "<<(i+1)<<" : ";
    cin>>arr[i];
  }

    cout<<"\nEnter the Target : ";
    cin>>target;

   for(int i=0; i<n; i++){
    if(target == arr[i]){
        counter++;
        found =true;
    }
  }
    cout<<"\nTarget counter Found : "<<counter;

  if(found == false){
        cout<<"Target Not Found!!!"<<endl;
    }
  return 0;
}
