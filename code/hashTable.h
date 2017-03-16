// Ethan Trinh
// 10/16/16
// hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include <vector>
#include <string>

using namespace std;

class hashTable{
 public:

  hashTable(unsigned int num_elements);
  unsigned int get_size();
  unsigned int get_collisions();
  void insert(string str);
  bool find(string str);
  unsigned int hash(string str);
  bool checkprime(unsigned int p);
  int getNextPrime(unsigned int n);

 private:
  unsigned int size;
  double load_factor;
  vector<string> vect;
  unsigned int collisions;
};

#endif

  
