#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include<FL/Fl.H>
#include<FL/fl_ask.H>
#include<FL/Fl_Window.H>
using namespace std;
// /////////////////////////////////////
//           R O B O T P A R T
// /////////////////////////////////////

class Robot_part {

	protected:
		string type;
		string name;
		int model_number;
		double cost;
		double weight;
		string description;
		string image_filename;
	public:
		string get_name();
		int get_model_number();
		string get_string_part_num();
		double get_cost();
		string get_description();
		string get_type();
		double get_weight();
		string robot_part_to_string();
		Robot_part(string _name, int _model_number, double _cost, string _description, string _type, double _weight) :
		name(_name), model_number(_model_number), cost (_cost),
		description(_description), type(_type), weight(_weight) {}
		Robot_part(): name(), model_number(), cost(), description(), type() {}
	string Robot_part_to_string(){string list ="Name: " + name + " | Model #: " + std::to_string(model_number) + " | Cost: $" + std::to_string(cost) + " | Description: " + description+ " | Weight: " + std::to_string(weight) + " lbs"; return list;}
	virtual string specific_string() = 0;
	string save(){string list = type + "/" + name + "/" + std::to_string(model_number) + "/" + std::to_string(cost) + "/" + description + "/" + std::to_string(weight); return list;}
	virtual string specific_save() = 0;
};
string Robot_part::get_type(){return type;}
string Robot_part::get_name(){return name;}
int Robot_part::get_model_number(){return model_number;}
string Robot_part::get_string_part_num(){string list = std::to_string(model_number); return list;}
double Robot_part::get_cost(){return cost;}
string Robot_part::get_description(){return description;}
double Robot_part::get_weight(){return weight;}
// /////////////////////////////////////
//              H E A D
// /////////////////////////////////////

class Head : public Robot_part {

	private:
		double power;
	public:
		double get_power();
		Head(string _name, int _model_number, double _cost, string _description,string _type, double _weight, double _power) : Robot_part(_name,_model_number,_cost,_description,_type,_weight), power(_power) {};
		Head(): Robot_part(), power() {}
		string specific_string(){string list = " | Power: " + std::to_string(power) + " W"; return list;}
		string specific_save(){string list = "/" + std::to_string(power); return list; }
		friend istringstream& operator>>(istream& iss, Head& head);
};
double Head::get_power(){return power;}
istringstream& operator>>(istream& iss, Head& head)
{
	string name, model_number, cost, description, type, weight, power;
	int counter = 0;
	for(char h; iss.get(h);)
	{
		if(h == '/')
		{
			counter++;
		}
		else if((isalnum(h)||ispunct(h)) && counter == 0)
		{
			type += h;
		}
		else if((isalnum(h)||ispunct(h)) && counter == 1)
		{
			name += h;
		}
		else if((isalnum(h)||ispunct(h)) && counter == 2)
		{
			model_number += h;
		}
		else if((isalnum(h)||ispunct(h)) && counter == 3)
		{
			cost += h;
		}
		else if((isalnum(h)||ispunct(h)) && counter == 4)
		{
			description += h;
		}
		else if((isalnum(h)||ispunct(h)) && counter == 5)
		{
			weight += h;
		}
		else if((isalnum(h)||ispunct(h)) && counter == 6)
		{
			power += h;
		}
	}
	head.type = type;
	head.name = name;
	head.model_number = stoi(model_number);
	head.cost = stod(cost);
	head.description = description;
	head.weight = stod(weight);
	head.power = stod(power);
}
// /////////////////////////////////////
//              T O R S O
// /////////////////////////////////////

class Torso : public Robot_part {

	private:
		int battery_compartments;
		int max_arms;
	public:
		int get_battery_compartments();
		int get_max_arms();
		Torso(string _name, int _model_number, double _cost, string _description, string _type, double _weight, int _battery_compartments, int _max_arms) :
		Robot_part(_name,_model_number,_cost,_description, _type,_weight),
		battery_compartments(_battery_compartments), max_arms(_max_arms) {};
		Torso(): Robot_part(), battery_compartments(), max_arms() {}
		string specific_string(){string list = " | # of Batteries: " + std::to_string(battery_compartments) + " | # of Max Arms: " + std::to_string(max_arms); return list;}
		string specific_save(){string list = "/" + std::to_string(battery_compartments) + "/" + std::to_string(max_arms); return list; }
		friend istringstream& operator>>(istream& iss, Torso& torso);
};
int Torso::get_battery_compartments(){return battery_compartments;}
int Torso::get_max_arms(){return max_arms;}
istringstream& operator>>(istream& iss, Torso& torso)
{
	string name, model_number, cost, description, type, weight, battery_compartments, max_arms;
	int counter = 0;
	for(char t; iss.get(t);)
	{
		if(t == '/')
		{
			counter++;
		}
		else if((isalnum(t)||ispunct(t)) && counter == 0)
		{
			type += t;
		}
		else if((isalnum(t)||ispunct(t)) && counter == 1)
		{
			name += t;
		}
		else if((isalnum(t)||ispunct(t)) && counter == 2)
		{
			model_number += t;
		}
		else if((isalnum(t)||ispunct(t)) && counter == 3)
		{
			cost += t;
		}
		else if((isalnum(t)||ispunct(t)) && counter == 4)
		{
			description += t;
		}
		else if((isalnum(t)||ispunct(t)) && counter == 5)
		{
			weight += t;
		}
		else if((isalnum(t)||ispunct(t)) && counter == 6)
		{
			battery_compartments += t;
		}
		else if((isalnum(t)||ispunct(t)) && counter == 7)
		{
			max_arms += t;
		}
	}
	torso.type = type;
	torso.name = name;
	torso.model_number = stoi(model_number);
	torso.cost = stod(cost);
	torso.description = description;
	torso.weight = stod(weight);
	torso.battery_compartments = stoi(battery_compartments);
	torso.max_arms = stoi(max_arms);
}
// /////////////////////////////////////
//               A R M
// /////////////////////////////////////

