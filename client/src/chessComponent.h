#ifndef CHESS_GUI_COMPONENT_H_INCLUDED
#define CHESS_GUI_COMPONENT_H_INCLUDED

#include <boost/utility.hpp>
#include <boost/shared_ptr.hpp>

#include <iostream>

#include <ClanLib/GUI/gui_component.h>

class CL_Image;

class t_chessComponent : boost::noncopyable, public CL_GUIComponent
{
public:

   t_chessComponent(CL_GUIComponent *parent,const CL_Rect& position, boost::shared_ptr<CL_Image> imagePtr) : CL_GUIComponent(parent), boardImage(imagePtr)
   {
      func_render().set(this,&t_chessComponent::renderFunc);
      func_resized().set(this,&t_chessComponent::resizeFunc);
      func_process_message().set(this,&t_chessComponent::messageFunc);
      
      set_geometry(position);
      
      std::cout<<"I was created!!!, good"<<std::endl;
   }

private:   
   void renderFunc(CL_GraphicContext &gc, const CL_Rect &clip_rect);
   void resizeFunc();
   void messageFunc(CL_GUIMessage &lol);

   boost::shared_ptr<CL_Image> boardImage;
      

};


#endif
