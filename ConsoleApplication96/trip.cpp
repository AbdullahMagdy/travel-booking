#include "trip.h"
#include"customer.h"
#include<string>
using namespace std;

trip::trip()
{
	year_statrt = 0;
	year_End = 0;
	month_start = 0;
	month_end = 0;
	day_start = 0;
	day_End = 0;
	kind_of_trip = "";
	tour_guide_name_inTrip = "noone";
	number_ticket_gold = 5;
	number_ticket_silver = 5;
	number_ticket_platinum = 5;


	name_trip = "";
	number_of_seats_avilable = 0;

}


int trip::get_id()
{
	return id;
}
void trip::set_id(int n)
{
	id = n;
}

void trip::set_trip_name(string n)
{
	name_trip = n;
}
string trip::get_trip_name()
{
	return name_trip;
}

void trip::set_day_statrt(int ds)
{
	this->day_start = ds;
}
int trip::get_day_statrt()
{
	return this->day_start;
}
void trip::set_day_End(int de)
{
	day_End = de;
}
int trip::get_day_End()
{
	return day_End;
}
void trip::set_month_start(int ms)
{
	month_start = ms;
}
int trip::get_month_start()
{
	return month_start;
}
void trip::set_month_end(int me)
{
	month_end = me;
}
int trip::get_month_end()
{
	return month_end;
}
void trip::set_year_statrt(int ys)
{
	year_statrt = ys;
}
int trip::get_year_statrt()
{
	return year_statrt;
}
void trip::set_year_end(int ye)
{
	year_End = ye;
}
int trip::get_year_end()
{
	return year_End;
}
void trip::set_kind_of_trip(string kt)
{
	kind_of_trip = kt;
}
string trip::get_kind_of_trip()
{
	return kind_of_trip;
}




void  trip::set_number_ticket_gold(int n)
{
	number_ticket_gold = n;
}
int  trip::get_number_ticket_gold()
{
	return number_ticket_gold;
}

int  trip::get_number_ticket_silver()
{
	return number_ticket_silver;
}
void  trip::set_number_ticket_silver(int n)
{
	number_ticket_silver = n;
}

int  trip::get_number_ticket_platinum()
{
	return number_ticket_platinum;
}
void  trip::set_number_ticket_platinum(int n)
{
	number_ticket_platinum = n;
}


void trip::set_number_of_seats_avilable(int n)
{
	number_of_seats_avilable = n;
}
int trip::get_number_of_seats_avilable()
{
	return number_of_seats_avilable;
}

string trip::get_tour_guide_name_inTrip()
{
	return tour_guide_name_inTrip;
}
void trip::set_tour_guide_name_inTrip(string n)
{
	tour_guide_name_inTrip = n;
}