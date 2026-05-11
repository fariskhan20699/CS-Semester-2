#include <iostream>
using namespace std;
class Book{
	protected:
		string title,author;
		int Id;
		bool isAvailable;
	public:
		Book(string t,string a,int id):title(t),author(a),Id(id){
			isAvailable=true;
		}
		void borrowBook(){
			if(isAvailable){
				isAvailable=false;
				cout<<title<<" Book borrow Succesfully\n";
			}
			else{
			cout<<title<<" Book Already borrow \n";

			}
		}
		
void returnBack(){
    if(!isAvailable){
        isAvailable = true;
        cout<<title<<" Book Return Successfully\n";
    }
    else{
        cout<<" Book was not borrowed\n";
    }
}
		virtual void display()=0;//pure virtual func...
		virtual float fineCalculate(int dayLate)=0;//pure virtual func..
	//destructor...
	virtual ~Book(){}
};
//first derived class...
class FictionBook:public Book{
		public:
			FictionBook(string t,string a,int id):Book(t,a,id){
			}
		//display function override...	
		void display()override{
			cout<<"=====Fiction Book====="<<endl;
			cout<<"Title      : "<<title<<endl;
			cout<<"Author     : "<<author<<endl;
			cout<<"ID         : "<<Id<<endl;
			cout<<"======================"<<endl<<endl;
		}
		//fine function override...
		float fineCalculate(int dayLate)override{
			return dayLate*10;
		}
};
//second derived class...
class AcademicBook:public Book{
		public:
			AcademicBook(string t,string a,int id):Book(t,a,id){}
		//display function override...	
		void display()override{
			cout<<"====Academic  Book====" << endl;
			cout<<"Title      : "<<title<<endl;
			cout<<"Author     : "<<author<<endl;
			cout<<"ID         : "<<Id<<endl;
			cout<<"======================"<<endl<<endl;
		}
		//fine function override...
		float fineCalculate(int dayLate)override{
			return dayLate*20;
		}
};
//third derived class...
class ReferenceBook:public Book{
		public:
			ReferenceBook(string t,string a,int id):Book(t,a,id){}
		//display function override...
		void display()override{
			cout<<"====Reference Book===="<<endl;
			cout<<"Title      : " <<title<<endl;
			cout<<"Author     : " <<author<<endl;
			cout<<"ID         : " <<Id<<endl;
			cout<< "======================"<<endl<<endl;
		}
		//fine function override...
		float fineCalculate(int dayLate)override{
			return dayLate*30;
		}
};

int main(){
	//first derived class....
	Book* b=new FictionBook("Harry Potter","J.K Rowlling",1001);
	b->display();
	//second derived class...
	Book*b1=new AcademicBook("DataStructure","Mark allen",1002);
	b1->display();
	cout<<"Fine Amount: "<<b1->fineCalculate(10)<<endl;
	//third derived class...
	Book*b2=new ReferenceBook("Encyclopedia","Oxford",1003);
	b2->display();
	b2->borrowBook();
	cout<<endl;
	b2->returnBack();
	
	delete b;
	delete b1;
	delete b2;
	return 0;
}
