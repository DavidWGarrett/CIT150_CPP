/*
David Garrett
Chapter 1 Lab 1 Juice Machine
11-10-22
*/

namespace dispensers
{
	class dispenser
	{
	public:
		dispenser() { stock = 50; cost = 50.0; name = ""; } // Default constructor
		dispenser(int, double, std::string); // constructor with arguments
		void setStock(int newStock) { stock = newStock; } // mutator function, can change stock variable
		int getStock() const { return stock; } // accessor function, returns stock
		void setCost(double newCost) { cost = newCost; } // mutator function, can change cost variable
		double getCost() const { return cost; } // accessor function, returns cost
		void setName(std::string newName) { name = newName; } // mutator function, can change name variable
		std::string getName() const { return name; } // accessor function, returns name
		void makeSale() { stock--; } // When sale happens, inventory iterates down 1
	private: // private variables, cannot be modified directly
		int stock;
		double cost;
		std::string name; 
	};
}

namespace cashRegisters
{
	class registers
	{
	public:
		registers() { money = 500.0; } // Default constructor
		registers(double); // constructor with arguments
		void setBalance(double newBalance) { money = newBalance; }  // mutator function, can change money variable
		double getBalance() const { return money; } // accessor function, returns money

		// Can pass money to register object. Add money to money variable
		void takeMoney(double moneyGiven) { money += moneyGiven; }
	private: // private variables, cannot be modified directly
		double money;
	};
}

dispensers::dispenser::dispenser(int inputStock, double inputCost, std::string inputName)
{
	// stock and cost cannot be a negative value. Both defaults to 50

	if (inputStock >= 0)
		stock = inputStock;
	else
		stock = 50;

	if (inputCost > 0.0)
		cost = inputCost;
	else
		cost = 50.0;

	name = inputName;
}

cashRegisters::registers::registers(double cashInRegister)
{
	// money cannot be a negative value. Defaults to 500

	if (cashInRegister > 0.0)
		money = cashInRegister;
	else
		money = 500.0;
}