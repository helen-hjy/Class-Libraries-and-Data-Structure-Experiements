#ifndef APPLICATION_H
#define APPLICATION_H

#include "position.h"

class Application
{
public:
	void initialize(); //intialization 

	Position getStartPosition(); //get the start position

	bool isValid(Position p);

	void extend(Position p);

	bool success(Position p);

	void goBack(Position p);

	void print();

	class Iterator
	{
	public:
		Iterator();
		Iterator(Position currP);

		Position getNextPossible(Application& a);
		bool tryAllNextPossible();

	private:
		Position curr;
		int Directions;
	};
};


#endif
