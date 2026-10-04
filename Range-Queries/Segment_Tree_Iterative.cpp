#include <Template.h>

// iterative segment tree for range queries
struct Node
{
    int sum;

    Node()
    {
        sum = 0;
    }

    Node(int x)
    {
        sum = x;
    }

    void change(int x)
    {
        // sum += x for adding
        sum = x; // for updating
    }
};

struct segTree
{
    int tree_size;
    vector<Node> segData;

    segTree(int n)
    {
        tree_size = n;
        segData.assign(2 * tree_size, Node());
    }

    Node merge(Node &lf, Node &ri)
    {
        Node res = Node();
        res.sum = lf.sum + ri.sum; 
        return res;
    }

    void set(int idx, int val)
    {
        int i = idx + tree_size;
        segData[i].change(val);
        for(i /= 2; i > 0; i /= 2)
        {
            segData[i] = merge(segData[2 * i], segData[2 * i + 1]);
        }
    }

    //  [l, r)
    int get(int l, int r)
    {
        Node res_left = Node();
        Node res_right = Node();

        for (l += tree_size, r += tree_size; l < r; l /= 2, r /= 2)
        {
            if(l & 1)
            {
                res_left = merge(res_left, segData[l]);
                l++;
            }
            if(r & 1)
            {
                --r;
                res_right = merge(segData[r], res_right);
            }
        }
        return merge(res_left, res_right).sum;
    }

    void init(vector<int> &a)
    {
        for(int i = 0; i < tree_size; i++)
        {
            if(i < sz(a))
                segData[tree_size + i] = Node(a[i]);
        }
        for(int i = tree_size - 1; i > 0; --i)
        {
            segData[i] = merge(segData[2 * i], segData[2 * i + 1]);
        }
    }
};