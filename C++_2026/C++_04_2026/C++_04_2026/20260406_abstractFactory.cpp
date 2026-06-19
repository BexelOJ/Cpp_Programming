#include <iostream>
#include <string>

//Abstract Product - Button
class Button{
public:
	virtual void render() = 0;
	virtual ~Button() = default;
};

//Abstract Product - CheckBox
class checkBox{
public:
	virtual void render() = 0;
	virtual ~checkBox() = default;
};

//Concrete Product - DarkThemeButton
class DarkThemeButton: public Button{
public:
	void render() override {
		std::cout<<" Rendering Dark Theme Button"<<std::endl;
	}
};

//Concrete Product - LightThemeButton
class LightThemeButton: public Button{
public:
	void render() override {
		std::cout<<" Rendering Light Theme Button"<<std::endl;
	}
};

//Concrete Product - DarkThemeCheckBox
class DarkThemeCheckBox: public checkBox{
public:
	void render() override {
		std::cout<<" Rendering Dark Theme CheckBox"<<std::endl;
	}
};

//Concrete Product - LightThemeCheckBox
class LightThemeCheckBox: public checkBox{
public:
	void render() override {
		std::cout<<" Rendering Light Theme checkBox"<<std::endl;
	}
};

//Abstract Factory
class GUIFactory{
public:
	virtual Button* createButton() = 0;
	virtual checkBox* createCheckBox() = 0;
	virtual ~GUIFactory() = default;

};

//Concrete Factory - DarkThemeFactory()
class DarkThemeFactory: public GUIFactory{
public:
	Button* createButton() override {
		return new DarkThemeButton();
	}
	checkBox* createCheckBox() override {
		return new DarkThemeCheckBox();
	}
};

//Concrete Factory - LightThemeFactory()
class LightThemeFactory: public GUIFactory{
public:
	Button* createButton() override {
		return new LightThemeButton();
	}
	checkBox* createCheckBox() override {
		return new LightThemeCheckBox();
	}
};

int main(){
GUIFactory* factory;
Button* button;
checkBox* checkBox;
 

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

/*

 Rendering Dark Theme Button
 Rendering Dark Theme CheckBox
 Rendering Light Theme Button
 Rendering Light Theme checkBox

 */



