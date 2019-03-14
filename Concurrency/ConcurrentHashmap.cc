/*
Comments :
Implement a concurrent hashmap using lock striping
Note: apply a locking strategy that offers better concurrency  and scalability;
instead of synchronizing every method on a common lock, restricting access to a
single thread at a time, utilize a finer grained locking mechanism called lock
striping to allow greater degree of shared access
*/

#include <iostream>

using namespace std;

template <typename Key, typename Value>
class MyMap
{
    public:
    MyMap(size_t size, int partitions) : size(size), partitions(partitions) {}
    long hashFn(Key k) {}
    
    pair<bool, Value> get(Key key)
    {
        long index = hashFn(key);
        
        mutexes[index%partitions].read_lock();
        for (auto element : table[index%size])
        {
            if (element.first == key)
                return make_pair<true,element.second>;
        }
        return make_pair<false, NULL>;
        
    }
    
    void put(Key key, Value value)
    {
        long index = hashFn(key);
        bool found = false;
        
        mutexes[index%partitions].write_lock();
        for (auto element : table[index%size])
        {
            if (element.first == key) {
                element.second = value;
                found = true;
             }
        }
        if (!found)
            table[index%size].push_back(make_pair(key, value));
    
    }

    
    private:
    vector<long, vector<pair<Key, Value> >  > table;
    vector<rw_lock> rw_mutexes;
    size_t size;
};

int main(int argc, char** argv)
{
  return 0;
}

