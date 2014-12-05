#ifndef ZL_LRUCACHE_H
#define ZL_LRUCACHE_H
#include <list>
#include <map>
#include <algorithm>

class LRUCache
{
public:
	LRUCache(int capacity) : capacity_(capacity)
	{

	}

	int get(int key)
	{
		MAP::iterator iter = keyIndex_.find(key);
		if (iter != keyIndex_.end())
		{
			valueList_.splice(valueList_.begin(), valueList_, iter->second);

			//��������
			iter->second = valueList_.begin();
			int value = iter->second->second;
			return value;
		}
		return -1;
	}

	void set(int key, int value) 
	{
		MAP::iterator miter = keyIndex_.find(key);
		if (miter != keyIndex_.end()) //����
		{
			if (miter->second->second == value)  //����ȣ�ֱ�ӷ���
				return ;
			remove(key);   //���Ƴ�
		}

		//���»���
		valueList_.push_front(std::make_pair(key, value));

		//���·�������
		LIST::iterator liter = valueList_.begin();
		keyIndex_[key] = liter;

		//�Ƿ���
		if (keyIndex_.size() > capacity_)
		{
			liter = valueList_.end();
			--liter;
			remove(liter->first);
		}
	}
private:
	bool remove(const int& key)
	{
		MAP::iterator iter = keyIndex_.find(key);
		if (iter == keyIndex_.end())
			return false;
		valueList_.erase(iter->second);
		keyIndex_.erase(iter);
		return true;
	}

private:
	typedef std::list<std::pair<int, int> >         LIST;
	typedef std::map<int, typename LIST::iterator>  MAP;

	LIST                   valueList_;
	MAP                    keyIndex_;
	size_t                 capacity_;
};

#endif  /* ZL_LRUCACHE_H */