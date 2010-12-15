#ifndef CHESS_SERVER_SELECT_H_INCLUDED
#define CHESS_SERVER_SELECT_H_INCLUDED

#include <boost/utility.hpp>

#include <ClanLib/GUI/gui_window.h>

class chessServerSelect : boost::noncopyable, public CL_GUIWindow
{
public:
   t_chessComponent(CL_GUIComponent *parent, boost::shared_ptr<CL_ResourceManager> resPtr);

private:

}


#endif
