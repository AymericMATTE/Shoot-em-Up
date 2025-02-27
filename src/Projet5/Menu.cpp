#include "Menu.h"
#include "GameManager.h"

Menu::Menu()
{
	if (!mFont.loadFromFile("../../../res/Font/m04b.ttf"))
		exit(0);

	if (!mButtonTexture.loadFromFile("../../../res/Button.png"))
		exit(0);

	if (!mPressedButtonTexture.loadFromFile("../../../res/PressedButton.png"))
		exit(0);
}
