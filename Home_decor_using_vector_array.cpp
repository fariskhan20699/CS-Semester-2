// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
class HomeDecor{
    protected:
        string item,material;
        int size;
    public:
        HomeDecor(string i,string m,int s):item(i),material(m),
        size(s){}
    //pure virtual function....
    virtual float calculate()=0;
    virtual void display()=0;
    virtual~HomeDecor(){}
};
class WallDecor:public HomeDecor{
    public:
    WallDecor(string i,string m,int s):HomeDecor(i,m,s){}
    
    float calculate()override{
        if(material=="wood"){
            return size*110;
        }
        else if(material=="plastic"){
            return size*130;
        }
        else if(material=="metal"){
            return size*170;
        }
        else if(material=="fabric"){
            return size*140;
        }
        return 0;
    }
    void display()override{
        cout<<"========Wall Decor========"<<endl;
        cout<<"Item name: "<<item<<endl;
        cout<<"Material: "<<material<<endl;
        cout<<"Size(sq): "<<size<<endl;
        cout<<"Price Rs: "<<calculate()<<endl;
        cout<<"--------------------------"<<endl;
    }
};

class LightDecor:public HomeDecor{
    public:
    LightDecor(string i,string m,int s):HomeDecor(i,m,s){}
    
    float calculate()override{
        if(material=="wood"){
            return size*120;
        }
        else if(material=="plastic"){
            return size*110;
        }
        else if(material=="metal"){
            return size*180;
        }
        else if(material=="fabric"){
            return size*90;
        }
        return 0;
    }
    void display()override{
        cout<<"========Light Decor========"<<endl;
        cout<<"Item name: "<<item<<endl;
        cout<<"Material: "<<material<<endl;
        cout<<"Size(sq): "<<size<<endl;
        cout<<"Price Rs: "<<calculate()<<endl;
        cout<<"---------------------------"<<endl;
    }
};

class FurnitureDecor:public HomeDecor{
    public:
    FurnitureDecor(string i,string m,int s):HomeDecor(i,m,s){}
    
    float calculate()override{
        if(material=="wood"){
            return size*190;
        }
        else if(material=="plastic"){
            return size*90;
        }
        else if(material=="metal"){
            return size*220;
        }
        else if(material=="fabric"){
            return size*130;
        }
        return 0;
    }
    void display()override{
        cout<<"========Furniture Decor========"<<endl;
        cout<<"Item name: "<<item<<endl;
        cout<<"Material: "<<material<<endl;
        cout<<"Size(sq): "<<size<<endl;
        cout<<"Price Rs: "<<calculate()<<endl;
        cout<<"-------------------------------"<<endl;
    }
};
int main(){

    vector<HomeDecor*> Decor;
    Decor.push_back(new WallDecor("Painting","wood",19));
    Decor.push_back(new LightDecor("Lamp","metal",9));
    Decor.push_back(new FurnitureDecor("Bookself","fabric",29));
    
    for(auto h : Decor){
        h->display();
    }
    for(auto h : Decor){
        delete h;
    }
    Decor.clear();
    return 0;
}
