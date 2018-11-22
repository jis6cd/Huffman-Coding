#include "huffmannode.h"

///CHANGED ALL CHARS TO STRINGS!
using namespace std;

huffmannode::huffmannode(){
  c = "";
  freq = 0;
  left = NULL;
  right = NULL;
  leaf = false;
}

huffmannode::huffmannode(string character, int frequency, bool l){
  c = character;
  freq = frequency;
  left = NULL;
  right = NULL;
  leaf = l;
}

string huffmannode::getChar(){
  return c;
}

int huffmannode::getFreq(){
  return freq;
}

void huffmannode::setFreq(int j){
  freq = j;
}

void huffmannode::setLeft(huffmannode h){
  left = &h;
}

void huffmannode::setLpointer(huffmannode *h){
  left = h;
}

void huffmannode::setRpointer(huffmannode *h){
  right = h;
}

void huffmannode::setRight(huffmannode h){
  right = &h;
}

void huffmannode::setIsLeaf(bool m){
  leaf = m;
}
huffmannode huffmannode::getLeft(){
  return *left;
}

huffmannode* huffmannode::getLpointer(){
  return left;
}
huffmannode* huffmannode::getRpointer(){
  return right;
}

huffmannode huffmannode::getRight(){
  return *right;
}

bool huffmannode::isLeaf(){
  if (leaf){
    return true;
  }
  return false;
}
