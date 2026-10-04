#include <Template.h>

const int MAX = 1e5;
int SPF[MAX]{}; // SPF[i] = smallest prime factor of i

void precalc_spf()
{
    for(int i = 1; i < MAX; i++)
    {
        SPF[i] = i;
    }
    for(int i = 2; i * i < MAX; i++)
    {
        if(SPF[i] == i)
        {
            for(int j = i * i; j < MAX; j += i)
            {
                if(SPF[j] == j) SPF[j] = i; // assign smallest prime factor for composite number j
            }
        }
    }
}