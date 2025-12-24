ll pw[N], ps[N], seg[N << 2], lazy[N << 2], n;
string s;
 
void build (int x = 1, int l = 0, int r = n) {
  if (r - l == 1) {
    seg[x] = s[l] - '0';
    return;
  }
  int md = (l + r) >> 1;
  build(x << 1, l, md);
  build(x << 1 | 1, md, r);
  seg[x] = (seg[x << 1] + seg[x << 1 | 1] * pw[md - l] % mod) % mod;
}
 
void shift (int x, int l, int r) {
  if (lazy[x] == -1) return;
  seg[x] = ps[r - l] * lazy[x] % mod;
  if (r - l > 1) {
    lazy[x << 1] = lazy[x];
    lazy[x << 1 | 1] = lazy[x];
  }
  lazy[x] = -1;
}
 
void upd (int l, int r, ll val, int cl = 0, int cr = n, int x = 1) {
  shift(x, cl, cr);
  if (cl >= r || cr <= l) return;
  if (cl >= l && cr <= r) {
    lazy[x] = val;
    shift(x, cl, cr);
    return;
  }
  int md = (cl + cr) >> 1;
  upd(l, r, val, cl, md, x << 1);
  upd(l, r, val, md, cr, x << 1 | 1);
  seg[x] = (seg[x << 1] + seg[x << 1 | 1] * pw[md - cl] % mod) % mod;
}
 
ll get (int l, int r, int cl = 0, int cr = n, int x = 1) {
  shift(x, cl, cr);
  if (cl >= r || cr <= l) return 0;
  if (cl >= l && cr <= r) return seg[x];
  int md = (cl + cr) >> 1;
  return (get(l, r, cl, md, x << 1) + get(l, r, md, cr, x << 1 | 1) * pw[max(0, min(r, md) - max(l, cl))] % mod) % mod;
}
pw[0] = 1;
ps[1] = 1;
for (int i = 1; i < N - 1; i++) {
  pw[i] = pw[i - 1] * P % mod;
  ps[i + 1] = (ps[i] + pw[i]) % mod;
}
memset(lazy, -1, sizeof lazy);