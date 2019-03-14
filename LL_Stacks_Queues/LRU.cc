/*
Comments :
Q: Design and implement an LRU cache. Item lookup, insertion and deletion should
be very efficient.

Solution summary:
Requirements for a cache : efficient CRUD operations
Create : O(1)
Read   : O(1)
Update : O(1)
Delete : O(1)

Questions to ask: 
1. What is the strategy for handling duplicates ? Lookup can't be O(1) if we
allow for duplicates
2. What is the cache capacity
3. When is eviction performed
*/

#include <iostream>
#include <unordered_map>

using namespace std;

template <typename K, typename V>
class Cache
{
 public:
  void insert(const K&, const V&);
  bool remove(const K&);
  void update(const K&, const V&);
  bool get(const K&, V&);
  void evict();

  Cache(size_t capacity);
  ~Cache();

 private:
  template <typename K1, typename V1>
  struct LLNode
  {
    K1 key;
    V1 value;

    LLNode* prev;
    LLNode* next;

    LLNode(const K1& k, const V1& v) : key(k), value(v) , prev(nullptr), next(nullptr) {}
  };

  void insertIntoBeginningOfList(LLNode<K,V>* node);
  void eraseListNode(LLNode<K,V>* node);


  size_t                          m_capacity;
  size_t                          m_size;
  LLNode<K,V>*                    m_head;
  LLNode<K,V>*                    m_tail;
  unordered_map<K, LLNode<K,V>* > m_table;
};

//////////////////////////// Public Interface Implemenation //////////////////////
template<typename K, typename V>
Cache<K,V>::Cache(size_t capacity) : m_capacity(capacity), m_size(0), m_head(nullptr),
                                     m_tail(nullptr)
{}


template<typename K, typename V>
Cache<K,V>::~Cache()
{
  LLNode<K,V>* node = m_head;

  while (node)
  {
    LLNode<K,V>* tmp = node->next;
    delete node;
    node = tmp;
  }
}

template<typename K, typename V>
void Cache<K,V>::insert(const K& key, const V& value)
{
  LLNode<K,V>* node = nullptr;
  typedef typename unordered_map<K, LLNode<K,V>* >::iterator Iterator;

  if (m_size == m_capacity)
    evict();

  Iterator it;
  if ((it = m_table.find(key)) != m_table.end())
  {
    node = it->second;
    if (node->prev)
    {
      node->prev->next = node->next;
      node->next->prev = node->prev;
    }
  }
  else
  {
    node = new LLNode<K,V>(key, value);
    m_table[key] = node;
    ++m_size;
  }

  insertIntoBeginningOfList(node);
}

template<typename K, typename V>
bool Cache<K,V>::remove(const K& key)
{
  bool found = false;
  typedef typename unordered_map<K, LLNode<K,V>* >::iterator Iterator;

  Iterator it;
  if ((it = m_table.find(key)) != m_table.end())
  {
    found = true;

    LLNode<K,V>* node = it->second;
    m_table.erase(it);

    eraseListNode(node);
    --m_size;
  }

  return found;
}

template<typename K, typename V>
void Cache<K,V>::update(const K& key, const V& val)
{
  typedef typename unordered_map<K, LLNode<K,V>* >::iterator Iterator;

  Iterator it;
  if ((it = m_table.find(key)) != m_table.end())
  {
    LLNode<K,V>* node = it->second;
    node->value = val;
    insertIntoBeginningOfList(node);
  }
  else
  {
    insert(key, val);
  }
}

template<typename K, typename V>
bool Cache<K,V>::get(const K& key, V& val /*out*/)
{
  typedef typename unordered_map<K, LLNode<K,V>* >::iterator Iterator;
  bool found = false;
  Iterator it;

  if ((it = m_table.find(key)) != m_table.end())
  {
    LLNode<K,V>* node = it->second;
    val = node->value;
    found = true;
    insertIntoBeginningOfList(node);
  }
  return found;
}

template<typename K, typename V>
void Cache<K,V>::evict()
{
  LLNode<K,V>* node = m_tail->prev;
  K& key = m_tail->key;
  auto it = m_table.find(key);
  if (it == m_table.end())
    throw "invalid cache!!, node value does not exist in table";

  m_table.erase(it);
  delete m_tail;
  m_tail = node;
  --m_size;
}

////////////////////////// Private Helper Methods Implementation/////////////////
template <typename K, typename V>
void Cache<K,V>::insertIntoBeginningOfList(LLNode<K,V>* node)
{
  if (m_head)
  {
    node->next = m_head->next;
    m_head->prev = node;
    node->prev = nullptr;
  }
  else
  {
    m_tail = node;
  }
  m_head = node;
}

template <typename K, typename V>
void Cache<K,V>::eraseListNode(LLNode<K,V>* node)
{
  if (m_head == node)
  {
    LLNode<K,V>* tmp = node->next;
    m_head = tmp;
    if (tmp)
      tmp->prev = nullptr;
  }
  else
  {
    if (node->next)
      node->next->prev = node->prev;
    node->prev->next = node->next;
  }
  
  if ( m_tail == node)
    m_tail = node->prev;  
  delete node;
}

/////////////////////// Test ////////////////////////////////////
int main(int argc, char** argv)
{
  Cache<int, string> cache(5);;
  cache.insert(1, "samriti");
  cache.insert(2, "sam");
  cache.insert(3, "samr");
  cache.insert(4, "samri");
  cache.insert(5, "samrit");
  cache.insert(1, "abc");
  cache.update(1, "sss");
  string str;
  if (cache.get(1, str))
    cout << str << endl;
  else
    cout << "not found" << endl;
  cache.remove(1);
  if (cache.get(1, str))
    cout << str << endl;
  else
    cout << "not found" << endl;
  return 0;
}
