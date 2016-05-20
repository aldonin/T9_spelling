#ifndef TRIE_H
#define TRIE_H

#include "itrie.h"

class Trie : public ITrie
{
public:
    Trie();
    ~Trie();

    std::string find(std::string prefix);
    bool insert(std::string word);
};

#endif // TRIE_H
