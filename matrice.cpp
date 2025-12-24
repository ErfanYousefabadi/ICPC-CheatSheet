struct Matrix {
    ll n, m, a[200][200];
    Matrix (const ll &n1, const ll &m1) {
        n = n1, m = m1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = 0;
    }
    Matrix operator * (const Matrix &b) {
        Matrix c = Matrix(n, b.m);
        for (int i = 0; i < n; i++)
            for (int k = 0; k < m; k++)
                for (int j = 0; j < b.m; j++) 
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j] % mod) % mod;
        return c;
    }
    void prnt() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << a[i][j] << ' ';
            cout << '\n';
        }
    }
    Matrix operator ^ (ll b) {
        Matrix M = Matrix(n, m);
        Matrix O = Matrix(n, m);
        for (int i = 0; i < n; i++)
            M.a[i][i] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                O.a[i][j] = a[i][j];
        while (b) {
            if (b & 1) M = M * O;
            O = O * O;
            b >>= 1;
        }
        return M;
    }
};
