#include <iostream>
#include <cmath>
using namespace std;

int arr[] = {1, 2, 4, 1, 7, 8, 3};

int rec_opt(int arr[], int i) {
    if (i == 0) return arr[i];
    else if (i == 1) return max(arr[0], arr[i]);
    else return max(rec_opt(arr, i - 2) + arr[i], rec_opt(arr, i - 1));
}

int main() {
    cout << rec_opt(arr, 6);
    return 0;
}
