#include "itrie.h"
#include "node.h"
#include <QDebug>

ITrie::ITrie() :
    m_size(0),
    m_nodes(1),
    m_maxSuggestion(3),
    m_root(new Node('0'))
{

}

ITrie::~ITrie()
{
    qDebug() << Q_FUNC_INFO;
    m_size = 0;
    delete m_root;
    m_root = Q_NULLPTR;
}

size_t ITrie::size() const
{
    return m_size;
}

size_t ITrie::nodes() const
{
    return m_nodes;
}

size_t ITrie::numberOfSuggestions() const
{
    return m_maxSuggestion;
}

void ITrie::setNumberOfSuggestions(const size_t number)
{
    m_maxSuggestion = number;
}
