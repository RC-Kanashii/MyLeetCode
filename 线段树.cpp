#include <iostream>
using namespace std;

const int MAX_LEN = 1005;


// arr: 原数组  tree: 线段树  node: 当前创建的节点  start: node对应区间(指arr)左端  end: node对应区间右端
void build_tree(int arr[], int tree[], int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }

    int mid = start + end >> 1;
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2;

    build_tree(arr, tree, left_node, start, mid);
    build_tree(arr, tree, right_node, mid +  1, end);
    tree[node] = tree[left_node] + tree[right_node];
}

// arr: 原数组  tree: 线段树  node: 当前要修改的节点  start: node对应区间(指arr)左端  end: node对应区间右端  idx: 待修改的元素下标  val: 修改后的值
void update_tree(int arr[], int tree[], int node, int start, int end, int idx, int val) {
    if (start == end) {  // 已经定位到要修改的节点了（此时start == end == idx）
        arr[idx] = val;  // 直接修改arr[idx]的值
        tree[node] = val;  // 当start == end == idx时，node即表示[start, end]的区间和，已经只覆盖一个元素了，直接修改即可
        return;
    }
    int mid = start + end >> 1;
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2;

    // 检查修改node的左分支还是右分支
    if (idx >= start && idx <= mid) {
        update_tree(arr, tree, left_node, start, mid, idx, val);
    } else {
        update_tree(arr, tree, right_node, mid + 1, end, idx, val);
    }
    tree[node] = tree[left_node] + tree[right_node];
}

// arr: 原数组  tree: 线段树  node: 当前要修改的节点  start: node对应区间(指arr)左端  end: node对应区间右端  L: 查找区间左端  R: 查找区间右端
int query_tree(int arr[], int tree[], int node, int start, int end, int L, int R) {
    if (R < start || L > end) return 0;  // 查找区间和node对应区间没有交集
    if (start == end) return tree[node];  // 访问到叶节点了，直接返回叶结点的值
    if (L <= start && end <= R) return tree[node];  // 如果[L, R]完全覆盖了[start, end]，那直接返回tree[node]，不用再计算下面的子区间

    int mid = start + end >> 1;
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2;
    int sum_left = query_tree(arr, tree, left_node, start, mid, L, R);
    int sum_right = query_tree(arr, tree, right_node, mid + 1, end, L, R);
    return sum_left + sum_right;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int size = 6;
    int tree[MAX_LEN] = {0};

    build_tree(arr, tree, 0, 0, size - 1);

    for (int i = 0; i < 15; i++) {
        cout << "tree[" << i << "] = " << tree[i] << endl;
    }

    cout << endl;

    update_tree(arr, tree, 0, 0, size - 1, 4, 6);
    for (int i = 0; i < 15; i++) {
        cout << "tree[" << i << "] = " << tree[i] << endl;
    }

    cout << query_tree(arr, tree, 0, 0, size - 1, 2, 5);
}
