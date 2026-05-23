#include <iostream>
using namespace std;
class HomeDecor{
	protected:
		string item,material;
		int size;
	public:
		HomeDecor(string i,string m,int s):item(i),material(m),size(s){}
		
	//pure virtual function...
	virtual float calculatePrice()=0;
	virtual void display()=0;
};
//1st derived class...
class WallDecor:public HomeDecor{
	public:
		WallDecor(string i,string m,int s):HomeDecor(i,m,s){}
		
		//calculate function override...
		float calculatePrice() override{
			double price;
			if(material=="wood"){
				return size*120;
			}
			else if(material=="plastic"){
				return size*80;
			}
			else if(material=="metal"){
				return size*150;	
			}
			else if(material=="fibric"){
				return size*100;
			}
			return 0;
		}
		void display()override{
			cout<<"--------=Wall Decor---------"<<endl;
			cout<<"Item Name: "<<item<<endl;
			cout<<"Material: "<<material<<endl;
			cout<<"Size: "<<size<<" ft "<<endl;
			cout<<"Price Rs: "<<calculatePrice()<<endl;
			cout<<"-----------------------------"<<endl;
		}
};
//2nd derived class
class LightDecor:public HomeDecor{
	public:
		LightDecor(string i,string m,int s):HomeDecor(i,m,s){}
		//calculate function override...
		float calculatePrice()override{
			double price;
			if(material=="wood"){
				return size*140;
			}
			else if(material=="plastic"){
				return size*90;
			}
			else if(material=="metal"){
				return size*170;	
			}
			else if(material=="fibric"){
				return size*130;
			}
			return 0;
		}
		//display function override...
		void display()override{
			cout<<"---------Light Decor---------"<<endl;
			cout<<"Item Name: "<<item<<endl;
			cout<<"Material: "<<material<<endl;
			cout<<"Size: "<<size<<" ft "<<endl;
			cout<<"Price Rs: "<<calculatePrice()<<endl;
			cout<<"-----------------------------"<<endl;
		}
};
//3rd derived classs
class FurnitureDecor:public HomeDecor{
	public:
		FurnitureDecor(string i,string m,int s):HomeDecor(i,m,s){}
		//calculate function override...
		float calculatePrice()override{
			double price;
			if(material=="wood"){
				return size*240;
			}
			else if(material=="plastic"){
				return size*140;
			}
			else if(material=="metal"){
				return size*190;	
			}
			else if(material=="fibric"){
				return size*140;
			}
			return 0;
		}
		//display function override...
		void display()override{
			cout<<"-------Furniture Decor-------"<<endl;
			cout<<"Item Name: "<<item<<endl;
			cout<<"Material: "<<material<<endl;
			cout<<"Size: "<<size<<" ft "<<endl;
			cout<<"Price Rs: "<<calculatePrice()<<endl;
			cout<<"-----------------------------"<<endl;
		}
};

int main(){
	HomeDecor*Hd=new WallDecor("Painting","wood",12);
	Hd->display();
	
	HomeDecor*Hd1=new LightDecor("Lamp","metal",9);
	Hd1->display();
	
	HomeDecor*Hd2=new FurnitureDecor("Bookshelf","wood",14);
	Hd2->display();

delete Hd;
delete Hd1;
delete Hd2;
	return 0;
}
