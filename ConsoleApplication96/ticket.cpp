#include "ticket.h"

#include<string>
using namespace std;
ticket::ticket()
{
	type_ticket = "";
}


string ticket::get_type_ticket()
{
	return  type_ticket;
}
void ticket::set_type_ticket(string n)
{
	type_ticket = n;
}

ticket::~ticket()
{
}
