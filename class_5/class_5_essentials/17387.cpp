#include<bits/stdc++.h>
using namespace std;
 
typedef pair<long long, long long> Point;
 
int ccw(Point a, Point b, Point c) {
    long long ans = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
    if (ans < 0) return -1;
    if (ans > 0) return 1;
    return 0;
}

int main() {
    Point p[4];
		bool ans = false;
		for(int i =0  ; i < 4; ++i)
		cin >> p[i].first >> p[i].second;
	  long long ccw_1 = ccw(p[0], p[1], p[2]) * ccw(p[0], p[1], p[3]);
    long long ccw_2 = ccw(p[2], p[3], p[0]) * ccw(p[2], p[3], p[1]);
    if (ccw_1 == 0 && ccw_2 == 0) {
        if (p[0] > p[1]) swap(p[0], p[1]);
        if (p[2] > p[3]) swap(p[2], p[3]);
        if (p[0] <= p[3] && p[1] >= p[2]) ans = true;
        cout << ans;
				return 0;
    }
    if (ccw_1 <= 0 && ccw_2 <= 0) ans = true;
		cout << ans;
		return 0;
}
