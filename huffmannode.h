#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <iostream>
//CHANGED ALL CHARS TO STRINGS
using namespace std;

class huffmannode{
public:
  huffmannode();
  huffmannode(string character, int frequency, bool l);
  string getChar();
  int getFreq();
  void setFreq(int j);
  void setLeft(huffmannode h);
  void setRight(huffmannode h);
  void setLpointer(huffmannode *h);
  void setRpointer(huffmannode *h);
  huffmannode getLeft();
  huffmannode* getLpointer();
  huffmannode getRight();
  huffmannode* getRpointer();
  void setIsLeaf(bool m);
  bool isLeaf();
private:
  int freq;
  bool leaf;
  string c;
  huffmannode *left, *right;
  
  friend class heap;

  friend class huffmanenc;
};
#endif
