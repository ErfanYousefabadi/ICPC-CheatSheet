ll fen[N][N]; //or map<pii, int> fen;

void upd (int x, int y, int v) {
    for (; x <= n; x += x & (-x))
        for (int i = y; i <= n; i += i & (-i))
            fen[x][i] += v;
}
 
ll get (int x, int y) {
    ll res = 0;
    for (; x; x -= x & (-x))
        for (int i = y; i; i -= i & (-i))
            res += fen[x][i];
    return res;
}

ll get (int x1, int y1, int x2, int y2) {
    return get(x2, y2) - get(x2, y1 - 1) - get(x1 - 1, y2) + get(x1 - 1, y1 - 1);
}
