#include "chessClientGui.h"
#include "chessClient.h"
#include "chessComponent.h"

#include <ClanLib/core.h>
#include <ClanLib/gl.h>
#include <ClanLib/display.h>
#include <ClanLib/gui.h>
#include <ClanLib/sound.h>


using boost::shared_ptr;

void t_chessClientGui::resize(CL_Rect &lol)
{
   int x = lol.right- lol.left;
   int y = lol.bottom - lol.top;
   
   sizex = x;
   sizey = y;         
}

void t_chessClientGui::run()
{

   while (!quit)
   {
      CL_Colorf red(155/255.0f, 60/255.0f, 68/255.0f);
      CL_Draw::fill(*gc, CL_Rectf(0, sizey, sizex, 0), red);
      boardImage->draw(*gc,CL_Rectf(0,sizey,sizex,0));

      //window->flip();
      CL_KeepAlive::process();
      CL_System::sleep(10);
   }		

}

void t_chessClientGui::init()
{
   quit = 0;   

   CL_SetupCore setupCore;
   CL_SetupDisplay setupDisplay;
   CL_SetupGL setupGL;
   CL_SetupGUI setupGUI;

   board = shared_ptr<t_chessClient>(new t_chessClient()); 
   
   resources = shared_ptr<CL_ResourceManager>(new CL_ResourceManager("res/resources.xml"));
   gui = shared_ptr<CL_GUIManager>(new CL_GUIManager("res"));
   createWindow();

   gc = &(window->get_gc());


   boardImage = shared_ptr<CL_Image> (new CL_Image(*gc,"Board",resources.get()));
   

   CL_Rect client_area = window->get_client_area();

   t_chessComponent what(window.get(),CL_Rect(client_area.left + 300,client_area.top + 300,CL_Size(100,100)),boardImage);

   CL_PushButton button(window.get());
   button.set_geometry(CL_Rect(client_area.left + 10, client_area.top + 10, CL_Size(160, 40)));
   button.set_text("Button");

   what.request_repaint();
   

   gui->exec();
}


void t_chessClientGui::createWindow()
{
   CL_DisplayWindowDescription window_desc;
   window_desc.set_size(CL_Size(sizex, sizey), true);
   window_desc.set_title("Chess");
   window_desc.set_allow_resize(true);
   
   window = shared_ptr<CL_Window>(new CL_Window(gui.get(),window_desc));
   
   //window->func_window_resize().set(this, &t_chessClientGui::resize);
   //quitSlot = shared_ptr<CL_Slot>(new CL_Slot(window->sig_window_close().connect(this, &t_chessClientGui::onQuit)));
}

void t_chessClientGui::onQuit()
{
   quit = true;
}
