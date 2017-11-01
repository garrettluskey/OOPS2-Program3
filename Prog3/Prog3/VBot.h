
#pragma once      // This is instead of the "#ifndef guard"


#include <vcclr.h>   

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class VBot
{
public:

	VBot(int startX, int startY, Panel ^ drawingPanel) :
		x(startX), y(startY), panel(drawingPanel), energy(100), image(NULL) { }

	
	virtual ~VBot() { }

	
	virtual void Move() = 0;

	
	virtual int EnergyToFightWith() = 0;

	bool IsDead() const { return energy <= 0; }

	virtual void Show();

	bool CollidedWith(VBot * b) const;

	void DoBattleWith(VBot * b);

protected:
	int x, y;                           
	gcroot<Drawing::Bitmap ^> image;   
	gcroot<Panel ^> panel;              
	int energy;                         
};