class Arm : public Robot_part {

	private:
		double max_power;
	public:
		double get_max_power();
		Arm(string _name, int _model_number, double _cost, string _description,string _type, double _weight, double _max_power):
		Robot_part(_name, _model_number, _cost, _description,_type,_weight), max_power(_max_power) { }
		Arm(): Robot_part(), max_power() {}
		string specific_string(){string list = " | Max Power: " + std::to_string(max_power) + " W"; return list;}
		string specific_save(){string list = "/" + std::to_string(max_power); return list; }
		friend istringstream& operator>>(istream& iss, Arm& arm);
};
double Arm::get_max_power(){return max_power;}
istringstream& operator>>(istream& iss, Arm& arm)
{
	string name, model_number, cost, description, type, weight, max_power;
	int counter = 0;
	for(char a; iss.get(a);)
	{
		if(a == '/')
		{
			counter++;
		}
		else if((isalnum(a)||ispunct(a)) && counter == 0)
		{
			type += a;
		}
		else if((isalnum(a)||ispunct(a)) && counter == 1)
		{
			name += a;
		}
		else if((isalnum(a)||ispunct(a)) && counter == 2)
		{
			model_number += a;
		}
		else if((isalnum(a)||ispunct(a)) && counter == 3)
		{
			cost += a;
		}
		else if((isalnum(a)||ispunct(a)) && counter == 4)
		{
			description += a;
		}
		else if((isalnum(a)||ispunct(a)) && counter == 5)
		{
			weight += a;
		}
		else if((isalnum(a)||ispunct(a)) && counter == 6)
		{
			max_power += a;
		}
	}
	arm.type = type;
	arm.name = name;
	arm.model_number = stoi(model_number);
	arm.cost = stod(cost);
	arm.description = description;
	arm.weight = stod(weight);
	arm.max_power = stod(max_power);
}
// /////////////////////////////////////
//          L O C O M O T O R
// /////////////////////////////////////

class Locomotor : public Robot_part {

	private:
		double max_power;
		double max_speed;
	public:
		double get_max_speed();
		double get_max_power();
		Locomotor(string _name, int _model_number, double _cost, string _description,string _type, double _weight, double _max_power, double _max_speed): Robot_part(_name, _model_number, _cost, _description,_type,_weight),
		max_power(_max_power), max_speed(_max_speed) { }
		Locomotor(): Robot_part(), max_power(), max_speed() {}
		string specific_string(){string list = " | Max Power: " + std::to_string(max_power) + " W | Max Speed: " + std::to_string(max_speed) + " mph"; return list;}
		string specific_save(){string list = "/" + std::to_string(max_power) + "/" + std::to_string(max_speed); return list; }
		friend istringstream& operator>>(istream& iss, Locomotor& locomotor);
};
double Locomotor::get_max_speed(){return max_speed;}
double Locomotor::get_max_power(){return max_power;}
istringstream& operator>>(istream& iss, Locomotor& locomotor)
{
	string name, model_number, cost, description, type, weight, max_power, max_speed;
	int counter = 0;
	for(char l; iss.get(l);)
	{
		if(l == '/')
		{
			counter++;
		}
		else if((isalnum(l)||ispunct(l)) && counter == 0)
		{
			type += l;
		}
		else if((isalnum(l)||ispunct(l)) && counter == 1)
		{
			name += l;
		}
		else if((isalnum(l)||ispunct(l)) && counter == 2)
		{
			model_number += l;
		}
		else if((isalnum(l)||ispunct(l)) && counter == 3)
		{
			cost += l;
		}
		else if((isalnum(l)||ispunct(l)) && counter == 4)
		{
			description += l;
		}
		else if((isalnum(l)||ispunct(l)) && counter == 5)
		{
			weight += l;
		}
		else if((isalnum(l)||ispunct(l)) && counter == 6)
		{
			max_power += l;
		}
		else if((isalnum(l)||ispunct(l)) && counter == 7)
		{
			max_speed += l;
		}
	}
	locomotor.type = type;
	locomotor.name = name;
	locomotor.model_number = stoi(model_number);
	locomotor.cost = stod(cost);
	locomotor.description = description;
	locomotor.weight = stod(weight);
	locomotor.max_power = stod(max_power);
}
// /////////////////////////////////////
//            B A T T E R Y
// /////////////////////////////////////

class Battery : public Robot_part {

