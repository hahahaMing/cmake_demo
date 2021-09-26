#include "tools.hpp"
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
            }
            node = node->children[ch];
        }
        node->is_end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(std::string word)
    {
        return search_prefix(word)->is_end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix)
    {
        return search_prefix(prefix)!=nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Solution
{
public:
    void test()
    {
        std::cout << "test start" << std::endl;
        std::string word, prefix;
        word = "apple";
        prefix = "app";
        Trie *obj = new Trie();
        obj->insert(word);
        bool param_2 = obj->search(word);
        bool param_3 = obj->startsWith(prefix);
        std::cout << param_2 << std::endl;
        std::cout << param_3 << std::endl;
    }
};