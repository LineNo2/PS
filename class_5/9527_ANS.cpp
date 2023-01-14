#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;
ll a, b;

ll sum(ll x) {
	ll ret = 0;
	for (int i = 0; i < 55; i++) ret += (x + 1 >> i + 1 << i) + max<ll>(0, (x + 1) % (1LL << i + 1) - (1LL << i));
	return ret;
}

int main() {
	fastio;
	cin >> a >> b;
	cout << sum(b) - sum(a - 1) << '\n';
}

