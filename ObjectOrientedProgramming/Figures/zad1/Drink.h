#pragma once
class Drink
{
	 
public:
	char *Title;
	 double Alcohol;

	Drink(void);
	Drink(Drink &v);
	Drink(char *title, double alcohol);

	bool operator<(Drink &v) { 
		return strcmp(Title,v.Title) < 0 ; 
	}

	bool operator<(char *title) { 
		return strcmp(Title,title) < 0 ; 
	}

	~Drink(void);
};

