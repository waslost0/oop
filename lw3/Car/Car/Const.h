#pragma once
#include <string>

const std::string INFO_MODE = "info";
const std::string HELP = "help";
const std::string ENGINE_ON_MODE = "engineon";
const std::string ENGINE_OFF_MODE = "engineoff";
const std::string SET_GEAR_MODE = "setgear";
const std::string SET_SPEED_MODE = "setspeed";
const std::string UNKNOWN_MODE = "Unknown mode\n";
const std::string HELP_INFO = "Commands: EngineOn, EngineOff, SetGear, SetSpeed, Info";

const std::string ENGINE_CONDITION_INFO = "Engine condition ";
const std::string DIRECTION_INFO = "Direction of movement ";
const std::string SPEED_INFO = "Speed ";
const std::string GEAR_INFO = "Gear ";

const std::string ENGINE_ON = "The engine is on\n";
const std::string ERROR_ENGINE_ON = "Engine failed to turn on\n";

const std::string ENGINE_OFF = "The engine is off\n";
const std::string ERROR_ENGINE_OFF = "Engine failed to turn off\nThe engine can be turned off, if the speed is 0, the transmission is neutral in the direction of standing\n";

const std::string ERROR_NON_NUMBER = "You entered not a number\n";

const std::string SET_GEAR = "Gear is set to ";
const std::string ERROR_SET_GEAR = "Gear is not set\n";
const std::string ERROR_SET_GEAR_NUMBER_OUTSIDE = "Gear must be a number from -1 to 5\n";

const std::string SET_SPEED = "The speed is set to ";
const std::string ERROR_SET_SPEED = "The speed is not set\n";
const std::string ERROR_SET_SPEED_NUMBER_OUTSIDE = "The speed should be a number from 0 to 150\n";



const int GEAR_REVERSE = -1;
const int GEAR_FIFTH = 5;

const int SPEED_MIN = 0;
const int SPEED_MAX = 150;