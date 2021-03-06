
#include <time.h>
#include <iostream>
#include "backtrack.h"
using namespace std;
int main()
{
	Application app;
	BackTrack btr(app);
	time_t t1,t2;
	t1= time(NULL);
	
	if (btr.backTrack(app.getStartPosition()))
	{
		t2 = time(NULL);
		app.print();
		cout << "time cost:" << t2 - t1 << "s";
	}
	else
		cout << "Problem has no solution!" << endl;

	
	return 0;
}
