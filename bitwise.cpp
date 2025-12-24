~(1 << x)	//all bits set expect x-th bit
n ^ (1 << x)	//flips the x-th bit
n & ~(1 << x)	//clears the x-th bit
(n >> x) & 1	//true if x-th bit of n is set
(n & ((1 << x) – 1)) == 0	//true if n is a power of 2x 
n & (n – 1)	//clears the rightest bit
n && !(n & (n-1))	//true if n is a power of 2
n & -n	//extract last set bit
