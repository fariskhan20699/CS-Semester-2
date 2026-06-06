#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;
//================================//
const int MAX_ACCOUNTS=50;
const int MAX_HISTORY=20;
const string ADMIN_USER="admin";
const string ADMIN_PASS="admin123";
//================================//
class Transaction{
public:
    string type;
    double amount;

    Transaction(){ type=""; amount=0; }

    void set(string t,double a){ type=t; amount=a; }

    void display(){
        if(type=="") return;
        cout<<"   "<<type<<" -> Rs. "<<amount<<endl;
    }
};
//================================//
class Account{
protected:
    int accountNumber;
    string holderName;
    string cnic;
    double balance;
    string accountType;
    Transaction history[MAX_HISTORY];
    int historyCount;

public:
    string password;

    Account(){
        accountNumber=0;
        holderName="";
        cnic="";
        balance=0;
        accountType="";
        historyCount=0;
        password="";
    }

  
    void setup(int num,string name,string c,double bal,string type,string pass=""){
        accountNumber=num;
        holderName=name;
        cnic=c;
        balance=bal;
        accountType=type;
        password=pass;
        historyCount=0;
        addHistory("Opening Balance",bal);
    }

    void setupLoad(int num,string name,string c,double bal,string type,string pass){
        accountNumber=num;
        holderName=name;
        cnic=c;
        balance=bal;
        accountType=type;
        password=pass;
        historyCount=0;
    }

    void addHistory(string type,double amount){
        if(historyCount<MAX_HISTORY){
            history[historyCount].set(type,amount);
            historyCount++;
        }else{
            for(int i=0;i<MAX_HISTORY-1;i++)
                history[i]=history[i+1];
            history[MAX_HISTORY-1].set(type,amount);
        }
    }

    int getAccountNumber(){ 
			return accountNumber; 
		}
    string getHolderName(){ 
			return holderName; 
		}
    string getCNIC(){
			return cnic;
		}
    double getBalance(){ 
			return balance; 
		}
    string getAccountType(){ 
			return accountType; 
		}

    void setBalance(double b){ 
			balance=b; 	
		}
    
    void setHistoryCount(int c){ 
			historyCount=c; 
		}

    void deposit(double amount){
        if(amount<=0){ 
			cout<<"[ERROR] Amount must be positive!\n"; 
				return; 
			}
        balance+=amount;
        addHistory("Deposit",amount);
        cout<<"[SUCCESS] Rs. "<<amount<<" deposited. Balance: Rs. "<<balance<<endl;
    }

    virtual void withdraw(double amount){
        if(amount<=0){ 
			cout<<"[ERROR] Amount must be positive!\n"; 
				return; 
		}
		
        if(amount>balance){ 
			cout<<"[ERROR] Insufficient Balance! Available: Rs. "<<balance<<endl; 
				return; 
		}
        balance-=amount;
        addHistory("Withdraw",amount);
        cout<<"[SUCCESS] Rs. "<<amount<<" withdrawn. Balance: Rs. "<<balance<<endl;
    }

    void showHistory(){
        cout<<"\n--- Transaction History (Acc #"<<accountNumber<<") ---\n";
        if(historyCount==0){ 
			cout<<"No transactions found.\n"; 
				return; 
		}
        for(int i=0;i<historyCount;i++) 
			history[i].display();
        cout<<"------------------------------------------\n";
    }

    void showDetails(){
        cout<<"\n====================================\n";
        cout<<"Account Number : "<<accountNumber<<endl;
        cout<<"Account Type   : "<<accountType<<endl;
        cout<<"Holder Name    : "<<holderName<<endl;
        cout<<"CNIC           : "<<cnic<<endl;
        cout<<"Balance        : Rs. "<<balance<<endl;
        cout<<"====================================\n";
    }

    void showSummary(){
        cout<<"------------------------------------\n";
        cout<<"Acc #  : "<<accountNumber<<endl;
        cout<<"Name   : "<<holderName<<endl;
        cout<<"Type   : "<<accountType<<endl;
        cout<<"Balance: Rs. "<<balance<<endl;
    }

    virtual void showTypeInfo()=0;

