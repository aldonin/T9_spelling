#include <QTest>
#include "testtrie.h"
#include "trie.h"

TestTrie::TestTrie(QObject *parent) : QObject(parent)
{

}

void TestTrie::initTestCase()
{
    trie = new Trie;

    QCOMPARE(trie->size(),  (size_t)0);
    QCOMPARE(trie->nodes(), (size_t)1);
}

void TestTrie::cleanupTestCase()
{
    delete trie;
    trie = Q_NULLPTR;
}

void TestTrie::insertTestCase()
{
    trie->insert("hello");
    QCOMPARE(trie->nodes(), (size_t)6);
    QCOMPARE(trie->size(),  (size_t)1);

    trie->insert("hell");
    QCOMPARE(trie->nodes(), (size_t)6);
    QCOMPARE(trie->size(),  (size_t)2);

    trie->insert("helicopter");
    QCOMPARE(trie->nodes(), (size_t)13);
    QCOMPARE(trie->size(),  (size_t)3);

    QVERIFY2(trie->insert("hello") == false, "Double inserting the same word should return FALSE");
}

void TestTrie::findTestCase()
{
    trie->insert("where");
    trie->insert("when");
    trie->insert("what");
    trie->insert("wall");
    trie->setNumberOfSuggestions(3);

    QCOMPARE(trie->find("w").size(),     (size_t)3);
    QCOMPARE(trie->find("wh").size(),    (size_t)3);
    QCOMPARE(trie->find("whe").size(),   (size_t)2);
    QCOMPARE(trie->find("when").size(),  (size_t)1);
    QCOMPARE(trie->find("whent").size(), (size_t)0);
}

void TestTrie::suggestionNumberTestCase()
{
    trie->setNumberOfSuggestions(1);
    QCOMPARE(trie->numberOfSuggestions(), (size_t)1);

    trie->setNumberOfSuggestions(3);
}
