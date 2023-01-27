#define LT(x, y) (((x) + eps) < (y))
#define GT(x, y) (((x)-eps) > (y))
#define EQ(x, y) (abs((x) - (y)) < eps)
#define LE(x, y) (LT(x, y) || EQ(x, y))
#define GE(x, y) (GT(x, y) || EQ(x, y))
#define NE(x, y) (!EQ(x, y))
#define CSB(x) __builtin_popcountll(staic_cast<unsigned long long>(x))
#define CLZ(x) __builtin_clzll(staic_cast<unsigned long long>(x))
#define CTZ(x) __builtin_ctzll(staic_cast<unsigned long long>(x))
#define ISPOW2(x) ((x) && !((x) & ((x)-1)))
#define LOG2_F(x) (63 - CLZ(x))
#define LOG2_C(x) (LOG2_F(x) + !ISPOW2(x))
#define GETBIT(x, i) (((x) >> (i)) & 1)
#define SETBIT(x, i) ((x) | (1LL << (i)))
#define CLRBIT(x, i) ((x) & ~(1LL << (i)))                             
#define INVBIT(x, i) ((x) ^ (1LL << (i)))
#define GETBITS(x, i, j) (((x) >> (i)) & ((1LL << ((j) - (i))) - 1))
#define SETBITS(x, i, j) ((x) | (((1LL << ((j) - (i))) - 1) << (i)))
#define CLRBITS(x, i, j) ((x) & ~(((1LL << ((j) - (i))) - 1) << (i)))
#define INVBITS(x, i, j) ((x) ^ (((1LL << ((j) - (i))) - 1) << (i)))