#include<iostream>
using namespace std; 
 class Student{
 	private:
 		string name;
 		int rollno;
 	public:
 		//setters..
 		void setName(string t){
 			name=t;
		 }
		 void setRoll(int r){
		 	rollno=r;
		 }
		//getters...
		 string getName(){
		 	return name;
		 }
		 int getRoll(){
		 	return rollno;
		 }
		 //comstructor....
		 Student(string t,int r){
		 	name=t;
		 	rollno=r;
		 }
		void display(){
			cout<<"Name: "<<name<<endl;
			cout<<"Roll no."<<rollno<<endl;
		}
 };
 int main(){
 	Student s1("Faris",1002);
 	s1.display();we
 	return 0;
 }
