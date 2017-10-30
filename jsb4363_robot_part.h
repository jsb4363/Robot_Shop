#ifndef __JSB4363_ROBOT_PART_H
#define __JSB4363_ROBOT_PART_H
#include <iostream>
#include <string>

using namespace std;

class Robot_part {
	
	protected:
		string name;
		int model_number;
		double cost;
		string description;
		string image_filename;
	public:
		string get_name(){return name;}
		int get_model_number(){return model_number;}
		double get_cost(){return cost;}
		string get_description(){return description;}		
		Robot_part(string _name, int _model_number, double _cost, string _description) : 
		name(_name), model_number(_model_number), cost (_cost),
		description(_description) {}
	friend ostream& operator<<(ostream& os, const Robot_part& robot_part);

};
class Head : public Robot_part {
	
	private:
		double power;
	public:
		double get_power(){return power;}
		Head(string _name, int _model_number, double _cost, string _description, double _power) : 			Robot_part(_name,_model_number,_cost,_description), power(_power) {};
};
class Torso : public Robot_part {
	
	private:
		int battery_compartments;
		int max_arms;
	public:
		int get_battery_compartments(){return battery_compartments;}
		int get_max_arms(){return max_arms;}
		Torso(string _name, int _model_number, double _cost, string _description, 			int _battery_compartments, int _max_arms) : 
		Robot_part(_name,_model_number,_cost,_description),
		battery_compartments(_battery_compartments), max_arms(_max_arms) {};		
};
class Arm : public Robot_part {
	
	private:
		double max_power;
	public:
		double get_max_power(){return max_power;}
		Arm(string _name, int _model_number, double _cost, string _description, double _max_power): 
		Robot_part(_name, _model_number, _cost, _description), max_power(_max_power) { }
};
class Locomotor : public Robot_part {
	
	private:
		double max_power;
		double max_speed;
	public:
		double get_max_speed(){return max_speed;}
		double get_max_power(){return max_power;}
		Locomotor(string _name, int _model_number, double _cost, string _description, double 			_max_power, double _max_speed): Robot_part(_name, _model_number, _cost, _description), 
		max_power(_max_power), max_speed(_max_speed) { }
};
class Battery : public Robot_part {
	
	private:
		double power_available;
		double max_energy;
	public:
		double get_power_available(){return power_available;}
		double get_max_energy(){return max_energy;}
		Battery(string _name, int _model_number, double _cost, string _description, 			double _power_available, double _max_energy) : 
		Robot_part(_name,_model_number,_cost,_description),
		power_available(_power_available), max_energy(_max_energy) {};
	
};
#endif
