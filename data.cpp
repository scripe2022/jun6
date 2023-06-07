// compile: make data
// run: ./data < data.in
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

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, W; cin >> n >> W;
    vector<int> h(n+1), w(n+1);
    rep(i, 1, n+1) cin >> h[i] >> w[i];
    vector<vector<int>> dp(n+1, vector<int>(n+1, INF)), maxh(n+1, vector<int>(n+1, 0)), sumw(n+1, vector<int>(n+1, 0));
    rep(i, 1, n+1) rep(j, i, n+1) {
        if (i == j) maxh[i][j] = h[i], sumw[i][j] = w[i];
        else maxh[i][j] = max(maxh[i][j-1], h[j]), sumw[i][j] = sumw[i][j-1] + w[j];
    }
    dp[0][0] = 0;
    rep(i, 0, n) {
        rep(j, 0, i+1) {
            if (sumw[i-j+1][i] > W) break;
            if (dp[i][j] == INF) continue;
            if (sumw[i-j+1][i] + w[i+1] <= W) cmin(dp[i+1][j+1], dp[i][j] + max(h[i+1] - maxh[i-j+1][i], 0ll));
            cmin(dp[i+1][1], dp[i][j] + h[i+1]);
        }
    }
    int ans = INF;
    rep(i, 0, n+1) cmin(ans, dp[n][i]);
    cout << ans << endl;

    return 0;
}