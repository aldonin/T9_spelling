#include <qglobal.h>
#include <QDebug>
#include "node.h"
#include "trie.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    Trie t;
    qDebug() << t.insert("Hello");
    qDebug() << t.insert("Hellou");
    qDebug() << t.insert("Hello");
    qDebug() << t.size() << t.nodes();
}
