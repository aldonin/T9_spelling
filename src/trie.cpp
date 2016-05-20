#include "trie.h"
#include "node.h"
#include <QDebug>

Trie::Trie() : ITrie()
{

}

Trie::~Trie()
{
}

std::string Trie::find(std::string prefix)
{
    Q_UNUSED(prefix)
    return std::string();
}

bool Trie::insert(std::string word)
{
    if (word.length() == 0)
        return false;   // insert empty word

    Node *current = m_root;

    for (auto it = word.begin(); it != word.end(); ++it) {
        Node *child = current->find(*it);

        if (child != Q_NULLPTR) {
            current = child;
        } else {
            Node *newNode = new Node(*it);
            current->append(newNode);
            current = newNode;
            m_nodes++;  // increase number of nodes because of new one appeared
        }
    }

    // if the word is already in a trie?
    if (current->isEnd()) {
        return false;
    } else {
        current->setEnd(true);
        m_size++;
        return true;
    }
}

