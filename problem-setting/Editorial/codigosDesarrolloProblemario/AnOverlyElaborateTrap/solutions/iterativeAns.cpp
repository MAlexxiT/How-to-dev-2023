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

lli n, m;

ii replace(ii u, ii v) {
  if(u.f == -1) return v;
  if(v.f > u.f) return v;
  if(u.f == v.f) return {u.f, min(u.s, v.s)};
  return u;
}

bool ok(int u, int v) {
  return (u >= 0 and u < n) and (v >= 0 and v < m);
}

vector<vector<bool>> source;

int f(int r, int c) {
  int ret = 4;
  for(int i = -3; i <= 3; ++i) {
    for(int j = -3; j <= 3; ++j) {
      int dist = abs(i) + abs(j);
      if(ok(r + i, c + j) and dist <= 3) {
        if(source[r + i][c + j]) ret= min(ret, dist);
      }
    }
  }
  return ret;
}
void solve() {
  cin >> n >> m;
  lli k; cin >> k;
  if(k == (n * m)) {
    cout << -1 << ENDL;
    return;
  }
  vector<ii> q(k);
  source.clear();
  source.assign(n, vector<bool>(m, false));
  fore(i, 0, k) {
    cin >> q[i].f >> q[i].s;
    source[q[i].f][q[i].s] = true;
  }
   vector<ii> v(5, {-1, -1});
  fore(i, 0, n) {
    fore(j, 0, m) {
      ii p = {i, j};
      lli dd = f(i, j);
      v[dd] = replace(v[dd], p);
    }
  }
  for(int i = 4; i >= 0; --i) {
     if(v[i].f != -1) {
      cout << v[i].f << " " << v[i].s;
      return;
     }
  }
  cout << -1 << ENDL;
}

int main() { _
  solve();
  return 0;
}
