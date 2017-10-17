/*
Comments :
Code a simple bloom filter.
(1) Read words from a dictionary . Can use /usr/share/dict/words
(2) Add the words in a bloom filter
(3) Lookup random words from bloom filter
(4) Do a comparison with linear time seraching with a dictionary. Can also
compare with a hash table
*/

#include <iostream>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <chrono>
#include <utility>

using namespace std;

#define SIZE       3000000
#define NUM_HASHES 9


unsigned int MurmurHash2 ( const void * key, int len, unsigned int seed )
{
  // 'm' and 'r' are mixing constants generated offline.
  // They're not really 'magic', they just happen to work well.

  const unsigned int m = 0x5bd1e995;
  const int r = 24;

  // Initialize the hash to a 'random' value

  unsigned int h = seed ^ len;

  // Mix 4 bytes at a time into the hash

  const unsigned char * data = (const unsigned char *)key;

  while(len >= 4)
  {
    unsigned int k = *(unsigned int *)data;

    k *= m; 
    k ^= k >> r; 
    k *= m; 
    
    h *= m; 
    h ^= k;

    data += 4;
    len -= 4;
  }
  
  // Handle the last few bytes of the input array

  switch(len)
  {
  case 3: h ^= data[2] << 16;
  case 2: h ^= data[1] << 8;
  case 1: h ^= data[0];
          h *= m;
  };

  // Do a few final mixes of the hash to ensure the last few
  // bytes are well-incorporated.

  h ^= h >> 13;
  h *= m;
  h ^= h >> 15;

  return h;
} 

class BloomFilter {
 public:
  BloomFilter(unsigned nHashes);
  ~BloomFilter() {}

  bool lookup(const string& str);
  void add(const string& str);

 private:
  int          m_numHashes;
  bitset<SIZE> m_bitset;
};


BloomFilter::BloomFilter(unsigned nHashes) : m_numHashes(nHashes) {}

bool BloomFilter::lookup(const string& str)
{
  for (int i = 0; i < m_numHashes; ++i) {
    unsigned h = MurmurHash2(str.c_str(), str.size()-1, i) % SIZE;
    if (m_bitset[h] != 1) 
      return false;
  }

  return true;
}

void BloomFilter::add(const string& str)
{
  for (int i = 0; i < m_numHashes; ++i) {
    unsigned h = MurmurHash2(str.c_str(), str.size()-1, i) % SIZE;
    m_bitset[h] = 1;
  }
}

int main(int argc, char** argv)
{
  BloomFilter bf(NUM_HASHES);
  unordered_map<string, char> table;

  fstream fs;
  fs.open("/usr/share/dict/words", fstream::in);
  string str;
  while (fs >> str) {
    table.emplace(make_pair(str, '1'));
    bf.add(str);
  }

  auto start = chrono::high_resolution_clock::now();
  bool found = bf.lookup("Zythia");
  auto elapsed = chrono::high_resolution_clock::now() - start;
  long long microsecondsBF =
      std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
  cout << found << endl;

  start = chrono::high_resolution_clock::now();
  found =  table.find("Zythia") != table.end();
  elapsed = std::chrono::high_resolution_clock::now() - start;
  long long microsecondsTable =
      std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

  cout << microsecondsBF << " " << microsecondsTable << endl;
  return 0;
}