    void saveToFile(ofstream& file){
        file<<accountType<<"\n";
        file<<accountNumber<<"\n";
        file<<holderName<<"\n";
        file<<cnic<<"\n";
        file<<balance<<"\n";
        file<<password<<"\n";
        file<<historyCount<<"\n";
        for(int i=0;i<historyCount;i++)
            file<<history[i].type<<"|"<<history[i].amount<<"\n";
    }

    void loadHistory(ifstream& file){
        historyCount=0;
        int count;
        file>>count;
        file.ignore();
        for(int i=0;i<count;i++){
            string line;
            getline(file,line);
            int sep=line.find('|');
            history[i].type=line.substr(0,sep);
            double amt;
            stringstream ss(line.substr(sep+1));
            ss>>amt;
            history[i].amount=amt;
            historyCount++;
        }
    }

    virtual ~Account(){}
};
//================================//
class SavingsAccount:public Account{
private:
    double interestRate;
public:
    SavingsAccount():Account(){ 
		interestRate=0.05; 
		}

    void setInterestRate(double r){ 
		interestRate=r; 
		}
    double getInterestRate(){ 
		return interestRate; 
		}

    void applyInterest(){
        double interest=balance*interestRate;
        balance+=interest;
        addHistory("Interest",interest);
        cout<<"[SUCCESS] Interest Applied: Rs. "<<interest<<endl;
        cout<<"New Balance: Rs. "<<balance<<endl;
    }

    void showTypeInfo()override{
        cout<<"[Savings] Interest Rate: "<<(interestRate*100)<<"% per year\n";
    }
};
//================================//
class CurrentAccount:public Account{
private:
    double overdraftLimit;
public:
    CurrentAccount():Account(){ 
		overdraftLimit=10000;
		}

    void setOverdraftLimit(double l){ 
		overdraftLimit=l; 
		}
    double getOverdraftLimit(){ 
		return overdraftLimit; 
		}

    void withdraw(double amount)override{
        if(amount<=0){ 
			cout<<"[ERROR] Amount must be positive!\n"; 
				return; 
		}
        if((balance-amount)<-overdraftLimit){
            cout<<"[ERROR] Overdraft limit exceeded!\n";
            cout<<"[INFO]  Max withdrawable: Rs. "<<(balance+overdraftLimit)<<endl;
            return;
        }
        balance-=amount;
        addHistory("Withdraw",amount);
        
        if(balance<0)
            cout<<"[WARNING] Overdraft active! Balance: Rs. "<<balance<<endl;
        else
            cout<<"[SUCCESS] Rs. "<<amount<<" withdrawn. Balance: Rs. "<<balance<<endl;
    }

    void showTypeInfo()override{
        cout<<"[Current] Overdraft Limit: Rs. "<<overdraftLimit<<endl;
    }
};
//================================//
class Bank{
private:
    SavingsAccount savAccounts[MAX_ACCOUNTS];
    CurrentAccount curAccounts[MAX_ACCOUNTS];
    int savCount;
    int curCount;
    int nextNum;
    string filename;

    Account* findAccount(int num){
        for(int i=0;i<savCount;i++)
            if(savAccounts[i].getAccountNumber()==num) 
				return &savAccounts[i];
				
        for(int i=0;i<curCount;i++)
            if(curAccounts[i].getAccountNumber()==num) 
				return &curAccounts[i];
        return NULL;
    }

public:
    Bank(){ 
			savCount=0; 
			curCount=0; 
			nextNum=1001; 
			filename="accounts.dat"; 
			}

    //------------- AUTH -------------//
    bool adminLogin(){
        string user,pass;
        cout<<"\n=== ADMIN LOGIN ===\n";
        cout<<"Username: "; 
		cin>>user;
		
        cout<<"Password: "; 
		cin>>pass; 
		
        if(user==ADMIN_USER && pass==ADMIN_PASS){
            cout<<"[SUCCESS] Admin login successful!\n";
            return true;
        }
        cout<<"[ERROR] Invalid admin credentials!\n";
        return false;
    }

