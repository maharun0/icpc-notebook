// pbds set // more like a indexed set
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>,
rb_tree_tag,tree_order_statistics_node_update> pbds;

/*  pbds s; s.insert(x);
    int value = *s.find_by_order(index);
    int index = s.order_of_key(value); */