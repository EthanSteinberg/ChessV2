#include "chessComponent.h"

#include <ClanLib/display.h>
   

void t_chessComponent::renderFunc(CL_GraphicContext &gc, const CL_Rect &clip_rect)
{
   CL_Colorf red(155/255.0f, 60/255.0f, 68/255.0f);
   CL_Draw::fill(gc, clip_rect,red);
   boardImage->draw(gc,clip_rect);
   std::cout<<"I was rendered!!!, yay"<<std::endl;
}

void t_chessComponent::resizeFunc()
{
   std::cout<<"I was resized!!!, ok"<<std::endl;
}

void t_chessComponent::messageFunc(CL_GUIMessage &lol)
{
   std::cout<<"I got a message"<<std::endl;
}