    Account* userLogin(){
        int num; 
		string pass;
		
        cout<<"\n=== USER LOGIN ===\n";
        cout<<"Account Number: "; 
		cin>>num;
		
        cout<<"Password      : "; 
		cin>>pass;
		
        Account* acc=findAccount(num);
        
        if(!acc){ cout<<"[ERROR] Account not found!\n"; 
				return NULL; 
		}
        if(acc->password!=pass){ 
			cout<<"[ERROR] Wrong password!\n"; 
				return NULL; 
		}
        cout<<"[SUCCESS] Login successful! Welcome, "<<acc->getHolderName()<<"\n";
        return acc;
    }

    //------------- CREATE -------------//
    void createAccount(){
        string name,cnic,pass;
        double deposit;
        int choice;

        cout<<"\n--- Create New Account ---\n";
        cin.ignore();
        cout<<"Name: "; 
		getline(cin,name);
        
        cout<<"CNIC: "; 
		getline(cin,cnic);
        
        cout<<"Initial Balance : Rs. "; 
		cin>>deposit;
        
        cout<<"Password: "; 
		cin>>pass;

        if(deposit<=0){ 
			cout<<"[ERROR] Balance must be positive!\n"; 
				return; 
			}

        cout<<"\n1. Savings Account\n2. Current Account\nChoice: "; 
		cin>>choice;

        if(choice==1){
            if(savCount>=MAX_ACCOUNTS){ 
				cout<<"[ERROR] Savings accounts full!\n"; 
						return; 
			}
			
            double rate;
            cout<<"Interest Rate (default 0.05): "; 
			cin>>rate;
			
            savAccounts[savCount].setup(nextNum,name,cnic,deposit,"Savings",pass);
            savAccounts[savCount].setInterestRate(rate);
            savCount++;
        }
		else if(choice==2){
            if(curCount>=MAX_ACCOUNTS){ 
				cout<<"[ERROR] Current accounts full!\n"; 
						return; 
			}
            double limit;
            
            cout<<"Overdraft Limit (Rs.): "; 
			cin>>limit;
			
            curAccounts[curCount].setup(nextNum,name,cnic,deposit,"Current",pass);
            curAccounts[curCount].setOverdraftLimit(limit);
            curCount++;
        }
		else{
			 cout<<"[ERROR] Invalid choice!\n"; 
				return; 
			}

        cout<<"[SUCCESS] Account created! Account Number: "<<nextNum<<endl;
        nextNum++;
    }

    //------------- OPERATIONS -------------//
    void depositMoney(){
        int num; 
		double amount;
		
        cout<<"\nAccount Number : "; 
		cin>>num;
		
        Account* acc=findAccount(num);
        if(!acc){ 
			cout<<"[ERROR] Account not found!\n"; 
				return; 
		}
        cout<<"Deposit Amount : Rs. "; 
		cin>>amount;
		
        acc->deposit(amount);
    }

    void withdrawMoney(){
        int num; 
		double amount;
		
        cout<<"\nAccount Number : "; 
		cin>>num;
        Account* acc=findAccount(num);
        if(!acc){ 
			cout<<"[ERROR] Account not found!\n"; 
				return;
		}
        cout<<"Withdraw Amount: Rs. "; 
		cin>>amount;
        acc->withdraw(amount);
    }

    void transferFunds(){
        int from,to; double amount;
        cout<<"\nSender Account  : "; 
		cin>>from;
		
        cout<<"Receiver Account: "; 
		cin>>to;
		
        cout<<"Amount (Rs.)    : "; 
		cin>>amount;
		
        Account* accFrom=findAccount(from);
        Account* accTo=findAccount(to);
        
        if(!accFrom||!accTo){ cout<<"[ERROR] One or both accounts not found!\n"; return; }
        double balBefore=accFrom->getBalance();
        accFrom->withdraw(amount);
       
	    if(accFrom->getBalance()<balBefore){
            accTo->deposit(amount);
            cout<<"[SUCCESS] Transfer of Rs. "<<amount<<" completed!\n";
        }
    }

    void checkBalance(){
        int num;
        cout<<"\nAccount Number: "; 
		cin>>num;
		
        Account* acc=findAccount(num);
        if(!acc){ 
		cout<<"[ERROR] Account not found!\n";
				 return;
		}
        cout<<"Balance: Rs. "<<acc->getBalance()<<endl;
        acc->showTypeInfo();
    }

