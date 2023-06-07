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
    int H = *max_element(h.begin(), h.end());
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(H+1, vector<int>(W+1, INF)));
    // i h w
    dp[0][0][0] = 0;
    rep(i, 0, n) {
        rep(j, 0, H+1) {
            rep(k, 0, W+1) {
                if (dp[i][j][k] == INF) continue;
                if (k+w[i+1] <= W) cmin(dp[i+1][max(j, h[i+1])][k+w[i+1]], dp[i][j][k] + max(h[i+1]-j, 0ll));
                cmin(dp[i+1][h[i+1]][w[i+1]], dp[i][j][k] + h[i+1]);
            }
        }
    }
    int ans = INF;
    rep(j, 0, H+1) rep(k, 0, W+1) cmin(ans, dp[n][j][k]);
    cout << ans << endl;

    return 0;
}