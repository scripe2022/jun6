// compile: make brute
// run: ./brute < data.in
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#ifdef LOCAL
#include <debug/codeforces.h>
#define debug(x...) _debug_print(#x, x);
#else
#define debug(x...) {};
#endif
template<typename...Args> void print_(Args...args){((cout<<args<<" "),...)<<endl;}
#define rep(i,a,b) for(int i=(a);i<(int)(b);++i)
#define sz(v) ((int)(v).size())
#define print(...) print_(__VA_ARGS__);
#define cmin(x,...) x=min({(x), __VA_ARGS__})
#define cmax(x,...) x=max({(x), __VA_ARGS__})
#define INTMAX (int)(9223372036854775807)
#define INF (int)(1152921504606846976)
#define double long double
#define int long long
#define MAXN 200010

int bit(int x, int i) {
    return (x >> i) & 1;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, W; cin >> n >> W;
    vector<int> h(n), w(n);
    rep(i, 0, n) cin >> h[i] >> w[i];
    int minh = INF;
    rep(i, 0, 1<<n) {
    // rep(i, 2, 3) {
        bool valid = 1;
        int th = 0, tw = 0;
        int total = 0;
        rep(j, 0, n) {
            if (!bit(i, j)) tw += w[j], cmax(th, h[j]);
            if (tw > W) {
                valid = 0;
                break;
            }
            if (bit(i, j)) {
                tw = w[j];
                total += th;
                th = h[j];
            }
        }
        total += th;
        // debug(i, total)
        if (valid) cmin(minh, total);
    }
    cout << minh << endl;

    return 0;
}