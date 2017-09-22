#ifndef NODE_H
#define NODE_H

#include<utility>
#include<string>
#include <iostream>
#include<set>

using std::string;
using std::endl;
using std::set;
using std::cout;

class Node
{
  typedef unsigned int Date;
  friend class AON;
public:
 explicit Node() = default;
 explicit Node(Date, Date, Date, Date, unsigned int, 
string, string);
 explicit Node(unsigned int); //only contains the duration of activity
 explicit Node(Date, Date, Date, Date); //only contains the ES,EF,LS,LF of the activity
 explicit Node(Date, Date, Date, Date, unsigned int);
  Node(const Node&); 
  Node(Node&&);
  Node& operator = (const Node&);
  Node& operator = (Node&&);
  ~Node() = default;   
  
    bool check_Elementary_Parameters() const;
    bool check_Optional_Parameters() const;
  
    void print_Parameters() const; 
	string get_ActID() const;
	const Node* get_Iterator() const;

  void add_predecessor(Node&);
  void add_successsor(Node&);

  
 private:
  Date EarlyStart = 0;		// ES = EF = LS = LF = 0 indicates that those data haven't been initialized
  Date EarlyFinish = 0;
  Date LateStart = 0;
  Date LateFinish = 0;
  unsigned int Duration = 0;	//Duration = 0 indicates that it has not been initialized
  string ActID;
  string Description;
  set<Node* > Predecessors;
  set<Node* > Successors;   
};

#endif
