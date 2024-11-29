// pbds set // more like a indexed set
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>,
rb_tree_tag,tree_order_statistics_node_update> pbds;

void getMoAnswer(vector<int>& v, vector<array<int, 5>>& queries, vector<int>& ans) {
    pbds oset; // ordered set
    auto add = [&](int x) -> void { oset.insert(v[x]); };
    auto remove = [&](int x) -> void { oset.erase(v[x]); };
    auto get = [&](int k) -> int { return *oset.find_by_order(k-1); };

    sort(all(queries));
    int left = 0, right = -1;
    for (auto& [b, r, l, idx, k] : queries) {
        while(right < r) add(++right);  while(right > r) remove(right--);
        while(left < l) remove(left++); while(left > l) add(--left);
        ans[idx] = get(k);
    }
}
// v = main array, // N = v.size()
queries.push_back({l/sqrtN, r, l, idx, k}); // for each query
// sort quiries according to -> starting block, and then r wise sort
// gives k'th smallest number's index in [l, r) range