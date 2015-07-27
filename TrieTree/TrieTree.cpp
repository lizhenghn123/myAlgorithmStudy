#include "TrieTree.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

namespace zl
{
    namespace stl
    {
        // �����ִ�Сд
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
            int level = 0;  //����   

            TrieNode *location = root_;  //�Ӹ���㿪ʼ   
            while (location != NULL && *word != 0)
            {
                int pos = caclPosition(*word);
                if (pos < 0)    // ���Ϸ��ĵ���
                    return -1;

                location = location->branch_[pos];  //ת����Ӧ��ָ֧��
                level++;
                word++;
            }

            //�ҵ�����ȡ���ݣ��ɹ�����   
            if (location != NULL && location->id_ != 0) // ȥ��location->id_ != 0���жϣ��Ϳ��Բ��ҷ�֧�ϵĵ���
            {
                *id = location->id_;
                return level;
            }
            else   // ���Ϸ��ĵ���
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
            TrieNode *location = root_;   //�Ӹ���㿪ʼ
            while (location != NULL && *word != 0)
            {
                int pos = caclPosition(*word);
                if (pos < 0)    // ���Ϸ��ĵ���
                    return -1;

                if (location->branch_[pos] == NULL)
                    location->branch_[pos] = new TrieNode;    //�����շ�֧     

                location = location->branch_[pos];  //ת����Ӧ��ָ֧��
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
                else  //������ĵ����Ѿ�����
                {
                    level = -1;
                }
            }
            else
            {    //��������
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
            int level = 0;  //����   

            TrieNode *location = root_;  //�Ӹ���㿪ʼ   
            while (location != NULL && *word != 0)
            {
                int pos = caclPosition(*word);
                if (pos < 0)    // ���Ϸ��ĵ���
                    return NULL;

                location = location->branch_[pos];  //ת����Ӧ��ָ֧��
                level++;
                word++;
            }
            return location;
        }
    }
}