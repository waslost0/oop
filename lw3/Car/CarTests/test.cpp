#include "pch.h"
#include "../Car/Car.cpp"
#include "../Car/CarCommunication.cpp"
#include "../Car/Const.h"


TEST(Car, CarConstructor) {
	CCar car;
	EXPECT_EQ(car.GetTurnEngine(), false);
	EXPECT_EQ(car.GetDirection(), "STAY");
	EXPECT_EQ(car.GetGear(), "NEUTRAL");
	EXPECT_EQ(car.GetSpeed(), 0);
}

TEST(Car, TruenOnEngine) {
	CCar car;
	car.TurnOnEngine();
	EXPECT_EQ(car.GetTurnEngine(), true);

	EXPECT_EQ(car.GetDirection(), "STAY");
	EXPECT_EQ(car.GetGear(), "NEUTRAL");
	EXPECT_EQ(car.GetSpeed(), 0);

	EXPECT_EQ(car.SetGear(1), true);
	EXPECT_EQ(car.SetGear(1), true);
}

TEST(Car, TurnOffEngine) {
	CCar car;
	EXPECT_EQ(car.TurnOffEngine(), false);

	EXPECT_EQ(car.GetTurnEngine(), false);
	EXPECT_EQ(car.GetDirection(), "STAY");
	EXPECT_EQ(car.GetGear(), "NEUTRAL");
	EXPECT_EQ(car.GetSpeed(), 0);

	car.TurnOnEngine();
	EXPECT_EQ(car.GetTurnEngine(), true);

	EXPECT_EQ(car.SetGear(1), true);
	EXPECT_EQ(car.TurnOffEngine(), false);
	EXPECT_EQ(car.GetGear(), "FIRST");

	EXPECT_EQ(car.SetSpeed(15), true);
	EXPECT_EQ(car.TurnOffEngine(), false);
	EXPECT_EQ(car.GetSpeed(), 15);

	EXPECT_EQ(car.SetGear(0), true);
	EXPECT_EQ(car.TurnOffEngine(), false);
	EXPECT_EQ(car.GetSpeed(), 15);
	EXPECT_EQ(car.GetGear(), "NEUTRAL");

	EXPECT_EQ(car.SetSpeed(0), true);
	EXPECT_EQ(car.TurnOffEngine(), true);
	EXPECT_EQ(car.GetSpeed(), 0);
	EXPECT_EQ(car.GetGear(), "NEUTRAL");

	EXPECT_EQ(car.GetTurnEngine(), false);
}

TEST(Car, SetGearEngineOff) {
	CCar car;

	EXPECT_EQ(car.SetGear(0), true);
	EXPECT_EQ(car.SetGear(1), false);

	EXPECT_EQ(car.GetTurnEngine(), false);
	EXPECT_EQ(car.GetDirection(), "STAY");
	EXPECT_EQ(car.GetGear(), "NEUTRAL");
	EXPECT_EQ(car.GetSpeed(), 0);
}

TEST(Car, SetSpeedEngineOff) {
	CCar car;

	EXPECT_EQ(car.SetSpeed(0), true);
	EXPECT_EQ(car.SetSpeed(1), false);

	EXPECT_EQ(car.GetTurnEngine(), false);
	EXPECT_EQ(car.GetDirection(), "STAY");
	EXPECT_EQ(car.GetGear(), "NEUTRAL");
	EXPECT_EQ(car.GetSpeed(), 0);
}

TEST(Car, SetGear_SetSpeed_ReverseToNeutralToFirst) {
	CCar car;
	car.TurnOnEngine();
	EXPECT_EQ(car.GetTurnEngine(), true);

	EXPECT_EQ(car.SetGear(-1), true);
	EXPECT_EQ(car.SetSpeed(10), true);
	EXPECT_EQ(car.SetGear(0), true);

	EXPECT_EQ(car.SetGear(1), false);
	EXPECT_EQ(car.SetSpeed(0), true);

	EXPECT_EQ(car.GetDirection(), "STAY");
	EXPECT_EQ(car.SetGear(1), true);
}


