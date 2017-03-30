//
//  slog_api.h
//  slog
//
//

#ifndef __slog_slog_api__
#define __slog_slog_api__

#include <stdio.h>

class CSLogObject;
class CSLog
{
public:
	CSLog(const char* module_name);

	void Info(const char* format,...);
	void Error(const char* format,...);

private:
	CSLogObject* m_log;
};

#endif
