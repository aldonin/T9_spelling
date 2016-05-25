#include "trie.h"
#include "node.h"
#include <vector>
#include <QDebug>

Trie::Trie() : ITrie()
{

}

std::vector<std::string> Trie::find(std::string prefix) const
{
    Node *current = findNode(prefix);

    if (current == Q_NULLPTR)
        return {};  // empty vector is case there are no words with this prefix

    std::vector<std::string> result;
    result.reserve(m_maxSuggestion);

    fillVector(current, prefix.substr(0, prefix.size()-1), result);

    return result;
}

bool Trie::insert(std::string word)
{
    if (word.length() == 0)
        return false;   // insert empty word

    Node *current = m_root;

    for (const auto &ch : word) {
        Node *child = current->find(ch);

        if (child != Q_NULLPTR) {
            current = child;
        } else {
            Node *newNode = new Node(ch);
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

Node *Trie::findNode(std::string prefix) const
{
    Node *current = m_root;

    for (const auto &ch : prefix) {
        current = current->find(ch);

        if (current == Q_NULLPTR)
            return current;
    }

    return current;
}

void Trie::fillVector(Node *node, std::string prefix, std::vector<std::string> &v) const
{
    if (v.size() == v.capacity())
        return;

    if (node->isEnd())
        v.push_back(prefix + node->data());

    for (const auto &it : node->children()) {
        fillVector(it.second, prefix+node->data(), v);
    }
}