	private:
		double power_available;
		double max_energy;
	public:
		double get_power_available();
		double get_max_energy();
		Battery(string _name, int _model_number, double _cost, string _description, string _type, double _weight, double _power_available, double _max_energy) :
		Robot_part(_name,_model_number,_cost,_description,_type,_weight),
		power_available(_power_available), max_energy(_max_energy) {};
		Battery(): Robot_part(), power_available(), max_energy() {}
		string specific_string(){string list = " | Power Available: " + std::to_string(power_available) + " W  |  Max Energy: " + std::to_string(max_energy) + " kWh"; return list;}
		string specific_save(){string list = "/" + std::to_string(power_available) + "/" + std::to_string(max_energy); return list; }
		friend istringstream& operator>>(istream& iss, Battery& battery);
};
double Battery::get_power_available(){return power_available;}
double Battery::get_max_energy(){return max_energy;}
istringstream& operator>>(istream& iss, Battery& battery)
{
	string name, model_number, cost, description, type, weight, max_energy, power_available;
	int counter = 0;
	for(char b; iss.get(b);)
	{
		if(b == '/')
		{
			counter++;
		}
		else if((isalnum(b)||ispunct(b)) && counter == 0)
		{
			type += b;
		}
		else if((isalnum(b)||ispunct(b)) && counter == 1)
		{
			name += b;
		}
		else if((isalnum(b)||ispunct(b)) && counter == 2)
		{
			model_number += b;
		}
		else if((isalnum(b)||ispunct(b)) && counter == 3)
		{
			cost += b;
		}
		else if((isalnum(b)||ispunct(b)) && counter == 4)
		{
			description += b;
		}
		else if((isalnum(b)||ispunct(b)) && counter == 5)
		{
			weight += b;
		}
		else if((isalnum(b)||ispunct(b)) && counter == 6)
		{
			max_energy += b;
		}
		else if((isalnum(b)||ispunct(b)) && counter == 7)
		{
			power_available += b;
		}
	}
	battery.type = type;
	battery.name = name;
	battery.model_number = stoi(model_number);
	battery.cost = stod(cost);
	battery.description = description;
	battery.weight = stod(weight);
	battery.max_energy = stod(max_energy);
	battery.power_available = stod(power_available);
}
// /////////////////////////////////////
//         R O B O T M O D E L
// /////////////////////////////////////

class Robot_model {

	private:
		string name;
		int model_number;
		Robot_part* torso;
		Robot_part* head;
		Robot_part* locomotor;
		vector<Robot_part*> arms;
		vector<Robot_part*> batteries;
	public:
		Robot_model(string _name, int _model_number, Robot_part* t, Robot_part* h, Robot_part* l, vector<Robot_part*> a, vector<Robot_part*> b) : name(_name), model_number(_model_number), torso(t), head(h), locomotor(l), arms(a), batteries(b) {}
		Robot_model(): name(), model_number(), torso(), head(), locomotor(), arms(), batteries() {}
		void load_name(string _name);
		void load_model_number(string _model_number);
		void load_torso(Robot_part* _torso);
		void load_head(Robot_part* _head);
		void load_locomotor(Robot_part* _locomotor);
		void load_arm(Robot_part* _arms);
		void load_battery(Robot_part* _batteries);
		int get_model_number();
		string get_string_model_num();
		double cost()
		{
			double sum = 0;
			for(int i = 0; i < arms.size(); i++)
			{
				sum += arms[i]->get_cost();
			}
			for(int i = 0; i < batteries.size(); i++)
			{
				sum += batteries[i]->get_cost();
			}
			sum +=  head->get_cost() + locomotor->get_cost() + torso->get_cost();

			return sum;
		}
		double max_battery()
		{
			double total, battery_energy, battery_life, armtotal = 0;
			Locomotor* l1 = (Locomotor*) locomotor;
			Head* h1 = (Head*) head;
			total = 0.15*(l1->get_max_power()) + h1-> get_power();
			for(int i = 0; i < arms.size(); i++)
			{
				Arm* a1 = (Arm*) arms[i];
				armtotal += a1 -> get_max_power();
			}
			for(int i = 0; i < batteries.size(); i++)
			{
				Battery* b1 = (Battery*) batteries[i];
		 		battery_energy += b1 -> get_max_energy();
			}
			total += armtotal*0.4;
			battery_energy *= 1000;
			battery_life = battery_energy/total;
			return battery_life;
		}
		double power_limited()
		{
			double total, battery_power = 0;
			Locomotor* l1 = (Locomotor*) locomotor;
			Head* h1 = (Head*) head;
			total = 0.15*(l1->get_max_power()) + h1-> get_power();
			for(int i = 0; i < arms.size(); i++)
			{
				Arm* a1 = (Arm*) arms[i];
				total += a1 -> get_max_power();
			}
			for(int i = 0; i < batteries.size(); i++)
			{
				Battery* b1 = (Battery*) batteries[i];
		 		battery_power += b1 -> get_power_available();
			}
			if(battery_power < total)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		double total_weight()
		{
			double sum = 0;
			for(int i = 0; i < arms.size(); i++)
			{
				sum += arms[i]->get_weight();
			}
			for(int i = 0; i < batteries.size(); i++)
			{
				sum += batteries[i]->get_weight();
			}
			sum +=  head->get_weight() + locomotor->get_weight() + torso->get_weight();

			return sum;
		}
		double max_speed()
		{	Locomotor* l1 = (Locomotor*) locomotor;
			double weight = total_weight();
			double locomotor_weight = locomotor->get_weight();
			double locomotor_speed = l1->get_max_speed();
			double max_speed = locomotor_speed*((locomotor_weight*5)/weight);
			return max_speed;
		}
		string save_string()
		{
			string list = "Robot Model: " + name + "/" + std::to_string(model_number) + "/" + std::to_string(torso->get_model_number())  + "/" + std::to_string(head->get_model_number())  + "/" + std::to_string(locomotor->get_model_number());
			for (int i = 0; i < arms.size(); i++)
			{
				list +=  "/A" + std::to_string(arms[i]->get_model_number());
			}
			for (int i = 0; i < batteries.size(); i++)
			{
				list +=  "/B" + std::to_string(batteries[i]->get_model_number());
			}
			return list;
		}
		string model_to_string()
		{
		string list;
		list += "Name: " + name + " | Model #: " + std::to_string(model_number) + "\n";
		list += "Power Limited: " + std::to_string(power_limited()) + " | Cost: " + std::to_string(cost()) + " | Max Battery Life: " + std::to_string(max_battery()) + " | Max Speed: " + std::to_string(max_speed()) + " | Total Weight: " + std::to_string(total_weight()) + "\n";
		list += "Head: " + head->Robot_part_to_string() + head->specific_string() + "\n";
		list += "Locomotor: " + locomotor->Robot_part_to_string() + locomotor->specific_string() + "\n";
		list += "Torso: " + torso->Robot_part_to_string() + torso->specific_string() + "\n";
		for(int i = 0; i < arms.size(); i++)
		{
			list += "Arm: " + arms[i]->Robot_part_to_string() + arms[i]->specific_string() + "\n";
		}
		for(int i = 0; i < batteries.size(); i++)
		{
			list += "Battery: " + batteries[i]->Robot_part_to_string() + batteries[i]->specific_string() + "\n";
		}
		return list;
		}

};
int Robot_model::get_model_number(){return model_number;}
string Robot_model::get_string_model_num() {string list = std::to_string(model_number); return list;}
void Robot_model::load_name(string _name) {name = _name;}
void Robot_model::load_model_number(string _number) {model_number = stoi(_number);}
void Robot_model::load_torso(Robot_part* _torso) {torso = _torso;}
void Robot_model::load_head(Robot_part* _head) {head = _head;}
void Robot_model::load_locomotor(Robot_part* _locomotor) {locomotor = _locomotor;}
void Robot_model::load_arm(Robot_part* _arms) {arms.push_back(_arms);}
void Robot_model::load_battery(Robot_part* _batteries) {batteries.push_back(_batteries);}
// /////////////////////////////////////
//           C U S T O M E R
// /////////////////////////////////////

class Customer {