TEST(Car, SetGear_SetSpeed_Reverse) {
	CCar car;
	car.TurnOnEngine();
	EXPECT_EQ(car.GetTurnEngine(), true);

	EXPECT_EQ(car.GetSpeed(), 0);
	EXPECT_EQ(car.SetGear(-1), true);

	EXPECT_EQ(car.SetSpeed(20), true);
	EXPECT_EQ(car.SetSpeed(21), false);

	EXPECT_EQ(car.GetDirection(), "BACK");
	EXPECT_EQ(car.GetGear(), "REVERSE");
	EXPECT_EQ(car.GetSpeed(), 20);

	EXPECT_EQ(car.SetGear(-2), false);

	EXPECT_EQ(car.SetGear(1), false);
	EXPECT_EQ(car.SetSpeed(0), true);
	EXPECT_EQ(car.SetGear(1), true);
}

TEST(Car, Set_gear_SetSpeed_Neutral) {
	CCar car;
	car.TurnOnEngine();
	EXPECT_EQ(car.GetTurnEngine(), true);

	EXPECT_EQ(car.SetSpeed(15), false);
	EXPECT_EQ(car.SetSpeed(0), true);
}

TEST(Car, SetGear_SetSpeed_First) {
	CCar car;
	car.TurnOnEngine();
	EXPECT_EQ(car.GetTurnEngine(), true);

	EXPECT_EQ(car.SetGear(1), true);
	EXPECT_EQ(car.SetSpeed(10), true);

	EXPECT_EQ(car.SetSpeed(30), true);
	EXPECT_EQ(car.SetSpeed(31), false);

	EXPECT_EQ(car.GetDirection(), "FORWARD");
	EXPECT_EQ(car.GetGear(), "FIRST");
	EXPECT_EQ(car.GetSpeed(), 30);
}


TEST(Car, SetGear_SetSpeed_Second) {
	CCar car;
	car.TurnOnEngine();
	EXPECT_EQ(car.GetTurnEngine(), true);

	EXPECT_EQ(car.SetGear(1), true);
	EXPECT_EQ(car.SetSpeed(19), true);

	EXPECT_EQ(car.GetDirection(), "FORWARD");
	EXPECT_EQ(car.GetGear(), "FIRST");
	EXPECT_EQ(car.GetSpeed(), 19);

	EXPECT_EQ(car.SetGear(2), false);
	EXPECT_EQ(car.SetSpeed(20), true);
	EXPECT_EQ(car.SetGear(2), true);

	EXPECT_EQ(car.GetDirection(), "FORWARD");
	EXPECT_EQ(car.GetGear(), "SECOND");
	EXPECT_EQ(car.GetSpeed(), 20);

	EXPECT_EQ(car.SetSpeed(50), true);
	EXPECT_EQ(car.SetSpeed(51), false);
	EXPECT_EQ(car.GetSpeed(), 50);
}


TEST(Car, SetGear_SetSpeed_Third) {
	CCar car;
	car.TurnOnEngine();
	EXPECT_EQ(car.GetTurnEngine(), true);

	EXPECT_EQ(car.SetGear(1), true);
	EXPECT_EQ(car.SetSpeed(29), true);

	EXPECT_EQ(car.GetDirection(), "FORWARD");
	EXPECT_EQ(car.GetGear(), "FIRST");
	EXPECT_EQ(car.GetSpeed(), 29);

	EXPECT_EQ(car.SetGear(3), false);
	EXPECT_EQ(car.SetSpeed(30), true);
	EXPECT_EQ(car.SetGear(3), true);

	EXPECT_EQ(car.GetDirection(), "FORWARD");
	EXPECT_EQ(car.GetGear(), "THIRD");
	EXPECT_EQ(car.GetSpeed(), 30);

	EXPECT_EQ(car.SetSpeed(60), true);
	EXPECT_EQ(car.SetSpeed(61), false);
	EXPECT_EQ(car.GetSpeed(), 60);
}


