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

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

lli n, m;

vector<vector<int>> vis;

bool ok(int u, int v) {
  return (u >= 0 and u < n) and (v >= 0 and v < m);
}

bool okk(int u, int v) {
  if(!ok(u, v)) return false;
  return vis[u][v] == -1;
}

void solve() {
  cin >> n >> m;
  lli k; cin >> k;
  if(k == (n * m)) {
    cout << -1 << ENDL;
    return;
  }
  vis.clear();
  vis.assign(n, vector<int>(m, -1));
  lli r, c; 
  queue<ii> q;
  fore(i, 0, k) {
    cin >> r >> c;
    vis[r][c] = 0;
    q.push({r, c});
  }
  ii ans = {-1, -1};
  lli last = 0;
  while(!q.empty()) {
    ii cur = q.front();
    q.pop();
    r = cur.f; c = cur.s;
    if(vis[r][c] > last) {
      ans = {r, c};
      last = vis[r][c];
    }
    else {
      if(r == ans.f) ans.s = min(ans.s, c);
      if(r > ans.f) ans = {r, c}; 
    }
    if(vis[r][c] == 3) continue;
    fore(i, 0, 4) {
      int nr = r + dx[i];
      int nc = c + dy[i];
      if(okk(nr, nc)) {
        vis[nr][nc] = vis[r][c] + 1;
        q.push({nr, nc});
      }
    }
  }
  fore(i, 0, n) {
    for(int j = m - 1; j >= 0; --j) {
      if(vis[i][j] == -1) {
        ans = {i, j};
      }
    }
  }
  cout << ans.f << " " << ans.s << ENDL;
}

int main() { _
  solve();
  return 0;
}
