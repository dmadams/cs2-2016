/**
 * @file
 * @author The CS2 TA Team
 * @version 1.0
 * @date 2013-2014
 * @copyright This code is in the public domain.
 *
 * @brief The gift wrapping and Graham scan convex hull algorithms
 * (implementation).
 *
 */
#include "HullAlgorithms.hpp"

/**
 * TO STUDENTS: In all of the following functions, feel free to change the
 * function arguments and/or write helper functions as you see fit. Remember to
 * add the function header to HullAlgorithms.hpp if you write a helper function!
 *
 * Our reference implementation has four helper functions and the function(s)
 * copied over from angleSort.cpp.
 */

/**
 * sorted_points = sort_x(points)
 * start = first element in sorted_points
 * erase first element from sorted_points
 * add start to end of sorted points
 * add start to new_points
 * not_at_start = true
 * 
 * WHILE not_at_start = true
 *     FOR elements in sorted_points
 *         j = 0
 *         WHILE j < length of sorted_points
 *             IF i == j THEN
 *                 direction = 'o'
 *             ELSE
 *                 direction = right_or_left()
 *             IF direction = 'l' THEN
 *                 break
 *             j = j + 1
 *         IF j = length of sorted_points THEN
 *             add sorted_points[i] to new_points
 *             IF sorted_points[i] = start THEN
 *                 not_at_start = false
 *                 break
 *             erase sorted_points[i] from sorted_points
 *             i = 0
 * FOR elements in new_points
 *     add_to_hull(element)
 */
void DoGiftWrap(vector<Tuple*> points, ConvexHullApp *app)
{
    vector<Tuple*> sorted_points = sort_x(points);
    Tuple* start = sorted_points[0];
    sorted_points.erase(sorted_points.begin());
    sorted_points.push_back(start);
    vector<Tuple*> new_points;
    new_points.push_back(start);
    bool not_at_start = true;

    while (not_at_start)
    {
        for (unsigned int i = 0; i < sorted_points.size(); i ++)
        {
            unsigned int j = 0;
            while (j < sorted_points.size())
            {
                char direction;
                if (i == j)
                {
                    direction = 'o';
                }
                else
                {
                    direction = right_or_left(new_points.back(), 
                        sorted_points[i], sorted_points[j]);
                }
                if (direction == 'l')
                {
                    break;
                }
                j ++;
            }
            if (j == sorted_points.size())
            {
                new_points.push_back(sorted_points[i]);
                if(sorted_points[i] == start)
                {
                    not_at_start = false;
                    break;
                }
                sorted_points.erase(sorted_points.begin() + i);
                i = 0;
            }
        }   
    }
    for (unsigned int k = 0; k < new_points.size(); k ++)
    {
        app->add_to_hull(new_points[k]);
    }
}

/**
* Sorts list of points based on their x values from least to greatest. 
*/
vector<Tuple*> sort_x(vector<Tuple*> points)
{
    if (points.size() <= 1)
    {
        return points;
    }
    int pivot = points.size() - 1;
    std::vector<Tuple*> low;
    std::vector<Tuple*> hi;
    for (int i = 0; i < pivot; i ++)
    {
        if (points[i]->x >= points[pivot]->x)
        {
            hi.push_back(points[i]);
        }
        else
        {
            low.push_back(points[i]);
        }
    }
    hi = sort_x(hi);
    low = sort_x(low);
    low.push_back(points[pivot]);
    for (unsigned int j = 0; j < hi.size(); j ++)
    {
        low.push_back(hi[j]);
    }
    return low;
}

/**
* Determines in a set of 3 points if point3 is to the right, left, or on the 
* same line as point1 and point2. Returns 'o' if it is on the same line, 'r'
* if it is to the right, and 'l' if it is to the left. 
*/
char right_or_left(Tuple* point1, Tuple* point2, Tuple* point3)
{
    int val = (point2->y - point1->y) * (point3->x - point2->x) - 
        (point2->x - point1->x) * (point3->y - point2->y);
    if (val == 0)
    {
        return 'o';
    }
    else if(val > 0)
    {
        return 'l';
    }
    return 'r';
}
 /**
 * TODO: Implement this function.
 */
void DoGrahamScan(vector<Tuple*> points, ConvexHullApp *app)
{
    for (unsigned int i = 0; i < points.size(); ++i)
    {
        app->add_to_hull(points[i]);
    }
    app->add_to_hull(points[0]);
}
