#include "customer.h"
#include<iostream>
using namespace std;
#include<string>
#include<vector>
 vector<trip> customer:: list_of_add_trips_done;

customer::customer()
{
	
	id_customer = 0;
	name_customer = "";
	number_trips_custommer = 0;
	discount_or_No = "";
	number_ticket_recive = 0;
	

}

void customer::set_id_customer(int ic)
{
	id_customer = ic;
}
int customer::get_id_customer()
{
	return id_customer;
}
void customer::set_name_customer(string nc)
{
	name_customer = nc;
}
string customer::get_name_customer()
{
	return name_customer;
}
void customer::set_discount_or_No(string dn)
{
	discount_or_No = dn;
}
string customer::get_discount_or_No()
{
	return discount_or_No;
}
void customer::set_number_trips_customer(int ntc)
{
	number_trips_custommer = ntc;
}
int customer::get_number_trips_customer()
{
	return number_trips_custommer;
}


trip customer::get_object_trip()
{
	return object_trip;

}
void customer::set_object_trip(trip o)
{
	object_trip = o;
}

int customer::get_number_ticket_recive()
{
	return number_ticket_recive;
}
void customer::set_number_ticket_recive(int n)
{
	number_ticket_recive = n;
}



customer customer::add()
{

	int id; string name; string kind_trip; int y_s; int m_s; int d_s; int y_e; int m_e; int d_e; string nameoftrip;
	customer obj; string ticket_type; int number_of_allseats_avilable_in_trip;
	trip objtrip;
	cout << "Enter Customer ID : \n";
	cin >> id;
	cout << "Enter Customer name : \n";
	cin >> name;



	cout << "Enter name of trip : \n";
	cin >> nameoftrip;
	objtrip.set_trip_name(nameoftrip);

	cout << "Enter Trip start year  : \n";
	cin >> y_s;
	objtrip.set_year_statrt(y_s);

	cout << "Enter Trip start month  : \n";
	cin >> m_s;
	objtrip.set_month_start(m_s);

	cout << "Enter Trip start day  : \n";
	cin >> d_s;
	objtrip.set_day_statrt(d_s);

	objtrip = check_trip_is_already_found_or_not(objtrip);


	cout << "Enter Trip End year  : \n";
	cin >> y_e;
	objtrip.set_year_end(y_e);

	cout << "Enter Trip End month  : \n";
	cin >> m_e;
	objtrip.set_month_end(m_e);

	cout << "Enter Trip End day  : \n";
	cin >> d_e;
	objtrip.set_day_End(d_e);

	cout << "Enter Customer kind trip ( Family , Couple , General ): \n";
	cin >> kind_trip;
	objtrip.set_kind_of_trip(kind_trip);

	

	while (true)
	{
		cout << "Enter type  Of ticket you want to recive it( gold , platinum , silver ) : \n ";
		cin >> ticket_type;
		if (checkticket(ticket_type, objtrip))
		{
			objtrip.set_type_ticket(ticket_type);
			obj.set_number_ticket_recive((obj.get_number_ticket_recive() + 1));
			int choice;
			cout << "Do you want to add new ticket :(1/0) :";
			cin >> choice;
			if (choice == 0)
				break;


		}

	}


	number_of_allseats_avilable_in_trip = objtrip.get_number_ticket_gold() + objtrip.get_number_ticket_platinum() + objtrip.get_number_ticket_silver();
	objtrip.set_number_of_seats_avilable(number_of_allseats_avilable_in_trip);
	obj.set_id_customer(id);
	obj.set_name_customer(name);
	obj.set_number_trips_customer((obj.get_number_trips_customer() + 1));
	obj.set_object_trip(objtrip);
	choice_tour_guide_auto(objtrip);
	int y = check_trip(objtrip);
	if (y == -1)
		obj.list_of_add_trips_done.push_back(objtrip);
	else
	{
		obj.list_of_add_trips_done.at(y) = objtrip;

	}
	
	return obj;
}


trip customer::check_trip_is_already_found_or_not(trip object)
{
	customer obj;
	for (vector<trip >::iterator it = obj.list_of_add_trips_done.begin(); it != obj.list_of_add_trips_done.end(); it++)
	{
		if (it->get_trip_name() == object.get_trip_name() && it->get_year_statrt() == object.get_year_statrt() && it->get_month_start() == object.get_month_start() && it->get_day_statrt() == object.get_day_statrt())
		{

			return *it;
		}

	}

	return object;
}


int customer::check_trip(trip object)
{
	
		customer obj;
		vector<trip>::iterator it ;
	int i = 0;
	for (it = obj.list_of_add_trips_done.begin(); it != obj.list_of_add_trips_done.end(); it++)
	{
		if (it->get_trip_name() == object.get_trip_name() && it->get_year_statrt() == object.get_year_statrt() && it->get_month_start() == object.get_month_start() && it->get_day_statrt() == object.get_day_statrt())
		{
			return i;
		}
		i++;

	}

	return -1;

	
}

