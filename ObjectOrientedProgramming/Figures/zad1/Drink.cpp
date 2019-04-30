#include "stdafx.h"
#include "Drink.h"
#include <string.h>
using namespace std;
Drink::Drink(void)
{
	Title = NULL;
	Alcohol = 0;
}


Drink::Drink(Drink &v)
{
	 if( v.Title != NULL)  {
		 Title = (char *)new char[strlen(v.Title)+1];
		 strcpy(Title,v.Title);
	 } else {
		 Title = NULL;
	 }
	  Alcohol = v.Alcohol;
}

Drink::Drink(char *title, double alcohol)
{
	 Title = (char *)new char[strlen(title)+1];
	 strcpy(Title,title);
	  Alcohol = alcohol;
}

Drink::~Drink(void)
{
	if( Title!= NULL) delete Title;

}
