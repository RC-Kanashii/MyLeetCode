#include <iostream>
using namespace std;

const int M = 5005;
int pic[M][M] = {0};

int main() {
    int N, R;
    cin >> N >> R;
    R = min(R, 5001);
    while(N--) {
        int x, y, v;
        cin >> x >> y >> v;
        pic[x + 1][y + 1] += v;
    }

    for (int i = 1; i <= 5001; i++) {
        for (int j = 1; j <= 5001; j++) {
//            if (j == 0) pic[i][j] = pic[i - 1][j];
            pic[i][j] = pic[i][j] + pic[i - 1][j] + pic[i][j - 1] - pic[i - 1][j - 1];
        }
    }

    int maxx = 0;
    for (int i = R; i <= 5001; i++) {
        for (int j = R; j <= 5001; j++) {
            maxx = max(maxx, pic[i][j] - pic[i - R][j] - pic[i][j - R] + pic[i - R][j - R]);
        }
    }

    cout << maxx;
    return 0;
}
