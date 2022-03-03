#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


class Customer{
	
	private:
		string name, email,address,number;
		string ID;
		string gender;
		string Date_Of_Birth;
		string Country;
		string City;
		string street;
		int age;
	public:
		Customer()
		{}
		Customer(string name, string gender, string email,string Country,string City,string street,string Date_Of_Birth, string number, int age, string ID)
		{
			this->name=name;
			this->gender=gender;
			this->email=email;
			this->Country=Country;
			this->City=City;
			this->street=street;
			this->Date_Of_Birth=Date_Of_Birth;
			this->number=number;
			this->age = age;
			this->ID = ID;
		}
		bool setname(string N){
			bool correct = true;
			int length = N.length();
			for(int i = 0; i<length; i++){
				if(isdigit(N[i])){
					correct = false;
				}
			}	
			name = N;
			return correct;
			
		}
		
		bool setID(string I){
			bool correct = true;
			int count = I.length();
			if(count == 14){
				correct = true;
				ID = I;
			}
			else{
				correct = false;
			}
			return correct;
		}			
			
		bool setemail(string e){
			bool correct = true;
			if ( e.find("@gmail.com") != std::string::npos ||  e.find("@hotmail.com") != std::string::npos ||  e.find("@outlook.com") != std::string::npos) {
				correct = true;
				email = e;
			}
			else{
				correct = false;
			}
			
			return correct;	
		}
		
		bool set_age(int a){
			bool correct = false;
			if(a >= 21){
				correct = true;
				age = a;
			}	
			else{
				cout << endl;
				cout << "We are very Sorry...But You have to be 21 years or above to be able to open an account" << endl;
				exit(0);
			}	
				
			return correct;
			
		}
		
		
		bool set_Date_Of_Birth(int d, int m, int y){
	
			bool valid = false;
			string space = " ";
			
			if(d>0 && d<=31){
				if(m > 0 && m <=12){
					if( y <= 2000 && y>=1900){
						valid = true;
						Date_Of_Birth = to_string(d) + space + to_string(m) + space + to_string(y);
					}
				}	
			}
			
			return valid;
			
		}
		
		bool set_Country(string g){
			bool correct = true;
			int length = g.length();
			for(int i = 0; i<length; i++){
				if(isdigit(g[i])){
					correct = false;
				}
			}	
			Country = g;
			return correct;
			
		}		
		
		void set_city(string c){
			City = c;
		}
		
		void set_street(string s){
			street = s;
		}
		
		bool setnumber(string s){
			bool correct = true;
			int length = s.length();
			for(int i = 0; i<length; i++){
				if(!isdigit(s[i])){
					correct = false;
				}
			}
			number = s;	
			return correct;
			
		}

		bool set_gender( string G){
			if (G=="F" || G == "M" || G == "m" || G == "f"){
				gender = G;
				return true;
			}
			else{
				return false;
			}
		}
		
		void getData()
		{
			bool valid_name = false;
			bool valid_governorate = false;
			bool valid_phone = false;
			bool valid_age = false;
			bool valid_gender = false;
			bool valid_email = false;
			bool valid_ID = false;
			bool valid_date = false;
			int d;
			int m;
			int y;
			
			
			cout << setw(90) << "*Personal Info*" << endl;
			cout << " " << endl;
			do{
				cin.ignore();
				cout<<"* Full name: "<<flush;
				getline(cin, name);
				if(setname(name)){
					valid_name = true;
				}
			}while(!valid_name);
			
			cout << "___________________________________________________" << endl;
			cout << endl;
			
			do{		
				cout<<"* Governorate: "<<flush;
				getline(cin, Country);
				if(set_Country(Country)){
					valid_governorate = true;
				}
			}while(!valid_governorate);
			
			cout << "___________________________________________________" << endl;
			cout << endl;
					
			cout<<"* City: "<<flush;
			getline(cin, City);
			
			cout << "___________________________________________________" << endl;
			cout << endl;


			cout<<"* Street Name: "<<flush;
			getline(cin, street);
			
			cout << "___________________________________________________" << endl;
			cout << endl;
			
			do{
				cout << "* National ID Number: " << flush;
				getline(cin, ID);
				if(setID(ID)){
					valid_ID = true;
				}
			}while(!valid_ID);
			cout << "___________________________________________________" << endl;
			cout << endl; 		
			
			do{
				cout<<"* E-mail (eg..example@gmail.com): "<<flush;
				getline(cin, email);
				if(setemail(email)){
					valid_email = true;
				}
				
			}while(!valid_email);		
			
			cout << "___________________________________________________" << endl;
			cout << endl;
			
			do{
				cout<<"* Gender (M/F): "<<flush;
				getline(cin, gender);
				if(set_gender(gender)){
					valid_gender = true;
				}
			}while(!valid_gender);
			
			cout << "___________________________________________________" << endl;
			cout << endl;
					
					
			do{		
				cout<<"* Date_Of_Birth: "<<endl;
				cout << endl;
				cout << "# Day: " << flush;
				cin >> d;
				
				cout << "# Month: " << flush;
				cin >> m;
				
				cout << "# Year: " << flush;
				cin >> y;
				
				if(set_Date_Of_Birth(d, m, y)){
					valid_date = true;
				}
				
			}while(!valid_date);		
		    
		    cout << "___________________________________________________" << endl;
		    cout << endl;
		    
		    do{
				cout<<"* Age: "<<flush;
				cin >> age;
				if(set_age(age)){
					valid_age = true;
				}
			}while(!valid_age);	
		    
		    cout << "___________________________________________________" << endl;
		    cout << endl;
		    
		    do{
				cout<<"* Phone Number: "<<flush;
				cin.ignore();
				getline(cin, number);
				if(setnumber(number)){
					valid_phone = true;
				}
			}while(!valid_phone);
			
			cout << "___________________________________________________" << endl;
			cout << endl;
				
		}
		
		
		string getName(){
			return name;
		}
		
