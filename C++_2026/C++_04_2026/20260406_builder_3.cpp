#include <iostream>
#include <string>

class Computer{
public:
	std::string cpu;
	std::string ram;
	std::string storage;
	
	void show(){
		std::cout<<"Computer Specifiactions : "<<std::endl;
		std::cout<<"CPU : "<<cpu<<std::endl;
		std::cout<<"RAM : "<<ram<<std::endl;
		std::cout<<"Storage : "<<storage<<std::endl;				
	}			
};

class ComputerBuilder{
public:
	virtual void buildCPU();
	virtual void buildRAM();
	virtual void buildStorage();
	virtual Computer* getResult();
	virtual ~ComputerBuilder();
};

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

class Director{
public:
	ComputerBuilder* builder;

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

	GamingComputerBuilder gamingBuilder; // stack object
	director.setBuilder(&gamingBuilder);

	Computer* gamingPC = director.constructComputer();
	gamingPC->show();

	std::cout<<std::endl;

	OfficeComputerBuilder officeBuilder; // stack object
	director.setBuilder(&officeBuilder);

	Computer* officePC = director.constructComputer();
	officePC->show();

	std::cout<<std::endl;

	delete gamingPC;
	delete officePC;

	return 0;
}




