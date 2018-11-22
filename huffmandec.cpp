// This program is the skeleton code for the lab 10 in-lab.  It uses
// C++ streams for the file input, and just prints out the data when
// read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <unordered_map>
#include "huffmannode.h"
using namespace std;

void makeTree(huffmannode *&r, string c, string prefix, int i);
void readTree(string s, huffmannode *roo);
typedef unordered_map<string, string> stringmap;
stringmap my_hash;

// main(): we want to use parameters
int main (int argc, char **argv) {
  vector<string> characters;
  huffmannode *root = NULL;
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // read in the first section of the file: the prefix codes
    while ( true ) {
      string character, prefix;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
	for (int k = 0; k<prefix.size(); k++){
	  makeTree(root, character, prefix,k);
	}
	my_hash.insert({prefix, character});
        //cout << "character '" << character << "' has prefix code '"
	//<< prefix << "'" << endl;
	characters.push_back(character);
    }

    /*for (int i = 0; i < characters.size(); i++){
      string key = characters[i];
      cout << "for character " << key << " the prefix is: " << endl;
      unordered_map<string, string>::const_iterator get = my_hash.find(key);
      string ret_prefix = get->second;
      cout << ret_prefix << endl;
      for (int j=0; j<ret_prefix.size(); j++){
	makeTree(root, key, ret_prefix, j);
	}
	}*/
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' ){
            break;
	}
	unordered_map<string, string>::const_iterator get = my_hash.find(bits);
	string ret_char = get->second;
	cout << ret_char;
        // add it to the stringstream
        sstm << bits;
    }
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    //readTree(allbits, root);
    // close the file before exiting
    file.close();
    cout << endl;
}

void makeTree(huffmannode*&r, string c, string prefix, int i){
  if(i==prefix.length())
    r = new huffmannode(c, 0, true);
  else{
    if (r == NULL)
      r = new huffmannode();
    if (prefix.at(i) == '0'){
      huffmannode*left = r->getLpointer();
      makeTree(*&left, c, prefix, i+1);
    }
    if (prefix.at(i) == '1'){
      huffmannode*right = r->getRpointer();
      makeTree(*&right, c, prefix, i+1);
    }
  }
  }

void readTree(string s, huffmannode *roo){
  //cout << "in readTree" << endl;
  for (int i=0; i<s.length(); i++){
    //cout << "in for loop of read tree" << endl;
      string sub =s.substr(1);
      //cout << "created substring. substring is: " << sub << endl;
      if (s[i] == '0'){
	//cout << "in 'if (s[i] == '0''" << endl;
	if (roo->getLeft().getChar() != ""){
	  //cout << roo->getLeft().getChar();
	}
	else{
	  //cout << "in else" << endl;
	  readTree(sub, roo->getLpointer());
	}
      }
      if (s[i] == '1'){
	//cout << "in 's[i] == '1'" << endl;
	if (roo->getRpointer()->isLeaf()){
	  //cout << "hello" << endl; //roo->getRight().getChar();
	}
	else{
	  //cout << "in else" << endl;
	  readTree(sub, roo->getRpointer());
	}
      }
  }
}
    
      
