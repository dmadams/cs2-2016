/**
 * @file
 * @author The CS2 TA Team
 * @version 1.0
 * @date 2013-2014
 * @copyright This code is in the public domain.
 *
 * @brief The bubble sort, quick sort, merge sort, and in-place quicksort
 * algorithms (implementation).
 *
 */
#include "sorter.hpp"

int main(int argc, char* argv[])
{
    // Set up buffers and data input
    std::vector<int> nums;
    std::string line;
    char *filename;
    int sort_type;

    // Ensure that at most one type of sort and at least a filename are specified.
    if (argc > 3 || argc < 2)
    {
        usage();
    }

    // default sort is bubble sort
    sort_type = BUBBLE_SORT;

    // Figure out which sort to use
    for (int i = 1; i < argc; ++i)
    {
        char *arg = argv[i];
        if (strcmp(arg, "-b") == 0) { sort_type = BUBBLE_SORT; }
        else if (strcmp(arg, "-q") == 0) { sort_type = QUICK_SORT; }
        else if (strcmp(arg, "-m") == 0) { sort_type = MERGE_SORT; }
        else if (strcmp(arg, "-qi") == 0) { sort_type = QUICK_SORT_INPLACE; }
        else { filename = argv[i]; }
    }

    // Read the file and fill our vector of integers
    // THIS FUNCTION IS STUDENT IMPLEMENTED
    readFile(filename, nums);

    switch (sort_type)
    {
        case BUBBLE_SORT:
        print_vector(bubbleSort(nums));
        break;

        case QUICK_SORT:
        print_vector(quickSort(nums));
        break;

        case MERGE_SORT:
        print_vector(mergeSort(nums));
        break;

        case QUICK_SORT_INPLACE:
        quicksort_inplace(nums, 0, nums.size() - 1);
        print_vector(nums);
        break;

        default:
        usage();
        break;
    }
    return 0;
}

/**
 * Usage    Prints out a usage statement and exits.
 */
void usage()
{
    std::cerr << usage_string << std::endl;
    exit(1);
}

/**
 * TO STUDENTS: In all of the following functions, feel free to change the
 * function arguments and/or write helper functions as you see fit. Remember to
 * add the function header to sorter.hpp if you write a helper function!
 */

/**
 * The function returns list sorted from least to greatest. c is a
 * counter that marks the last position that hould be switched to avoid 
 * unnecessary steps. x and y are set to two adjacent elements of list and are 
 * compared to determine whether a swap should be made or not.
 *
 * WHILE c > 0
 *     set x and y to the first 2 elements in the list
 *     FOR each element in list up to the cth element
 *         IF x > y THEN
 *             swap the elements in the list corresponding to x and y
 *         set x and y to the next 2 elements
 *     c = c - 1
 * return sorted list
 */
std::vector<int> bubbleSort(std::vector<int> &list)
{
    int c = list.size() - 1;
    while (c > 0)
    {
        int x = list[0];
        int y = list[1];
    
        for (int i = 0; i < c; i ++)
        {
            if (x > y)
            {
                list[i] = y;
                list[i + 1] = x;
            }
            x = list[i + 1];
            y = list[i + 2];
        }
        c --;
    }
    return list;
}

/**
 * The function returns list sorted from least to greatest. pivot is the index
 * of the element of which all the other elements will be compared to and
 * flipped about. low and hi are vectors that are filled with the elements that
 * are less than and greater than or equal to the pivot value respectively. 
 *
 * IF the length of the list = 1 or the list is empty THEN
 *     return list
 * set pivot to the last element in list
 * FOR each element in list up to pivot
 *     IF the element is >= pivot THEN
 *         add the element to hi
 *     ELSE
 *         add the element to low 
 * hi = quickSort(hi)
 * low = quickSort(low)
 * add the pivot element to the end of low
 * add the elements in hi to the end of low
 * return low
 */
