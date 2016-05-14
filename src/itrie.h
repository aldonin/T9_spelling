#ifndef ITRIE_H
#define ITRIE_H
#include <string>

class Node;

class ITrie {
public:
    virtual ~ITrie() { }
    virtual bool insert(std::string word) = 0;
    virtual bool erase(std::string word) = 0;
    virtual std::string find(std::string prefix) = 0;
    size_t size() const { return m_size; }

private:
    size_t m_size;
    Node *m_root;
};

#endif // ITRIE_H
