int par[N], sz[N], val[N], cnt;
vector<pii> st;

int root (int &v) {
    int res = 0;
    while (par[v] != v) 
        res ^= val[v], v = par[v];
    return res;
}
void mrg (pii e) {
    auto [v, u] = e;
    int r1 = root(v) , r2 = root(u);
    if (v == u) {
        if (r1 == r2) st.pb(pii(-2 , -2)), cnt++;
        else st.pb(pii(-1 , -1));
        return;
    }
    if (sz[v] < sz[u]) swap(v , u);
    par[u] = v;
    sz[v] += sz[u];
    st.pb(pii(v , u));
    val[u] = r1 ^ r2 ^ 1;
}

void undo() {
    pii e = st.back(); st.pop_back();
    if(e.F == -1) return;
    if(e.F == -2) return cnt-- , void();
    val[e.S] = 0;
    par[e.S] = e.S;
    sz[e.F] -= sz[e.S];
}