#include <QString>
#include <QtTest>
#include "node.h"


class TestNode : public QObject
{
    Q_OBJECT

public:
    TestNode();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void modifiedEndMarkCase();
    void eraseCase();
private:
    Node *root;
};

TestNode::TestNode()
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
}

void TestNode::modifiedEndMarkCase()
{
    QVERIFY2(root->isEnd() == false, "Setting default mark of the end is incorrect");
    root->setEnd(true);
    QVERIFY2(root->isEnd() == true, "Setting default mark of the end is incorrect");
    root->setEnd(false);
    QVERIFY2(root->isEnd() == false, "Setting default mark of the end is incorrect");
}

void TestNode::eraseCase()
{
    Node *child = new Node('b');
    child->append(new Node('c'));
    root->append(child);

    QCOMPARE(root->erase('c'), false);
    QCOMPARE(root->erase('b'), true);
    QCOMPARE(root->erase('b'), false);

}


QTEST_APPLESS_MAIN(TestNode)

#include "tst_testnode.moc"
