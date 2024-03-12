#include <cstdlib>
#include <map>
#include <iostream>
#include <string>
using namespace std;

class UserAuthentication {
private:

    map<string, string> userDatabase; // Map to store usernames and passwords
    float balance;

public:

    // Method to register a new user
    void registerUser(string username, string password) {
        balance = 0;
        userDatabase[username] = password;
        cout << "User registered successfully!" << endl;
    }

    void deposit(){
        float amount;
        cout<<"Enter amount:\n";
        cin>>amount;
        balance = amount+balance;
        cout<<"Your deposit was succesful\n";
        
    }
    void withdraw(){
        float amount;
        cout<<"Enter amount:\n";
        cin>>amount;

        if (balance<amount){
            cout<<"Insufficient funds\n";
        }
        else{
            balance = balance-amount;
            cout<<"Withdrawall succesful\n";
        }
        
    }
    void checkbalance(){
        cout<<"Your current balnce is:$"<<balance<<endl;
           }

    // Method to authenticate a user
    bool authenticateUser(string username, string password) {
        // Check if the username exists in the database
        if (username=="4")
        return false;
        if (userDatabase.find(username) != userDatabase.end()) {
            // If the username exists, check if the password matches
            if (userDatabase[username] == password) {
                cout << "\t\t\t\tYou are logged in!" << endl;
                return true;
            } else {
                cout << "Incorrect password!" << endl;
                return false;
            }
        } else {
            cout << "User not found!" << endl;
            return false;
        }
    }
};




int main(int argc, char *argv[])
{
    int action;
    float balance = 0;
    string name, surname,password,login;
    UserAuthentication check;
   
     cout<<"Do have an account?\n";
        cin>>login;

    if (login=="YES"){
        cout<<"Enter username\n";
        cin>>name;
        cout<<"Enter your password\n";
        cin>>password;
        while(check.authenticateUser(name, password)){
            cout<<"\t\t\t\tEnter a number a required action\n";
            cout<<"1.Deposit\t\t2.withdraw\t\t3.checkbalance\t\t4.exit\n";
            cin>>action;
            switch (action)
            {
            case 1:
               check.deposit();
               
                break;
            case 2:
               check.withdraw();
                break;
            case 3:
               check.checkbalance();
                break;
            case 4:
            name="4";
            check.authenticateUser(name, password);
            break;
            default:

            cout<<"Invalid input you homogenious idiot!\n";

            
                break;
            }

        }
    }
    else if(login=="NO"){
    cout<<"To create a new account\n";
          cout<<"Enter username\n";
        cin>>name;
        cout<<"Enter your password\n";
        cin>>password;
        check.registerUser(name,password);
        while(check.authenticateUser(name, password)){
            cout<<"\t\t\t\tEnter a number a required action\n";
            cout<<"1.Deposit\t\t2.withdraw\t\t3.checkbalance\t\t4.exit\n";
            cin>>action;
            switch (action)
            {
            case 1:
               check.deposit();
               
                break;
            case 2:
               check.withdraw();
                break;
            case 3:
               check.checkbalance();
                break;
            case 4:
            name="4";
            check.authenticateUser(name, password);
            break;
            default:

            cout<<"Invalid input you homogenious idiot!\n";

            
                break;
            }

        }
    }
    else
     cout<<"Invalid input\n";
    
    
    
    return EXIT_SUCCESS;
}
