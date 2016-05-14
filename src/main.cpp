#include <qglobal.h>
#include <QDebug>
#include "node.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)
    Node *root = new Node('a');
    delete root;
}
