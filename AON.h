#ifndef AON_H
#define AON_H

#include "Node.h"
#include<map>
#include<string>

using std::string;
using std::map;

class AON
{
public:
  AON() = default;//先把构造和析构设为default，结构复杂之后再自己写吧
  AON(initializer_list<Node *>);
  AON(const AON&);
  AON(AON&&);
  AON& operator=(const AON&);
  AON& operator=(AON&&);
  ~AON() = default;

  //向图中插入点,插入点的同时，更新start和end
  void insert(const Node&);
  
  void calculate();//对于只有开始结束时间的点，计算duration；对于只有duration的点，计算开始，结束时间
  
  
private:
  map<string ,Node *> Nodes;    //存放图里的点；keyvalue
  Node* start;//开始时间最早的点，不能有箭头指向他，如果存在多个最早开始点，新建一个Duration为0的点作为Start；
  Node* end;//结束时间最晚的点，不能产生新的箭头，如果存在多个最晚完成点，新建一个Duration为0的点作为End;
};

#endif
