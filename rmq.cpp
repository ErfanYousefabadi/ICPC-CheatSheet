for (int j = 1; j < LG; j++) 
    for (int i = 1; i + (1 << j) <= m + 1; i++) 
        dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);

ll get (int l, int r) {
    if (l > r) swap(l, r);
    int x = r - l;
    if (x == 0) return a[r];
    x = 31 - __builtin_clz(x);
    return max(dp[l][x], dp[l + (r - l + 1) - (1LL << x)][x]);
}