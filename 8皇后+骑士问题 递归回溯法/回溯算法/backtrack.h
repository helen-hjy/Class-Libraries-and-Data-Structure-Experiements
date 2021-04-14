#ifndef BACKTRACK_H
#define BACKTRACK_H

#include "application.h"

class BackTrack
{
public:
	BackTrack();
	BackTrack(Application thisApp);

	bool backTrack(Position currPos);
private:
	Application app;
};

#endif
