#ifndef NODE_H
#define NODE_H

#include <map>

class Node
{
public:
    explicit Node(const char content);
    ~Node();
    Node* find(const char key) const;
    bool erase(const char key);
    void append(Node* child);
    char data() const;
    void setEnd(const bool isEnd);
    bool isEnd() const;

private:
    std::map<char, Node*> m_children;
    char m_data;
    bool m_isEnd;

    Node(const Node&);
    Node& operator=(const Node&);
};

#endif // NODE_H
