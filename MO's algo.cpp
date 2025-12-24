// erfan
bool cmp(pair<pii, int> a, pair<pii, int> b) {
  if (a.F.F / SQ != b.F.F / SQ) return a.F.F < b.F.F;
  return ((a.F.F / SQ) & 1) ? (a.F.S > b.F.S) : (a.F.S < b.F.S);
}

add(1);
int cl = 1, cr = 1;
for (auto que: Q) {
    int l = que.F.F, r = que.F.S, idx = que.S;
    if (cl >= l && cr <= r) {
        while (cr < r) add(++cr);
        while (cl > l) add(--cl);
    }
    if (cl <= l && cr <= r) {
        while (cl < l) rm(cl++);
        while (cr < r) add(++cr);
    }
    if (cl >= l && cr >= r) {
        while (cl > l) add(--cl);
        while (cr > r) rm(cr--);
    }
    if (cl <= l && cr >= r) {
        while (cl < l) rm(cl++);
        while (cr > r) rm(cr--);
    }
    res[idx] = ans;
}

// mahdi
struct Query {
    int l, r, idx;
};

bool cmp(Query &a, Query &b) {
    int A = a.l / sqr;
    int B = b.l / sqr;
    if (A != B) return A < B;
    return (A & 1) ? (a.r > b.r) : (a.r < b.r);
}

vector<Query> queries(q);
for(int i = 0; i < q; i++) {
    cin >> queries[i].l >> queries[i].r;
    queries[i].l--;
    queries[i].idx = i;
}
sort(all(queries), cmp);
ll cur = 0;
int L = 0, R = -1;

auto add = [&](int pos) {
    cur += a[pos];
};
auto remove = [&](int pos) {
    cur -= a[pos];
};

for (auto &qr : queries) {
    while (R < qr.r) add(++R);
    while (R > qr.r) remove(R--);
    while (L < qr.l) remove(L++);
    while (L > qr.l) add(--L);
    ans[qr.idx] = cur;
}