    void showDetails(){
        int num;
        cout<<"\nAccount Number: "; 
		cin>>num;
        Account* acc=findAccount(num);
        if(!acc){ cout<<"[ERROR] Account not found!\n"; 
			return; 
			}
        acc->showDetails();
        acc->showTypeInfo();
    }

    void showHistory(){
        int num;
        cout<<"\nAccount Number: "; 
		cin>>num;
        cout<<"Loading";
        
        for(int i=0;i<3;i++){ 
			cout<<"."; 
			Sleep(900); }
        	cout<<endl;
        	Account* acc=findAccount(num);
        if(!acc){ 
			cout<<"[ERROR] Account not found!\n"; 
				return; 
		}
        acc->showHistory();
    }

    void showAllAccounts(){
        cout<<"\n====== All Accounts ======\n";
        if(savCount+curCount==0){ 
			cout<<"No accounts found.\n"; 
				return; 
		}
        for(int i=0;i<savCount;i++){ 
			savAccounts[i].showSummary(); 
			savAccounts[i].showTypeInfo(); 
		}
		
        for(int i=0;i<curCount;i++){ 
			curAccounts[i].showSummary(); 
			curAccounts[i].showTypeInfo(); 
		}
        cout<<"==========================\n";
        cout<<"Total accounts: "<<(savCount+curCount)<<endl;
    }

    void applyInterest(){
        int num;
        cout<<"\nSavings Account Number: "; cin>>num;
        for(int i=0;i<savCount;i++){
            if(savAccounts[i].getAccountNumber()==num){
                savAccounts[i].applyInterest();
                return;
            }
        }
        cout<<"[ERROR] Savings account not found!\n";
    }

    //------------- FILE I/O -------------//
    void saveToFile(){
        ofstream file(filename.c_str());
        if(!file){ cout<<"[ERROR] Could not save file!\n"; return; }
        file<<nextNum<<"\n";
        file<<savCount<<"\n";
        for(int i=0;i<savCount;i++){
            savAccounts[i].saveToFile(file);
            file<<savAccounts[i].getInterestRate()<<"\n";
        }
        file<<curCount<<"\n";
        for(int i=0;i<curCount;i++){
            curAccounts[i].saveToFile(file);
            file<<curAccounts[i].getOverdraftLimit()<<"\n";
        }
        file.close();
        cout<<"[INFO] Data saved successfully!\n";
    }

    void loadFromFile(){
        ifstream file(filename.c_str());
        if(!file){ cout<<"[INFO] No saved data found. Starting fresh.\n"; return; }
        file>>nextNum>>savCount;
        file.ignore();
        for(int i=0;i<savCount;i++){
            string type,name,cnic,pass;
            int num; 
			double balance;
            getline(file,type);
            file>>num; 
			file.ignore();
			
            getline(file,name);
            getline(file,cnic);
            file>>balance; 
			file.ignore();
			
            getline(file,pass);
            
            savAccounts[i].setupLoad(num,name,cnic,balance,"Savings",pass);
            savAccounts[i].loadHistory(file);
            
			double rate; 
			file>>rate; 
			file.ignore();
            savAccounts[i].setInterestRate(rate);
        }
       	 	file>>curCount; 
			file.ignore();
		
        for(int i=0;i<curCount;i++){
            string type,name,cnic,pass;
            int num; 
			double balance;
            getline(file,type);
            
            file>>num;
			file.ignore();
			
            getline(file,name);
            getline(file,cnic);
            file>>balance; 
            
			file.ignore();
            getline(file,pass);
            
            curAccounts[i].setupLoad(num,name,cnic,balance,"Current",pass);
            curAccounts[i].loadHistory(file);
            
			double limit; 
			file>>limit; 
			file.ignore();
			
            curAccounts[i].setOverdraftLimit(limit);
        }
        file.close();
        	cout<<"[INFO] "<<(savCount+curCount)<<" account(s) loaded.\n";
    }

