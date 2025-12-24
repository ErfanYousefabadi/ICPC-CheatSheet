void Getsz (int v, int p = 0) {
    sz[v] = 1;
    for (auto u: adj[v]) {
        if (u - p && !mark[u]) {
            Getsz(u, v);
            sz[v] += sz[u];
        }
    }
}

int Cen (int v, int Size, int p = 0) {
  for (auto u: adj[v])
        if (u - p && !mark[u] && sz[u] * 2 > Size) 
            return Cen(u, Size, v);
  return v;
}

void dfs (int v, char x) {
    Getsz(v);
    int c = Cen(v, sz[v]);
    val[c] = x;
    mark[c] = true;
    for (auto u: adj[c])
        if (!mark[u]) 
            dfs(u, x + 1);
}
