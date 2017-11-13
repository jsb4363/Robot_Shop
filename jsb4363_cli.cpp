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
		string robot_part_to_string();		
		Robot_part(string _name, int _model_number, double _cost, string _description) : 
		name(_name), model_number(_model_number), cost (_cost),
		description(_description) {}
	friend ostream& operator<<(ostream& os, const Robot_part& robot_part);

};
string Robot_part::robot_part_to_string() {
  string med= "\"" + name + "\"" + " with " ". Directed by " + description + ". " + std::to_string(cost) +  ". ID: " + std::to_string(model_number);
return med; }
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
//           C U S T O M E R
// /////////////////////////////////////
	
class Customer {

	private:
		string name;
		int customer_number;
		string phone_number;
		string email_address;
	public:
		Customer(string _name, int _number, string _phone, string _email) : name(_name), 			customer_number(_number), phone_number(_phone), email_address(_email) {} 
		string get_name(){return name;}
		int get_customer_number(){return customer_number;}
		string get_phone_number(){return phone_number;}
		string get_email_address(){return email_address;}
		string to_string() {string output = name +" "+std::to_string(customer_number) + " (" + phone_number + ") " + email_address;  return output;}

};
// /////////////////////////////////////
//      S A L E S A S S O C I A T E     
// /////////////////////////////////////
	
class Sales_Associate {

	private:
		string name;
		int employee_number;
	public:
		Sales_Associate(string _name, int _number) : name(_name), employee_number(_number) {}
		string get_name(){return name;}
		int get_employee_number(){return employee_number;}
		string to_string(){return name + " " + std::to_string(employee_number);}

};
	
// /////////////////////////////////////
//              O R D E R
// /////////////////////////////////////

class Order {

	private:
		int order_number = 0;
		string date = "";
		Customer customer;
		Sales_Associate sales_associate;
		Robot_model robot_model;
		int status;
	public:
		double robot_cost();
		double extended_price();

}; 
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
	public:
	string sales_associate_to_string(int sale_index) {return sales_a[sale_index].to_string();}
	string customer_to_string(int cust_index) {return customer[cust_index].to_string();}
	void create_new_customer() 
	{
	string name, phone, email;
	int number;
	cout << "Name? \n";
	getline(cin, name);
	cout << "Customer number? \n";
	cin >> number;
	cin.ignore();
	cout << "Phone Number? \n";
	getline(cin, phone);
	cout << "Email Address? \n";
	getline(cin, email);
	Customer cus(name, number, phone, email);
	customer.push_back(cus);
	}
	void create_new_sales_associate() 
	{
	string name;
	int number;
	cout << "Name? \n";
	getline(cin, name);
	cout << "Employee Number? \n";
	cin >> number;
	Sales_Associate s_a(name, number);
	sales_a.push_back(s_a);
	}
	int number_of_sales_associates(){return sales_a.size();}
    	int number_of_customers(){return customer.size();}
	void create_new_robot_parts(int choice){
	string _name, _description;	
	int _max_arms, _battery_compartments, _model_number;
	double _cost, _power, _max_power, _power_available, _max_energy, _max_speed;
	cout << endl;

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
		

	if(choice == 1)
	{
	cout << "power? \n";
    	cin >> _power;
    	cin.ignore();    
	
	//Robot_part* head = new Head(_name,_model_number,_cost,_description,_power);
	//parts_list.push_back(head);	
	}
	if(choice == 2)
	{
	cout << "Max Power? \n";
    	cin >> _max_power;
    	cin.ignore();    
	
	//Robot_part* arm = new Arm(_name,_model_number,_cost,_description,_max_power);
	}
	if(choice == 3)
	{
	cout << "Battery Compartments? \n";
    	cin >> _battery_compartments;
    	cin.ignore();    

	cout << "Max Arms? \n";
    	cin >> _max_arms;
    	cin.ignore();    

	//Robot_part* torso = new Torso(_name,_model_number,_cost,_description,_battery_compartments,_max_arms);
	}	
	if(choice == 4)
	{
	cout << "Battery Compartments? \n";
    	cin >> _power_available;
    	cin.ignore();    

	cout << "Max Arms? \n";
    	cin >> _max_energy;
    	cin.ignore();    

	//Robot_part* battery = new Battery(_name,_model_number,_cost,_description,_power_available,_max_energy);	
	}
	if(choice == 5)
	{
	cout << "Max Power? \n";
    	cin >> _max_power;
    	cin.ignore();    

	cout << "Max Speed? \n";
    	cin >> _max_speed;
    	cin.ignore();

	//Robot_part* locomotor = new Locomotor(_name,_model_number,_cost,_description,_max_power,_max_speed);
	}

}
void create_new_robot_models(){}
int number_of_Robot_parts(){return parts_list.size();}
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
	return list;
} 
string View::get_robot_parts_list(){
  string list = R"(
-------------------------
   List of Robot Parts
-------------------------
)";
/*for (int i=0; i<shop.number_of_Robot_parts(); ++i) {
    list += std::to_string(i) + ") " + robot_part.robot_part_to_string(i) + '\n';
  }*/
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
	
 } else if (cmd == 2) { 
	cout << view.get_orders_list() << endl;
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
	cout << list;
	cin >> choice;
	shop.create_new_robot_parts(choice);	
}
   else if(cmd == 4){
	cout << view.get_robot_parts_list();
 } else if(cmd == 5){
	cout << view.get_robot_parts_list();
 } else if (cmd == 6) {
	cout << view.get_robot_models_list();
 } else if (cmd == 7) {
	shop.create_new_customer();
 } else if (cmd == 8) {
	cout << view.get_customers_list();
 } else if (cmd == 9){
	shop.create_new_sales_associate();
 } else if (cmd == 10) {
	cout << view.get_sales_associates_list();
 } else if (cmd == 99) { // Help
    cout << view.get_help();
 } else if (cmd == 0) { // Exit
 } else {
   cerr << "**** Invalid command - type 99 for help" << endl << endl;
 }
}
// /////////////////////////////////////
//              M A I N
// /////////////////////////////////////

int main() {
	View view;
	Controller controller(view, shop);
	controller.cli();
}
