# Implementation of T9 autocomplete algorithm

## Implementation description
The implementation based on [Trie](https://en.wikipedia.org/wiki/Trie) data structure. 
Each [`Node`](https://github.com/aldonin/T9_spelling/blob/master/src/node.h) contain `isEnd` flag which shows if there is a separate word which stops on currect character.

For example: 

![alt text](https://github.com/aldonin/T9_spelling/blob/master/img/trie.png "Trie example")

Nodes with `isEnd` flag is marked with double round. We see 13 nodes(including empty root node), which represent 5 names:
 - Joe
 - John
 - Johnny
 - Jane
 - Jack

As we can see 'John' name stops on 'N' character, however we have more long 'Johnny' name, that's why we have one more pointer to another character of 'John**n**y' name (next 'N' character). So `isEnd` flags doesn't mean the end of all words started with that prefix.

[`Trie`](https://github.com/aldonin/T9_spelling/blob/master/src/trie.h) class contain two methods:
 - *insert* new word
 - *find* word with specified prefix


`Trie::insert` try to find if the trie is already contain this word or part of word. We iterate thought character and try to find any children of current node with iterating character. If there is no more children, we find the parent node which represents the longest word of trie as a part of inserting word. After that, if we still have some non-iterating character we add them into the trie. And marked the last character in the trie with `isEnd` flag.

`Trie::find` firstly try to find the node which corresponds the full prefix string. If the node is found, we fill the result set of word with specified prefix using [DFS](https://en.wikipedia.org/wiki/Depth-first_search) algorithm. The finding stops if we exceed the number of suggestions word (could be specified with `ITrie::setNumberOfSuggestions` ).

## Requirements
**The minimal:** Qt 5.6 or higher.

There are no any specific or third-party libs required. The projected tested only on Win7 OS.

## Usage
The [`Trie`](https://github.com/aldonin/T9_spelling/blob/master/src/trie.h) class provide with only default constructor:
```c++
Trie *trie = new Trie;
```

One of the possible way to fill trie is using dictionary. The examples of dictionary could be found [here](https://github.com/aldonin/T9_spelling/tree/master/dictionaries).
```c++
    QFile file("dict_en.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Can't open file";
        return;
    }
    Trie *trie = new Trie;
    while(!file.atEnd()) {
        QString str = file.readLine();
        trie->insert(str.toLocal8Bit().constData());    // convert from to QString to std::string
    }
```

After the trie is fiiled we could check the number of words in the trie or number of nodes required for representation the dictionary:
```c++
std::cout << "The size of trie is " << trie->size();
std::cout << "The nodes require for trie is " << trie->nodes();
```

For finding the word with specified prefix use:
```c++
std::vector<std::string> v = trie->find("helip"); // find words started with 'helip'
for (auto str : v) {
    std::cout << str << std::endl;
}
```

