#include <Template.h>

int set_bit(int n, int bit)
{
    return n | (1LL << bit);
}

bool is_set(unsigned int n, int bit)
{
    return (n >> bit) & 1LL;
}

int flip_bit(int n, int bit)
{
    return n ^ (1LL << bit);
}

int clear_bit(int n, int bit) // make bit = 0
{
    return n & ~(1LL << bit);
}

int isolate_lowest_set_bit(int n) // lsb = 1, remaining bits = 0
{
    return n & -n;
}

int clear_lowest_set_bit(int n) // lsb = 0
{
    return n & (n - 1);
}

bool is_odd(int n)
{
    return n & 1LL;
}

bool is_even(int n)
{
    return !(n & 1LL);
}

bool is_power_of_two(unsigned int n)
{
    return n && !(n & (n - 1));
}

bool is_divisible_by_power_of_two(int n, int k)
{
    int powerOf2 = 1 << k;
    return (n & (powerOf2 - 1)) == 0;
}

int count_set_bits(int n)
{
    int count = 0;
    while(n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int count_bits(int n)
{
    int count = 0;
    while(n > 0)
    {
        count++;
        n >>= 1LL;
    }
    return count;
}

ll count_ones(ll n)
{
    int c = 0;
    for(int bit = 0; bit < 64; bit++)
    {
        if((n >> bit) & 1LL) c++;
    }
    return c;
}

int binary_to_decimal(string bin)
{
    int res = 0;
    for(char c : bin)
    {
        res = res * 2 + (c - '0');
    }
    return res;
}


string decimal_to_binary(int n)
{
    if(n == 0) return "0"; 

    string binary = "";
    while(n > 0)
    {
        binary = char((n % 2) + '0') + binary;
        n /= 2;
    }
    return binary;
}

int msb(int n) // most significant bit
{
    int pos = 0;
    while(n > 1)
    {
        n >>= 1LL;
        pos++;
    }
    return (1LL << pos);
}
