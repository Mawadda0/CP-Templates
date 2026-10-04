#include <Template.h>

bool is_prime(ll n)
{
    if(n == 2) return 1;
    if((n == 0 || n == 1) || n % 2 == 0) return 0;
    for(ll i = 3; i * i <= n; i+= 2)
    {
        if(n % i == 0) return 0;
    }
    return 1;
} // with time O(sqrt(n) / 2)