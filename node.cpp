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
}

Node *Node::findChild(const char key) const
{
    auto it = m_children.find(key);
    return it == m_children.end() ? Q_NULLPTR : it->second;

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
