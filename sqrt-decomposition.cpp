// sqrt decomposition easy slow way (0-indexed)
// int len = (int) sqrt (n + .0) + 1; 
vector<int> b (SQ);
for (int i=0; i<n; ++i)
    b[i / len] += a[i];

int l, r;
// read input data for the next query
int sum = 0;
for (int i=l; i<=r; ) {
    if (i % SQ == 0 && i + SQ - 1 <= r) {
        // if the whole block starting at i belongs to [l, r]
        sum += b[i / SQ];
        i += SQ;
    }
    else sum += a[i++];
}


// sqrt decomposition hard fast way
int sum = 0;
int c_l = l / SQ, c_r = r / SQ;
if (c_l == c_r)
    for (int i=l; i<=r; ++i)
        sum += a[i];
else {
    for (int i = l; i <= (c_l+1)*SQ-1; i++)
        sum += a[i];
    for (int i=c_l+1; i<=c_r-1; ++i)
        sum += b[i];
    for (int i=c_r*len; i<=r; ++i)
        sum += a[i];
}