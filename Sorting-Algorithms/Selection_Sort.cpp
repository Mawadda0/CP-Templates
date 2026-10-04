#include <Template.h>

void selectionSort(vector<int> & a)
{
    int n = sz(a);
    for(int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for(int j = i + 1; j < n; ++j)
        {
            if(a[j] < a[min_idx])\
            {
                min_idx = j; 
            }
        }
        swap(a[i], a[min_idx]);
    }
}