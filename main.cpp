#include <qglobal.h>
#include <QDebug>
#include "node.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)
    Node root('a');
    Node *child = new Node('b');
    child->append(new Node('c'));
    root.append(child);
}
