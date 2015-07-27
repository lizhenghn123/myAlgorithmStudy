#include "TrieTree.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

namespace zl
{
    namespace stl
    {
        // 不区分大小写
        static inline int caclPosition(char c)
        {
            if (c >= 'A' && c <= 'Z')
                return c - 'A';
            else if (c >= 'a' && c <= 'z')
                return c - 'a';
            else
                return -1;
        }

        TrieTree::TrieTree()
        {
            root_ = new TrieNode;
        }

        TrieTree::~TrieTree()
        {
            delete root_;
        }

        int TrieTree::search(const char* word, uint64_t* id) const
        {
            assert(word);
            int level = 0;  //层数   

            TrieNode *location = root_;  //从根结点开始   
            while (location != NULL && *word != 0)
            {
                int pos = caclPosition(*word);
                if (pos < 0)    // 不合法的单词
                    return -1;

                location = location->branch_[pos];  //转入相应分支指针
                level++;
                word++;
            }

            //找到，获取数据，成功返回   
            if (location != NULL && location->id_ != 0) // 去掉location->id_ != 0的判断，就可以查找分支上的单词
            {
                *id = location->id_;
                return level;
            }
            else   // 不合法的单词
            {
                return -1;
            }
        }

        int TrieTree::insert(const char* word, uint64_t id)
        {
            return insertOrUpdate(word, id, false);
        }

        int TrieTree::update(const char* word, uint64_t id/* = 0*/)
        {
            return insertOrUpdate(word, id, true);
        }

        int TrieTree::insertOrUpdate(const char* word, uint64_t id, bool updateIfExist)
        {
            assert(word);
            int level = 0;

            char char_code;
            TrieNode *location = root_;   //从根结点开始
            while (location != NULL && *word != 0)
            {
                int pos = caclPosition(*word);
                if (pos < 0)    // 不合法的单词
                    return -1;

                if (location->branch_[pos] == NULL)
                    location->branch_[pos] = new TrieNode;    //创建空分支     

                location = location->branch_[pos];  //转入相应分支指针
                level++;
                word++;
            }

            if (location->id_ != 0 && location->freq_ > 0)
            {
                if (updateIfExist)
                {
                    location->freq_++;
                    id == 0 ? (void)id : location->id_ = id;
                }
                else  //欲插入的单词已经存在
                {
                    level = -1;
                }
            }
            else
            {    //插入数据
                location->id_ = id;
                location->freq_++;
                assert(location->freq_ == 1);
            }
            return level;
        }

        int TrieTree::remove(const char* word, uint64_t* id)
        {
            assert(word);
            TrieNode *node = getNode(word);
            if (node != NULL && node->freq_ > 0)
            {
                id != NULL ? *id = node->id_ : (void)id;
                node->freq_ = 0;
                return node->id_;
            }
            else
            {
                return -1;
            }
        }

        int TrieTree::count(const char* word)
        {
            TrieNode *node = getNode(word);
            if (node != NULL && node->freq_ > 0)
            {
                return node->freq_;
            }
            else
            {
                return 0;
            }
        }

        TrieNode* TrieTree::getNode(const char* word)
        {
            assert(word);
            int level = 0;  //层数   

            TrieNode *location = root_;  //从根结点开始   
            while (location != NULL && *word != 0)
            {
                int pos = caclPosition(*word);
                if (pos < 0)    // 不合法的单词
                    return NULL;

                location = location->branch_[pos];  //转入相应分支指针
                level++;
                word++;
            }
            return location;
        }
    }
}