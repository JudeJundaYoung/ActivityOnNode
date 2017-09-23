#include "node.h"
#include <string>
using std::string;

Node::Node(string id,int dur){
	duration = dur;
	actid = id;
}

void Node::add_pre(Node* nd){
	pres.insert(nd);
}

void Node::add_suc(Node* nd){
	sucs.insert(nd);
}


void printpres(Node& nd){
	std::set<Node*>::iterator it = nd.pres.begin();
 
	// Iterate till the end of set
	while (it != nd.pres.end()){
	// Print the element
		
		int du = (*it)->duration;
		cout << du << endl;
	//Increment the iterator
		it++;
	}
}

void printsucs(Node& nd){
	std::set<Node*>::iterator it = nd.sucs.begin();
 
	// Iterate till the end of set
	while (it != nd.sucs.end()){
	// Print the element
		
		int du = (*it)->duration;
		cout << du << endl;
	//Increment the iterator
		it++;
	}
}

void printNode(Node& nd){
	cout << "This is Node  " << nd.actid << endl;
	cout << "The duration is " << nd.duration <<endl;
	printpres(nd);
	printsucs(nd);
}

