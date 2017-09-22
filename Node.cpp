#include "Node.h"

// detailed
Node::Node(Date ES, Date EF, Date LS, Date LF, unsigned int Dura, 
           string ID,string Desc): EarlyStart(ES), EarlyFinish(EF),
          LateStart(LS), LateFinish(LF), Duration(Dura), ActID(ID),
          Description(Desc)
          {}
// only duration entered
Node::Node(unsigned int Dura):Duration(Dura)
           {}

// lack of ActID and Description
Node::Node(Date ES, Date EF, Date LS, Date LF): EarlyStart(ES),EarlyFinish(EF),
           LateStart(LS), LateFinish(LF)
           {
              unsigned int Dura1 = EF - ES;
              unsigned int Dura2 = LF - LS;
              if(Dura1!=Dura2)
              {
                  //输入的起止时间所计算出的duration不一致
                  throw std::invalid_argument( "Durations don't correspondense" );
              }
              else
              {
                Duration = Dura1;
              }
           }

Node::Node(Date ES, Date EF, Date LS, Date LF, unsigned int Dura):
          EarlyStart(ES), EarlyFinish(EF), LateStart(LS), LateFinish(LF),
          Duration(Dura)
          {}

Node::Node(const Node & rhs)
{
  EarlyStart = rhs.EarlyStart;
  EarlyFinish = rhs.EarlyFinish;
  LateStart = rhs.LateStart;
  LateFinish = rhs.LateFinish;
  Duration = rhs.Duration;
  ActID = rhs.ActID;
  Description = rhs.Description;
}

Node::Node(Node && rhs)
{
  EarlyStart = std::move(rhs.EarlyStart);
  EarlyFinish = std::move(rhs.EarlyFinish);
  LateStart = std::move(rhs.LateStart);
  LateFinish = std::move(rhs.LateFinish);
  Duration = std::move(rhs.Duration);
  ActID = std::move(rhs.ActID);
  Description = std::move(rhs.Description);
}

Node& Node::operator= (const Node& rhs)
{
  if(this == &rhs)
  {
      return *this;
  }
  EarlyStart = rhs.EarlyStart;
  EarlyFinish = rhs.EarlyFinish;
  LateStart = rhs.LateStart;
  LateFinish = rhs.LateFinish;
  Duration = rhs.Duration;
  ActID = rhs.ActID;
  Description = rhs.Description;
  return *this;
}
                    
Node& Node::operator= (Node&& rhs)
{
  if(this == &rhs)
  {
      return *this;
  }
  EarlyStart = std::move(rhs.EarlyStart);
  EarlyFinish = std::move(rhs.EarlyFinish);
  LateStart = std::move(rhs.LateStart);
  LateFinish = std::move(rhs.LateFinish);
  Duration = std::move(rhs.Duration);
  ActID = std::move(rhs.ActID);
  Description = std::move(rhs.Description);
  return *this;
}

bool Node::check_Elementary_Parameters() const
{   
  if(EarlyStart==0||EarlyFinish==0||LateStart==0||LateFinish==0||Duration==0)
  {
             return 0;
  }
           return 1;
}

bool Node::check_Optional_Parameters() const
{
           if(ActID.empty()||Description.empty())
           {
                      return 0;
           }
           return 1;
}

void Node::print_Parameters() const
{
         if(check_Elementary_Parameters())
         {
                    cout<<"EarlyStart: "<<EarlyStart<<endl;
                    cout<<"EarlyFinish: "<<EarlyFinish<<endl;
                    cout<<"LateStart: "<<LateStart<<endl;
                    cout<<"LateFinish: "<<LateFinish<<endl;
                    cout<<"Duration: "<<Duration<<endl;
         }
           if(check_Optional_Parameters())
           {
                    cout<<"ActID: "<<ActID<<endl;
                      cout<<"Description: "<<Description<<endl;
           }
}

string Node::get_ActID() const
{
	return ActID;
}

const Node* Node::get_Iterator() const
{
	return this;
}

void Node::add_predecessor(Node & pre)
{
	if (pre.EarlyFinish > EarlyStart || pre.LateFinish > LateStart)
	{
		//汉典帮我改一下 throw("Wrong Sequence");
		return;
	}
	if (Predecessors.find(&pre) != Predecessors.end())
	{
		//throw("predecessor exists!")
		return;
	}
	Predecessors.emplace(&pre);                  
	pre.add_successsor(*this);
}

void Node::add_successsor(Node & suc)
{
	if (suc.EarlyStart < EarlyFinish || suc.LateStart < LateFinish)
	{
		// throw(" Wrong sequence");
		return;
	}
	if (Successors.find(&suc) != Predecessors.end())
	{
		//throw("Successor Exists!");
		return;
	}
	Successors.emplace(&suc);
	suc.add_predecessor(*this);
}


          


 
