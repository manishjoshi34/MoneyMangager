#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <string>
#include <iostream>
#include <mutex>
#include<sstream>

#include "LogWritter.h"

using namespace std;

enum logtype
{	debug=0,
	warning,
	error
};
template <typename LogWritter>
class Logger
{
	private:
		unsigned long int mLog_line_number;
		string get_time();
		string get_header();
	       	stringstream mLog_stream;
		mutex mWrite_mutex;	
		void print_impl();
		template<typename First, typename...Rest>
		void print_impl(First arg1, Rest...args);
		LogWritter* mLogWritter;
	public:
		Logger(const string& aFilename);
		template< logtype aLogType, typename...Args >
		void print(Args...args);
		~Logger();
};

template <typename LogWritter>
Logger<LogWritter>::Logger(const string& filename)
{
	mLog_line_number = 0;
	mLogWritter = new LogWritter;
	if(mLogWritter == NULL)
	{
		throw runtime_error("LOGGER: Unable to get LogWritter");
	}

	mLogWritter -> open_logfile( filename );	
}
template <typename LogWritter>
Logger<LogWritter>::~Logger()
{
	if(mLogWritter)
	{
		mLogWritter -> close_logfile();
		delete mLogWritter;
	}
}
template <typename LogWritter>
string Logger<LogWritter>::get_time()
{
	string time_str;
	time_t raw_time;
	time(& raw_time);
	time_str = ctime(&raw_time);
	return time_str.substr(0,time_str.size()-1); //remove new line character
}
template <typename LogWritter>
string Logger<LogWritter>::get_header()
{
	stringstream header;
	header.str("");
	header <<"["<<mLog_line_number++<<"][ "<<get_time()<<"]";
	return header.str();
}
template <typename LogWritter >
void Logger<LogWritter>::print_impl()
{
	mLogWritter->write(get_header() + mLog_stream.str() );
	mLog_stream.str("");
}

template <typename LogWritter >
template<typename First, typename...Rest>
void Logger<LogWritter>::print_impl(First arg1,Rest...args)
{
	mLog_stream<<"[ "<<arg1<<" ]";
	print_impl(args...);
}
template <typename LogWritter >
template< logtype aLogType, typename...Args >
void Logger<LogWritter>::print(Args...args)
{
	mWrite_mutex.lock();
	switch ( aLogType )
	{
		case logtype::debug :
		     mLog_stream<<"[Debug]";
		     break;
		case logtype::warning :
		    mLog_stream<<"[Warning]";
		    break;
		case logtype::error :
		    mLog_stream<<"[Error]";
		    break;
		default:
		    mLog_stream<<"[info]";
	};
	print_impl(args...);
	mWrite_mutex.unlock();
}
#endif
