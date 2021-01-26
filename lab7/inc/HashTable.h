#ifndef HashTable_h
#define HashTable_h
#include <iostream>
#include <ostream>
#include <LinkedList.h>

struct HashTable {
 
    LinkedList* hashTable;  //initialize a linked list 
    long count = 0;

    ///////HASH FUNCTION,USES CHARACTER FOLDING
    HashTable(long size){
       hashTable = new LinkedList[size];  //create a table of linked lists with size of resizable array
       count = size; //the count is the size of array, this is taken from resizable array

    }
    long hashString(std::string word){
        long g = 7919; //prime for unique hashing
        long hash = 0;
        ///Only hashes the first four words, if lower it adds "x"
        while(word.size() < 4){
            word.append("x");
    }
        for(int i =0; i < 4 ;i++){
            hash = (g*hash) + long(word.at(i));
    }
    ///Gets the key by modulus size of the array
    return hash%count;
    }

    //uses insert from linked list with the key
    void insert(std::string word){
        hashTable[hashString(word)].append(word);
    }
    //Uses search function from linked lists
    bool search(std::string word) {
        if(hashTable[hashString(word)].search(word) == true){
            return true;
        }
    }
    ///Deconstructs the HashTable
    ~HashTable(){
		delete[] hashTable;
	}
};
#endif