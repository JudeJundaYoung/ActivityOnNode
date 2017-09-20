#include Node.h

// detailed
Node::Node(Date ES, Date EF, Date LS, Date LF, unsigned int Dura, 
           string ID,string Desc): EarlyStart(ES), EarlyFinish(EF),
          LateStart(LS), LateFinish(LF), Duration(Dura), ActID(ID),
          Description(Desc)
          {}
// only duration entered
Node::Node(unsigned int Dura):duration(Dura)
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
  ES = rhs.ES;
  EF = rhs.EF;
  LS = rhs.LS;
  LF = rhs.LF;
  Duration = rhs.Duration;
  ActID = rhs.ActID;
  Description = rhs.Description;
}

Node::Node(Node && rhs)
{
  ES = std::move(rhs.ES);
  EF = std::move(rhs.EF);
  LS = std::move(rhs.LS);
  LF = std::move(rhs.LF);
  Duration = std::move(rhs.Duration);
  ActID = std::move(rhs.ActID);
  Description = stD::move(rhs.Description);
}

Node& Node::operator= (const Node& rhs)
{
  if(this = &rhs)
  {
      return *this;
  }
  ES = rhs.ES;
  EF = rhs.EF;
  LS = rhs.LS;
  LF = rhs.LF;
  Duration = rhs.Duration;
  ActID = rhs.ActID;
  Description = rhs.Description;
  return *this;
}
                    
Node& Node::operator= (Node&&)
{
  if(this = &rhs)
  {
      return *this;
  }
  ES = std::move(rhs.ES);
  EF = std::move(rhs.EF);
  LS = std::move(rhs.LS);
  LF = std::move(rhs.LF);
  Duration = std::move(rhs.Duration);
  ActID = std::move(rhs.ActID);
  Description = stD::move(rhs.Description);
  return *this;
}

bool Node::check_Elmentary_Parameters()
{   
  if(EarlyStart==0||EarlyFinish==0||LateStart==0||LateFinish==0||Duratin==0)
  {
             return 0;
  }
           return 1;
}

bool Node::check_Optional_Parameters()
{
           if(ActID.empty()||Description.empty())
           {
                      return 0;
           }
           return 1;
}

void Node::printParameters()
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

void add_predecessor(const Node & pre)
{
           if(pre.EarlyFinish>EarlyStart||pre.LateFinish>LateStart)
                      //throw
                 
                  
}
          


 
