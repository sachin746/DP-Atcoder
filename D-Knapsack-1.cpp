#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
  int n, w;
  cin >> n >> w;
  vector<pi> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  vector<vector<ll>> dp(n, vector<ll>(w + 1, 0));

  for (int j = 0; j <= w; j++) {
    if (v[0].first <= j) {
      dp[0][j] = v[0].second;
    }
  }
  ll ans = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= w; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= v[i].first) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i].first] + v[i].second);
      }
    }
  }
  cout << dp[n - 1][w];
  return 0;
}