bool customer::checkticket(string s, trip &ob)
{

	int x;
	if (s == "gold")
	{
		if (ob.get_number_ticket_gold() != 0)
		{
			x = ob.get_number_ticket_gold();
			ob.set_number_ticket_gold(x - 1);
			return true;
		}
		else
			return false;
	}
	else if (s == "silver")
	{
		if (ob.get_number_ticket_silver() != 0)
		{
			x = ob.get_number_ticket_silver();
			ob.set_number_ticket_silver(x - 1);
			return true;
		}
		else
			return false;
	}
	else if (s == "platinum")
	{
		if (ob.get_number_ticket_platinum() != 0)
		{
			x = ob.get_number_ticket_platinum();
			ob.set_number_ticket_platinum(x - 1);
			return true;
		}
		else
			return false;
	}

	return false;


}



customer customer::edit(customer ob)
{

	string s;
	cout << "Enter what you want to edit : ";
	cin >> s;
	if (s == "name")
	{
		string na;
		cout << "Enter new name : \n";
		cin >> na;
		ob.set_name_customer(na);
		return ob;
	}

	else if (s == "year_statrt")
	{
		int na;
		cout << "Enter new year_statrt : \n";
		cin >> na;
		ob.object_trip.set_year_statrt(na);
		return ob;
	}
	else if (s == "nametrip")
	{
		string n;
		cout << "Enter the new trip name : \n";
		cin >> n;
		ob.object_trip.set_trip_name(n);
		return ob;
	}
	else if (s == "year_End")
	{
		int na;
		cout << "Enter new year_End : \n";
		cin >> na;
		ob.object_trip.set_year_end(na);
		return ob;
	}
	else if (s == "month_start")
	{
		int na;
		cout << "Enter new month_start : \n";
		cin >> na;
		ob.object_trip.set_month_start(na);
		return ob;
	}
	else if (s == "month_end")
	{
		int na;
		cout << "Enter new month_end : \n";
		cin >> na;
		ob.object_trip.set_month_end(na);
		return ob;
	}
	else if (s == "day_start")
	{
		int na;
		cout << "Enter new day_start : \n";
		cin >> na;
		ob.object_trip.set_day_statrt(na);
		return ob;
	}
	else if (s == "day_End")
	{
		int na;
		cout << "Enter new day_End : \n";
		cin >> na;
		ob.object_trip.set_day_End(na);
		return ob;
	}


	else if (s == "kindoftrip")
	{
		string na;
		cout << "Enter new kind_of_trip : \n";
		cin >> na;
		ob.object_trip.set_kind_of_trip(na);
		return ob;


	}
	else if (s == "kindofticket")
	{
		string tiket_old_type, tiket_new_type;
		cout << "Enter old kind of ticket you want to change : ";
		cin >> tiket_old_type;
		cout << "Enter new kind of ticket :";
		cin >> tiket_new_type;
		if (tiket_old_type == "gold")
		{
			int x = ob.object_trip.get_number_ticket_gold();
			ob.object_trip.set_number_ticket_gold(x + 1);


		}
		else if (tiket_old_type == "silver")
		{
			int x = ob.object_trip.get_number_ticket_silver();
			ob.object_trip.set_number_ticket_silver(x + 1);

		}

		else if (tiket_old_type == "platinum")
		{
			int x = ob.object_trip.get_number_ticket_platinum();
			ob.object_trip.set_number_ticket_platinum(x + 1);

		}
		if (tiket_new_type == "gold")
		{
			int x = ob.object_trip.get_number_ticket_gold();
			ob.object_trip.set_number_ticket_gold(x - 1);
			return ob;
		}
		if (tiket_old_type == "silver")
		{
			int x = ob.object_trip.get_number_ticket_silver();
			ob.object_trip.set_number_ticket_silver(x - 1);
			return ob;
		}

		if (tiket_old_type == "platinum")
		{
			int x = ob.object_trip.get_number_ticket_platinum();
			ob.object_trip.set_number_ticket_platinum(x - 1);
			return ob;
		}
	}

	return ob;

}






void customer::display(vector<customer> vec)

{

	int size = vec.size();
	vec.at(0).set_number_trips_customer(size);
	cout << "Customer ID :  " << vec.at(0).get_id_customer() << "\n";
	cout << "Customer name :  " << vec.at(0).get_name_customer() << "\n";
	cout << "Customer number of trip :  " << vec.at(0).get_number_trips_customer() << "\n";
	cout << "Name of trips this customer do : \n";
	for (auto i = vec.begin(); i != vec.end(); i++)
	{
	
		cout << "name : " << i->object_trip.get_trip_name() << "  Start Year : " << i->object_trip.get_year_statrt() << "  End Year : " << i->object_trip.get_year_end() << "  kind : " << i->object_trip.get_kind_of_trip() << "\n";
		cout << "tickets avilable in trip : " << i->object_trip.get_number_of_seats_avilable()<<"\n";
		cout << "******************************* \n";
		cout << "\n";
	}

}

void customer::display_all_trip_done()
{
	vector<trip> ::iterator it = list_of_add_trips_done.begin();
	for (; it != list_of_add_trips_done.end(); it++)
	{
		
		cout << "Trip Name : " << it->get_trip_name()<<"\n";
		cout << "Trip Start year :" << it->get_year_statrt() << "\n";
		cout << "Trip Start Month : " << it->get_month_start() << "\n";
		cout << "Trip Tour guide : " << it->get_tour_guide_name_inTrip()<<"\n";

	}




}





customer::~customer()
{
}
