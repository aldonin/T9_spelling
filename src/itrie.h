#ifndef ITRIE_H
#define ITRIE_H

#include <string>
#include "node.h"

class ITrie {
public:
    explicit ITrie(size_t size = 0);
    virtual ~ITrie();
    virtual bool insert(std::string word) = 0;
    virtual std::string find(std::string prefix) = 0;
    size_t size() const;
    size_t nodes() const;

protected:
    size_t m_size;  // number of word at trie
    size_t m_nodes; // number of Node for trie representation
    Node *m_root;
};



#endif // ITRIE_H
