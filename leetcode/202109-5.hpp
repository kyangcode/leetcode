/*
时间: 2021.09.17
题目描述：
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
实现 LRUCache 类：

LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？
*/
#include <list>
#include <map>
#include <vector>
using namespace std;

class LRUCache {
public:
	// 缓存的值
	struct CacheValue {
		CacheValue(int data, list<int>::iterator it) :data(data), it(it) {}

		int data; // 数据域
		list<int>::iterator it; // key所在的lru的迭代器
	};
public:
	LRUCache(int capacity) 
		: cache(10000, nullptr)
		, capacity(capacity)
		, size(0)
	{}

	int get(int key) {
		CacheValue* val = cache[key];
		if (val != nullptr)
		{
			// 将key放在lru的开头
			lru.erase(val->it);
			lru.push_front(key);

			val->it = lru.begin();
			return val->data;
		}
		else
		{
			return -1;
		}
	}

	void put(int key, int value) {
		CacheValue* val = cache[key];
		if (val != nullptr) // 先判断key是否存在
		{
			// 将key放在lru的开头
			lru.erase(val->it);
			lru.push_front(key);

			val->data = value;
			val->it = lru.begin();
		}
		else
		{
			if (size < capacity) // 说明缓存还未满
			{
				lru.push_front(key);
				cache[key] = new CacheValue(value, lru.begin());
				size++;
			}
			else // 缓存满了，需淘汰末尾元素
			{
				int k = lru.back();
				lru.pop_back();
				lru.push_front(key);
				
				// 释放堆上的空间，避免内存泄漏
				delete cache[k];
				cache[k] = nullptr;
				
				cache[key] = new CacheValue(value, lru.begin());
			}
		}
	}
private:
	list<int> lru; // 用于lru，存放的是key，末尾的会被淘汰
	vector<CacheValue*> cache; // 一个hash表，用于实现O(1)完成get和put操作
	int capacity;
	int size;
};