#pragma once
#include <iostream>
#include "VBot.h"
class FighterBot : public VBot {
public:
	FighterBot(int x, int y, Panel ^ drawingPanel);
	//Moves from top left to bottom right of screen
	void Move();
	//Displays Bot
	void Show();

	// Inherited via VBot
	virtual int EnergyToFightWith();
};