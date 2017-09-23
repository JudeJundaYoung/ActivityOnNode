#include "aon.h"
#include "node.h"

Aon::Aon(){
	start = NULL;
	end = NULL;
	if (!nodes.empty()){
		nodes.clear();
	}
}

void Aon::insert(Node& node){
	//Case 0: error case
	if (node.pres.size() == 0 && node.sucs.size() == 0){
		// throw error("This is an invalid node");
	}
	//Case 1: node is a start point
	if (node.pres.size() == 0){
		cout << "Case 1" << endl;
		Node* temp = start;
		start = &node;
		temp->pres.insert(&node);
		node.sucs.insert(temp);
		nodes.insert (std::pair<std::string,Node*>(node.actid,&node));
		// change node.key to node.actid when using nodes.insert
	}
	//Case 2: node is an end point
	if (node.sucs.size() == 0){
		cout << "Case 2" << endl;
		Node* temp = end;
		end = &node;
		temp->sucs.insert(&node);
		node.pres.insert(temp);
		nodes.insert (std::pair<std::string,Node*>(node.actid,&node));
		// change node.key to node.actid when using nodes.insert
	}
	//Case 3: node is in between
	else{
		cout << "Case 3" << endl;
		nodes.insert (std::pair<std::string,Node*>(node.actid,&node));
		// change node.key to node.actid when using nodes.insert
	}
}

void Aon::calculate(){
	cout << "calculate" << endl;

}

void Aon::printAon(){
	cout << "The size of the Aon is " << nodes.size() << endl;
}


void Aon::createAon(){
	int cond = 1;
	string det;

	cout << "Create an AON now" << endl;
	while (cond){
		string actid;
		int duration;
		cout << "Please create a Node" << endl;
		cout << "Actid: ";
		cin >> actid;
		cout << "Duration: ";
		cin >> duration;
		Node node = Node(actid,duration);
		nodes.insert (std::pair<std::string,Node*>(node.actid,&node));
		cout << "Adding Node successfully. Do you want to continue? (y/n)" << endl;
		cin >> det;
		if (det == "n"){
			cond = 0;
		}
	}
	cout << "Thank you! An Aon is created." << endl;
}
