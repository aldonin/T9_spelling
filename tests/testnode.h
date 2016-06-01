#ifndef TESTNODE_H
#define TESTNODE_H

#include <QObject>

class Node;

class TestNode : public QObject
{
    Q_OBJECT

public:
    explicit TestNode(QObject *parent = 0);

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void modifiedEndMarkTestCase();
    void findTestCase();
    void eraseTestCase();
private:
    Node *root;
};
#endif // TESTNODE_H
