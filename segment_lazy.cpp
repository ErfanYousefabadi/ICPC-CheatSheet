void build(int x = 1, int l = 1, int r = n + 1) {
    if (r - l == 1) {
        seg[x] = a[l]; 
        return; 
    }
    int md = (l + r) >> 1;
    build(x << 1, l, md); 
    build(x << 1 | 1, md, r);
    seg[x] = min(seg[x << 1], seg[x << 1 | 1]);
} 
 
void shift(int x, int l, int r) {
    seg[x] += lazy[x]; 
    if(r - l > 1) {
        lazy[x << 1] += lazy[x];
        lazy[x << 1 | 1] += lazy[x];
    }
    lazy[x] = 0;
}
 
void upd(int l, int r, ll v, int cl = 1, int cr = n + 1, int x = 1) {
    shift(x, cl, cr);
    if (cl >= r || cr <= l) return;
    if (cl >= l && cr <= r) {
        lazy[x] += v;
        shift(x, cl, cr);
        return; 
    }
    int md = (cl + cr) >> 1;
    upd(l , r , v , cl , md, x << 1); 
    upd(l , r , v , md , cr, x << 1 | 1);
    seg[x] = min(seg[x << 1], seg[x << 1 | 1]);
}
ll get(int l, int r, int cl = 1, int cr = n + 1, int x = 1) {
    shift(x, cl, cr);
    if (cl >= r || cr <= l) return inf;
    if (cl >= l && cr <= r) return seg[x];
    int md = (cl + cr) >> 1;
    return min(get(l, r, cl, md, x << 1), get(l, r, md, cr, x << 1 | 1));
}
