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

lli INF = 1e18;

struct Segtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct Node{
    lli s, mn;
    Node(lli s = 0, lli mn = INF): s(s), mn(mn) {}
    Node operator + (const Node &n){
      return Node(s + n.s, min(mn, n.mn));
    }
  };
  vector<Node> st;
  Segtree(int n): st(2 * n) {}
  void update(int u, int l, int r, int kth, lli val){ // O(logN)
    if(l == r){
      st[u].s = min(val, st[u].s);
      st[u].mn = min(val, st[u].mn);
      return;
    }
    if(kth <= mid) update(left(u), l, mid, kth, val);
    else update(right(u), mid + 1, r, kth, val);
    st[u] = st[left(u)] + st[right(u)];
  }
  Node query(int u, int l, int r, int ll, int rr){ // O(logN)
    if(l > r or r < ll or l > rr) return Node();
    if(ll <= l and r <= rr) return st[u];
    return query(left(u), l, mid, ll, rr) + query(right(u), mid + 1, r, ll, rr);
  }
};

typedef pair<ii, lli> iii;

bool cmp(iii a, iii b) {
  if(a.f.f == b.f.f) return a.f.s > b.f.s;
  return a.f.f < b.f.f;
}

void solve() {
  lli m, t; cin >> m >> t;
  vector<iii> v(t);
  fore(i, 0, t) {
    cin >> v[i].f.f >> v[i].f.s >> v[i].s;
    v[i].f.s = min(v[i].f.s, m);
  }
  sort(all(v), cmp);
  Segtree seg(m + 1);
  seg.update(0, 0, m, 0, 0);
  for(auto it : v) {
    if(it.f.f >= it.f.s) continue;
    auto q = seg.query(0, 0, m, it.f.f, it.f.s - 1LL);
    lli cur = q.mn + it.s;
    seg.update(0, 0, m, it.f.s, cur); 
  }
  lli ans = seg.query(0, 0, m, m, m).mn;
  cout << (ans == INF ? -1 : ans) << ENDL;
}

int main() { _
  solve();
  return 0;
}
