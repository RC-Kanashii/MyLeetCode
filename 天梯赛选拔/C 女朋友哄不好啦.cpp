//#include <iostream>
//using namespace std;
//
//int main() {
//    int n;
//    char c;
//    cin >> n >> c;
//
//    // 上
//    for (int i = 0; i < n; i++) {  // n行
//        cout << ' ';
//        for (int j = 0; j < n - i - 1; j ++) cout << ' ';
//        for (int j = 0; j < 2 * (i + 2) + n - 1; j ++) cout << c;
//        for (int j = 0; j < 2 * (n - i - 1) + 1 + 2 * (n - 2); j ++) cout << ' ';
//        for (int j = 0; j < 2 * (i + 2) + n - 1; j ++) cout << c;
//        cout << endl;
//    }
//
//    // 下
//    for (int i = 0; i < n * 2; i++) {  // 2n行
//        cout << ' ';
//        for (int j = 0; j < 2 * i + 1; j ++) cout << ' ';
//        for (int j = 0; j < 4 * (n * 2 - i) - 3;j ++) cout << c;
//        cout << endl;
//    }
//}
//#include <iostream>
//using namespace std;
//
//int main() {
//    int n;
//    char c;
//    cin >> n >> c;
//
//    // 上
//    for (int i = 0; i < n; i++) {  // n行
////        cout << ' ';
//        for (int j = 0; j < n - i; j ++) cout << ' ';
//        for (int j = 0; j < 2 * i + 5; j ++) cout << c;
//        for (int j = 0; j < 2 * (n - i) - 1 + 4 * (n - 2); j ++) cout << ' ';
//        for (int j = 0; j < 2 * i + 5; j ++) cout << c;
//        cout << endl;
//    }
//
//    // 下
//    for (int i = 0; i < n * 2; i++) {  // 2n行
////        cout << ' ';
//        for (int j = 0; j < 2 * (i + 1); j ++) cout << ' ';
//        for (int j = 0; j < 4 * (n * 2 - i) - 3;j ++) cout << c;
//        cout << endl;
//    }
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//    int n;
//    char c;
//    cin >> n >> c;
//
//    // 上
//    for (int i = 0; i < n; i++) {  // n行
////        cout << ' ';
//        for (int j = 0; j < n - i; j ++) cout << ' ';
//        for (int j = 0; j < (n - 1) * i + 5; j ++) cout << c;
//        for (int j = 0; j < n * (n - i); j ++) cout << ' ';
//        for (int j = 0; j < (n - 1) * i + 5; j ++) cout << c;
//        cout << endl;
//    }
//
//    // 下
//    for (int i = 0; i < n * 2; i++) {  // 2n行
////        cout << ' ';
//        for (int j = 0; j < 2 * (i + 1); j ++) cout << ' ';
//        for (int j = 0; j < 4 * (n * 2 - i) - 3;j ++) cout << c;
//        cout << endl;
//    }
//}

#include <iostream>
using namespace std;

int main() {
    int n;
    char c;
    cin >> n >> c;

    // 上
    int max_shang = (4 * (n * 2) - 2) / 2;
    int d = (max_shang - 5) / (n - 1);
    cout << max_shang << "  " << d << endl;
    for (int i = 0; i < n; i++) {  // n行
//        cout << ' ';
        for (int j = 0; j < n - i; j ++) cout << ' ';
        for (int j = 0; j < d * i + 5; j ++) cout << c;
        for (int j = 0; j < 2 * (n - 1) * (n - i - 1) + 1; j ++) cout << ' ';
        for (int j = 0; j < d * i + 5; j ++) cout << c;
        cout << endl;
    }

    // 下
    for (int i = 0; i < n * 2; i++) {  // 2n行
//        cout << ' ';
        for (int j = 0; j < 2 * (i + 1); j ++) cout << ' ';
        for (int j = 0; j < 4 * (n * 2 - i) - 3;j ++) cout << c;
        cout << endl;
    }
}
