template <class T>
struct SegmentTree{
private:
	int n;
	vector<T> tree;
	
	void buildTree(const vector<T>& v, int node, int b, int e){
		if(b==e){tree[node] = v[b];return;}
		int mid = (b+e)>>1, ln = node<<1, rn = ln+1;
		buildTree(v, ln, b, mid);
		buildTree(v, rn, mid+1, e);
		tree[node] = merge(tree[ln],tree[rn]);
	}

	T query(int node, int b, int e, int l, int r){
		if(l > e or r < b) return identity;
		if(l<=b and r>=e) return tree[node];
		int mid = (b+e)>>1, ln = node<<1, rn = ln+1;
		T c1 = query(ln, b, mid, l, r);
		T c2 = query(rn, mid+1, e, l, r);
		return merge(c1,c2);
	}
	
	void set(int node, int b, int e, int ind, T val){
		if(ind > e or ind < b) return;
		if(ind<=b and ind>=e){
			tree[node] = val; 
			return;
		}
		int mid = (b+e)>>1, ln = node<<1, rn = ln+1;
		if (ind <= mid) set(ln, b, mid, ind, val);
		else set(rn, mid+1, e, ind, val);
		tree[node] = merge(tree[ln],tree[rn]);
	}

	void update(int node, int b, int e, int ind, T val){
		if(ind > e or ind < b) return;
		if(ind<=b and ind>=e){
			tree[node] = merge(tree[node], val);
			return;
		}
		int mid = (b+e)>>1, ln = node<<1, rn = ln+1;
		if (ind <= mid) update(ln, b, mid, ind, val);
		else update(rn, mid+1, e, ind, val);
		tree[node] = merge(tree[ln],tree[rn]);
	}

public:
	T query(int l, int r){return query(1, 0, n-1, l, r);}
	void set(int ind, T val){set(1, 0, n-1, ind, val);}
	void update(int ind, T val){update(1, 0, n-1, ind, val);}
	
	SegmentTree(const vector<T>& input) {
		n = input.size();
		int sz = n<<2; // 4n
		tree.resize(sz);
		buildTree(input, 1, 0, n-1);
	}

	T merge(const T& a, const T& b) { return a + b; }
	T identity = 0;
};

/*
	vector<int> v(n); cin >> v;

	SegmentTree<int> segTree(v); // All 0 based index

	segTree.query(left-1, right-1);
	segTree.set(index-1, value);
	segTree.update(index-1, increasingValue);
*/