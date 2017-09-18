#ifndef NODE_H
#define NODE_H

#include<vector>
#include<string>

using std::string;

class Node
{
  typedef unsigned int Date;
public:
  Node();
  Node(Date ES, Date EF, Date LS, Date LF, unsigned int Duration, int ActID, string Description);
  Node(Date ES, Date EF, Date LS, Date LF);
  Node(Date ES, Date EF, Date LS, Date LF, unsigned int Duration);
  Node(const Node&);
  Node(Node&&);
  Node& operator = (const Node&);
  Node& operator = (Node&&);
  ~Node() = default;

private:
  Date EarlyStart;
  Date EarlyFinish;
  Date LateStart;
  Date LateFinish;
  unsigned int Duration;
  int ActID;
  string Description;
}；

#endif
