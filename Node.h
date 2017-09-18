#ifndef NODE_H
#define NODE_H

#include<utility>
#include<vector>
#include<string>

using std::string;
using std::vector;

class Node
{
  typedef unsigned int Date;
public:
  Node() = default;
  Node(Date, Date, Date, Date, unsigned int, 
string, string);
  Node(Date, Date, Date, Date);
  Node(Date, Date, Date, Date, unsigned int);
  Node(const Node&);
  Node(Node&&);
  Node& operator = (const Node&);
  Node& operator = (Node&&);
  ~Node() = default;  // 


  
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
}；

#endif
