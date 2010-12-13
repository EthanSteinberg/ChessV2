#ifndef CHESS_CLIENT_H_INCLUDED
#define CHESS_CLIENT_H_INCLUDED

#include <boost/utility.hpp>
#include <iostream>


class t_chessClient : boost::noncopyable
{
public:
   t_chessClient()
   {}
   
   ~t_chessClient()
   {
      std::cout<<"I can only hope..."<<std::endl;  
   }

private:
   t_chessClient(const t_chessClient &); //keep undefined
   t_chessClient operator=(const t_chessClient &); //also keep an errorc

};

#endif
