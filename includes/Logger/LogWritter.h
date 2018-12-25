#ifndef __LOG_WRITTER_H__
#define __LOG_WRITTER_H__

#include<iostream>
#include<string>
#include <memory>
#include<fstream>


class LogWritter
{
	private:
		std::unique_ptr< std::ofstream > mFileWritter;
	public:
		LogWritter();
		~LogWritter();
		void open_logfile(const std::string& filename);
		void close_logfile();
		void write(const std::string& msg);
};
LogWritter::LogWritter():mFileWritter(new std::ofstream)
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
#endif


