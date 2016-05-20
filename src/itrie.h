#ifndef ITRIE_H
#define ITRIE_H

#include <string>
#include <vector>

class Node;

class ITrie {
public:
    explicit ITrie();
    virtual ~ITrie();

    virtual bool insert(std::string word) = 0;
    virtual std::vector<std::string> find(std::string prefix) = 0;

    size_t size() const;
    size_t nodes() const;
    size_t numberOfSuggestions() const;
    void setNumberOfSuggestions(const size_t number);

protected:
    size_t m_size;  // number of word at trie
    size_t m_nodes; // number of Node for trie representation
    size_t m_maxSuggestion;
    Node *m_root;

};



#endif // ITRIE_H
