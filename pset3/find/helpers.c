/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
     if(n<0)
        return false;
    
    if(n==1)
    {
        
        if(values[0] == value)
            return true;
        
        return false;
    }
    
        if(value==values[n/2])
            return true;
            
        if(value> values[n/2])
        {
            return search(value, (values+n/2), n%2==0? n/2 : n/2+1 );
        }
        if(value< values[n/2])
        {
           return search(value, values, n/2);
        }
       
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
     for(int j=n; j>1; j-- )
    for(int i=0; i<j-1; i++)
    {
        if(values[i]>values[i+1])
        {
            int t = values[i];
            values[i] = values[i+1];
            values[i+1] = t;
            
        }
    }
}