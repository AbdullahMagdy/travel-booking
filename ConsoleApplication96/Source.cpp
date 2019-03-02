#include<iostream>
using namespace std;
#include"ticket.h"
#include "trip.h"
#include"tour_guide.h"
#include"customer.h"

#include<map>
#include<vector>
#include<cmath>
map<int, tour_guide> tour_guide_map;
map<int, vector<customer>> customer_map;
void choice_tour_guide_auto(trip& ob);
void prepare_tourguide();
void make_discount(vector<customer>vec);


int main()
{
	while (true)
	{
	int choice;
	cout << " 1 : Customer Account \n";
	cout << " 2 : Tour Guide Account \n";
	cout << " 3 : To display all trip Done \n";
	cout << " 4 : To Exit from proggram \n";
	cout << "Enter your Choice :  ";
	cin >> choice;
	

		switch (choice)
		{
		case 1:
			int ch;
			cout << "1: Add new Coustomer to Project \n";
			cout << "2: Edit new Coustomer to Project \n";
			cout << "3: Delete new Coustomer to Project \n";
			cout << "4: Display new Coustomer to Project \n";
			cin >> ch;
			if (ch == 1)
			{
				while (true)
				{
					int state;
					customer obj1;
					obj1 = obj1.add();
					customer_map[obj1.get_id_customer()].push_back(obj1);
					vector<customer> vec = customer_map.at(obj1.get_id_customer());

					cout << "this trip is recived ! \n";
					void prepare_tourguide();
					make_discount(vec);
					cout << "You want to save new Trip (1/0)  :";
					cin >> state;
					if (state == 0)
						break;
				}
				break;
			}
			else if (ch == 2)
			{
				customer objnew, obj;
				int i; string name;
				cout << "Enter ID for Customer you want to edit : ";
				cin >> i;
				cout << "Enter Name of Trip you want to edit it : ";
				cin >> name;
				vector<customer> ::iterator it1 = customer_map[i].begin();
				vector<customer> ::iterator it2 = customer_map[i].begin();
				int ind;
				int size = customer_map[i].size();
				while (it1 != customer_map[i].end())
				{
					if (it1->get_object_trip().get_trip_name() == name)
					{
						objnew = obj.edit(*it1);
						ind = distance(it2, it1);

						break;
					}
					it1++;
				}
				customer_map[i].at(ind) = objnew;
				break;

			}

			else if (ch == 3)
			{
				int i;
				cout << "Enter id of customer you want to remove him : ";
				cin >> i;
				for (auto it = customer_map.begin(); it != customer_map.end(); it++)
				{
					if (it->first == i)
					{
						customer_map.erase(it);
						cout << "Delete is Done \n";
						break;
					}
				}
				break;

			}
			else if (ch == 4)
			{
				customer ob;
				vector<customer> vec;
				int i;
				cout << "Enter id of customer you want to display his data :";
				cin >> i;

				auto it = customer_map.find(i);
				vec = it->second;
				ob.display(vec);

				break;
			}
		case 2:

			int ch2;
			cout << "1: Add new tour guide to Project \n";
			cout << "2: Edit new tour guide \n";
			cout << "3: Delete  tour guide from Project \n";
			cout << "4: Display new tour guide to Project \n";
			cin >> ch2;
			

				if (ch2 == 1)
				{
					tour_guide obj;
					obj = obj.add();
					map<int, tour_guide> ::iterator it;
					do
					{
						it = tour_guide_map.find(obj.get_id_tour_guide());
						while (it != tour_guide_map.end())
						{
							int n;
							cout << "this id is already fout pleas Enter new id : \n";
							cin >> n;
							obj.set_id_tour_guide(n);
							it = tour_guide_map.find(obj.get_id_tour_guide());

						}
						break;

					} while (true);

					tour_guide_map.insert(pair<int, tour_guide>(obj.get_id_tour_guide(), obj));
					cout << "Done \n";
					break;
				}
				else if (ch2 == 2)
				{
					tour_guide obj;
					int num;

					cout << "Enter ID of tour Guide you want to Edit  : \n";
					cin >> num;
					obj = obj.edit(tour_guide_map.at(num));
					tour_guide_map.at(num) = obj;
					break;
				}
				else if (ch2 == 3)
				{
					tour_guide obj; int i;
					cout << "Enter Id tour_guide you want to remove him : \n";
					cin >> i;
					for (auto it = tour_guide_map.begin(); it != tour_guide_map.end(); it++)
					{
						if (it->first == i)
						{
							tour_guide_map.erase(it);
							cout << "Delete is Done \n";
							break;
						}
					}
					break;

				}
				else if (ch2 == 4)
				{
					int i; tour_guide obj;
					cout << "Enter ID for tour_guide you want to display his Data : \n";
					cin >> i;
					obj = tour_guide_map.at(i);
					obj.display(obj);
					break;
				}
	
		case 3:
		{	
				  customer ob;
		ob.display_all_trip_done();
		break;

		}

		case 4:
		{
				  exit(0);
		}
		default:
			break;
		}

	}


	system("pause");

	return  0;

}

void choice_tour_guide_auto(trip& ob)
{

	map<int, tour_guide> ::iterator it = tour_guide_map.begin();
	for (; it != tour_guide_map.end(); it++)
	{
		if (ob.get_tour_guide_name_inTrip() == "noone")
		{

			if (it->second.get_state() == "free")
			{
				ob.set_tour_guide_name_inTrip(it->second.get_name_tour_guide());
				it->second.set_state("basy");
				it->second.set_number_of_trips_forMonth(ob.get_month_start(), (it->second.get_number_of_trips_forMonth(ob.get_month_start()) + 1));
				it->second.set_salary(ob.get_month_start(), (it->second.get_salary(ob.get_month_start()) + 100));
				cout << "tour guide add to trip successful !\n";
				return;
			}
		}

	}
	if (ob.get_tour_guide_name_inTrip() != "noone")
	{
		cout << "this trip have tour guide already ! \n";
		return;
	}
	cout << "No tour guide free now ! \n";
	ob.set_tour_guide_name_inTrip("noone");
	return;




}
void prepare_tourguide()
{
	map<int, tour_guide> ::iterator it = tour_guide_map.begin();
	for (; it != tour_guide_map.end(); it++)
	{
		if (it->second.get_year_end() > 2018)
		{
			continue;
			
		}
		if (it->second.get_month_end() > 5)
		{
			continue;
		}

		if (it->second.get_day_End() > 2)
		{
			continue;
		}
		
		it->second.set_state("free");
		
	}
}
void make_discount(vector<customer>vec)
{
	int count=0;
	int size = vec.size();
	if (size == 1)
	{
		return;
	}
	else
	{
		string s = vec.at(0).get_object_trip().get_kind_of_trip();
		vector<customer> ::iterator it = vec.begin();
		for (; it != vec.end(); it++)
		{
			if (it->get_object_trip().get_kind_of_trip() != s)
			{
				count++;
			}

		}

		if (count != 0)
			cout << "you have discount ! \n";
		return;

	}
	
	


}