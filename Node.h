#include<vector>
#include<string>

using std::string;

class Node
{
  typedef unsigned int Date;
public:
  Node();
  Node(Date ES, Date EF, Date LS, Date LF, unsigned int Duration, int ActID, string Description);
  Node(const Node&);
  Node(Node&&);
  Node& operator = (const Node&);
  Node& operator = (Node&&);
  ~Node();





private:
  Date EarlyStart;
  Date EarlyFinish;
  Date LateStart;
  Date LateFinish;
  unsigned int Duration;
  int ActID;
  string Description;
}；