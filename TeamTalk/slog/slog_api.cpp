//
// slog_api.cpp
//

#include "slog_api.h"
#include <log4cxx/logger.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/propertyconfigurator.h>
#include <log4cxx/helpers/exception.h>
#include <stdarg.h>

using namespace log4cxx;

#define MAX_LOG_LENGTH 		1024*10

class CSLogObject
{
public:
	CSLogObject(const char* module_name){}
  	virtual ~CSLogObject(){}

	virtual void Info(const char* loginfo){};
	virtual void Error(const char* loginfo){};
};

class CLog4CXX : public CSLogObject
{
public:
	CLog4CXX(const char* module_name);
	virtual ~CLog4CXX(){}

	virtual void Info(const char* loginfo);
	virtual void Error(const char* loginfo);
private:
	LoggerPtr m_logger;
};

CLog4CXX::CLog4CXX(const char* module_name) : CSLogObject(module_name)
{
	PropertyConfigurator::configureAndWatch(File("log4cxx.properties"));
	m_logger = Logger::getLogger("file");
}

void CLog4CXX::Info(const char* loginfo)
{
	m_logger->info(loginfo);
}

void CLog4CXX::Error(const char* loginfo)
{
	m_logger->error(loginfo);
}


CSLog::CSLog(const char* module_name)
{
	m_log = new CLog4CXX(module_name);
}

void CSLog::Info(const char* format,...)
{
	va_list args;
	va_start(args,format);
	char szBuffer[MAX_LOG_LENGTH];
	vsnprintf(szBuffer,sizeof(szBuffer),format,args);
	va_end(args);
	m_log->Info(szBuffer);
}

void CSLog::Error(const char* format,...)
{
	va_list args;
	va_start(args,format);
	char szBuffer[MAX_LOG_LENGTH];
	vsnprintf(szBuffer,sizeof(szBuffer),format,args);
	va_end(args);
	m_log->Error(szBuffer);
}
