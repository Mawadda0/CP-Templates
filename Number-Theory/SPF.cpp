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

vector<int> get_divisors(int n)
{
    vector<int> divisors = {1};

    while(n > 1)
    {
        int prime = SPF[n];
        int count = 0;
        while(n % prime == 0)
        {
            count++;
            n /= prime;
        }

        int current_size = sz(divisors);
        int p = 1;
        for(int k = 1; k <= count; k++)
        {
            p *= prime;
            for(int i = 0; i < current_size; i++)
            {
                divisors.push_back(divisors[i] * p);
            }
        }
    }
    return divisors;
}
