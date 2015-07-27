#include <iostream>
#include <stdio.h>
#include <assert.h>
#include "TrieTree.h"
using namespace std;
using namespace zl::stl;

uint64_t find(const TrieTree& t, const char* word)
{
    uint64_t id = 0;
    int level = t.search(word, &id);
    if (level > 0)
    {
        printf("find [%s] : id = [%llu], level [%d]\n", word, id, level);
    }
    else
    {
        printf("find [%s] : failure\n", word);
    }
    return id;
}

int main()
{
    TrieTree t;
    uint64_t id = 0;
    t.insert("a", 1);
    t.insert("abacus", 2);
    t.insert("abalone", 3);
    t.insert("abandon", 4);
    t.insert("abandoned", 5);
    t.insert("abashed", 6);
    t.insert("abate", 7);
    t.insert("this", 8);

    assert(find(t, "this") == 8);
    assert(find(t, "abate") == 7);
    assert(find(t, "baby") == 0);


    t.insert("hello", 5678);
    assert(find(t, "hello") == 5678);

    id = 0;
    cout << t.remove("hello", &id) << "\n";
    cout << id << "\n";
    id = 0;
    cout << t.remove("hello", &id) << "\n";
    cout << id << "\n";

    t.insert("hello", 5678);
    assert(find(t, "hello") == 5678);
    t.update("hello", 9723);
    assert(find(t, "hello") == 9723);

    assert(t.count("hello") == 2);
    assert(t.count("abate") == 1);
    assert(t.count("world") == 0);

    t.remove("hello", NULL);
    assert(t.count("hello") == 0);

    t.remove("asdfgh", NULL);
    assert(t.count("asdfgh") == 0);

    system("pause");
}