	private:
		string name;
		string customer_number;
		string phone_number;
		string email_address;
	public:
		Customer(string _name, string _number, string _phone, string _email) : name(_name), 			customer_number(_number), phone_number(_phone), email_address(_email) {}
		Customer(): name(), customer_number(), phone_number(), email_address() {}
		string get_name(){return name;}
		string get_customer_number(){return customer_number;}
		string get_phone_number(){return phone_number;}
		string get_email_address(){return email_address;}
		string to_string() {string output = name +" "+customer_number + " (" + phone_number + ") " + email_address;  return output;}
		string save_c();
		string get_cus();
		string get_string_cus();
		string get_save_cus();
		friend istringstream& operator>>(istringstream& ist, Customer& c);
		};
		istringstream& operator>>(istringstream& ist, Customer& c)
		{
			string name, phone_number, email_address, customer_number;
			int counter = 0;
			for(char c; ist.get(c);)
			{
				if(c =='|')
				{
					counter++;
				}
				else if((ispunct(c)||isalnum(c)) && counter == 0)
				{
					name += c;
				}
				else if((ispunct(c)||isalnum(c)) && counter == 1)
				{
			    phone_number += c;
				}
				else if((ispunct(c)||isalnum(c)) && counter == 2)
				{
					email_address += c;
				}
				else if((ispunct(c)||isalnum(c)) && counter == 3)
				{
			    customer_number += c;
			  }
			}
			c.name = name;
			c.phone_number = phone_number;
			c.email_address = email_address;
			c.customer_number = customer_number;
		}
		string Customer::save_c()
		{
			string list = "Customer: " + name + "/" + phone_number + "/" + email_address + "/" +customer_number;
			return list;
		}
		string Customer::get_string_cus(){string list = customer_number; return list;}
		string Customer::get_cus()
		{
		  string list;
		  list = "Customer Name: " + name + " Customer Number: " + customer_number + " Customer E-mail Address: " + email_address + " Customer Phone Number: " + phone_number + "\n";
		  return list;
		}
// /////////////////////////////////////
//      S A L E S A S S O C I A T E
// /////////////////////////////////////

class Sales_Associate {

