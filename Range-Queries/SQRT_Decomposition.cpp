#include <Template.h>

class SqrtDecomposition
{
private:
    int n, SQ, blocks;
    vector<int> blk, lazy, a;

    void process()
    {
        for(int i = 0; i < n; i++)
        {
            blk[i / SQ] += a[i];
        }
    }

public:
    SqrtDecomposition(int n, const vector<int>& a)
    {
        this->n = n;
        this->a = a;

        SQ = sqrt(n) + 1;
        blocks = (n + SQ - 1) / SQ;

        blk.assign(blocks, 0);
        lazy.assign(blocks, 0);

        process();
    }

    // Range Add [l, r] += x
    void update(int l, int r, int x)
    {
        while(l <= r)
        {
            int id = l / SQ;
            int start = id * SQ;
            int en = min(n - 1, start + SQ - 1);

            if(l == start && en <= r)
            {
                lazy[id] += x;
                blk[id] += x * (en - start + 1);
                l = en + 1;
            }
            else
            {
                a[l] += x;
                blk[id] += x;
                l++;
            }
        }
    }

    // Range Sum Query [l, r]
    int query(int l, int r)
    {
        int res = 0;

        while(l <= r)
        {
            int id = l / SQ;
            int start = id * SQ;
            int en = min(n - 1, start + SQ - 1);

            if(l == start && en <= r)
            {
                res += blk[id];
                l = en + 1;
            }
            else
            {
                res += a[l] + lazy[id];
                l++;
            }
        }

        return res;
    }

    // Point Query
    int get(int idx)
    {
        return a[idx] + lazy[idx / SQ];
    }
};