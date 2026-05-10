  #include <iostream>
using namespace std;
class Person{
	protected:
		string name;
		int age;
	public:
		Person(string n,int a){
			name=n;
			age=a;
		}
		//setters...
		void setName(string n){
			name=n;
		}
		void setAge(int a){
			age=a;
		}
		//accesors...
		string getName(){
			return name;
		}
		int getAge(){
			return age;
		}
		void display(){
			cout<<"======Person Information====="<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Age: "<<age<<endl;
		}
};
//inherite the person class...
class Employee:public Person{
	protected:
		string department;
		int empId;
	public:
		Employee(string n,int a,int id,string d):Person(n,a){
			empId=id;
			department=d;
		}
		//mutators...
		void setID(int id){
			empId=id;
		}
		void setDept(string d){
			department=d;
		}
		//accesors...
		int getID(){
			return empId;
		}
		string getDept(){
			return department;
		}
		void empDisplay(){
			display();
			cout<<"Employee ID: "<<empId<<endl;
			cout<<"Department: "<<department<<endl;
		}
};
//inherite the class employee...
class Faculty:public Employee{
	private:
		string sub_spl;
		int totalCourse;
	public:
		Faculty(string n,int a,int id,string d,int tc,string s):Employee(n,a,id,d){
			sub_spl=s;
			totalCourse=tc;
		}
		//setters....
		void setSubSpecail(string s){
			sub_spl=s;
		}
		void setTotal(int tc){
			totalCourse=tc;
		}
		//getters...
		string getSubSpecial(){
			return sub_spl;
		}
		int getTotal(){
			return totalCourse;
		}
		//display func...
		void facultyDisplay(){
			empDisplay();
			cout<<"Subject Specialization: "<<sub_spl<<endl;
			cout<<"Total Courses: "<<totalCourse<<endl;
			cout<<"------------------------------"<<endl;
		}
};

int main(){
	//constrct the const of faculity class an slow display func...
	Faculty f1("Abdul Sammad",23,1001,"Computer Science",4,"C++");
	f1.facultyDisplay();
	return 0;
}
