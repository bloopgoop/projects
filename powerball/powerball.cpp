//Author: Kevin Zhu
//CIS 3100
//Assignment 4

#include <iostream>
#include <ctime>
#include <random>
using namespace std;

const int WHITEBALLS = 69;
const int WHITEPICKS = 5;
const int REDBALLS = 26; 

void populate(int array[], int size);
int takeout(int array[], int size);
void sort(int array[], int size);

int main()
{

    int games;
    cout << "How many games would you like to play? ";
    cin >> games;

    int white_pool[WHITEBALLS];
    int red_pool[REDBALLS];
    int hand[WHITEPICKS];
    int value;


    for (int i = 1; i <= games; i++)
    {
        cout << "Game " << i << '\n' << "White balls are: ";
        populate(white_pool, WHITEBALLS);
        populate(red_pool, REDBALLS);

        //take out random ball and insert it into hand
        for (int round = 0; round <= 4; round ++)
        {
            value = takeout(white_pool, WHITEBALLS - round);
            hand[round] = value;
        }

        //sort hand and display in ascending order using SELECTION SORT
        sort(hand, WHITEPICKS);
        for (int j = 0; j < WHITEPICKS; j++)
        {
            cout << hand[j] << ' ';
        }

        random_device engine;
        uniform_int_distribution<int> randomInt(0, REDBALLS - 1); //this statement defines a distribution object named randomInt
        int index = randomInt(engine);

        cout << "Power Ball is: ";
        cout << red_pool[index] << "\n\n";
    }

}

void populate(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = i + 1;
    }
}


int takeout(int array[], int size) //returns the value of the powerball chosen by rng
{
    random_device engine;
    uniform_int_distribution<int> randomInt(0, size - 1); //this statement defines a distribution object named randomInt
    int index = randomInt(engine);

    //select the random index
    int value = array[index];

    //consolidate
    for (int i = index; i < size - 1; i++)
    {   
        array[i] = array[i + 1];
    }
    
    //set last item of array to -1 (FLAG)
    array[size - 1] = -1;

    return value;
}

void sort(int array[], int size)
{
    int min_index;
    int value;

    for (int index = 0; index < size; index++)
    {
        min_index = index; //set the minimum's index to first value

        for (int j = index + 1; j < size; j++)
        {
            if (array[j] < array[min_index]) //if anything is lower than minimum, change minimum's value
            {
                min_index = j;
            }
        }
        
        //put the minimum into correect position by swapping
        value = array[index];
        array[index] = array[min_index];
        array[min_index] = value;
    }
}