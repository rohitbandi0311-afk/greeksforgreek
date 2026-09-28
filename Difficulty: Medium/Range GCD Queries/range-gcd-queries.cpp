#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> tree;
    int n;

    // Helper function to build the segment tree
    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(arr, 2 * node + 1, start, mid);
        build(arr, 2 * node + 2, mid + 1, end);
        tree[node] = std::gcd(tree[2 * node + 1], tree[2 * node + 2]);
    }

    // Helper function to update an element in the segment tree
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node + 1, start, mid, idx, val);
        } else {
            update(2 * node + 2, mid + 1, end, idx, val);
        }
        tree[node] = std::gcd(tree[2 * node + 1], tree[2 * node + 2]);
    }

    // Helper function to query range GCD
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0; // Identity element for GCD
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        int p1 = query(2 * node + 1, start, mid, l, r);
        int p2 = query(2 * node + 2, mid + 1, end, l, r);

        if (p1 == 0) return p2;
        if (p2 == 0) return p1;
        return std::gcd(p1, p2);
    }

public:
    vector<int> processQueries(vector<int>& arr, vector<vector<int>>& queries) {
        n = arr.size();
        tree.resize(4 * n, 0);
        build(arr, 0, 0, n - 1);

        vector<int> result;
        for (const auto& q : queries) {
            if (q[0] == 0) {
                // Type 1: Range GCD query [0, l, r]
                result.push_back(query(0, 0, n - 1, q[1], q[2]));
            } else {
                // Type 2: Point update [1, index, value]
                update(0, 0, n - 1, q[1], q[2]);
            }
        }
        return result;
    }
};