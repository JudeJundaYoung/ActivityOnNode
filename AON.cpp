#include "AON.h"
#include <iostream>

using std::string; 
using std::map;
using namespace std;

/*AON::AON(){
	// Nodes = NULL;
	start = NULL;
	end = NULL;
}*/


//���б���ʽ��AON���г�ʼ��
AON::AON(initializer_list<Node *> list)
{
	for (const auto & element : list)
	{
		insert(*element);
	}
}

void AON::insert(const Node& node)
{
	Nodes.emplace(node.get_ActID(), node.get_Iterator());
	//����START��END
}

void calculate(){};


int main(){
	cout << "Hello World" << endl;
}

