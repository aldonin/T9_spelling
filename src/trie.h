#ifndef TRIE_H
#define TRIE_H

#include "itrie.h"
#include <QtGlobal>

class Trie : public ITrie
{
public:
    Trie();
    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;

    std::vector<std::string> find(std::string prefix) const Q_DECL_OVERRIDE;
    bool insert(std::string word) Q_DECL_OVERRIDE;

private:
    // find the first node which fully contains prefix word,
    // return null in case the word is not found
    Node* findNode(std::string prefix) const;

    // dfs implementation for node element
    void fillVector(Node *node, std::string prefix, std::vector<std::string> &v) const;
};

#endif // TRIE_H
