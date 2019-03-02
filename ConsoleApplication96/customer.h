#pragma once
#include"trip.h"
#include<vector>
class customer
{
	int id_customer;
	string name_customer;
	int number_trips_custommer;
	string discount_or_No;
	trip object_trip;
	int number_ticket_recive;

public:
	friend class trip;
	friend void choice_tour_guide_auto(trip& ob);
		
	 static vector<trip> list_of_add_trips_done;

	void set_id_customer(int ic);

	int get_id_customer();

	void set_name_customer(string nc);

	string get_name_customer();

	void set_discount_or_No(string dn);

	string get_discount_or_No();

	void set_number_trips_customer(int ntc);

	int get_number_trips_customer();

	customer add();
	void display(vector<customer> vec);
	int check(string s, int n);
	bool checkticket(string s, trip &ob);
	customer edit(customer ob);
	trip get_object_trip();
	void set_object_trip(trip o);

	int get_number_ticket_recive();
	void set_number_ticket_recive(int n);
	trip check_trip_is_already_found_or_not(trip object);
	void display_all_trip_done();
	int check_trip(trip object);
	
	customer();
	~customer();
};

