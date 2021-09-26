#include"tools.hpp"

using namespace std;

class Trie
{
private:
    std::vector<Trie *> children;
    bool is_end;
 
    Trie *search_prefix(std::string word)
    {
        
        Trie *node = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
                return nullptr;
            node = node->children[ch];
        }
        return node;
    }
 
public:
    /** Initialize your data structure here. */
    Trie() : children(26, nullptr), is_end(false) {}
    /** Inserts a word into the trie. */
    void insert(std::string word)
    {
        Trie* node = this;
        for(char ch:word){
            ch-='a';
            if(node->children[ch]==nullptr){
                node->children[ch] = new Trie();

// Start testing!
int main() {
    cout << "hello cmake!" << endl;
    return 0;
}
