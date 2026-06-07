#include <iostream>
#include <fstream>
using namespace std;

class User
{
public:
    virtual bool login() = 0;
};

class Admin : public User
{
public:
    bool login()
    {
        string username, password;

        cout<<"\n*********** ADMIN LOGIN ************\n";

        cout<<"Enter Username: ";
        cin>>username;

        cout<<"Enter Password: ";
        cin>>password;

        if(username == "admin" && password == "1234")
        {
            cout<<"\nLogin Successful!\n";
            return true;
        }

        cout<<"\nInvalid Username or Password!\n";
        return false;
    }
};

class Restaurant
{
protected:

    string foodName[5] ={"Burger","Pizza","Biryani","Fries","Sandwich"};

    int foodPrice[5] ={500,1200,350,250,300};

    int quantity[5] = {0,0,0,0,0};

    int totalBill = 0;

    float tax = 0.05;
    float discount = 0.10;

public:

    void showMenu()
    {
        cout<<"\n*********** RESTAURANT MENU ************\n";

        for(int i=0; i<5; i++)
        {
            cout<<i + 1<<". "<<foodName[i]<<" - Rs. "<<foodPrice[i]<<endl;
        }
    }

    void takeOrder()
    {
        int choice,qty;
        char more;
        do
        {
            showMenu();

            cout<<"\nEnter Food Number: ";
            cin>>choice;

            if(choice>=1 && choice<=5)
            {
                cout<<"Enter Quantity: ";
                cin>>qty;
                quantity[choice - 1]+=qty;

                totalBill+=foodPrice[choice-1]*qty;

                cout<<"Item Added Successfully!\n";
            }
            else
            {
                cout<<"Invalid Choice!\n";
            }

            cout<<"\nOrder More? (y/n): ";
            cin>>more;
        }
        while(more=='y' || more=='Y');
    }
};

class DeliveryService : public Restaurant
{
protected:
    string deliveryChoice;

public:

    void deliverySystem()
    {
        cout<<"\nDelivery Required? (yes/no): ";
        cin>>deliveryChoice;
    }
};

class PaymentService : public DeliveryService
{
protected:
    string paymentMethod;

public:

    void paymentSystem()
    {
        cout<<"\nSelect Payment Method (cash/card): ";
        cin>>paymentMethod;
    }

    void generateBill()
    {
        float gstAmount;
        float discountAmount;
        float finalBill;

        cout<<"\n************** RECEIPT ****************\n";

        for(int i=0; i<5; i++)
        {
            if(quantity[i]>0)
            {
                cout<<foodName[i]<<" x "<<quantity[i]<<" = Rs. "<<quantity[i]*foodPrice[i]<<endl;
            }
        }

        gstAmount =totalBill * tax;
        discountAmount =totalBill * discount;
        finalBill =totalBill+ gstAmount- discountAmount;

        cout<<"\n--------------------------------";
        cout<<"\nTotal Bill: Rs. " << totalBill;
        cout<<"\nGST (5%): Rs. " << gstAmount;
        cout<<"\nDiscount (10%): Rs. " << discountAmount;
        cout<<"\nFinal Bill: Rs. " << finalBill;
        cout<<"\n--------------------------------";

        if(deliveryChoice == "yes")
        {
            cout << "\nDelivery Service: Enabled";
        }
        else
        {
            cout << "\nDine-In Service";
        }

        cout << "\nPayment Method: " << paymentMethod;
        cout << "\n================================\n";

        ofstream file("Receipt.txt");

        file << "******** RESTAURANT RECEIPT *********\n";

        for(int i= 0; i< 5; i++)
        {
            if(quantity[i] > 0)
            {
                file<<foodName[i]<<" x "<<quantity[i]<<" = Rs. "<<quantity[i]*foodPrice[i]<<endl;
            }
        }

        file<<"\nTotal Bill: Rs. "<<totalBill;
        file<<"\nGST: Rs. "<<gstAmount;
        file<<"\nDiscount: Rs. "<<discountAmount;
        file<<"\nFinal Bill: Rs. "<<finalBill;
        file<<"\nPayment Method: "<<paymentMethod;

        file.close();

        cout<<"\nReceipt Saved Successfully!\n";
    }
};

int main()
{
    PaymentService restaurant;

    User* user;

    user= new Admin();

    if(!user->login())
    {
        delete user;
        return 0;
    }

    int choice;

    while(true)
    {
        cout<<"\n******* RESTAURANT MANAGEMENT SYSTEM ******\n";

        cout<<"1. Show Menu\n";
        cout<<"2. Delivery Option\n";
        cout<<"3. Payment Method\n";
        cout<<"4. Order Food\n";
        cout<<"5. Generate Bill\n";
        cout<<"6. Exit\n";

        cout<<"Enter Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                restaurant.showMenu();
                break;

            case 2:
                restaurant.deliverySystem();
                break;

            case 3:
                restaurant.paymentSystem();
                break;

            case 4:
                restaurant.takeOrder();
                break;

            case 5:
                restaurant.generateBill();
                break;

            case 6:
                cout<<"\nThank You!\n";
                delete user;
                return 0;

            default:
                cout<<"\nInvalid Choice!\n";
        }
    }

    return 0;
}
