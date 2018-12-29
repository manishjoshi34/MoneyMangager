#ifndef __LOG_H__
#define __LOG_H__

#include"logger.h"
#include"LogWritter.h"
#include<string>


#define LOG mLogger->print< logtype::debug>
#define LOG_ERR mLogger->print<logtype::error>
#define LOG_WAR mLogger->print<logtype::warning>

	
static Logger<LogWritter>* mLogger  = Logger<LogWritter>::getLogger();

#endif
