#include <iostream>

//Target Interface
class ModernSystem{
public:
	virtual void connect() = 0;
	virtual ~ModernSystem() = default;
};

//Adaptee with incompatible interface
class LegacySystem{
public:
	void establishConnection(){
		std::cout<<"Legacy System: Connection established!"<<std::endl;
	}
};

//adapter class
class LegacyToModernAdapter: public ModernSystem{
private:
	LegacySystem* legacySystem;
public:
	LegacyToModernAdapter(LegacySystem* system):legacySystem(system){}

	void connect() override {
		std::cout<<"Adpter: Adapting Legacy system's connection method..."<<std::endl;
		legacySystem->establishConnection();
	}

	~LegacyToModernAdapter(){
		delete legacySystem;
	}
};

int main(){
	ModernSystem* modernSystem = new LegacyToModernAdapter(new LegacySystem());

	modernSystem->connect();

	delete modernSystem;

	return 0;
}
