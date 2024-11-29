// Trie
struct Node {
    Node *links[26];
    int cp = 0, cw = 0;

    bool containsRef(char c) { return links[c - 'a'] != NULL;}
    void putRef(char c, Node *node) { links[c - 'a'] = node; }
    Node* getRef(char c) { return links[c - 'a']; }
    
    void incPrefix() { cp++; }
    void decPrefix() { cp--; }
    int countPrefixes() { return cp; }

    void incWord() { cw++; }
    void decWord() { cw--; }
    int countWords() { return cw; }
    
};

struct Trie {
    Node *root;
    Trie() { root = new Node(); }
                                                                                                                                            
    // O( len(word) )
    void insert(string& word) {
        Node *node = root;
        for (auto& c : word) {
            if (!node->containsRef(c)) {
                node->putRef(c, new Node());
            }
            node = node->getRef(c);
            node->incPrefix();
        }
        node->incWord();
    }

    // O( len(word) )
    void remove(string& word) {
        Node *node = root;
        for (auto& c : word) {
            if (!node->containsRef(c)) return;
            node = node->getRef(c);
            node->decPrefix();
        }
        node->decWord();
    }

    // O( len(word) )
    int countWordsEqualTo(string& word) {
        Node *node = root;
        for (auto& c : word) {
            if (!node->containsRef(c)) return 0;
            node = node->getRef(c);
        }
        return node->countWords();
    }

    // O( len(word) )
    int countWordsStartingWith(string& prefix) {
        Node *node = root;
        for (auto& c : prefix) {
            if (!node->containsRef(c)) return 0;
            node = node->getRef(c);
        }
        return node->countPrefixes();
    }
};
// Trie trie;