// Sqrt Decomposition
struct SqrtDecom {
int block_size;
vector<int> nums;
vector<long long> blocks;
SqrtDecom(int sqrtn, vector<int> &arr) : block_size(sqrtn), blocks(sqrtn, 0) {
    nums = arr;
    for (int i = 0; i < nums.size(); i++) { blocks[i / block_size] += nums[i]; }
}

/** O(1) update to set nums[i] to v */
void update(int i, int v) {
    blocks[i / block_size] -= nums[i];
    nums[i] = v;
    blocks[i / block_size] += nums[i];
}

/** O(sqrt(n)) query for sum of [0, r) */
long long query(int r) {
    long long res = 0;
    for (int i = 0; i < r / block_size; i++) { res += blocks[i]; }
    for (int i = (r / block_size) * block_size; i < r; i++) { res += nums[i]; }
    return res;
}

/** O(sqrt(n)) query for sum of [l, r) */
long long query(int l, int r) { return query(r) - query(l - 1); }
};
// SqrtDecomp sq((int)ceil(sqrt(n)), v); // O(n)
// sq.query(l, r); // O( sqrt(n) )
// sq.update(i, v); // O(1)