#pragma once
#include<string>


using namespace std;
class ticket
{
	string type_ticket;
public:
	ticket();

	string get_type_ticket();
	void set_type_ticket(string n);

	~ticket();
};

