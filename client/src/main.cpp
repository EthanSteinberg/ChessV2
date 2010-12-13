#include <ClanLib/core.h>
#include <ClanLib/application.h>

#include <vector>

#include "chessClientGui.h"

using std::vector;

int MyMain(const vector<CL_String> &args)
{
   CL_Console console;

   try
   {
      t_chessClientGui gui;

      gui.init();
      gui.run();
   }

   catch(CL_Exception &exception)
   {
      console.write_line("Error: " + exception.get_message_and_stack_trace());
      
      return -1;
   }
   
   catch(std::exception &exception)
   {
      console.write("Error: %s",exception.what());
      return -2;
   }

   return 0;
}
CL_ClanApplication app(MyMain);
      
      
      
      
      