		string getemail(){
			return email;
		}
		
		string get_Date(){
			return Date_Of_Birth;
		}
		
		string get_Country(){
			return Country;
		}
		
		string getnumber(){
			return number;
		}
		
		string get_city(){
			return City;
		}
		
		string get_street(){
			return street;
		}
		
		string getgender(){
			return gender;
		}	
		string get_ID(){
			return ID;
		}	
};


class Account{
	private:
		int account_number;
		string account_type;
		string currency_type;
		int balance=1000;
	public:
	Customer c;
	void setaccount_number(int account_number){
	    this->account_number=account_number;
	}
	
	void setbalance(int balance){
	    this->balance=balance;
	}
	bool set_type(string t){
		bool correct = true;
		if(t == "P" ||  t == "B" || t == "p" || t == "b"){
			correct = true;
			account_type = t;
		}	
		else{
			correct = false;
		}		
		return correct;
	}
	
	bool set_currency(string Curr){
		bool correct = true;
		if(Curr == "$" || Curr == "EGP" || Curr == "egp"){
			correct = true;
			currency_type = Curr;
		}
		else{
			correct = false;
		}
		return correct;
	}			
		
	int getaccount_number()	{
		return account_number;
	}
	string get_account_type(){
		return account_type;
	}	
	int getbalance(){
		return balance;
	}
	string get_currency(){
		return currency_type;
	}	
	
};


class Bank{
	private:
		int StartWith=2000000;
		vector <Account> Accounts;
	
		void vectorAccount(int size, int account_number, int balance, vector<Account>& v){
			for(int i=0; i<size; i++){
				Account a;
				account_number = a.getaccount_number();
				balance = a.getbalance();
				v.push_back(a);
			}
		}
		
	public:
		void new_account(){
			Account a;
		    Customer c;
		    bool valid_type = false;
		    bool valid_currency = false;
		    string type;
		    string currency;
			c.getData();
			cout << setw(90) << "*Account Info*" << endl;
			cout << " " << endl;
			do{
				cout << "* Please Choose Account type you want (P/B) ..? " << flush;
				cin >> type;
				if(a.set_type(type)){
					valid_type = true;
				}
			}while(!valid_type);	
			cout << " __________________________________________________" << endl;
			cout << endl;		
			
			do{
				cout << "* Currency ($ / EGP): " << flush;
				cin >> currency;
				if(a.set_currency(currency)){
					valid_currency = true;
				}
			}while(!valid_currency);
			cout << " __________________________________________________" << endl;
			cout << endl;		
			
		    a.setaccount_number(StartWith+100);
		    StartWith+=100;
		    cout << " " << endl;
			cout << "* Customer "<<c.getName()<<" has been assinged account number: "<<a.getaccount_number() << endl;
			cout << endl;
			cout << endl;
			cout << "____________________________________________________________________________________________________________________________________________________________________________" << endl;
			cout << endl;
			a.c=c;
			Accounts.push_back(a);
		}
		
