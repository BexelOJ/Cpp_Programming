#include <iostream>

//
class Computer{
public:
	std::string cpu;
	std::string ram;
	std::string storage;
	void show(){
		std::cout<<"Computer Specification : "<<std::endl;
		std::cout<<"CPU : "<<cpu<<std::endl;
		std::cout<<"RAM : "<<ram<<std::endl;
		std::cout<<"Storage : "<<storage<<std::endl;			
	}		
};

// 
class ComputerBuilder{
public:
	virtual void buildCPU() = 0;
	virtual void buildRAM() = 0;
	virtual void buildStorage() = 0;
	virtual Computer* getResult() = 0;
	virtual ~ComputerBuilder() = default;				
};

// 
class GamingComputerBuilder: public ComputerBuilder{
private:
	Computer* computer;
public:
	GamingComputerBuilder(){
		computer = new Computer();
	}

	void buildCPU() override {
		computer->cpu = "Intel Core i9";
	}

	void buildRAM() override {
		computer->ram = "32GB DDR4";
	}

	void buildStorage() override {
		computer->storage = "1TB SSD";
	}

	Computer* getResult() override {
		return computer;
	}
};

// 
class OfficeComputerBuilder: public ComputerBuilder{
private:
	Computer* computer;
public:
	OfficeComputerBuilder(){
		computer = new Computer();
	}

	void buildCPU() override {
		computer->cpu = "Intel Core i5";
	}

	void buildRAM() override {
		computer->ram = "8GB DDR4";
	}

	void buildStorage() override {
		computer->storage = "500GB HDD";
	}

	Computer* getResult() override {
		return computer;
	}	
};

// 
class Director{
private:
	ComputerBuilder* builder;
public:
	void setBuilder(ComputerBuilder* newBuilder){
		builder = newBuilder;
	}

	Computer* constructComputer(){
		builder->buildCPU();
		builder->buildRAM();
		builder->buildStorage();
		return builder->getResult();
	}
};

int main(){
	Director director;

	GamingComputerBuilder gamingBuilder;
	director.setBuilder(&gamingBuilder);

	Computer* gamingPC = director.constructComputer();
	gamingPC->show();

	std::cout<<std::endl;

	OfficeComputerBuilder officeBuilder;
	director.setBuilder(&officeBuilder);

	Computer* officePC = director.constructComputer();
	officePC->show();

	delete gamingPC;
	delete officePC;

	return 0;
}


/*

Computer Specification :
CPU : Intel Core i9
RAM : 32GB DDR4
Storage : 1TB SSD

Computer Specification :
CPU : Intel Core i5
RAM : 8GB DDR4
Storage : 500GB HDD

*/