	private:
		string name;
		int employee_number;
	public:
		Sales_Associate(string _name, int _number) : name(_name), employee_number(_number) {}
		Sales_Associate(): name(), employee_number() {}
		string get_name(){return name;}
		int get_employee_number(){return employee_number;}
		string to_string(){return name + " " + std::to_string(employee_number);}
		string save_sa();
		string get_sa();
		string get_string_sa();
		friend istringstream& operator>>(istringstream& ist, Sales_Associate& sa);
		};
		istringstream& operator>>(istringstream& ist, Sales_Associate& sa)
		{
			string name, employee_number;
			int counter = 0;
			for(char s; ist.get(s);)
			{
				if(s =='/')
				{
					counter++;
				}
				else if((ispunct(s)||isalnum(s)) && counter == 0)
				{
					name += s;
				}
				else if((ispunct(s)||isalnum(s)) && counter == 1)
				{
			    employee_number += s;
				}
			}
			sa.name = name;
			sa.employee_number = stoi(employee_number);
		}
		string Sales_Associate::save_sa()
		{
			string list = "Sales_Associate: " + name + "/" + std::to_string(employee_number);
			return list;
		}
		string Sales_Associate::get_sa()
		{
		  string list;
		  list = "Sales Associate Name: " + name + " Sales Associate Number: " + std::to_string(employee_number) + "\n";
		  return list;
		}
		string Sales_Associate::get_string_sa(){string list = std::to_string(employee_number); return list;}

// /////////////////////////////////////
//              O R D E R
// /////////////////////////////////////

class Order {

	private:
		string order_number;
		string date;
		string status;
		Customer customer;
		Sales_Associate sales_associate;
		Robot_model robot_model;
	public:
		Order(string _order_number, string _date, Customer _customer, Sales_Associate _sales_associate, Robot_model _robot_model, string _status): order_number(_order_number), date(_date), customer(_customer), sales_associate(_sales_associate), robot_model(_robot_model), status(_status) {}
		string save_order();
		string get_order();

};
string Order:: save_order()
{
string list = "Order: " + order_number + "/" + date + "/" + sales_associate.get_string_sa() + "/" + customer.get_string_cus() + "/" + robot_model.get_string_model_num()+ "/" + status + "\n";
return list;
}
string Order::get_order()
{
string orderstring;
orderstring = "Order Number: " + order_number + " Date: " + date + "\n";
orderstring += customer.get_cus() + "\n";
orderstring += sales_associate.get_sa() + "\n";
orderstring += robot_model.get_string_model_num()+ "\n";
orderstring += "Status: " + status + "\n";
return orderstring;
}
//Order order;
// /////////////////////////////////////
//              S H O P
// /////////////////////////////////////

class Shop {

	private:
		vector<Sales_Associate> sales_a;
		vector<Customer> customer;
		vector<Robot_part*> parts_list;
	  vector<Robot_model> models_list;
		vector<Order> order;
	public:
	void save()
	{
		ofstream file("Robot_Shop.txt");
		if(file.is_open())
		{
					for(int i = 0; i < parts_list.size(); i++)
				{
						file<< parts_list[i]->save() + parts_list[i]->specific_save() + "\n";
				}
					for(int i = 0; i < customer.size(); i++)
				{
						file<< customer[i].save_c() + "\n";
				}
					for(int i = 0; i < sales_a.size(); i++)
				{
						file<< sales_a[i].save_sa() + "\n";
				}
						file<< "#\n";
					for(int i = 0; i< models_list.size(); i++)
				{
						file<< models_list[i].save_string() + "\n";
				}
    				file<<"#\n";
		}
		else
		{
			cout << "File not open" << endl;
			return;
		}
	}
	void load()
{
	string line;
	ifstream file("Robot_Shop.txt");
	char c = 'z';
	if(file.is_open())
	{
		while(getline(file, line))
		{
			istringstream ist {line};
			c = ist.get();
			if(c == 't')
			{
				ist.putback(c);
				Torso* torso  = new Torso();
				ist >> (*torso);
				parts_list.push_back(torso);
			}
			if(c == 'h')
			{
				ist.putback(c);
				Head* head  = new Head();
				ist >> (*head);
				parts_list.push_back(head);
			}
			if(c == 'l')
			{
				ist.putback(c);
				Locomotor* locomotor  = new Locomotor();
				ist >> (*locomotor);
				parts_list.push_back(locomotor);
			}
			if(c == 'a')
			{
				ist.putback(c);
				Arm* arm  = new Arm();
				ist >> (*arm);
				parts_list.push_back(arm);
			}
			if(c == 'b')
			{
				ist.putback(c);
				Battery* battery  = new Battery();
				ist >> (*battery);
				parts_list.push_back(battery);
			}
			if(c == 'C')
	    {
				Customer customers;
				ist >> (customers);
				customer.push_back(customers);
			}
			if(c == 'S')
			{
				Sales_Associate sales_associate;
				ist >> (sales_associate);
				sales_a.push_back(sales_associate);
			}
			if(c == '#')break;
		}
		while(getline(file, line))
		{
			istringstream ist {line};
		  c = ist.get();
			if(c == 'R')
			{
				Robot_model robot_model;
				string name, model_number, head, locomotor, torso;
				vector<string> arms;
				vector<string> batteries;
				string a, b;
				char r;
				int counter  = 0;
				for(;ist.get(r) && counter <= 4;)
				{
					if(r == '/')
					{
						counter++;
					}
					else if((isalnum(r) || ispunct(r)) && counter == 0)
					{
						 name += r;
					}
					else if((isalnum(r) || ispunct(r)) && counter == 1)
					{
						model_number += r;
					}
					else if((isalnum(r) || ispunct(r)) && counter == 2)
					{
						torso += r;
					}
					else if((isalnum(r) || ispunct(r)) && counter == 3)
					{
						head += r;
					}
					else if((isalnum(r) || ispunct(r)) && counter == 4)
					{
						locomotor += r;
					}
				}
				ist.putback(r);

				for(char r; ist.get(r);)
				{
					if(r == 'A')
					{
						getline(ist, a, '/');
						arms.push_back(a);
					}
					else if(r == 'B')
					{
						getline(ist, b, '/');
						batteries.push_back(b);
					}
				}
				robot_model.load_name(name);
				robot_model.load_model_number(model_number);
				for(int i = 0; i< parts_list.size(); i++)
				{
					if(parts_list[i]->get_string_part_num() == torso)
					{
						robot_model.load_torso(parts_list[i]);
					}
					if(parts_list[i]->get_string_part_num() == head)
					{
						robot_model.load_head(parts_list[i]);
					}
					if(parts_list[i]->get_string_part_num() == locomotor )
					{
						robot_model.load_locomotor(parts_list[i]);
					}
					for(int i = 0; i < arms.size(); i++)
					{
						for(int j = 0; j < parts_list.size(); j++)
						{
							if(parts_list[j]-> get_string_part_num() == arms[i])
							{
								robot_model.load_arm(parts_list[j]);
							}
						}
					}
					for(int i = 0; i< batteries.size(); i++)
					{
						for(int j = 0; j< parts_list.size(); j++)
						{
							if(parts_list[j]->get_string_part_num() == batteries[i])
							{
								robot_model.load_battery(parts_list[j]);
							}
						}
					}
				}
				models_list.push_back(robot_model);
			}
			else if(c == '#')break;
		}
	}
	file.close();
}
	string sales_associate_to_string(int sale_index) {return sales_a[sale_index].to_string();}
	string customer_to_string(int cust_index) {return customer[cust_index].to_string();}
	void create_new_customer()
	{
	string name, phone, email, num;
	name = fl_input("Name? ", "");
	num = fl_input("Customer Number? ", "");
	phone = fl_input("Phone Number? ", "");
	email = fl_input("Email Address? ", "");
	Customer cus(name, num, phone, email);
	customer.push_back(cus);
	}
	void create_new_sales_associate()
	{
	string name;
	string number;
	int num;
	name = fl_input("Name? ", "");
	number = fl_input("Sales Associate Number? ", "");
	num = stoi(number);
	Sales_Associate s_a(name, num);
	sales_a.push_back(s_a);
	}
	int number_of_sales_associates(){return sales_a.size();}
    	int number_of_customers(){return customer.size();}

