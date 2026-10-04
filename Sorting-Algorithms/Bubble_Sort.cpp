#include <Template.h>

void bubbleSort(vector<int> & a)
{
    int n = sz(a);
    bool swapp;
    for(int i = 0; i < n - 1; i++)
    {
        swapp = false;
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapp= true;
            }
        }
        if(!swapp)
        {
            break;    
        }
    }
}