    //------------- MENUS -------------//
    void adminMenu(){
        int choice;
        do{
            cout<<"\n========= ADMIN MENU =========\n";
            cout<<"  1. Create Account\n";
            cout<<"  2. Deposit\n";
            cout<<"  3. Withdraw\n";
            cout<<"  4. Transfer Funds\n";
            cout<<"  5. Check Balance\n";
            cout<<"  6. Account Details\n";
            cout<<"  7. Transaction History\n";
            cout<<"  8. All Accounts Summary\n";
            cout<<"  9. Apply Interest (Savings)\n";
            cout<<" 10. Save Data\n";
            cout<<"  0. Logout\n";
            cout<<"==============================\n";
            cout<<"Choice: "; 
			cin>>choice;
			
            switch(choice){
                case 1:  {
                	createAccount();
					break;
				}
                case 2: {
                	depositMoney();
					break;
				}    
                case 3: {
                	withdrawMoney();
					break;
				}  
                case 4:{
                	transferFunds(); 
					break;
				}   
                case 5:{
                	checkBalance();
					break;
				}    
                case 6:{
                	showDetails();
					break;
				}  
                case 7:{
                	showHistory(); 
					break;
				}    
                case 8:{
                	showAllAccounts();
					break;
				} 
                case 9:{
                	applyInterest();
					break;
				}   
                case 10:{
                	saveToFile();
					break;
				}
                case 0:{
                	cout<<"[INFO] Admin logged out.\n";
					break;
				} 
                default: cout<<"[ERROR] Invalid choice!\n";
            }
        }while(choice!=0);
    }

    void userMenu(Account* acc){
        int choice;
        do{
            cout<<"\n========= USER MENU =========\n";
            cout<<"  Welcome: "<<acc->getHolderName()<<"\n";
            cout<<"  Acc #  : "<<acc->getAccountNumber()<<"\n";
            cout<<"-----------------------------\n";
            cout<<"  1. Withdraw\n";
            cout<<"  2. Check Balance\n";
            cout<<"  3. Transaction History\n";
            cout<<"  4. Transfer Funds\n";
            cout<<"  5. Account Details\n";
            cout<<"  0. Logout\n";
            cout<<"=============================\n";
            cout<<"Choice: "; 
			cin>>choice;
			
            switch(choice){
                case 1:{
                    double amt;
                    cout<<"Withdraw Amount: Rs. "; cin>>amt;
                    acc->withdraw(amt);
                    break;
                }
                case 2:{
                    cout<<"Balance: Rs. "<<acc->getBalance()<<endl;
                    acc->showTypeInfo();
                    break;
                }
                case 3:{
                    acc->showHistory();
                    break;
                }
                case 4:{
                    int to; double amt;
                    cout<<"Receiver Account Number: "; cin>>to;
                    cout<<"Amount: Rs. "; cin>>amt;
                    Account* receiver=findAccount(to);
                    if(!receiver){ 
						cout<<"[ERROR] Receiver account not found!\n"; 
						break; 
					}
                    double balBefore=acc->getBalance();
                    acc->withdraw(amt);
                    if(acc->getBalance()<balBefore){
                        receiver->deposit(amt);
                        cout<<"[SUCCESS] Transfer to "<<receiver->getHolderName()<<" successful!\n";
                    }
                    break;
                }
                case 5:{
                    acc->showDetails();
                    acc->showTypeInfo();
                    break;
                }
                case 0: cout<<"[INFO] Logged out.\n"; 
					break;
                default: cout<<"[ERROR] Invalid choice!\n";
            }
        }while(choice!=0);
    }
};
//================================//
int main(){
    Bank bank;
    bank.loadFromFile();

    int choice;
    cout<<"\n";
    cout<<" ================================\n";
    cout<<"   Welcome to Pak National Bank  \n";
    cout<<" ================================\n";

    while(true){
        cout<<"\n======= MAIN MENU =======\n";
        cout<<"  1. Admin Login\n";
        cout<<"  2. User Login\n";
        cout<<"  3. Exit\n";
        cout<<"=========================\n";
        cout<<"Choice: "; 
		cin>>choice;
		
        switch(choice){
            case 1:{
                if(bank.adminLogin())
                    bank.adminMenu();
                break;
            }
            case 2:{
                Account* user=bank.userLogin();
                if(user!=NULL)
                    bank.userMenu(user);
                break;
            }
            case 3:{
                bank.saveToFile();
                cout<<"Thank you for using Pak National Bank.Have a Good Day!\n";
                return 0;
            }
            default:
                cout<<"[ERROR] Invalid choice!\n";
        }
    }
    return 0;
}
