#include <iostream>
#include <string>

class Computer{
public:
	std::string cpu;
	std::string ram;
	std::string storage;

	void show(){
		std::cout<<"Computer specifications : "<<std::endl;
		std::cout<<"CPU : "<<cpu<<std::endl;
		std::cout<<"RAM : "<<ram<<std::endl;
		std::cout<<"Storage : "<<storage<<std::endl;
	}		
};

class ComputerBuilder{
public:
	virtual void buildCPU() = 0;
	virtual void buildRAM() = 0;
	virtual void buildStorage() = 0;
	virtual Computer* getResult() = 0;
	virtual ~ComputerBuilder() = default;				
};

class GamingComputerBuilder:public ComputerBuilder{
private:
	Computer* computer;
public:
	GamingComputerBuilder(){
		computer = new Computer();
	}

	void buildCPU(){
		computer->cpu = "Intel Core i9";
	}

	void buildRAM(){
		computer->ram = "32GB DDR4";
	}

	void buildStorage(){
		computer->storage = "1TB SSD";
	}

	Computer* getResult(){
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

	void buildCPU(){
		computer->cpu = "Intel Core i5";
	}

	void buildRAM(){
		computer->ram = "8GB DDR4";
	}

	void buildStorage(){
		computer->storage = "500G HDD";
	}

	Computer* getResult(){
		return computer;
	}

};

class Director{
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

	std::cout<<std::endl;

 	delete gamingPC;
 	delete officePC;

	return 0;
}

