/**
 * @file arrays1.cpp
 * @author The CS2 TA Team <cs2tas@caltech.edu>
 * @date 2014-2015
 * @copyright This code is in the public domain.
 *
 * @brief An array example.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

#define TEST_SIZE 20

using namespace std;

int arrayMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i ++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

double arrayMean(int arr[], int n)
{
    double mean = 0;
    for (int i = 0; i < n; i ++)
    {
        mean += arr[i];
    }
    mean /= n;
    return mean;
}

void arrayAscendingFill(int arr[], int n)
{
    int c = 1;
    for (int i = 0; i < n; i++)
    {
        arr[i] = c;
        c ++;
    }
}

void arraySort(int arr[], int n)
{
    while (n > 0)
    {
    int x = arr[0];
    int y = arr[1];
    
        for (int i = 0; i < n; i ++)
        {
            if (x > y)
            {
                arr[i] = y;
                arr[i + 1] = x;
            }
            x = arr[i + 1];
            y = arr[i + 2];
        }
        n --;
    }
}

void arrayPrint(int arr[], int n)
{
    for (int i = 0; i < n; i ++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

/**
 * @brief Sets up and runs an array example.
 */
int main(int argc, char ** argv)
{

    /*-------- CHANGE NOTHING BELOW THIS LINE FOR PART 1 --------*/
    int test_values[TEST_SIZE];
    int real_size;

    // seed the PRNG
    srand(time(nullptr));

    // initialize the test array to garbage
    for (int i = 0; i < TEST_SIZE; i++)
    {
        test_values[i] = rand();
    }

    // determine a real size
    real_size = TEST_SIZE - (rand() % 20);

    // initialize the meaningful part of the test array to random numbers
    // all of which are less than one million
    for (int i = 0; i < real_size; i++)
    {
        test_values[i] = rand() % 1000000;
    }
    /*-------- CHANGE NOTHING ABOVE THIS LINE FOR PART 1 --------*/

    arrayPrint(test_values, real_size);
    cout << arrayMax(test_values, real_size) << endl;
    cout << arrayMean(test_values, real_size) << endl;
    arraySort(test_values, real_size);
    arrayPrint(test_values, real_size);
    arrayAscendingFill(test_values, real_size);
    arrayPrint(test_values, real_size);

    return 0;
}
