#include <qglobal.h>
#include <QDebug>
#include "node.h"
#include "trie.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)
    //Node *root = new Node('a');
    Trie t;
    t.insert("Hello");
    t.insert("Hellou");
    qDebug() << t.size() << t.nodes();
    //delete root;
}
