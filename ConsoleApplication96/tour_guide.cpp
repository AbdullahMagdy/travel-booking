
#include "tour_guide.h"
#include<iostream>
using namespace std;
#include<string>
tour_guide::tour_guide()
{
	id_tour_guide = 0;
	name_tour_guide = "";
	state = "free";
	for (int i = 0; i < 12; i++)
	{
		salary[i] = 0;
	}
	for (int i = 0; i < 12; i++)
	{
		number_of_trips_forMonth[i] = 0;
	}
}
void tour_guide::set_id_tour_guide(int ID)
{
	id_tour_guide = ID;
}

int tour_guide::get_id_tour_guide()
{
	return id_tour_guide;
}
void tour_guide::set_name_tour_guide(string name)
{
	name_tour_guide = name;
}
string tour_guide::get_name_tour_guide()
{
	return name_tour_guide;
}
void tour_guide::set_salary(int index, float value)
{
	salary[index] = value;
}
float tour_guide::get_salary(int index)
{
	return salary[index];
}
void tour_guide::set_number_of_trips_forMonth(int index, int value)
{
	number_of_trips_forMonth[index] = value;
}
int tour_guide::get_number_of_trips_forMonth(int index)
{
	return  number_of_trips_forMonth[index];
}
void tour_guide::set_state(string s)
{
	state = s;
}
string tour_guide::get_state()
{
	return state;
}

tour_guide tour_guide::add()
{
	tour_guide obj;
	int id; string name;
	cout << "Enter id of tour guide : \n";
	cin >> id;
	cout << "Enter Name of tour guide : \n ";
	cin >> name;
	obj.set_id_tour_guide(id);
	obj.set_name_tour_guide(name);
	return obj;

}

tour_guide tour_guide::edit(tour_guide ob)

{
	string s;
	cout << "Enter what you want to change (name/state) : \n";
	cin >> s;
	if (s == "name")
	{
		string n;
		cout << "Enter new name : \n";
		cin >> n;
		ob.set_name_tour_guide(n);
		return ob;
	}
	else if (s == "state")
	{
		string n;
		cout << "Enter New state : \n";
		cin >> n;
		ob.set_state(n);
		return ob;

	}
	return ob;

}

void tour_guide::display(tour_guide ob)
{
	cout << "id tour_guide is  : " << ob.get_id_tour_guide()<<"\n";
	cout << "name tour_guide is  : " << ob.get_name_tour_guide()<<"\n";
	cout << "State tour_guide is :" << ob.get_state()<<"\n";
	for (int i = 0; i < 12; i++)
	{
		if (ob.get_number_of_trips_forMonth(i) != 0)
			cout << "tour_guide trip in (" << i << ") month is " << ob.get_number_of_trips_forMonth(i) << "\n";
	}
	for (int i = 0; i < 12; i++)
	{
		if (ob.get_salary(i) != 0)
			cout << "tour_guide salary in (" << i << ") month is " << ob.get_salary(i)<<"\n";
	}
	
	return;

}


tour_guide::~tour_guide()
{
}