TEST(Car, SetGear_SetSpeed_Fourth) {
	CCar car;
	car.TurnOnEngine();
	EXPECT_EQ(car.GetTurnEngine(), true);

	EXPECT_EQ(car.SetGear(1), true);
	EXPECT_EQ(car.SetSpeed(30), true);
	EXPECT_EQ(car.SetGear(2), true);
	EXPECT_EQ(car.SetSpeed(39), true);

	EXPECT_EQ(car.GetDirection(), "FORWARD");
	EXPECT_EQ(car.GetGear(), "SECOND");
	EXPECT_EQ(car.GetSpeed(), 39);

	EXPECT_EQ(car.SetGear(4), false);
	EXPECT_EQ(car.SetSpeed(40), true);
	EXPECT_EQ(car.SetGear(4), true);

	EXPECT_EQ(car.GetDirection(), "FORWARD");
	EXPECT_EQ(car.GetGear(), "FOURTH");
	EXPECT_EQ(car.GetSpeed(), 40);

	EXPECT_EQ(car.SetSpeed(90), true);
	EXPECT_EQ(car.SetSpeed(91), false);
	EXPECT_EQ(car.GetSpeed(), 90);
}


TEST(Car, SetGear_SetSpeed_Fifth) {
	CCar car;
	car.TurnOnEngine();
	EXPECT_EQ(car.GetTurnEngine(), true);

	EXPECT_EQ(car.SetGear(1), true);
	EXPECT_EQ(car.SetSpeed(30), true);
	EXPECT_EQ(car.SetGear(2), true);
	EXPECT_EQ(car.SetSpeed(49), true);

	EXPECT_EQ(car.GetDirection(), "FORWARD");
	EXPECT_EQ(car.GetGear(), "SECOND");
	EXPECT_EQ(car.GetSpeed(), 49);

	EXPECT_EQ(car.SetGear(5), false);
	EXPECT_EQ(car.SetSpeed(50), true);
	EXPECT_EQ(car.SetGear(5), true);

	EXPECT_EQ(car.GetDirection(), "FORWARD");
	EXPECT_EQ(car.GetGear(), "FIFTH");
	EXPECT_EQ(car.GetSpeed(), 50);

	EXPECT_EQ(car.SetSpeed(150), true);
	EXPECT_EQ(car.SetSpeed(151), false);
	EXPECT_EQ(car.GetSpeed(), 150);

	EXPECT_EQ(car.SetGear(6), false);
}


TEST(CarCommunication, INFO_MODE) {
	CCar car;
	car.TurnOnEngine();
	car.SetGear(-1);
	car.SetSpeed(10);
	std::stringstream issIn(INFO_MODE);
	std::stringstream issOut;
	CCarCommunication carCommunication(issIn, issOut, car);

	carCommunication.ProcessingCommand();
	EXPECT_EQ(issOut.str(), "Engine condition ON\nDirection of movement BACK\nSpeed 10\nGear REVERSE\n\n");
}

TEST(CarCommunication, ENGINE_ON_MODE) {
	CCar car;
	std::stringstream issIn(ENGINE_ON_MODE);
	std::stringstream issOut;
	CCarCommunication carCommunication(issIn, issOut, car);

	carCommunication.ProcessingCommand();
	EXPECT_EQ(issOut.str(), "The engine is on\n\n");
}

TEST(CarCommunication, ERROR_ENGINE_ON) {
	CCar car;
	car.TurnOnEngine();
	std::stringstream issIn(ENGINE_ON_MODE);
	std::stringstream issOut;
	CCarCommunication carCommunication(issIn, issOut, car);

	carCommunication.ProcessingCommand();
	EXPECT_EQ(issOut.str(), "Engine failed to turn on\n\n");
}

TEST(CarCommunication, ENGINE_OFF_MODE) {
	CCar car;
	car.TurnOnEngine();
	std::stringstream issIn(ENGINE_OFF_MODE);
	std::stringstream issOut;
	CCarCommunication carCommunication(issIn, issOut, car);

	carCommunication.ProcessingCommand();
	EXPECT_EQ(issOut.str(), "The engine is off\n\n");
}

TEST(CarCommunication, ERROR_ENGINE_OFF) {
	CCar car;
	std::stringstream issIn(ENGINE_OFF_MODE);
	std::stringstream issOut;
	CCarCommunication carCommunication(issIn, issOut, car);

	carCommunication.ProcessingCommand();
	EXPECT_EQ(issOut.str(), "Engine failed to turn off\nThe engine can be turned off, if the speed is 0, the transmission is neutral in the direction of standing\n\n");
}

