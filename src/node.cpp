#include "node.h"
#include <QDebug>

Node::Node(const char content) :
    m_data(content), m_isEnd(false)
{

}

Node::~Node()
{
    qDebug() << "~Node(" << m_data << ")";
    for (auto &it : m_children) {
        delete it.second;
    }
    m_children.clear();
}

Node *Node::find(const char key) const
{
    auto it = m_children.find(key);
    return it == m_children.end() ? Q_NULLPTR : it->second;

}

bool Node::erase(const char key)
{
    auto it = m_children.find(key);
    if (it != m_children.end()) {
        delete it->second;
    }

    // std::map::erase actually return the number of removed elements(1 or 0)
    return m_children.erase(key);
}

void Node::append(Node *child)
{
    m_children[child->m_data] = child;
}

char Node::data() const
{
    return m_data;
}

void Node::setEnd(const bool isEnd)
{
    m_isEnd = isEnd;
}

bool Node::isEnd() const
{
    return m_isEnd;
}
