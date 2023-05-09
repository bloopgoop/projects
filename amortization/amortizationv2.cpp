//Kevin Zhu
//CIS 3100

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

void printCurrencyFormat(ofstream& o, double x, int padding, int length);
int findLength(double n);

int main()
{
    const int TERMS_PER_YEAR = 12;
    const int PERCENTAGE = 100;
    const int UPPER_BOUND_LOAN = 99999999;
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
        cout << "Enter loan amount ($0-$99,999,999.00): ";
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
        cout << "Enter additional principle per month ($0-$99,999,999.00): ";
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
    outfile << setw(40) << left << "Amount:" << '$';
    printCurrencyFormat(outfile, loanAmount, 15, findLength(loanAmount));
    outfile << endl;
    outfile << setw(40) << left << "Interest Rate:" << annualInterest << '%' << endl;
    outfile << setw(40) << left << "Term(Years):" << years << endl;
    outfile << setw(40) << left << "Monthly Payment:" << '$';
    printCurrencyFormat(outfile, monthlyPayment, 15, findLength(monthlyPayment));
    outfile << endl;
    outfile << setw(40) << left << "Additional Principle:" << '$';
    printCurrencyFormat(outfile, additionalPrinciple, 15, findLength(additionalPrinciple));
    outfile << endl;
    outfile << setw(40) << left << "Actual Payment:" << '$';
    printCurrencyFormat(outfile, actualPayment, 15, findLength(actualPayment));
    outfile << endl << endl;
    outfile << setw(24) << right << "Principle" << setw(22) << right << "Interest" << setw(22) << right << "Balance" << endl;
    
    //print first row- has char $
    outfile << setw(4) << left << counter 
        << setw(7) << right << '$';
        printCurrencyFormat(outfile, principle, 15, findLength(principle));
        outfile << setw(7) << right << '$';
        printCurrencyFormat(outfile, interest, 15, findLength(interest));
        outfile << setw(7) << right << '$';
        printCurrencyFormat(outfile, remainingBalance, 15, findLength(remainingBalance));
        outfile << endl;

    //updates variables first so starts on second row
    //check remainingBalance - principle in anticipation for the last row. stops when the next row's remaining balance 
    //is going to go to the negatives
    while (remainingBalance - principle > 0)
    {
        interest = monthlyInterest * remainingBalance;
        principle = actualPayment - interest;
        remainingBalance -= principle;
        counter += 1;
        outfile << setw(4) << left << counter;
        printCurrencyFormat(outfile, principle, 22, findLength(principle));
        printCurrencyFormat(outfile, interest, 22, findLength(interest));
        printCurrencyFormat(outfile, remainingBalance, 22, findLength(remainingBalance));
        outfile << endl;
    }

    //last row
    interest = monthlyInterest * remainingBalance;
    principle = remainingBalance;
    remainingBalance = 0;
    counter += 1;
    outfile << setw(4) << left << counter;
    printCurrencyFormat(outfile, principle, 22, findLength(principle));
    printCurrencyFormat(outfile, interest, 22, findLength(interest));
    printCurrencyFormat(outfile, remainingBalance, 22, findLength(remainingBalance));
    outfile << endl;

    outfile.close();
    return 0;
}

int findLength(double n)
{
    if (n >= 10)
    {
        int d = log10(n);
        return d + d / 3 + 4;
    }
    else
    {
        return 4;
    }
}

void printCurrencyFormat(ofstream& o, double x, int padding, int length)
{
    // x is the dollar amount to be printed
    //padding is the field of space you want the formatted number to be in
    //length is the length of the formatted number
    //11855
    //.41095
    //10^3 = 1,000
    //10^6 = 1,000,000
    //  5,   345,   123   .54
    //  2,     1,     0   end <- 2,1,0 refers to what block it is in
    o << setw(padding - length) << right << ' '; //empty space to the left of formatted number
    int integerPart = x;
    int block = log10(integerPart) / 3;
    int fractionPart = ((x - integerPart) * 100);
    int toPrint;
    bool showZeroes = false;
    while (block > 0)
    {
        toPrint = integerPart; //get integer part
        toPrint = toPrint / pow(1000, (block)); //remove the last 3 or 6 digits based on which block
        toPrint = toPrint % 1000; //make sure only get 3 digits or less to print
        block--;
        if (showZeroes == true) //only show zeroes on second iteration
        {
            if (toPrint == 0)
            {
                o << 0 << 0 << 0;
            }
            else if (toPrint < 10)
            {
                o << 0 << 0 << toPrint;
            }
            else if (toPrint < 100)
            {
                o << 0 << toPrint;
            }
            else
            {
                o << toPrint;
            }
            o << ',';
        }
        else
        {
            o << toPrint << ',';
            showZeroes = true;
        }
    }

    if (integerPart < 1000)
    {
        o << integerPart << '.';
    }
    else
    {
        toPrint = integerPart % 1000;
        if (toPrint == 0)
        {
            o << 0 << 0 << 0;
        }
        else if (toPrint < 10)
        {
            o << 0 << 0 << toPrint;
        }
        else if (toPrint < 100)
        {
        o << 0 << toPrint;
        }
        else
        {
            o << toPrint;
        }
        o << '.';
    }

    if (fractionPart == 0)
    {
        o << 0 << 0;
    }
    else if (fractionPart < 10)
    {
        o << 0 << fractionPart;
    }
    else
    {
        o << fractionPart;
    }

    return;
}
