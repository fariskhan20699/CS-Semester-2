#include <iostream>
#include <vector>
using namespace std;
int main(){

    vector<int> vec;
    cout<<"Size = "<<vec.size()<<endl;
    vec.push_back(35);
    vec.push_back(45);
    vec.push_back(55);

    cout<<"After Push back Size = "<<vec.size()<<endl;
    vec.pop_back();
    cout<<"After pop back Size = "<<vec.size()<<endl;

//   for(int val : vec){
//     cout<<val<<endl;
//   }
  cout<<vec.front()<<endl;
  cout<<vec.at(1)<<endl;
return 0;
}
