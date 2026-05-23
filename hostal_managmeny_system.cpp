#include<iostream>
using namespace std;

class HostelManagement{
private:
int roomNo[100];
string name[100];
string city[100];
long long mobile[100];
int fees[100];
int total=0;

public:

void addStudent(){
int choice;

cout<<"\nHow many students you want to add: ";
cin>>choice;

for(int i=total;i<total+choice;i++){

cout<<"\nEnter Data of Student "<<i+1<<endl;

cout<<"Room Number: ";
cin>>roomNo[i];

cin.ignore();

cout<<"Student Name: ";
getline(cin,name[i]);

cout<<"City: ";
getline(cin,city[i]);

cout<<"Mobile Number: ";
cin>>mobile[i];

cout<<"Hostel Fees: ";
cin>>fees[i];
}

total=total+choice;

cout<<"\nStudent Record Added Successfully!\n";
}

void showStudents(){

if(total==0){
cout<<"\nNo Record Found!\n";
}
else{

for(int i=0;i<total;i++){

cout<<"\n========== Student "<<i+1<<" =========="<<endl;

cout<<"Room Number : "<<roomNo[i]<<endl;
cout<<"Name : "<<name[i]<<endl;
cout<<"City : "<<city[i]<<endl;
cout<<"Mobile No : "<<mobile[i]<<endl;
cout<<"Fees : "<<fees[i]<<endl;
}
}
}

void searchStudent(){

int room;

cout<<"\nEnter Room Number to Search: ";
cin>>room;

bool found=false;

for(int i=0;i<total;i++){

if(room==roomNo[i]){

cout<<"\nStudent Found!\n";

cout<<"Room Number : "<<roomNo[i]<<endl;
cout<<"Name : "<<name[i]<<endl;
cout<<"City : "<<city[i]<<endl;
cout<<"Mobile No : "<<mobile[i]<<endl;
cout<<"Fees : "<<fees[i]<<endl;

found=true;
}
}

if(!found){
cout<<"\nStudent Not Found!\n";
}
}

void updateStudent(){

int room;

cout<<"\nEnter Room Number to Update: ";
cin>>room;

bool found=false;

for(int i=0;i<total;i++){

if(room==roomNo[i]){

cin.ignore();

cout<<"\nEnter New Name: ";
getline(cin,name[i]);

cout<<"Enter New City: ";
getline(cin,city[i]);

cout<<"Enter New Mobile Number: ";
cin>>mobile[i];

cout<<"Enter New Fees: ";
cin>>fees[i];

cout<<"\nRecord Updated Successfully!\n";

found=true;
}
}

if(!found){
cout<<"\nStudent Not Found!\n";
}
}

void deleteStudent(){

int room;

cout<<"\nEnter Room Number to Delete: ";
cin>>room;

bool found=false;

for(int i=0;i<total;i++){

if(room==roomNo[i]){

for(int j=i;j<total-1;j++){

roomNo[j]=roomNo[j+1];
name[j]=name[j+1];
city[j]=city[j+1];
mobile[j]=mobile[j+1];
fees[j]=fees[j+1];
}

total--;

cout<<"\nRecord Deleted Successfully!\n";

found=true;
break;
}
}

if(!found){
cout<<"\nStudent Not Found!\n";
}
}
};

int main(){

HostelManagement h;

int choice;

while(true){

cout<<"\n=========== Hostel Management System ===========";
cout<<"\n1.Add Student";
cout<<"\n2.Show All Students";
cout<<"\n3.Search Student";
cout<<"\n4.Update Student";
cout<<"\n5.Delete Student";
cout<<"\n6.Exit";

cout<<"\n\nEnter Your Choice: ";
cin>>choice;

switch(choice){

case 1:
h.addStudent();
break;

case 2:
h.showStudents();
break;

case 3:
h.searchStudent();
break;

case 4:
h.updateStudent();
break;

case 5:
h.deleteStudent();
break;

case 6:
cout<<"\nThank You!\n";
return 0;

default:
cout<<"\nInvalid Choice!\n";
}
}

return 0;
}