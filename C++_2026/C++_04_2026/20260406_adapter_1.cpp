#include <iostream>

// Target interface
class ModernSystem{
public:
	virtual void connect() = 0;
	virtual ~ModernSystem() = default;
};

//Adaptee with incompatibe interface
class LegacySystem{
public:
	void establishConnection(){
		std::cout<<"LegacySystem: Connection established!"<<std::endl;
	}
};

//
class LegacyToModernAdapter: public ModernSystem{
private:
	LegacySystem* legacySystem;
public:
	LegacyToModernAdapter(LegacySystem* system): legacySystem(system){}

	void connect() override {
		std::cout<<"Adapter: Adapting legacy system's connection method..."<<std::endl;
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

