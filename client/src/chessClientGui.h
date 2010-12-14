#ifndef CHESS_CLIENT_GUI_H_INCLUDED
#define CHESS_CLIENT_GUI_H_INCLUDED

#include <boost/utility.hpp>
#include <boost/shared_ptr.hpp>

// Foreward declarations for needed classes
class t_chessClient;
class t_chessComponent;

class CL_ResourceManager;
class CL_GraphicContext;
class CL_Window;
class CL_Rect;
class CL_GUIManager;

class t_chessClientGui : boost::noncopyable
{
public:
   t_chessClientGui() : sizex(640), sizey(480)
   {}

   void run();
   void init();
         
private:
   void createWindow();
   void resizedFunc();
   bool closeFunc();

   boost::shared_ptr<CL_ResourceManager> resources;
   boost::shared_ptr<CL_Window> window;
   boost::shared_ptr<CL_GUIManager> gui;

   boost::shared_ptr<t_chessClient> board;
   boost::shared_ptr<t_chessComponent> comp;
   
   int sizex;
   int sizey;
};

#endif
