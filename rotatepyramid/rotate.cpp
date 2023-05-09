// Author: Kevin Zhu
// CIS 3100 Spring 2023


#include <iostream>
using namespace std;

int main()
{
    int n;
    do
    {
        cout << "Enter an integer number between 2 and 25: ";
        cin >> n;
    }
    while (n < 2 || n > 25);



    for (int i = n; i > 0; i--) //north
    {
        for (int j = 1; j < i; j++)
        {
            cout << ' ';
        }
        for (int k = 0; k < n - i; k++)//each row below has 2 extra **
        {
            cout << "**";
        }
        cout << '*';
        for (int j = 1; j < i; j++)
        {
            cout << ' ';
        }
        cout << '\n';
    }

    //outerloop refers to the amount of rows to print (2n - 1 rows), start row 1
    //...#
    //..##
    //.### print top half of the rows
    //#### print middle row
    // print bottom half of the row
    for (int rows = 1; rows < 2*n; rows ++)//west
    {
        if (rows < n)
        {
            for (int i = n; i > rows; i --)
            {
                cout << ' ';
            }
            for (int j = 0; j < rows; j++)
            {
                cout << '*';
            }
        }
        if (rows == n)
        {
            for (int middle = 0; middle < n; middle ++)
            {
                cout << '*';
            }
        }
        if (rows > n)
        {
            for (int i = n; i < rows; i++)
            {
                cout << ' ';
            }
            for (int j = 2*n; j > rows; j--)
            {
                cout << '*';
            }
        }
        cout << '\n';

    }

    for (int i = 0; i < n; i++) //south
    {
        for (int j = 0; j < i; j++)
        {
            cout << ' ';
        }
        for (int k = 1; k < n - i; k++)
        {
            cout << "**";
        }
        cout << '*';
        for (int j = 0; j < i; j++)
        {
            cout << ' ';
        }
        cout << '\n';
    }


    for (int rows = 1; rows < 2*n; rows ++)//east
    {
        if (rows < n)
        {
            for (int j = 0; j < rows; j++)
            {
                cout << '*';
            }
            for (int i = n; i > rows; i --)
            {
                cout << ' ';
            }
        }
        if (rows == n)
        {
            for (int middle = 0; middle < n; middle ++)
            {
                cout << '*';
            }
        }
        if (rows > n)
        {
            for (int j = 2*n; j > rows; j--)
            {
                cout << '*';
            }
            for (int i = n; i < rows; i++)
            {
                cout << ' ';
            }
        }
        cout << '\n';

    }
}