		int Withdraw(int account_number, int amount){
			bool exist = false;
			int new_balance;
		    int size = Accounts.size();
			for (int i=0;i<size;i++){
				if(Accounts[i].getaccount_number()==account_number){
					Accounts[i].getbalance();
					if(amount>Accounts[i].getbalance()){
						cout<<  "** Sorry you don't have enough money in your balance."<<endl;
						cout<< "* Maximum amount you can withdraw is "<<Accounts[i].getbalance()<<endl;
						break;
					}
					else{ 
						new_balance=Accounts[i].getbalance()-amount;
						Accounts[i].setbalance(new_balance);
						cout<<"^^ Transaction sucessfully done your new balance is: " <<Accounts[i].getbalance()<<" ^^" <<endl;
						exist = true;
						break;
					}
				}
				exist = false;		
		   }
		   if(exist == false){
			   cout << "## Invalid account number" << endl;
		   }
		   
		   return 0;
			
		}
		
		int Deposit(int account_number, int amount){
			bool exist = false;
			int new_balance;
		    int size = Accounts.size();
		    for (int i=0;i<size;i++){
				if(Accounts[i].getaccount_number()==account_number){
					Accounts[i].getbalance();
					if(amount<0 || amount==0){
						cout<<"* Please enter a number above zero"<<endl;
					}
					else{
						new_balance=Accounts[i].getbalance()+amount;
						Accounts[i].setbalance(new_balance);
						cout<<"^^ Transaction sucessfully done your new balance is "<<Accounts[i].getbalance()<< " ^^" <<endl;
						exist = true;
						break;
					}
				}
				exist = false;		
		    
			}
			
			if(exist == false){
				cout << "# Invalid account number" << endl;
			}	

	        return 0;
		}
		
		void Acc_details(int account_number){
			int size = Accounts.size();
			for (int i=0;i<size;i++){
				if(Accounts[i].getaccount_number()==account_number){
					cout <<  " ---------------" << endl;
					cout << "|## Personal Info |" << endl;
					cout <<  " ---------------" << endl;
					cout << " " << endl;
					cout<<"** Name        "<< setw(15) << "~~ " << Accounts[i].c.getName()<< " ~~" << endl;
					cout << "____________________________________________________________" << endl;
					cout << endl;
					cout<<"** Number      "<< setw(15) << "~~ " << Accounts[i].c.getnumber()<< " ~~" << endl;
					cout << "____________________________________________________________" << endl;
					cout << endl;
					cout<<"** Gender      "<< setw(15) << "~~ " << Accounts[i].c.getgender()<< " ~~" << endl;
					cout << "____________________________________________________________" << endl;
					cout << endl;
					cout<<"** Governorate "<< setw(15) << "~~ " << Accounts[i].c.get_Country()<<" ~~" << endl;
					cout << "____________________________________________________________" << endl;
					cout << endl;
					cout<<"** City        "<< setw(15) << "~~ " << Accounts[i].c.get_city()<<" ~~" << endl;
					cout << "____________________________________________________________" << endl;
					cout << endl;
					cout<<"** Street      "<< setw(15) << "~~ " << Accounts[i].c.get_street()<<" ~~" << endl;
					cout << "____________________________________________________________" << endl;
					cout << endl;
					cout<<"** D.O.B       "<< setw(15) << "~~ " << Accounts[i].c.get_Date()<<" ~~" << endl;
					cout << "____________________________________________________________" << endl;
					cout << endl;
					cout<<"** E-mail      "<< setw(15) << "~ " << Accounts[i].c.getemail()<<" ~" << endl;
					cout << "____________________________________________________________" << endl;
					cout << endl;
					cout<<"** National ID  "<< setw(15) << "~~ " << Accounts[i].c.get_ID()<<" ~~" << endl;
					cout << "____________________________________________________________" << endl;
					
					cout << " " << endl;
					
					cout <<" --------------" << endl;
					cout<< "|## Account Info|" << endl;
					cout <<" --------------" << endl;
					cout << " " << endl;
					
					cout<<"** Balance     "<< setw(15) << "~~ " << Accounts[i].getbalance()<<" ~~" << endl;
					cout << "____________________________________________________________" << endl;
					cout << endl;
					cout<<"** Acc.T       "<< setw(15) << "~~ " << Accounts[i].get_account_type() << " ~~" << endl;
					cout << "____________________________________________________________" << endl;
					cout << endl;
					cout<<"* Currency     "<< setw(15) << "~~ " << Accounts[i].get_currency() << " ~~" <<endl;
					cout << "____________________________________________________________" << endl;
					cout << endl;
					cout<<"** Acc.Num     "<< setw(15) << "~~ " << Accounts[i].getaccount_number()<<" ~~" << endl;
					cout << "____________________________________________________________" << endl;
					cout << endl;
				}
			}		
		}
		
