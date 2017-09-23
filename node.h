#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>
#include <set>

using namespace std;

class Node{
public:
	std::string actid;
	int duration;
	set<Node*> pres;
	set<Node*> sucs;

	Node(string,int);
	void add_pre(Node*);
	void add_suc(Node*);
private:
};

void printpres(Node&);
void printsucs(Node&);
void printNode(Node&);
#endif 
