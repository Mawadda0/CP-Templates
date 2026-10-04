#include <Template.h>

// 2D Fenwick Tree 0-based Indexing for range sum queries
class FenwickTree2D {
private:
    vector<vector<int>> bit;
    int n, m;

public:
    FenwickTree2D(int n, int m) : n(n), m(m)
    {
        bit.assign(n + 5, vector<int>(m + 5, 0));
    }

    void add(int x, int y, int val) // add value to point (x, y)
    {
        for(int i = x; i < n; i = i | (i + 1))
        {
            for(int j = y; j < m; j = j | (j + 1))
            {
                bit[i][j] += val;
            }
        }  
    }

    int query(int x, int y) // sum from (0, 0) to point (x, y)
    {
        int res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)
        {
            for(int j = y; j >= 0; j = (j & (j + 1)) - 1)
            {
                res += bit[i][j];
            }
        }
        return res;
    }

    int query(int x1, int y1, int x2, int y2) // sum from (x1, y1) to (x2, y2)
    {
        if(x1 > x2 || y1 > y2) return 0;
        
        int res = query(x2, y2);
        if(x1 > 0) res -= query(x1 - 1, y2);
        if(y1 > 0) res -= query(x2, y1 - 1);
        if(x1 > 0 && y1 > 0) res += query(x1 - 1, y1 - 1);
        return res;
    }

    void update(int x, int y, int val) // update point (x, y) to a new val
    {
        int curr = query(x, y, x, y);
        int delta = val - curr;
        add(x, y, delta);
    }
};