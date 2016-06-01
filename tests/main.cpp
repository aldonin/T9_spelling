#include <QTest>
#include <QApplication>

#include "testnode.h"
#include "testtrie.h"


int main(int argc, char *argv[])
{
    QTest::qExec(new TestNode, argc, argv);
    QTest::qExec(new TestTrie, argc, argv);

    return 0;
}

