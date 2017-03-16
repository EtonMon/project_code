// Ethan Trinh
// 10/16/16
// hashTable.cpp

#include "hashTable.h"
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

hashTable::hashTable(unsigned int num_elements) {
  load_factor=.25;
  collisions=0;
  double x = (double) num_elements/load_factor;
  unsigned int y = x;
  size=y;
  if(!checkprime(y)){
    size=getNextPrime(y);
  }
  
  vect.resize(size);
  
}

unsigned int hashTable::get_size(){
  return size;
}

unsigned int hashTable::get_collisions(){
  return collisions;
}


void hashTable::insert(string str){
  unsigned int hash_num = hash(str);
  int i = 1;
  
  while(vect.at(hash_num)!=""){
    hash_num+=pow(i,2);
    hash_num = hash_num%size;
    i++;
    
  }
  vect[hash_num]=str;
}

bool hashTable::find(string str){
  unsigned int hash_num = hash(str);
  int i = 1;
  while(vect.at(hash_num)!=""){
    if(vect.at(hash_num)==str){
      return true;
    }
    hash_num+=pow(i,2);
    hash_num = hash_num%size;
    i++;
    //collisions++;
    
  }
  return false;
}

unsigned int hashTable::hash(string str){
  unsigned int hash=0;
  for(int i=0; i<str.size(); i++){
    //time 300x300: 17.78
    //unsigned int x = pow(str.at(i)*7,i+1);
    //time 300x300: 5.123
    //unsigned int x = str.at(i)*str.size();
    //time 300x300: 4.708
    unsigned int x = 29*str.at(i)+str.size();
    //time 300x300: 4.882
    //unsigned int x = 11*str.at(i)*str.size();
    
    hash=hash+x;
  }
  hash = hash%size;
  
  return hash;
}

bool hashTable::checkprime(unsigned int p){
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime(unsigned int n){
    while ( !checkprime(++n) );
    return n;
}
