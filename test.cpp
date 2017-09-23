
#include "node.h"
#include "node.cpp"
#include "aon.h"
#include "aon.cpp"

int main(){
	Node a = Node("A", 1);
	Node b = Node("B", 2);
	Node c = Node("C", 3);
	Node d = Node("D", 4);
	Node e = Node("E", 5);
	Node f = Node("F", 6);
    cout << "Hello World" << endl;
    // a.printNode();
    a.add_pre(&b);
    a.add_pre(&c);
    a.add_pre(&d);
    a.add_suc(&e);
    a.add_suc(&f);
    printNoode(a);
    Aon aon = Aon();
    // cout << aon.nodes.size() <<endl;
    // if (a.pres.size() == 0){
    // 	cout << "A is a start point" << endl;
    // }
    // else printf("A has %lu pres\n", a.pres.size());
    aon.insert(a);
    aon.printAon();
}
