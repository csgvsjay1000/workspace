#ifndef __sztask_h__
#define __sztask_h__

class SZTask
{
public:
	SZTask(){}
	virtual ~SZTask(){}

	virtual void Run() = 0;
};

#endif