TEST(CarCommunication, SET_GEAR_MODE_Error_non_number) {
	CCar car;
	std::stringstream issIn("SetGear hello");
	std::stringstream issOut;
	CCarCommunication carCommunication(issIn, issOut, car);

	carCommunication.ProcessingCommand();
	EXPECT_EQ(issOut.str(), "You entered not a number\n\n");
}

TEST(CarCommunication, SET_GEAR_MODE_Error_outside1) {
	CCar car;
	std::stringstream issIn("SetGear -2");
	std::stringstream issOut;
	CCarCommunication carCommunication(issIn, issOut, car);

	carCommunication.ProcessingCommand();
	EXPECT_EQ(issOut.str(), "Gear must be a number from -1 to 5\n\n");
}


TEST(CarCommunication, SET_GEAR_MODE_Error_outside2) {
	CCar car;
	std::stringstream issIn("SetGear 6");
	std::stringstream issOut;
	CCarCommunication carCommunication(issIn, issOut, car);

	carCommunication.ProcessingCommand();
	EXPECT_EQ(issOut.str(), "Gear must be a number from -1 to 5\n\n");
}


TEST(CarCommunication, SET_GEAR_MODE_Set_gear) {
	CCar car;
	car.TurnOnEngine();
	std::stringstream issIn("SetGear -1");
	std::stringstream issOut;
	CCarCommunication carCommunication(issIn, issOut, car);

	carCommunication.ProcessingCommand();
	EXPECT_EQ(issOut.str(), "Gear is set to -1\n\n");
}

TEST(CarCommunication, SET_GEAR_MODE_Not_set_gear) {
	CCar car;
	std::stringstream issIn("SetGear -1");
	std::stringstream issOut;
	CCarCommunication carCommunication(issIn, issOut, car);

	carCommunication.ProcessingCommand();
	EXPECT_EQ(issOut.str(), "Gear is not set\n\n");
}

TEST(CarCommunication, SET_SPEED_Error_non_number) {
	CCar car;
	std::stringstream issIn("SetSpeed hello");
	std::stringstream issOut;
	CCarCommunication carCommunication(issIn, issOut, car);

	carCommunication.ProcessingCommand();
	EXPECT_EQ(issOut.str(), "You entered not a number\n\n");
}

TEST(CarCommunication, SET_SPEED_MODE_Error_outside1) {
	CCar car;
	std::stringstream issIn("SetSpeed -1");
	std::stringstream issOut;
	CCarCommunication carCommunication(issIn, issOut, car);

	carCommunication.ProcessingCommand();
	EXPECT_EQ(issOut.str(), "The speed should be a number from 0 to 150\n\n");
}

TEST(CarCommunication, SET_Speed_MODE_Error_outside2) {
	CCar car;
	std::stringstream issIn("SetSpeed 151");
	std::stringstream issOut;
	CCarCommunication carCommunication(issIn, issOut, car);

	carCommunication.ProcessingCommand();
	EXPECT_EQ(issOut.str(), "The speed should be a number from 0 to 150\n\n");
}


TEST(CarCommunication, SET_SPEED_MODE_Set_speed) {
	CCar car;
	car.TurnOnEngine();
	car.SetGear(-1);
	std::stringstream issIn("SetSpeed 10");
	std::stringstream issOut;
	CCarCommunication carCommunication(issIn, issOut, car);

	carCommunication.ProcessingCommand();
	EXPECT_EQ(issOut.str(), "The speed is set to 10\n\n");
}

TEST(CarCommunication, SET_SPEED_MODE_Not_set_speed) {
	CCar car;
	std::stringstream issIn("SetSpeed 10");
	std::stringstream issOut;
	CCarCommunication carCommunication(issIn, issOut, car);

	carCommunication.ProcessingCommand();
	EXPECT_EQ(issOut.str(), "The speed is not set\n\n");
}

TEST(CarCommunication, UNKNOWN_MODE) {
	CCar car;
	std::stringstream issIn("hello");
	std::stringstream issOut;
	CCarCommunication carCommunication(issIn, issOut, car);

	carCommunication.ProcessingCommand();
	EXPECT_EQ(issOut.str(), "Unknown mode\n\n");
}

