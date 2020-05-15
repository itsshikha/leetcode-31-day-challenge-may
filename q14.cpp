class TrieNode{
    public:
    bool isEnd = false;
    TrieNode *children[26];
    TrieNode(){
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isEnd = false;
    }
};
class Trie {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* temp = root;
        for(int i=0; i<word.size(); i++){
            int ind = word[i]-'a';
            if(temp->children[ind] == NULL){
                temp->children[ind] = new TrieNode();
            }
            temp = temp->children[ind];
        }
        temp->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* temp = root;
        for(int i=0; i<word.size();i++){
            int ind = word[i]-'a';
            if(temp->children[ind] == NULL)
                return false;
            temp = temp->children[ind];
        }
        return temp->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(int i=0; i<prefix.size();i++){
            int ind = prefix[i]-'a';
            if(temp->children[ind] == NULL)
                return false;
            temp = temp->children[ind];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
