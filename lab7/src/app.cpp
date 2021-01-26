#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <Array.h>
#include <HashTable.h>
#include <list>
#include <LinkedList.h>
#include <TimeSupport.h>
#include <RandomSupport.h>
#include <BST.h>


using namespace std;


string reverse(string word){
    reverse(word.begin(), word.end());
    return word;
}

bool find(string word, ResizableArray& arr){
    for (long i = 0; i < arr.count; i++){
        if (word == arr[i]){
            return true;
        }
    }
    return false;
}

int main(){
      int count = 0;
      int count2 = 0;
      int count3 = 0;
      fstream file;

   //////////////// WORDS 1 /////////////////////////////////////////////
    ResizableArray data;
    file.open("words.txt",ios::in);
    if (file.is_open()){
        string tp;
        while(getline(file, tp)){ //Reads the file and inputs the words into an resizable array, this is to keep from reading the folder again
            data.append(tp); //inputes words to be read later for efficiency
        }
        file.close(); 
    }
    else{
        cout << "Could not read file..." << endl; //catch
    }
    //initialize a new hash table
     HashTable hashTable(data.count);

    for(int i = 0; i < data.count; i++){  //data.count is the size of the array
         hashTable.insert(data[i]);       
    }

    timestamp start = current_time();
    for(int i = 0; i < data.count; i++){
         if(hashTable.search(reverse(data[i])) == true){
                 count++;
            }
    }
    timestamp end = current_time();
    //////////////// WORDS 1 /////////////////////////////////////////////

    //////////////// WORDS 2 /////////////////////////////////////////////
ResizableArray data2; //The same process is used here but for a different file containing more words
file.open("words2.txt",ios::in);
    if (file.is_open()){
        string tp;
        while(getline(file, tp)){    
            data2.append(tp);
        }
        file.close(); 
    }
    else{
        cout << "Could not read file..." << endl;
    }
    //initialize a new hash table
     HashTable wordsTwo(data2.count);

    for(int i = 0; i < data2.count; i++){
         wordsTwo.insert(data2[i]);
    }

    timestamp start1 = current_time();
    for(int i = 0; i < data2.count; i++){
         if(wordsTwo.search(reverse(data2[i])) == true){
                 count2++;
            }
    }
    timestamp end1 = current_time();
//////////////// WORDS 2 /////////////////////////////////////////////

//////////////// WORDS 3 /////////////////////////////////////////////
    ResizableArray data3;
    file.open("words3.txt",ios::in);
    if (file.is_open()){
        string tp;
        while(getline(file, tp)){
            data3.append(tp);
        }
        file.close(); 
    }
    else{
        cout << "Could not read file..." << endl;
    }
    //initialize a new hash table
     HashTable wordsThree(data3.count);

    for(int i = 0; i < data3.count; i++){
         wordsThree.insert(data3[i]);
    }

    timestamp start2 = current_time();
    for(int i = 0; i < data3.count; i++){
         if(wordsThree.search(reverse(data3[i])) == true){
                 count3++;
            }
    }
    timestamp end2 = current_time();

    //////////////// WORDS 3 /////////////////////////////////////////////

    //Prints out the time to complete

  cout << "In Words: Found " << count << " in " << time_diff(start,end) << " ms " << endl;
  cout << "In Words2: Found " << count2 << " in " << time_diff(start1,end1) << " ms " << endl;
  cout << "In Words3: Found " << count3 << " in " << time_diff(start2,end2) << " ms " << endl;

    return 0;
}
