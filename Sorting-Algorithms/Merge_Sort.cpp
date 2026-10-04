#include <Template.h>

void merge_parts(vector<int> & a, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++) L[i] = a[left + i];
    for(int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> & a, int left, int right)
{
    if(left >= right) return;

    int mid = left + (right - left) / 2;
    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);
    merge_parts(a, left, mid, right);
}