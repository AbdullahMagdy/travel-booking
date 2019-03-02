#pragma once
using namespace std;
#include<string>
#include"ticket.h"

class trip :public ticket
{
	int id;
	int year_statrt;
	int year_End;
	int month_start;
	int month_end;
	int day_start;
	int day_End;
	string kind_of_trip;
	string name_trip;
	int number_ticket_gold;
	int number_ticket_silver;
	int number_ticket_platinum;
	string tour_guide_name_inTrip;
	int number_of_seats_avilable;

public:


	trip();
	void set_day_statrt(int ds);

	int get_day_statrt();

	void set_day_End(int de);

	int get_day_End();

	void set_month_start(int ms);

	int get_month_start();

	void set_month_end(int me);

	int get_month_end();

	void set_year_statrt(int ys);

	int get_year_statrt();

	void set_year_end(int ye);

	int get_year_end();

	void set_kind_of_trip(string kt);

	string get_kind_of_trip();

	int get_id();
	void set_id(int n);


	void set_number_of_seats_avilable(int n);
	int get_number_of_seats_avilable();



	void set_trip_name(string n);
	string get_trip_name();


	void set_number_ticket_gold(int n);
	int get_number_ticket_gold();

	int get_number_ticket_silver();
	void set_number_ticket_silver(int n);

	int get_number_ticket_platinum();
	void set_number_ticket_platinum(int n);

	string get_tour_guide_name_inTrip();
	void set_tour_guide_name_inTrip(string n);



	
};

