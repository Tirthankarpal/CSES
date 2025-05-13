#include "bits/stdc++.h"
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        }
        else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);       
            build(arr, 2 * node + 2, mid + 1, end);   
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return INT_MAX;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftMin = query(2 * node + 1, start, mid, l, r);
        int rightMin = query(2 * node + 2, mid + 1, end, l, r);
        return min(leftMin, rightMin);
    }
    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    int rangeMinQuery(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    void updateValue(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }
};
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    SegmentTree st(a);
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<st.rangeMinQuery(l-1,r-1)<<endl;
    }
}