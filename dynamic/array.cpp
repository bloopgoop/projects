#include <iostream>
using namespace std;

int size = 5;

//tasked to make this dynamic

void insert(int **v, int n, int& b, int &s) //take address of pointer, int n, address of boundary and size.
{
    int *q = *v;

	if (b < s) //if the boundary is less than the size of the array
	{
		q[b] = n; //insert into array
	}
    else
    {
        s *= 2; //increase size by two times

        int *newptr = new int[s]; //create new array with new size
        for (int i = 0; i < b; i++) 
        {
            newptr[i] = q[i]; //copy contents
        }

        delete[] q; //delete old array

        newptr[b] = n; //add last item
        *v = newptr; //set value of v to point to new array
    }
    b += 1;
}

void display(int v[], int b)
{
	for (int i = 0; i < b; i++)
		cout << "v[" << i << "] = " << v[i] << endl;
}

int retrieve(int v[], int n, int& b)
{
    for (int i = 0; i < b; i++)
	{
        if (v[i] == n)
        {
            return i;
        }
    }
    return -1;
}

bool remove(int v[], int n, int& b) //remove the first instance of the integer recieved
{
    for(int i = 0; i < b; i++)
    {
        if(v[i] == n)
        {
            v[i] = -999;
            return true;
        }
    }
    return false;
}

void swap(int& x, int& y)
{
	int z;
	z = x;
	x = y;
	y = z;
}

void selectionSorta(int v[], int b)
{
// enter your code here

}

void selectionSortd(int v[], int b)
{
// enter your code here

}

int main()
{
	int *v = new int[size];
	int bound = 0;
	char c;
	int number;
	int index;
	bool flag = true;

	while (flag)
	{
		cout << endl;
		cout << "Please enter a (A) for add an integer to an array; " << endl;
		cout << "             r (R) to retrieve an integer from an array with its index;" << endl;
		cout << "             d (D) to delete an integer from an array;" << endl;
		cout << "             x (X) to sort all the elements of an integer array in ascending order;" << endl;
		cout << "             y (Y) to sort all the elements of an integer array in decending order;" << endl;
		cout << "             s (S) to display all the elements of an integer array;" << endl;
		cout << "             q (Q) to quite the program." << endl;
		cout << "Enter your choice here: ";
		cin >> c;

		switch (c)
		{
		case 'a':
		case'A':
			cout << endl << "Please enter an integer for insertion: ";
			cin >> number;
			insert(&v, number, bound, size);
			break;

		case 'r':
		case 'R':
			cout << endl << "Please enter an integer that you wish to retrieve from the array: ";
			cin >> number;
			index = retrieve(v, number, bound);
			if (index < 0)
				cout << endl << number << " doesn't exist in the array!" << endl;
			else
				cout << "v[" << index << "] = " << v[index] << endl;
			break;

		case 'd':
		case 'D':
			cout << endl << "Please enter an integer that you wish to delete from the array: ";
			cin >> number;
			if (!remove(v, number, bound))
				cout << endl << number << " doesn't exist in the array!" << endl;
			break;

		case 's':
		case 'S':
			cout << endl << "Here is the current content of the integer array: " << endl;
			display(v, bound);
			break;

		case 'x':
		case 'X':
			cout << endl << "Sorting array in ascending order: " << endl;
			selectionSorta(v, bound);
			break;

		case 'y':
		case 'Y':
			cout << endl << "Sorting array in decending order: " << endl;
			selectionSortd(v, bound);
			break;

		case 'q':
		case 'Q':
			cout << endl << "The end of this program!" << endl;
			flag = false;
			break;

		default:
			cout << endl << "Illegal choice. Try it again." << endl;
				break;
		}
	}
    delete[] v;
	system("pause");
	return 0;
}