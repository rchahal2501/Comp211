/* Palindrome and String Sort Fxns -- Reese Chahal 2022
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


/* conditions:
 *   true, if s is a palindrome (s[i] == s[n-1-i] for all 0 <= i < n-1-i,
 *         n = strlen(s))
 *   false, otherwise.
 */
bool is_palindrome(char[]);


/* Insert sort
 */
void insertion_sort(int[], int);



/* Mergesort
 */
void merge3(int[], int, int, int, int);
void merge_sort3(int[], int, int);




bool is_palindrome(char A[])
{
    int n = strlen(A);

    for (int i=0; i < n; i++)
    {
        if (A[i] != A[n-i-1])
        {
            return false;
            break;
        }
    }

    return true;
}




void insertion_sort(int A[], int n)
{
    int i, j, temp;

    //maybe also try (i<=n;) in the for loop
    for (i = 1; i < n; i++)
    {
        j = i;

        while (j > 0 && A[j - 1] > A[j])
        {
            temp = A[j];
            A[j] = A[j - 1];
            A[j - 1] = temp;
            j--;
        }
    }
}


/*  merge3: performs a 3-way merge
 *
 *  A is divided into 3 sub-arrays which are merged in sorted order
 *     -> lo:m1, m1:m2, m2:hi
 */
void merge3(int A[], int lo, int m1, int m2, int hi)
{
    int new[hi-lo];

    int i = lo; // counts from lo to mid1
    int j = m1; // counts from m1 to m2
    int k = m2; // counts from m2 to hi
    int l = 0; // counts from 0.. to hi

    while ((i < m1) && (j < m2) && (k < hi))
    {
        if(A[i] < A[j])
        {
            if(A[i] < A[k])
            {
                new[l++] = A[i++];
            }
            else
            {
                new[l++] = A[k++];
            }
        }
        else
        {
            if(A[j] < A[k])
            {
                new[l++] = A[j++];
            }
            else
            {
                new[l++] = A[k++];
            }
        }
    }

    // 1 2 range
    while ((i < m1) && (j < m2))
    {
        if(A[i] < A[j])
        {
            new[l++] = A[i++];
        }
        else
        {
            new[l++] = A[j++];
        }
    }

    // 2 3 range
    while ((j < m2) && (k < hi))
    {
        if(A[j] < A[k])
        {
            new[l++] = A[j++];
        }
        else
        {
            new[l++] = A[k++];
        }
    }

    // 1 3 range
    while ((i < m1) && (k < hi))
    {
        if(A[i] < A[k])
        {
            new[l++] = A[i++];
        }
        else
        {
            new[l++] = A[k++];
        }
    }

    // Copy values range 1
    while (i < m1) {
        new[l++] = A[i++];
    }

    // Copy values
    while (j < m2) {
        new[l++] = A[j++];
    }

    // Copy values
    while (k < hi) {
        new[l++] = A[k++];
    }

    // Copy sorted values from new[] back into A[]
    for (l=0; l<hi-lo; l++) {
        A[lo+l] = new[l];
    }

}




/*
 * Implements a recursive 3-way mergesort
 *   -> Divide array into thirds.
 *   -> Recursively sort each third.
 *   -> Merge thirds.
 */
void merge_sort3(int A[], int lo, int hi)
{
    int m1;
    int m2;

    if (hi - lo < 2) //for 1 element array
    {
        return;
    }

    m1= lo + ((hi-lo) / 3);
    m2= lo + 2*((hi-lo) / 3) +1;

    //recursive call 3x:
    merge_sort3 (A, lo, m1);
    merge_sort3 (A, m1, m2);
    merge_sort3 (A, m2, hi);

    //call merge3:
    merge3 (A, lo, m1,m2, hi);
}