	void create_new_robot_parts(int choice){
	string part_name, _description,_type, _max_a, _battery_c, _model_n, _c, _w, _p, _max_p, _power_a, _max_e, _max_s;
	int _max_arms, _battery_compartments, _model_number;
	double _cost, _weight, _power, _max_power, _power_available, _max_energy, _max_speed;


	part_name = fl_input("Name?  ", "");
	_model_n = fl_input("Model Number?  ", "");
	_model_number = stoi(_model_n);
	_c = fl_input("Cost?  ", "");
	_cost = stod(_c);
	_description = fl_input("Description?  ", "");
  _w = fl_input("Weight of the Part? ", "");
	_weight = stod(_w);

	if(choice == 1)
	{
		_type = "head";
		_p = fl_input("Power? ", "");
		_power = stod(_p);

	Robot_part* head = new Head(part_name,_model_number,_cost,_description,_type,_weight,_power);
	parts_list.push_back(head);
	}
	if(choice == 2)
	{
		_type = "arm";
		_max_p = fl_input("Max Power? ", "");
		_max_power = stod(_max_p);

	Robot_part* arm = new Arm(part_name,_model_number,_cost,_description,_type,_weight,_max_power);
  parts_list.push_back(arm);
	}
	if(choice == 3)
	{
		_type = "torso";
		_battery_c = fl_input("Battery Compartments? ", "");
		_battery_compartments = stoi(_battery_c);

		_max_a = fl_input("Max Arms? ", "");
		_max_arms = stoi(_max_a);

	Robot_part* torso = new Torso(part_name,_model_number,_cost,_description,_type,_weight,_battery_compartments,_max_arms);
  parts_list.push_back(torso);
	}
	if(choice == 4)
	{
		_type = "battery";
		_power_a = fl_input("Power Available? ", "");
		_power_available = stod(_power_a);

		_max_e = fl_input("Max Energy? ", "");
		_max_energy = stod(_max_e);

	Robot_part* battery = new Battery(part_name,_model_number,_cost,_description,_type,_weight,_power_available,_max_energy);
  parts_list.push_back(battery);
	}
	if(choice == 5)
	{
		_type = "locomotor";
		_max_p = fl_input("Max Power? ", "");
		_max_power = stod(_max_p);

		_max_s = fl_input("Max Speed? ", "");
		_max_speed = stod(_max_s);

	Robot_part* locomotor = new Locomotor(part_name,_model_number,_cost,_description,_type,_weight,_max_power,_max_speed);
  parts_list.push_back(locomotor);
	}

}
void create_new_robot_models()
{
	int modelnum;
	string mname, hname, bname, aname, tname, lname, mnum;
	Robot_part* headd = nullptr;
	Robot_part* torsoo = nullptr;
	Robot_part* locomotorr = nullptr;
	vector<Robot_part*> armm;
	vector<Robot_part*> batteryy;
	mname = fl_input("The name of the robot model? ", "");
	mnum = fl_input("The model number? ", "");
	modelnum = stoi(mnum);
	hname = fl_input("The head part name? ", "");
	for (int i = 0; i < parts_list.size(); i++)
	{
		if (parts_list[i]->get_type() == "head" && parts_list[i]->get_name() == hname)
		{
		headd = parts_list[i];
		}
	}
	lname = fl_input("The locomotor part name? ", "");
	for (int i = 0; i < parts_list.size(); i++)
	{
		if (parts_list[i]->get_type() == "locomotor" && parts_list[i]->get_name() == lname)
		{
		locomotorr = parts_list[i];
		}
	}
	tname = fl_input("The torso part name? ", "");
	for (int i = 0; i < parts_list.size(); i++)
	{
		if (parts_list[i]->get_type() == "torso" && parts_list[i]->get_name() == tname)
		{
		torsoo = parts_list[i];
		}
	}
	Torso* torso = (Torso*) torsoo;
	int armnum = torso->get_max_arms();
	int batnum = torso->get_battery_compartments();
	while (armnum != 0)
	{
		aname = fl_input("The arm part name? ", "");
		for (int i = 0; i < parts_list.size(); i++)
		{
			if (parts_list[i]->get_type() == "arm" && parts_list[i]->get_name() == aname)
			{
			armm.push_back(parts_list[i]);
			}
		}
		armnum--;
	}
	while (batnum != 0)
	{
		bname = fl_input("The battery part name? ", "");
		for (int i = 0; i < parts_list.size(); i++)
		{
			if (parts_list[i]->get_type() == "arm" && parts_list[i]->get_name() == bname)
			{
			batteryy.push_back(parts_list[i]);
			}
		}
		batnum--;
	}
	Robot_model robot_model(mname, modelnum, torsoo, headd, locomotorr, armm, batteryy);
	models_list.push_back(robot_model);
}
int number_of_Robot_parts(){return parts_list.size();}
string Robot_parts_list(int i) {return parts_list[i]->Robot_part_to_string(); }
string Specific_Robot_parts_list(int i) {return parts_list[i]->specific_string(); }
int number_of_Robot_models(){return models_list.size();}
string Robot_models_list(int i){string list; list += models_list[i].model_to_string(); return list;}
void create_new_order();
int number_of_orders(){return order.size();}
string order_to_string(int i){string list;
list+= order[i].get_order();
return list; }
};
Shop shop;

// /////////////////////////////////////
//              V I E W
// /////////////////////////////////////

class View {