		void transfer_money(int account_number, int account_number1, int amount){
			bool exist1 = false;
			bool exist2 = false;
			int new_balance;
			int size = Accounts.size();
			for (int i=0;i<size;i++){
				if(Accounts[i].getaccount_number()==account_number){
					Accounts[i].getbalance();
					if(amount>Accounts[i].getbalance()){
						cout<< "* Sorry you don't have enough money in your balance."<<endl;
						cout<< "* Maximum amount you can withdraw is "<<Accounts[i].getbalance()<<endl;
						break;
					}
					else{ 
						new_balance=Accounts[i].getbalance()-amount;
						Accounts[i].setbalance(new_balance);
						exist1 = true;
						break;
					} 
				}
				exist1 = false;
			}		
			//int size = Accounts.size();
			for (int i=0;i<size;i++){
				if(Accounts[i].getaccount_number()==account_number1){
					new_balance=Accounts[i].getbalance()+amount;
					Accounts[i].setbalance(new_balance);
					cout<<"^^ Money has been sucessfully transfered ^^"<<endl;
					exist2 = true;
					break;
				} 
				exist2 = false;
		   }
		   
		   if(exist1 == false){
			   cout << "## Account1 number is invalid" << endl;
		   }
		   if(exist2 == false){
			   cout << "## Account2 number is invalid" << endl;
		   }   
		}
		
		void edit_account(int account_number){
			char num;
			cout<<"1. Change my Address"<<endl;
			cout<<"2. Change my Number"<<endl;
			cout<<"3. Change my E-mail"<<endl;
			cout<<"4. EXIT"<<endl;
			cout<<"Please choose which one you want to edit: "<<flush;
			cin>>num;
			
			string new_Country;
			string new_City;
			string new_number;
			string new_street;
			string new_email;
            if(num=='1'){
				char num;
				cout<<"1. Change my Governorate"<<endl;
				cout<<"2. Change my City"<<endl;
				cout<<"3. Change my Street Name"<<endl;
				cout<<"Please choose which one you want to edit: "<<flush;
				cin>>num;
				
				int size = Accounts.size();
				for (int i=0;i<size;i++){
					if(Accounts[i].getaccount_number()==account_number){
						if(num=='1'){
							bool valid_gov = false;
							Customer c;
							do{
								cout<<"* Current Governorate: "<<Accounts[i].c.get_Country()<<endl;
								cout<<"* Please enter your new Governorate: "<<endl;
								cin>>new_Country;
								if(c.set_Country(new_Country)){
									Accounts[i].c.set_Country(new_Country);
									valid_gov = true;
								}
								else{
									cout << "## Error, all Characters, Please ##" << endl;
								}	
							}while(!valid_gov);	
							cout<<"* Your Governorate was sucessfully updated to: "<<Accounts[i].c.get_Country()<<endl;
						}
						if(num=='2'){
							cout<<"* Current City: "<<Accounts[i].c.get_city()<<endl;
							cout<<"* Please enter your new City: "<<endl;
							cin>>new_City;
							Accounts[i].c.set_city(new_City);
							cout<<"* Your City was sucessfully updated to: "<<Accounts[i].c.get_city()<<endl;
						}
						if(num=='3'){
							cout<<"* Current Street Name: "<<Accounts[i].c.get_street()<<endl;
							cout<<"* Please enter your new Street Name: "<<endl;
							cin>>new_street;
							Accounts[i].c.set_street(new_street);
							cout<<"* Your Street was sucessfully updated to: "<<Accounts[i].c.get_street()<<endl;
						}
						else{
							cout<<"* number entered isn't valid"<<endl;
						}
					}
				}
				cout<<"** Sorry account number entered is incorrect"<<endl;
			}
			if(num=='2'){
				int size = Accounts.size();
				for (int i=0;i<size;i++){
					if(Accounts[i].getaccount_number()==account_number){
						 bool valid_num = false;
						 Customer c;
						 do{
							cout<<"* Current Phone Number: "<<Accounts[i].c.getnumber()<<endl;
							cout<<"* Please enter your New Phone Number: "<<endl;
							cin>>new_number;
							if(c.setnumber(new_number)){
								valid_num = true;
								Accounts[i].c.setnumber(new_number);
							}
							else{
								cout << "## Error, all Digits, Please ##" << endl;
							}
						}while(!valid_num);		
						cout<<"* Your Phone Number was sucessfully updated to: "<<Accounts[i].c.getnumber()<<endl;
						break;
					}
				}
				cout<<"** Sorry account number entered is incorrect"<<endl;
			}
			if(num=='3'){
				int size = Accounts.size();
				for (int i=0;i<size;i++){
						if(Accounts[i].getaccount_number()==account_number){
							cout<<"* Current E-mail: "<<Accounts[i].c.getemail()<<endl;
							cout<<"* Please enter your New E-mail: "<<endl;
							cin>>new_email;
							Accounts[i].c.setemail(new_email);
							cout<<"* Your number was sucessfully updated to: "<<Accounts[i].c.getemail()<<endl;
							break;
						}
				}
				cout<<"** Sorry account number entered is incorrect"<<endl;
	
			}
			if(num=='4'){
				exit(0);
			}
			
			cout << "** Wrong Choice. \n Please, enter a number between 1 and 4: "<<flush;					
						
		}
		
};		


