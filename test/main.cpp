#include "pantheios/pantheios.hpp" //primary header file, always be included
#include "pantheios/frontends/stock.h"
#include "pantheios/backends/bec.file.h"

#include "pantheios/inserters.hpp"

//Specify process identity
const PAN_CHAR_T PANTHEIOS_FE_PROCESS_IDENTITY[] = "test.exe";

int main(int argc, char** argv){

//Use pantheios::log_xxx() or pantheios::log(xxx, ) with xxx is severity level

try
{
pantheios::log(pantheios::debug, "Entering main(", pantheios::args(argc, argv, pantheios::args::arg0FileOnly), ")");
pantheios_be_file_setFilePath("file");
pantheios::log_DEBUG("debug");
pantheios::log_INFORMATIONAL("informational");
pantheios::log_NOTICE("notice");
pantheios::log_WARNING("warning");
pantheios::log_ERROR("error");
pantheios::log_CRITICAL("critical");
pantheios::log_ALERT("alert");
pantheios::log_EMERGENCY("emergency");

return 1;
}

catch(std::bad_alloc&){
pantheios::log_ALERT("out of memory");
}
catch(std::exception& x){
pantheios::log_CRITICAL("Exception: ", x);
}
catch(...){
pantheios::puts(pantheios::emergency, "Unknown error");
}

return 2;
}
