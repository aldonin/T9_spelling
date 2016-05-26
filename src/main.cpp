#include <qglobal.h>
#include <QDebug>
#include <QFile>
#include "node.h"
#include "trie.h"
#include "utils.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    QFile file("e:\\workspace\\dict_en.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Can't open file";

    }

    Trie t;
    while(!file.atEnd()) {
        QString str = file.readLine();
        t.insert(str.toLocal8Bit().constData());
    }

    qDebug() << "The size of trie is " << t.size();
    qDebug() << "The nodes require for trie is " << t.nodes();


    getchar();

    std::vector<std::string> v = t.find("helip");

    for (auto str : v) {
        qDebug() << QString::fromUtf8(str.c_str());
    }

}
