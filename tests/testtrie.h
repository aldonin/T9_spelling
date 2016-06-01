#ifndef TESTTRIE_H
#define TESTTRIE_H

#include <QObject>

class Trie;

class TestTrie : public QObject
{
    Q_OBJECT

public:
    explicit TestTrie(QObject *parent = 0);

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void insertTestCase();
    void findTestCase();
    void suggestionNumberTestCase();

private:
    Trie *trie;
};

#endif // TESTTRIE_H
