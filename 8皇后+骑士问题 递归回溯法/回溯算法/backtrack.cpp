//#include "pch.h"

#include "backtrack.h"
BackTrack::BackTrack() {};

BackTrack::BackTrack(Application thisApp)
{
	this->app = thisApp;
}

bool BackTrack::backTrack(Position currPos)
{
	app.extend(currPos);//extend the position by n

	if (app.success(currPos))//if it hasn't reached the last position
		return true;

	else
	{
		Application::Iterator itr(currPos);
		//set the dierction as 0 and curr=currpostion

		Position itrPos;
		//use as the next position

		while (!itr.tryAllNextPossible())//if is hasn't finish 8 directions
		{
			itrPos = itr.getNextPossible(app);//try to find a direction for the next position
			if (app.isValid(itrPos) && backTrack(itrPos))
				//if is valid and also could find a next position,return true to stop this method
				return true;
		}
		//cannot reach goal from currPos
		app.goBack(currPos); //reset the position as 0 and n-1
	    	return false;
	}
}