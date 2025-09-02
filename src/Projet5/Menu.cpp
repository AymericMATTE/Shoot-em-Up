#include "Menu.h"
#include "GameManager.h"
#include "Macro.h"

Menu::Menu()
{
	if (!mFont.loadFromFile(RES_PATH + "Font/m04b.ttf"))
		exit(0);

	if (!mButtonTexture.loadFromFile(RES_PATH + "Button.png"))
		exit(0);

	if (!mPressedButtonTexture.loadFromFile(RES_PATH + "PressedButton.png"))
		exit(0);
}
