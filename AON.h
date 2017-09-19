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
  AON();
  //AON(...); 写个可以用initializer list初始化的构造函数，我已经忘记怎么写了233
  
  
  
  //拷贝构造函数，重载赋值操作符函数，析构函数等
  
  //向图中插入点,插入点的同时，更新start和end
  void insert(const Node&);
  
  void caculate();//对于只有开始结束时间的点，计算duration；对于只有duration的点，计算开始，结束时间
  
  
private:
  map<string ,Node *> Nodes;    //存放图里的点；keyvalue
  Node* start;//开始时间最早的点，不能有箭头指向他，如果存在多个最早开始点，新建一个Duration为0的点作为Start；
  Node* end;//结束时间最晚的点，不能产生新的箭头，如果存在多个最晚完成点，新建一个Duration为0的点作为End;
  
  
