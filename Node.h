#ifndef NODE_H
#define NODE_H

#include<utility>
#include<vector>
#include<string>
#include<vector>
#include <iostream>

using std::string;
using std::vector;
using std::endl;
using namespace std;

class Node
{
  typedef unsigned int Date;
public:
  Node() = default;
  Node(Date, Date, Date, Date, unsigned int, 
string, string);
  Node(unsigned int); //only contains the duration of activity
  Node(Date, Date, Date, Date); //only contains the ES,EF,LS,LF of the activity
  Node(Date, Date, Date, Date, unsigned int);
  Node(const Node&); 
  Node(Node&&);
  Node& operator = (const Node&);
  Node& operator = (Node&&);
  ~Node() = default;  // 
  
    bool check_Elementary_Parameters();
    bool check_Optional_Parameters();
  
    void print_Parameters();

  void add_predecessor(const Node&);
  void add_successsor(const Node&);

  
 private:
  Date EarlyStart;
  Date EarlyFinish;
  Date LateStart;
  Date LateFinish;
  unsigned int Duration;
  string ActID;
  string Description;
  vector<Node* > Predecessors;
  vector<Node* > Successors;   
};

#endif
