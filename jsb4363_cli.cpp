#include <iostream>
#include <string>
#include <vector>

using namespace std;
// /////////////////////////////////////
//           R O B O T P A R T 
// /////////////////////////////////////

class Robot_part {
	
	protected:
		string name;
		int model_number;
		double cost;
		string description;
		string image_filename;
	public:
		string get_name();
		int get_model_number();
		double get_cost();
		string get_description();		
		Robot_part(string _name, int _model_number, double _cost, string _description) : 
		name(_name), model_number(_model_number), cost (_cost),
		description(_description) {}
	friend ostream& operator<<(ostream& os, const Robot_part& robot_part);

};
string Robot_part::get_name(){return name;}
int Robot_part::get_model_number(){return model_number;}
double Robot_part::get_cost(){return cost;}
string Robot_part::get_description(){return description;}

// /////////////////////////////////////
//              H E A D
// /////////////////////////////////////

class Head : public Robot_part {
	
	private:
		double power;
	public:
		double get_power();
		Head(string _name, int _model_number, double _cost, string _description, double _power) : 			Robot_part(_name,_model_number,_cost,_description), power(_power) {};
};
double Head::get_power(){return power;}

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
		Torso(string _name, int _model_number, double _cost, string _description, 			int _battery_compartments, int _max_arms) : 
		Robot_part(_name,_model_number,_cost,_description),
		battery_compartments(_battery_compartments), max_arms(_max_arms) {};		
};
int Torso::get_battery_compartments(){return battery_compartments;}
int Torso::get_max_arms(){return max_arms;}

// /////////////////////////////////////
//               A R M
// /////////////////////////////////////

class Arm : public Robot_part {
	
	private:
		double max_power;
	public:
		double get_max_power();
		Arm(string _name, int _model_number, double _cost, string _description, double _max_power): 
		Robot_part(_name, _model_number, _cost, _description), max_power(_max_power) { }
};
double Arm::get_max_power(){return max_power;}

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
		Locomotor(string _name, int _model_number, double _cost, string _description, double 			_max_power, double _max_speed): Robot_part(_name, _model_number, _cost, _description), 
		max_power(_max_power), max_speed(_max_speed) { }
};
double Locomotor::get_max_speed(){return max_speed;}
double Locomotor::get_max_power(){return max_power;}

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
		Battery(string _name, int _model_number, double _cost, string _description, 			double _power_available, double _max_energy) : 
		Robot_part(_name,_model_number,_cost,_description),
		power_available(_power_available), max_energy(_max_energy) {};
	
};
double Battery::get_power_available(){return power_available;}
double Battery::get_max_energy(){return max_energy;}

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
		double cost();
		double max_speed();
		double max_battery();

};

// /////////////////////////////////////
//              S H O P
// /////////////////////////////////////

class Shop {

	private:
		vector<Robot_part*> parts_list;
		vector<Robot_model> models_list;
	public:

