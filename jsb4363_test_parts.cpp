#include "jsb4363_robot_part.h"

int main() {
	Head test1("Head part", 12345, 10.00, "testing for Head", 100.00);
	cout << "Part name: " << test1.get_name() << endl;
	cout << "Model #: " << test1.get_model_number() << endl;
	cout << "Cost: $" << test1.get_cost() << endl;
	cout << "Description: " << test1.get_description() << endl;
	cout << "Power (W):  " << test1.get_power() << endl << endl;
	
	Torso test2("Torso part", 12345, 25.00, "testing for Torso", 3, 2);
	cout << "Part name: " << test2.get_name() << endl;
	cout << "Model #: " << test2.get_model_number() << endl;
	cout << "Cost: $" << test2.get_cost() << endl;
	cout << "Description: " << test2.get_description() << endl;
	cout << "# of Battery Compartments:  " << test2.get_battery_compartments() << endl;
	cout << "# of Max Arms: " << test2.get_max_arms() << endl << endl;
	
	Arm test3("Arm part", 12345, 15.00, "testing for Arm", 200.00);
	cout << "Part name: " << test3.get_name() << endl;
	cout << "Model #: " << test3.get_model_number() << endl;
	cout << "Cost: $" << test3.get_cost() << endl;
	cout << "Description: " << test3.get_description() << endl;
	cout << "Power (W):  " << test3.get_max_power() << endl << endl;
	
	Locomotor test4("Locomotor part", 12345, 40.00, "testing for Locomotor", 500.00, 20.00);
	cout << "Part name: " << test4.get_name() << endl;
	cout << "Model #: " << test4.get_model_number() << endl;
	cout << "Cost: $" << test4.get_cost() << endl;
	cout << "Description: " << test4.get_description() << endl;
	cout << "Power (W):  " << test4.get_max_power() << endl;
	cout << "Max Speed (mph): " << test4.get_max_speed() << endl << endl;

	Battery test5("Head part", 12345, 20.00, "testing for Battery", 10.00, 100.00);
	cout << "Part name: " << test5.get_name() << endl;
	cout << "Model #: " << test5.get_model_number() << endl;
	cout << "Cost: $" << test5.get_cost() << endl;
	cout << "Description: " << test5.get_description() << endl;
	cout << "Power Available (kW):  " << test5.get_power_available() << endl;
	cout << "Max Energy: " << test5.get_max_energy() << endl << endl;
}
