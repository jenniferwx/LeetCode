/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: 
get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it 
should invalidate the least recently used item before inserting a new item.
*/

class LRUCache{
public:
private:  
    int capacity;  
    int size;  
    list<pair<int, int> > cache_list; // key-value pair  
    typedef list<pair<int, int> >::iterator pnode;  
    unordered_map<int, pnode> cache_map; // key - iterator to list  
public:
    LRUCache(int capacity) {  
        this->capacity = capacity;  
        size = 0;  
    }  
      
    int get(int key) {  
        int value = -1;  
        auto iter = cache_map.find(key);  
        if (iter != cache_map.end()) {  
            value = iter->second->second;  
            cache_list.erase(iter->second);  
            cache_map[key] = cache_list.insert(cache_list.end(), make_pair(key, value));  
        }  
          
        return value;  
    }  
      
    void set(int key, int value) {  
        auto iter = cache_map.find(key);  
        if (iter != cache_map.end()) {  
            cache_list.erase(iter->second);  
        }  
        else {  
            if (size < capacity) {  
                ++size;  
            }  
            else {  
                auto front = cache_list.front();  
                cache_map.erase(front.first);  
                cache_list.pop_front();  
            }  
        }  
        cache_map[key] = cache_list.insert(cache_list.end(), make_pair(key, value));  
    }  
};
