#include "node.h"
#include <string>
using std::string;

Node::Node(string k,int dur){
	duration = dur;
	key = k;
}

void Node::add_pre(Node* nd){
	pres.insert(nd);
}

void Node::add_suc(Node* nd){
	sucs.insert(nd);
}

void Node::printNode(){
	// cout << nd.duration <<endl;
	cout << "This is printNode" << endl;
	cout << key << endl;
	cout << duration << endl;

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

void printNoode(Node& nd){
	cout << "This is Node  " << nd.key << endl;
	cout << "The duration is " << nd.duration <<endl;
	printpres(nd);
	printsucs(nd);
}



//int main(){
//	Node a = Node(1);
//    cout << "Hello World" << endl;
//    cout << "1 2 3" << endl;
//    printNode();
//}
//
//
