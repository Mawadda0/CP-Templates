#include <Template.h>

vector<int> vals;

void compress()
{
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
}

int get_id(int x)
{
    return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
}
