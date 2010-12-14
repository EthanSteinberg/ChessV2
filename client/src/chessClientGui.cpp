#include "chessClientGui.h"
#include "chessClient.h"
#include "chessComponent.h"

#include <ClanLib/core.h>
#include <ClanLib/gl.h>
#include <ClanLib/display.h>
#include <ClanLib/gui.h>
#include <ClanLib/sound.h>

#include <boost/make_shared.hpp>

using boost::shared_ptr;
using boost::make_shared;

void t_chessClientGui::run()
{
   gui->exec();
}

void t_chessClientGui::init()
{
   
   board = make_shared<t_chessClient>(); 
   
   resources = make_shared<CL_ResourceManager>("res/resources.xml");
   gui = make_shared<CL_GUIManager>("res");
   
   createWindow();

   comp = make_shared<t_chessComponent>(window.get(),resources);
   
   resizedFunc();
}


void t_chessClientGui::createWindow()
{
   CL_DisplayWindowDescription window_desc;
   window_desc.set_size(CL_Size(sizex, sizey), true);
   window_desc.set_title("Chess");
   window_desc.set_allow_resize(true);
   
   window = make_shared<CL_Window>(gui.get(),window_desc);

   window->func_resized().set(this,&t_chessClientGui::resizedFunc);
   window->func_close().set(this,&t_chessClientGui::closeFunc);
}

void t_chessClientGui::resizedFunc()
{
   CL_Rect client_area = window->get_client_area();
   comp->set_geometry(CL_Rect(client_area.left,client_area.top,client_area.right,client_area.bottom));
   comp->request_repaint();
}
   
bool t_chessClientGui::closeFunc()
{
   gui->exit_with_code(0);
   return true;
}