int main(){
	Bank myBank;
	do {
		char num;
		cout<<"Main Menu: " << endl;
		cout <<"__________" << endl;
		cout << " " << endl;
		cout<<"1. Add a new Account"<<endl;
		cout << endl;
		cout<<"2. Display account details"<<endl;
		cout << endl;
		cout<<"3. Edit an existing account"<<endl;
		cout << endl;
		cout<<"4. Transfer Money"<<endl;
		cout << endl;
		cout<<"5. Withdraw Money"<<endl;
		cout << endl;
		cout<<"6. Deposit Money"<<endl;
		cout << endl;
		cout<<"7. EXIT"<<endl;
		cout << endl;
		cout<<"Enter Your Choice: "<<flush;
		cin>>num;
		cout << endl;
		switch (num)
		{
		    
		    int amount;
		    int accountnumber;
		    int accountnumber1;
		    char answer;
			case '1':
				cout << " --------------------------------------------------------------------" << endl;
				cout << "|* There are some information you should know first." << setw(18) << "|" << endl;
				cout << "|" << setw(69) << "|" << endl;
				cout << "|1- Your age shoulde be 21 or above."  << setw(34) << "|"  << endl;
				cout << "|" << setw(69)  << "|" << endl;
				cout << "|2- You Should Deposit 1000 EGP To Open A New Account."  << setw(16) << "|"  << endl;
				cout << "|" << setw(69)  << "|" << endl;
				cout << "|3- You Should Have A Valid National ID."  << setw(30) << "|"  << endl;
				cout << " --------------------------------------------------------------------" << endl;
				cout << "# Do you agree with that? (Y/N) "; cin >> answer;
				if(answer == 'Y' || answer == 'y'){
					myBank.new_account();
					break;
				}
				else{
					break;
				}		
			case '2':
				cout<<"Please enter the account number you want to display "<<endl;
				cin>>accountnumber;
				myBank.Acc_details(accountnumber);
				break;
			case '3':
				cout<<"Please enter the account number you want to edit"<<endl;
				cin>>accountnumber;
				myBank.edit_account(accountnumber);
				break;
			case '4':
				cout<<"Please enter the account number you want to withdraw from "<<endl;
				cin>>accountnumber;
				cout<<"Please enter the account number you want to transfer to "<<endl;
				cin>>accountnumber1;
				cout<<"Please enter the amount you want to transfer "<<endl;
				cin>>amount;
				myBank.transfer_money(accountnumber,accountnumber1,amount);
				break;
			case '5':
				cout<<"Please enter the account number you want to withdraw from "<<endl;
				cin>>accountnumber;
				cout<<"Please enter the amount you want to withdraw "<<endl;
				cin>>amount;
				myBank.Withdraw(accountnumber, amount);
				break;
			case '6':
				cout<<"Please enter the account number you want to Deposit to "<<endl;
				cin>>accountnumber;
				cout<<"Please enter the amount you want to Deposit "<<endl;
				cin>>amount;
				myBank.Deposit(accountnumber, amount);
				break;
			case '7':
				cout <<  setw(90) << "Thank you" << endl;
				exit(0);
				break;
			default:
				cout << "Wrong Choice. \n Please, enter a number between 1 and 6: "<<endl << flush;
				cout << endl;
		}
	}
	while (true);
	
	return 0;
}
