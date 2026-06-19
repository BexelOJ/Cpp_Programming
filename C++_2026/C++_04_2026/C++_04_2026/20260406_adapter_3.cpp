#include <iostream>

//Target System
class ModernSystem{
public:
	virtual void connect() = 0;
	virtual ~ModernSystem() = default;
};

//Adpter with incompatible interface
class LegacySystem{
public:
	void establishConnection(){
		std::cout<<"Legacy System: Connection established!"<<std::endl;
	}
};

//Adapter class
class LegacyToModernAdapter: public ModernSystem{
private:
	LegacySystem* legacySystem;
public:
	LegacyToModernAdapter(LegacySystem* system):legacySystem(system){}

	void connect() override {
		std::cout<<"Adapter: Adapting Legacy system's connection method..."<<std::endl;
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

