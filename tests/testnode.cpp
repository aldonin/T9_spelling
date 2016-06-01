#include <QTest>
#include "testnode.h"
#include "node.h"


TestNode::TestNode(QObject *parent) : QObject(parent)
{

}


void TestNode::initTestCase()
{
    root = new Node('a');
    QVERIFY2(root->data() == 'a', "Root node content mismathched");
    QVERIFY2(root->isEnd() == false, "Setting default mark of the end is incorrect");
}

void TestNode::cleanupTestCase()
{
    delete root;
    root = Q_NULLPTR;
}

void TestNode::modifiedEndMarkTestCase()
{
    QVERIFY2(root->isEnd() == false, "Setting default mark of the end is incorrect");
    root->setEnd(true);
    QVERIFY2(root->isEnd() == true, "Setting default mark of the end is incorrect");
    root->setEnd(false);
    QVERIFY2(root->isEnd() == false, "Setting default mark of the end is incorrect");
}

void TestNode::findTestCase()
{
    root->append(new Node('x'));
    root->append(new Node('y'));

    QVERIFY2(root->find('x') != Q_NULLPTR, "Can't find appended node");
    QVERIFY2(root->find('y') != Q_NULLPTR, "Can't find appended node");
    QVERIFY2(root->find('z') == Q_NULLPTR, "Finded node which are not actually in the root");

    root->erase('x');
    root->erase('y');
}

void TestNode::eraseTestCase()
{
    Node *child = new Node('b');
    child->append(new Node('c'));
    root->append(child);

    QCOMPARE(root->erase('c'), false);
    QCOMPARE(root->erase('b'), true);
    QCOMPARE(root->erase('b'), false);
}
