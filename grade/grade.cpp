#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

enum Grade {F, D, CMINUS, C, CPLUS, BMINUS, B, BPLUS, AMINUS, A};

struct StudentData{
        string first_name;
        string last_name;
        float score;
        float percentage;
        Grade standard;
        Grade rank;
        Grade final;
};

int main()
{
    string line;
    /*
    cout << "Enter the name of the file you want to read: ";
    cin >> in;
    */

    StudentData* students = new StudentData[36];

    ifstream input("input.txt");
    if(input.is_open())
    {
        while (input){
            getline(input, line);
            cout << line << '\n';
        }
        

    }


}

//Assuming that the input text file's columns are last name, first name, score
void enterinfo()