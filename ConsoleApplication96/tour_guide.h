#pragma once
#include<string>
#include"trip.h"
using namespace std;
class tour_guide :public trip 
{
	int id_tour_guide;
	string name_tour_guide;
	float salary[12];
	int number_of_trips_forMonth[12];
	string state;
public:
	tour_guide();
	void set_id_tour_guide(int ID);
	int get_id_tour_guide();
	void set_name_tour_guide(string name);
	string get_name_tour_guide();
	void set_salary(int index, float value);
	float get_salary(int index);
	void set_number_of_trips_forMonth(int index, int value);
	int get_number_of_trips_forMonth(int index);
	void set_state(string s);
	string get_state();
	tour_guide add();
	tour_guide edit(tour_guide ob);
	void display(tour_guide ob);

	~tour_guide();
};


