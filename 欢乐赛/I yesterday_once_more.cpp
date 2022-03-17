#include <iostream>
#include <vector>
#include <map>
using namespace std;

//long long mem[65] = {0};
map<vector<long long>, long long> mem;

long long yesterday_once_more(int start, int count, int end) {
    if (count == 0) {
        mem[{start, count, end}] = end - (start-1);
        return end - (start-1);
    }
    long long sum = 0;
    for (int i = start; i <= end - count + 1; i++) {
        int t = mem[{i + 1, count - 1, end}];
        if (t == 0) {
            t = yesterday_once_more(i + 1, count - 1, end);
            mem[{i + 1, count - 1, end}] = t;
            sum += t;
        }
        else sum += t;
//        mem[{start, count, end}] = end - (start-1);
//        sum += yesterday_once_more(i + 1, count - 1, end);
    }
    return sum;
}

int main() {
    int start, cnt, endd;
    cin >> start >> cnt >> endd;
    cout << yesterday_once_more(start, cnt, endd);
    return 0;
}
