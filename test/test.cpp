#include <iostream>
#include <cmath>
#include <string>
using namespace std;

enum Grade {F, D, CMINUS, C, CPLUS, BMINUS, B, BPLUS, AMINUS, A};

int main()
{
    struct StudentData {
        string lastName;
        string firstName;
        double score;
        double percentage;
        Grade standard;
        Grade rank;
        Grade final;
    };

    int array[10];
    int sum = 2;

    
}
