#ifndef AON_H
#define AON_H

// #include "node.h"
#include <iostream>
#include <map>

using namespace std;
using std::map;

class Aon{
public: 
	map<string, Node*> nodes;
	Node* start;
	Node* end;

	Aon();
	void insert(Node&);
	void calculate();
	void printAon();
};



#endif
