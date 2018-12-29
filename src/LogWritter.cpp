#include "LogWritter.h"

LogWritter::LogWritter():
        mFileWritter(new std::ofstream)
{
}

void LogWritter::open_logfile(const std::string& filename)
{
        mFileWritter ->open(filename.c_str(),std::ios_base::binary|std::ios_base::out);
        if( !mFileWritter->is_open() )
        {
                throw(std::runtime_error("LOGGER: Unable to open an output file"));
        }
}
void LogWritter::close_logfile()
{
        if(mFileWritter->is_open())
                mFileWritter->close();
}
void LogWritter::write(const std::string& msg)
{
        (*mFileWritter) << msg <<std::endl;
}

LogWritter::~LogWritter()
{
        if(mFileWritter->is_open())
                close_logfile();
}

