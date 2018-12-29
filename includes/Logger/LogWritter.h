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
#endif


