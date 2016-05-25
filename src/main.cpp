#include <qglobal.h>
#include <QDebug>
#include <QFile>
#include "node.h"
#include "trie.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    Trie t;
    t.insert("Hello");
    t.insert("Hellou");
    t.insert("Helloe");
    t.insert("Helloa");
    t.insert("Hellob");
    t.insert("Helloc");
    t.insert("Hellod");
    t.insert("Helloda");
    t.insert("Hellode");
    t.insert("Hellodaasas");
    t.insert("Hello");
    qDebug() << t.size() << t.nodes();

    std::vector<std::string> v = t.find("llo");

    for (auto it : v)
        qDebug() << QString::fromUtf8(it.c_str());


}