	private:
	public:
		string get_menu();
		string get_orders_list();
		string get_robot_parts_list();
		string get_robot_models_list();
		string get_customers_list();
		string get_sales_associates_list();
		string get_help();
};
string View::get_menu(){
string menu = R"(
===================================
	Robbie Robot Shop
===================================

Robots
------------
(1) Add an Order
(2) View all Orders
(3) Add Robot Parts
(4) View all Robot Parts
(5) Add a Robot Model
(6) View all Robot Models

People
-------
(7) Add Customer
(8) View all Customers
(9) Add Sales Associate
(10) View all Associates

Utility
-------
(77) Save
(88) Load
(99) Help
(0) Exit
)";
	return menu;
}
string View::get_orders_list(){
  string list = R"(
-------------------------
     List of Orders
-------------------------
)";
for (int i=0; i < shop.number_of_orders(); ++i) {
		list += std::to_string(i) + ") " + shop.order_to_string(i) + '\n';
	}
	return list;
}
string View::get_robot_parts_list(){
  string list = R"(
-------------------------
   List of Robot Parts
-------------------------
)";
for (int i=0; i<shop.number_of_Robot_parts(); ++i) {
    list += std::to_string(i) + ") " + shop.Robot_parts_list(i) + shop.Specific_Robot_parts_list(i)+'\n';
  }
	return list;
}
string View::get_robot_models_list(){
  string list = R"(
-------------------------
  List of Robot Models
-------------------------
)";
for (int i=0; i<shop.number_of_Robot_models(); ++i) {
    list += std::to_string(i) + ") " + shop.Robot_models_list(i) +'\n';
  }
	return list;
}
string View::get_customers_list(){
  string list = R"(
-------------------------
    List of Customers
-------------------------
)";

	for (int i=0; i<shop.number_of_customers(); ++i) {
    	list += std::to_string(i) + ") " + shop.customer_to_string(i) + '\n';}
	return list;
}
string View::get_sales_associates_list(){
  string list = R"(
-------------------------
List of Sales Associates
-------------------------
)";
	for (int i=0; i<shop.number_of_sales_associates(); ++i) {
    	list += std::to_string(i) + ") " + shop.sales_associate_to_string(i) + '\n';
  	}
	return list;
}
string View::get_help(){
  string list = R"(
-------------------------
     	  Help
-------------------------
Pressing (1) Add an Order
Pressing (2) Brings up all the Orders
Pressing (3) Adds Robot Parts
Pressing (4) Brings up all the Robot Parts
Pressing (5) Adds a Robot Model
Pressing (6) Brings up all the Robot Models
Pressing (7) Add a Customer
Pressing (8) Brings up all the Customers
Pressing (9) Add a Sales Associate
Pressing (10) Brings up all the Sales Associates
Pressing (77) Save the Data
Pressing (88) Load the Data
)";
	return list;
}
View view;
void Shop::create_new_order()
{
	string x;
	while(x != "N")
		{ 	string order_number = fl_input("Enter the order number: ", "");
				string date = fl_input("Enter today's date:", "");
				string name;
       	string list = view.get_sales_associates_list();
				const char* o = list.c_str();
				fl_message("%s", o);
        Sales_Associate sa;
        bool sa_Exists = false;
        int sa_Index;
        while(true)
        {
        	name = fl_input("Enter the name of the Sales Associate who helped you.", "");
        	for(int i = 0; i< sales_a.size(); i++)
        	{
        		if(sales_a[i].get_name() == name)
        		{
        			sa_Exists = true;
        			sa_Index = i;
        		}
        	}
        if(sa_Exists)break;
				}
        sa = sales_a[sa_Index];
				string customer_name;
        Customer cust;
        bool c_Exists = false;
        int c_Index;
        while(true)
        {
          customer_name = fl_input("Enter your name: ", "");
          for(int i = 0; i< customer.size(); i++)
            {
              if(customer[i].get_name() == customer_name)
               {
               c_Index = i;
               c_Exists = true;
               }
            }
          if(c_Exists)break;
        }
        cust = customer[c_Index];
				string print1 = view.get_robot_models_list();
        const char* c = print1.c_str();
				fl_message("%s", c);
        int id;
        Robot_model robot_model;
        bool m_Exists = false;
        int m_Index;
        while(true)
        	{
						string id_num;
            id_num = fl_input("Enter the model number of the Robot Model ", "");
            id = stoi(id_num);
            for(int i = 0; i < models_list.size(); i++)
            {
            	if(models_list[i].get_model_number() == id)
              	{
									m_Exists = true;
               		m_Index = i;
               	}
            }
              if(m_Exists)break;
          }
        robot_model = models_list[m_Index];
				string status = "0";
        Order ord{order_number, date, cust, sa, robot_model, status};
        order.push_back(ord);
        x = fl_input("Would you like to order another model?(Y/N) ", "");
    }
}
// /////////////////////////////////////
//          C O N T R O L L E R
// /////////////////////////////////////