std::vector<int> quickSort(std::vector<int> &list)
{
    if (list.size() <= 1)
    {
        return list;
    }
    int pivot = list.size() - 1;
    std::vector<int> low;
    std::vector<int> hi;
    for (int i = 0; i < pivot; i ++)
    {
        if (list[i] >= list[pivot])
        {
            hi.push_back(list[i]);
        }
        else
        {
            low.push_back(list[i]);
        }
    }
    hi = quickSort(hi);
    low = quickSort(low);
    low.push_back(list[pivot]);
    for (unsigned int j = 0; j < hi.size(); j ++)
    {
        low.push_back(hi[j]);
    }
    return low;
}

/**
 * The function returns list sorted from least to greatest. left and right are
 * the first half of list and the second half of list respectively. 
 *
 * IF length of list = 1 THEN
 *     return list
 * FOR elements in first half of list
 *     add element to left
 * FOR elements in second half of lst
 *     add element to right
 * left = mergeSort(left)
 * right = mergeSort(right)
 * list = merge(left, right)
 * return list
 */
std::vector<int> mergeSort(std::vector<int> &list)
{
    if (list.size() <= 1)
    {
        return list;
    }
    std::vector<int> left;
    std::vector<int> right;
    for (unsigned int i = 0; i < list.size() / 2; i ++)
    {
        left.push_back(list[i]);
    }
    for (unsigned int j = list.size() / 2; j < list.size(); j ++)
    {
        right.push_back(list[j]);
    }
    left = mergeSort(left);
    right = mergeSort(right);
    list = merge(left, right);
    return list;
}

/**
 * Combines left and right into a sorted list called new_lst. 
 * 
 * WHILE left and right both contain elements
 *     IF the 1st element in right <= the 1st element in left THEN
 *         add the first element of right to the end of new_lst
 *         delete the first element of right
 *     ELSE
 *         add the first element of left to the end of new_lst
 *         delete the first element of left
 * IF right contains any elements THEN
 *     add the first element of right to the end of new_lst
 *     delete the first element of right
 * ELSE
 *     add the first element of left to the end of new_lst
 *     delete the first element of left
 */
std::vector<int> merge(std::vector<int> &left, std::vector<int> &right)
{
    std::vector<int> new_lst;
    while (right.size() != 0 && left.size() != 0)
    {
        if (right[0] <= left[0])
        {
            new_lst.push_back(right[0]);
            right.erase(right.begin());
        }
        else
        {
            new_lst.push_back(left[0]);
            left.erase(left.begin());
        }
    }
    if (right.size() != 0)
    {
        while (right.size() != 0)
        {
            new_lst.push_back(right[0]);
            right.erase(right.begin());
        }
    }
    else
    {
        while (left.size() != 0)
        {
            new_lst.push_back(left[0]);
            left.erase(left.begin());
        }
    }
    return new_lst;
}

/*
 * quicksort_inplace:  In-place version of the quicksort algorithm. Requires
 *              O(1) instead of O(N) space, same time complexity. Each call of
 *              the method partitions the list around the pivot (an item taken
 *              from the middle of the array) with items left of the pivot
 *              smaller than it and items to its right larger than it. Then the
 *              method recursively sorts the left and right portions of the list
 *              until it reaches its base case: a list of length 1 is already
 *              sorted.
 *
 * @param list: pointer to integer array to be sorted
 * @returns:    Nothing, the array is sorted IN-PLACE.
 *
 * IF left >= right THEN
 *     return (end the function)
 * pivot = right
 * pivot_val = value at index pivot
 * FOR elements in list up to pivot
 *     IF element is >= pivot_val THEN
 *         move element to location of pivot
 *         move element to the left of pivot to location of element
 *         move pivot_val to the left
 *         pivot = pivot - 1
 * quicksort_inplace(list, left, pivot - 1)
 * quicksort_inplace(list, pivot + 1, right)
 */
void quicksort_inplace(std::vector<int> &list, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int pivot = right;
    int pivot_val = list[pivot];
    for (int i = left; i < pivot; i ++)
    {
        if (list[i] >= pivot_val)
        {
            list[pivot] = list[i];
            list[i] = list[pivot - 1];
            list[pivot - 1] = pivot_val;
            pivot --;
            i --;
        }
    }
    quicksort_inplace(list, left, pivot - 1);
    quicksort_inplace(list, pivot + 1, right);
}

