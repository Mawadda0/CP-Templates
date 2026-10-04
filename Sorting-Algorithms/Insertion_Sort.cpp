#include <Template.h>

void insertionSort(vector<int> & a, int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}