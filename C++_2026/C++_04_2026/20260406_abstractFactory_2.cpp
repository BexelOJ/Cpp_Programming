#include <iostream>

//Abstract Product - Button
class Button{
public:
	virtual void render() = 0;
	virtual ~Button() = default;
};

//Abstract Product - CheckBox
class CheckBox{
public:
	virtual void render() = 0;
	virtual ~CheckBox() = default;
};

//Concrete Product - DarkThemeButton
class DarkThemeButton: public Button{
public:
	void render() override {
		std::cout<<"Rendering Dark Theme Button"<<std::endl;
	}
};

//Concrete Product - LightThemeButton
class LightThemeButton: public Button{
public:
	void render() override {
		std::cout<<"Rendering Light Theme Button"<<std::endl;
	}
};

//Concrete Product - DarkThemeCheckBox
class DarkThemeCheckBox: public CheckBox{
public:
	void render() override {
		std::cout<<"Rendering Dark Theme CheckBox"<<std::endl;
	}
};

//Concrete Product - LightThemeCheckBox
class LightThemeCheckBox: public CheckBox{
public:
	void render() override {
		std::cout<<"Rendering Light Theme CheckBox"<<std::endl;
	}
};

//Abstract Factory
class GUIFactory{
public:
	virtual Button* createButton() = 0;
	virtual CheckBox* createCheckBox() = 0;
	virtual ~GUIFactory() = default;	
};

//Concrete Factory - DarkThemeFactory
class DarkThemeFactory: public GUIFactory{
public:
	Button* createButton() override {
		return new DarkThemeButton();
	}

	CheckBox* createCheckBox() override {
		return new DarkThemeCheckBox();
	}
};

//Concrete Factory - LightThemeFactory
class LightThemeFactory: public GUIFactory{
public:
	Button* createButton() override {
		return new LightThemeButton();
	}

	CheckBox* createCheckBox() override {
		return new LightThemeCheckBox();
	}
};

int main(){
GUIFactory* factory;
Button* button;
CheckBox* checkBox;

factory = new DarkThemeFactory();
button = factory->createButton();
checkBox = factory->createCheckBox();

button->render();
checkBox->render();

delete factory;

factory = new LightThemeFactory();
button = factory->createButton();
checkBox = factory->createCheckBox();

button->render();
checkBox->render();

delete button;
delete checkBox;
delete factory;

return 0;
}









