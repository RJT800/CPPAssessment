#include "Meteor.h"

#include <stdlib.h>
#include <time.h>

Meteor::Meteor(float x, float y, const char* name) : Actor(x,y,name)
{
	srand(time(NULL));
}

void Meteor::start()
{

}