class Controller {
  public:
    Controller (View& view, Shop& s) : view(view), shop(s) { }
    void cli();
		void gui();
    void execute_cmd(int cmd);
  private:
    int get_int(string prompt, int max_int);
    View& view;
    Shop& shop;
};
void Controller::gui(){
	int cmd = -1;
	while(cmd != 0){
	string print = view.get_menu();
	const char* menu = print.c_str();
	string choice = fl_input("%s", "", menu);
	cmd = stoi(choice);
	execute_cmd(cmd);}
}
/*void Controller::cli() {
  int cmd = -1;
  while (cmd != 0) {
    cout << view.get_menu() << endl;
    cout << "Command? ";
    cin >> cmd;
    cin.ignore(); // consume \n
    execute_cmd(cmd);
  }
}

int Controller::get_int(string prompt, int max_int) {
  int result;
  while(true) {
    cout << prompt;
    cin >> result;
    cin.ignore(); // consume \n
    if (0 <= result && result <= max_int) break;
    cout << "Please enter an integer between 0 and " << max_int << endl;
  }
  return result;
}*/

void Controller::execute_cmd(int cmd) {
  if (cmd == 1) {
	shop.create_new_order();
 } else if (cmd == 2) {
	 string print = view.get_orders_list();
	 const char* list = print.c_str();
	 fl_message("%s", list);
 } else if (cmd == 3) {
		int choice;
		string list = R"(
---------------------------------
       List of Robot Parts
---------------------------------
What type would you like to make
(1) Head
(2) Arm
(3) Torso
(4) Battery
(5) Locomotor

)";
	const char* robot_parts = list.c_str();
	string cmd = fl_input("%s", "", robot_parts);
	choice = stoi(cmd);
	shop.create_new_robot_parts(choice);
}
   else if(cmd == 4){
	string print = view.get_robot_parts_list();
	const char* list = print.c_str();
	fl_message("%s", list);
 } else if(cmd == 5){
	 execute_cmd(4);
	shop.create_new_robot_models();
 } else if (cmd == 6) {
	string print = view.get_robot_models_list();
 	const char* list = print.c_str();
 	fl_message("%s", list);
 } else if (cmd == 7) {
	shop.create_new_customer();
 } else if (cmd == 8) {
	string print = view.get_customers_list();
	const char* list = print.c_str();
	fl_message("%s", list);
 } else if (cmd == 9){
	shop.create_new_sales_associate();
 } else if (cmd == 10) {
	string print = view.get_sales_associates_list();
 	const char* list = print.c_str();
 	fl_message("%s", list);
 } else if (cmd == 77) { // Help
  shop.save();
	string print = "Saved!";
 	const char* list = print.c_str();
 	fl_message("%s", list);
 } else if (cmd == 88) { // Help
  shop.load();
	string print = "Loaded!";
 	const char* list = print.c_str();
 	fl_message("%s", list);
 } else if (cmd == 99) { // Help
	string print = view.get_help();
	const char* list = print.c_str();
	fl_message("%s", list);
 } else if (cmd == 0) { // Exit
 } else {
   cerr << "**** Invalid command - type 99 for help" << endl << endl;
 }
}
// /////////////////////////////////////
//              M A I N
// /////////////////////////////////////

int main() {
	Fl_Window beacon (1,1);
	beacon.show();
	Controller controller(view, shop);
	controller.gui();
}
