#include <iostream>
#include <cstdio>
using namespace std;

const int DPM[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date {
    int y;
    int m;
    int d;
};

int solveDiff(Date d1, Date d2) {
    int years_full_past = max(0, d2.y - d1.y - 1);
    int years_leap = years_full_past / 4 - years_full_past / 100 + years_full_past / 400; //(d2.y / 4 - d2.y / 100 + d2.y / 400) - (d1.y / 4 - d1.y / 100 + d1.y / 400);
    int all_days = years_full_past * 365 + years_leap;  // 中间完整度过的年份的总天数

    int days_d1 = DPM[d1.m] - d1.d;
    for (int i = d1.m + 1; i <= 12; i++) days_d1 += DPM[i];

    int days_d2 = d2.d + 1;
    for (int i = 1; i < d2.m; i++) days_d2 += DPM[i];

    return all_days + days_d1 + days_d2;
}

Date solveBen(int days_ben, Date d) {
    Date db;
    int days_d = d.d + 1;
    for (int i = 1; i < d.m; i++) days_d += DPM[i];

    int td = days_ben;
    td -= days_d;
    int years_full_past = td / 365;
    int years_leap = years_full_past / 4 - years_full_past / 100 + years_full_past / 400;
    td -= years_full_past * 365 + years_leap;  // 生日到出生那年年底经过的天数

    if (days_d > days_ben) { // 没过完
        db.y = d.y;
    }
    else {
        db.y = d.y - years_full_past - 1;
    }

    int m;
    cout << "td: " << td << endl;
    for (m = 12; td >= DPM[m]; m--) {
        td -= DPM[m];
    }
    cout << "m: " << m <<endl;
    cout << "td: " << td << endl;
    if (td == 0) {
        db.m = m - 1;
        db.d = DPM[m - 1];
    }
    else {
        db.m = m;
        db.d = DPM[m] - td;
    }

    return db;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Date d1, d2;
        int x;
        cin >> d1.y >> d1.m >> d1.d >> d2.y >> d2.m >> d2.d;
        cin >> x;
        int days_ben = x * solveDiff(d1, d2);
        cout << "ben: " << days_ben << endl;
        Date d3 = solveBen(days_ben, d2);
        printf("%d %d %d", d3.y, d3.m, d3.d);
//        cout << d3.y << d3.m << d3.d;
    }
}