	void create_new_robot_parts(int choice){
	string _name, _description;	
	int _max_arms, _battery_compartments, _model_number;
	double _cost, _power, _max_power, _power_available, _max_energy, _max_speed;

	cout << endl;	

	if(choice == 1)
	{
	cout << "Name? \n";
    	getline(cin, _name);
	cin.ignore(); // consume \n
		
	cout << "Model Number? \n";
    	cin >> _model_number;
    	cin.ignore();

	cout << "Cost? \n";
    	cin >> _cost;
    	cin.ignore();

   	cout << "Description? \n";
    	getline(cin, _description);
	cin.ignore(); // consume \n
	
	cout << "power? \n";
    	cin >> _power;
    	cin.ignore();    
	
	Robot_part* head = new Head(_name,_model_number,_cost,_description,_power);
	parts_list.push_back(head);	
	}
	if(choice == 2)
	{
	cout << "Name? \n";
    	getline(cin, _name);
	cin.ignore(); // consume \n
		
	cout << "Model Number? \n";
    	cin >> _model_number;
    	cin.ignore();

	cout << "Cost? \n";
    	cin >> _cost;
    	cin.ignore();

   	cout << "Description? \n";
    	getline(cin, _description);
	cin.ignore(); // consume \n
	
	cout << "Max Power? \n";
    	cin >> _max_power;
    	cin.ignore();    
	
	Robot_part* arm = new Arm(_name,_model_number,_cost,_description,_max_power);
	}
	if(choice == 3)
	{
	cout << "Name? \n";
    	getline(cin, _name);
	cin.ignore(); // consume \n
		
	cout << "Model Number? \n";
    	cin >> _model_number;
    	cin.ignore();

	cout << "Cost? \n";
    	cin >> _cost;
    	cin.ignore();

   	cout << "Description? \n";
    	getline(cin, _description);
	cin.ignore(); // consume \n
	
	cout << "Battery Compartments? \n";
    	cin >> _battery_compartments;
    	cin.ignore();    

	cout << "Max Arms? \n";
    	cin >> _max_arms;
    	cin.ignore();    

	Robot_part* torso = new Torso(_name,_model_number,_cost,_description,_battery_compartments,_max_arms);
	}	
	if(choice == 4)
	{
	cout << "Name? \n";
    	getline(cin, _name);
	cin.ignore(); // consume \n
		
	cout << "Model Number? \n";
    	cin >> _model_number;
    	cin.ignore();

	cout << "Cost? \n";
    	cin >> _cost;
    	cin.ignore();

   	cout << "Description? \n";
    	getline(cin, _description);
	cin.ignore(); // consume \n
	
	cout << "Battery Compartments? \n";
    	cin >> _power_available;
    	cin.ignore();    

	cout << "Max Arms? \n";
    	cin >> _max_energy;
    	cin.ignore();    

	Robot_part* battery = new Battery(_name,_model_number,_cost,_description,_power_available,_max_energy);	
	}
	if(choice == 5)
	{
	cout << "Name? \n";
    	getline(cin, _name);
	cin.ignore(); // consume \n
		
	cout << "Model Number? \n";
    	cin >> _model_number;
    	cin.ignore();

	cout << "Cost? \n";
    	cin >> _cost;
    	cin.ignore();

   	cout << "Description? \n";
    	getline(cin, _description);
	cin.ignore(); // consume \n

	cout << "Max Power? \n";
    	cin >> _max_power;
    	cin.ignore();    

	cout << "Max Speed? \n";
    	cin >> _max_speed;
    	cin.ignore();

	Robot_part* locomotor = new Locomotor(_name,_model_number,_cost,_description,_max_power,_max_speed);
	}
}
void create_new_robot_models(){

}
};
Shop shop;

// /////////////////////////////////////
//              V I E W
// /////////////////////////////////////

class View {
	
	private:
		Shop& shop;
	public: 
		View(Shop s) : shop(s)  {}
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
(1) View all orders
(2) Add Robot Parts
(3) View all robot parts
(4) Add a Robot Model
(5) View all robot models

People
-------
(6) View all customers
(7) View all associates

Utility
-------
(9) Help
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
	return list;
} 
string View::get_robot_parts_list(){
  string list = R"(
-------------------------
   List of Robot Parts
-------------------------
)";
	return list;
} 
string View::get_robot_models_list(){
  string list = R"(
-------------------------
  List of Robot Models
-------------------------
)";
	return list;
} 
string View::get_customers_list(){
  string list = R"(
-------------------------
    List of Customers
-------------------------
)";
	return list;
} 
string View::get_sales_associates_list(){
  string list = R"(
-------------------------
List of Sales Associates
-------------------------
)";
	return list;
} 
string View::get_help(){
  string list = R"(
-------------------------
     	  Help
-------------------------
Pressing (1) Brings up all the Orders
Pressing (2) Adds Robot Parts
Pressing (3) Brings up all the Robot Parts
Pressing (4) Adds a Robot Model
Pressing (5) Brings up all the Robot Models
Pressing (6) Brings up all the Customers
Pressing (7) Brings up all the Sales Associates
)";
	return list;
} 

// /////////////////////////////////////
//          C O N T R O L L E R
// /////////////////////////////////////

class Controller {
  public:
    Controller (View& view, Shop& s) : view(view), shop(s) { }
    void cli();
    void execute_cmd(int cmd);
  private:
    int get_int(string prompt, int max_int);
    View& view;
    Shop& shop;
};

void Controller::cli() {
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
}

void Controller::execute_cmd(int cmd) {
  if (cmd == 1) { 
	cout << view.get_orders_list() << endl;
 } else if (cmd == 2) {	
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
	cout << list;
	cin >> choice;
	shop.create_new_robot_parts(choice);	
}
   else if(cmd == 3){
	cout << view.get_robot_parts_list();
 } else if(cmd == 4){
	cout << view.get_robot_parts_list();
 } else if (cmd == 5) {
	cout << view.get_robot_models_list();
 } else if (cmd == 6) {
	cout << view.get_customers_list();
 } else if (cmd == 7) {
	cout << view.get_sales_associates_list();
 } else if (cmd == 8) { // Help
    cout << view.get_help();
 } else if (cmd == 0) { // Exit
 } else {
   cerr << "**** Invalid command - type 9 for help" << endl << endl;
 }
}
// /////////////////////////////////////
//              M A I N
// /////////////////////////////////////

int main() {
	View view(shop);
	Controller controller(view, shop);
	controller.cli();
}
