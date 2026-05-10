#include <iostream>
using namespace std;
class Order{
	private:
		string name,status;
		int quantity;
	public:
	void setName(string n){
		name=n;
	}
	void setStatus(string s){
		status=s;
	}
	void setQnty(int qnty){
		quantity=qnty;
	}
	
	string getName(){
		return name;
	}
	string getStatus(){
		return status;
	}
	int getQnty(){
		return quantity;
	}
};

int main(){
	int n,ch;
	cout<<"\nHow many order you Have: ";
	cin>>n;
	Order*od=new Order[n];
	while(true){
	menu:
	cout<<"========MENU========"<<endl;
	cout<<"1-Entering the Order"<<endl;
	cout<<"2-Update the Order"<<endl;
	cout<<"3-Display record"<<endl;
	cout<<"4- Exit the Program"<<endl;
	cout<<"Enter Choice: ";
	cin>>ch;
	
		switch(ch){
			case 1:{
				string na,st;
				int qnty;
			//input loop...
			for(int i=0;i<n;i++){
				cout<<"\nEnter the Customar Name: ";
				cin>>na;
				
				cout<<"Enter the Order Quantity: ";
				cin>>qnty;
				
				cout<<"Enter the Order Status: ";
				cin>>st;
				
				od[i].setName(na);
				od[i].setQnty(qnty);
				od[i].setStatus(st);
				
			}
				break;
			}
				
			case 2:{
				int index,qnty;
				string st;
				again:
				cout<<"Enter the Order Index Number: ";
				cin>>index;
				if(index>=0&&index<n){
					cout<<"========Updating Data======="<<endl;
					cout<<"Customar name "<<od[index].getName()<<endl;
					
					cout<<"Enter New Quantity: ";
					cin>>qnty;
					
					cout<<"Enter new Status: ";
					cin>>st;
					
					od[index].setQnty(qnty);
					od[index].setStatus(st);
					
					cout<<"Record Updated Sucessfully"<<endl<<endl;
				}
				else{
					cout<<"Invalid Index Number Enter correct: "<<endl<<endl;
					goto again;
				}
				break;
			}
				case 3:{
					cout<<"======Display Order Details======"<<endl;
				for(int i=0;i<n;i++){
					cout<<"Name: "<<od[i].getName()<<endl;
					cout<<"Status: "<<od[i].getStatus()<<endl;
					cout<<"Quantity: "<<od[i].getQnty()<<endl;
					cout<<"----------------------------------"<<endl;
				}
					break;
			}
			case 4:{
				delete []od;
				return 0;
			}
				default:
					cout<<"You enter invalid input..."<<endl<<endl;	
					goto menu;
		}
	}

	return 0;
}
