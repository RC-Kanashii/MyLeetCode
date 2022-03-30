#include <iostream>
using namespace std;

const int M = 100005;
int arr[M] = {0};
int bit[M] = {0};

inline int lowbit(int x) {
    return x & (-x);
}

void build(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i - lowbit(i) + 1; j <= i; j++) {
            bit[i] += arr[j];
        }
    }
}

int query(int a) {  // 查[1, a]区间和
    int sum = 0;
    for (int i = a; i >= 1; i -= lowbit(i)) {
        sum += bit[i];
    }
//    cout << "sum: " << sum << endl;
    return sum;
}

int query(int a, int b) {  // 查[a, b]区间和
    return query(b) - query(a - 1);
}

void add(int a, int b, int n) {  // 第a个数加b
    for (int i = a; i <= n; i += lowbit(i)) {
        bit[i] += b;
//        cout << "bit[" << i << "]: " << bit[i] << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(n);
//    for (int i = 1; i <= n; i++) cout << bit[i] << ' ';
//    cout << endl;
    while (m--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0) {  // 求区间和
            cout << query(a, b) << endl;
        } else {
            add(a, b, n);
        }
    }
}
