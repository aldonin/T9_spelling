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

    std::vector<std::string> find(std::string prefix) Q_DECL_OVERRIDE;
    bool insert(std::string word) Q_DECL_OVERRIDE;
};

#endif // TRIE_H
