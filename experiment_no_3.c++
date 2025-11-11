#include <iostream>
using namespace std;
// Saving Account Class
class SavingAccount {
private:
string account HolderName;
int accountNumber;
double balance;
double interestRate;
public:
SavingAccount(string name, int accNumber, double initialBalance, double rate) {
}
accountHolderName= = name;
accountNumber = accNumber;
balance initialBalance;
interest Rate = rate;
void deposit(double amount) {
}
if (amount > 0) {
balance + amount;
cout << "Deposited: " << amount << endl;
void withdraw(double amount) {
if (amount > 0 && amount <= balance) {
balance
amount;
cout << "Withdrawn: " << amount << endl; } else {
cout<<"Insufficient balance!" << endl;
void apply Interest() {
double interest = balance * interestRate / 100;
balance + interest;
cout<<"Interest Applied: " << interest << endl;
void display() {
cout<<"\n[Savings Account]" << endl;
cout<<"Account Holder: " << accountHolderName << endl; cout << "Account Number: " << accountNumber <<< endl;

}
cout << "Balance: " << balance << endl;
cout<<"Interest Rate: " << interestRate << "%" << endl;
};
// Checking Account Class
class CheckingAccount {
private:
string account HolderName;
int accountNumber;
double balance;
double transaction Fee;
public:
Checking Account(string name, int accNumber, double initialBalance, double fee) {
accountHolderName = name;
accountNumber = accNumber;
balance initial Balance;
transactionFee = fee;
void deposit(double amount) {
if (amount > 0) {
balance + amount;
cout << "Deposited: " << amount << endl;
}
}
void withdraw(double amount) {
double total amount + transaction Fee;
if (total <= balance) {
balance = total;
cout << "Withdrawn: " << amount << " ("<< transaction Fee <<<" fee applied)" << endl;
} else {
cout << "Insufficient balance for withdrawal + fee!" << endl;

}
};
}
cout<<"\n[Checking Account]" << endl;
cout<<"Account Holder: " << accountHolderName << endl;
cout << "Account Number: " << accountNumber << endl; cout<<"Balance: " << balance << endl;
cout<<"Transaction Fee: " << transaction Fee << endl;
// Main Function
int main() {
SavingAccount savings("Alice", 1001, 5000.0, 3.0); Checking Account checking("Bob", 1002, 3000.0, 20.0);
// Operations on Savings Account
savings.display();
savings.deposit(1000);
savings.withdraw(2000);
savings.apply Interest();
savings.display();
// Operations on Checking Account
checking.display();
checking.deposit(1500);
checking.withdraw(IC00);
checking.display();
return 0;
}