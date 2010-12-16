#ifndef CHESS_CLIENT_GUI_H_INCLUDED
#define CHESS_CLIENT_GUI_H_INCLUDED

#include <boost/utility.hpp>
#include <boost/shared_ptr.hpp>

// Foreward declarations for needed classes
class t_chessComponent;
class t_chessMenu;

class CL_ResourceManager;
class CL_GraphicContext;
class CL_Window;
class CL_Rect;
class CL_GUIManager;
class CL_Label;

class t_chessGui : boost::noncopyable
{
public:
   t_chessGui() : sizex(640), sizey(480)
   {}

   void run();
   void init();
         
private:
   void createWindow();
   void resizedFunc();
   bool closeFunc();

   CL_GUIManager *gui;
   CL_ResourceManager* resources;

   CL_Window* window;
   boost::shared_ptr<t_chessComponent> comp;
   boost::shared_ptr<t_chessMenu> menu;

   boost::shared_ptr<CL_Label> label;
   
   int sizex;
   int sizey;
};

#endif
