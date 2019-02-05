/**
 * @file testFileIO.cpp
 * @author The CS2 TA Team
 * @version 1.0
 * @date 2013-2015
 * @copyright This code is in the public domain.
 *
 * @brief A brief example of file input.
 */

#include "fileio.hpp"

using namespace std;
/**
 * @brief Read the file input and print out its contents
 *
 * Assumes that the file contains one integer per line.
 */
int main(int argc, char const *argv[])
{

    // TODO Write test code to instantiate a vector, then calls the readFile and
    // print_vector functions to demonstrat that the file was read successfully.
	vector<int> nums;
	readFile("nums", nums);
	print_vector(nums);

    return 0;
}
