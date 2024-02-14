#include<bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define ENDL '\n'
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a.size())
#define deb(a) cout << #a << ": " << a << ENDL;
#define fore(i, a, b) for(int i(a), ThkMk(b); i < ThkMk; ++i) 
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long lli;
typedef long double ld;
typedef pair<lli, lli> ii;
typedef vector<lli> vi;

lli INF = 1e12;
vi a, b;
lli n, kk;

lli calc(int idxa, int idxb, int selected, lli acum) {
  if(selected == kk) {
    return acum;
  }
  if(idxa == n or idxb == n) return INF;
  lli ans = calc(idxa + 1, idxb + 1, selected + 1, acum + abs(a[idxa] - b[idxb]));
  ans = min(ans, calc(idxa + 1, idxb, selected, acum));
  ans = min(ans, calc(idxa, idxb + 1, selected, acum));
  return ans;
}

void solve() {
  cin >> n >> kk;
  a.resize(n); fore(i, 0, n) cin >> a[i];
  b.resize(n); fore(i, 0, n) cin >> b[i];
  vector<vi> dp(n, vi(n, INF));
  lli acum = 0;
  fore(i, 0, n) {
    acum += abs(a[i] - b[i]);
  }
  fore(i, 0, n) {
    for(int j = i; j > 0; --j) {
      lli mn = dp[j - 1][j - 1];
      fore(k, j, n) {
        dp[j][k] = min(dp[j][k], mn + abs(a[k] - b[i]));
        mn = min(mn, dp[j - 1][k]);
      }
    }
    fore(j, 0, n) {
      dp[0][j] = min(dp[0][j], abs(a[j] - b[i]));
    }
  }
  lli ans = dp[kk - 1][0];
  fore(i, 1, n) ans = min(ans, dp[kk - 1][i]);
  cout << ans << ENDL;
}

int main() { _
  solve();
  return 0;
}
