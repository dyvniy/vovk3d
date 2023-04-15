/*
* Main interfase for client side
*/

#include "singleton0.h"

struct G_Screen: public Singleton {
	//
	virtual G_Screen* singleton();
};