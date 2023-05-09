//Kevin Zhu
//CIS 3100

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    const int TERMS_PER_YEAR = 12;
    const int PERCENTAGE = 100;
    const int UPPER_BOUND_LOAN = 9999999;
    const int UPPER_BOUND_INTEREST = 30;
    const int UPPER_BOUND_YEAR = 99;

    //Get file name from user input and create an variable named outfile of ofstream class
    string file;
    cout << "Send the mortgage amortization table to a file (enter file name): ";
    cin >> file;
    ofstream outfile;

    outfile << fixed << setprecision(2) << showpoint;

    double loanAmount, annualInterest, additionalPrinciple;
    int years;

    //Check user's input
    do
    {
        cout << "Enter loan amount ($0-$9,999,999.00): ";
        cin >> loanAmount;
    }
    while (loanAmount <= 0 || loanAmount > UPPER_BOUND_LOAN);

    do
    {
        cout << "Enter annual interest rate (0-30.0): ";
        cin >> annualInterest;
    }
    while (annualInterest <= 0 || annualInterest > UPPER_BOUND_INTEREST);
    
    do
    {
        cout << "Enter no. of years as integer (1-99): ";
        cin >> years;
    }
    while(years < 1 || years > UPPER_BOUND_YEAR);

    do
    {
        cout << "Enter additional principle per month ($0-$9,999,999.00): ";
        cin >> additionalPrinciple;
    }
    while(additionalPrinciple < 0 || additionalPrinciple > UPPER_BOUND_LOAN);
    
    //initialize variables to be used in the pmt equation
    double monthlyInterest = (annualInterest/PERCENTAGE)/TERMS_PER_YEAR;
    int nt = years * TERMS_PER_YEAR;


    //pmt equation
    double monthlyPayment = (((loanAmount) * (monthlyInterest * pow((1 + monthlyInterest), nt))) / ((pow(1 + monthlyInterest, nt) - 1)));
    double actualPayment = monthlyPayment + additionalPrinciple;
    cout << actualPayment;

    //initialize the variables of the first row to correct values
    double interest = loanAmount * monthlyInterest;
    double principle = actualPayment - interest;
    double remainingBalance = loanAmount - principle;
    int counter = 1;
    
    outfile.open(file);

    
    //setw(x) creates a field of x spaces. right or left makes it right or left justified
    //Top part of the text file
    outfile << setw(44) << right << "MORTGAGE AMORTIZATION TABLE" << endl;
    outfile << setw(40) << left << "Amount:" << '$' << loanAmount << endl;
    outfile << setw(40) << left << "Interest Rate:" << annualInterest << '%' << endl;
    outfile << setw(40) << left << "Term(Years):" << years << endl;
    outfile << setw(40) << left << "Monthly Payment:" << '$' << monthlyPayment << endl;
    outfile << setw(40) << left << "Additional Principle:" << '$' << additionalPrinciple << endl;
    outfile << setw(40) << left << "Actual Payment:" << '$' << actualPayment << endl << endl;
    outfile << setw(24) << right << "Principle" << setw(20) << right << "Interest" << setw(20) << right << "Balance" << endl;
    
    //print first rowm- has char $
    outfile << setw(4) << left << counter 
        << setw(10) << right << '$' << setw(10) << right << principle 
        << setw(10) << right << '$' << setw(10) << right << interest 
        << setw(10) << right << '$' << setw(10) << right << remainingBalance << endl;

    //updates variables first so starts on second row
    //check remainingBalance - principle in anticipation for the last row. stops when the next row's remaining balance 
    //is going to go to the negatives
    while (remainingBalance - principle > 0)
    {
        interest = monthlyInterest * remainingBalance;
        principle = actualPayment - interest;
        remainingBalance -= principle;
        counter += 1;
        outfile << setw(4) << left << counter << setw(20) << right << principle << setw(20) << right << interest 
        << setw(20) << right << remainingBalance << endl;
    }

    //last row
    interest = monthlyInterest * remainingBalance;
    principle = remainingBalance;
    remainingBalance = 0;
    counter += 1;
    outfile << setw(4) << left << counter << setw(20) << right << principle << setw(20) << right << interest 
        << setw(20) << right << remainingBalance << endl;

    outfile.close();

    return 0;
}