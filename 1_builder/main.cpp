#include<iostream>

enum Meat { CHIKEN, BEEF, PORK };

enum Cheese { AMBER, MOZZARELLA, ALMETTE };

enum Mushrooms { CHAMPIGNON, CHANTERELLES };

enum Vegetables { TOMATO, CUCUMBER, PEPER };

enum Greenery { ONION, PARSLEY, DILL };

enum Sauses { KETCHUP, MAYONNAISE, MUSTARD };

enum Bumpers { SAUSAGE, CHEESE };

std::string getMeat(Meat& index)
{
	switch(index)
	{
		case CHIKEN: return "Chiken "; break;
		case BEEF: return "Beef "; break;
		case PORK: return "Pork "; break;
	}
};

std::string getCheese(Cheese& index)
{
	switch (index)
	{
		case AMBER: return "Amber "; break;
		case MOZZARELLA: return "Mozzarella "; break;
		case ALMETTE: return "Almette "; break;
	}
};

std::string getMushrooms(Mushrooms& index)
{
	switch (index)
	{
		case CHAMPIGNON: return "Champignon "; break;
		case CHANTERELLES: return "Chanterelles "; break;
	}
};

std::string getVegetables(Vegetables& index)
{
	switch (index)
	{
		case TOMATO: return "Tomato "; break;
		case CUCUMBER: return "Cucumber "; break;
		case PEPER: return "Peper "; break;
	}
};
	
std::string getGreenery(Greenery& index)
{
	switch (index)
	{
		case ONION: return "Onion "; break;
		case PARSLEY: return "Parsley "; break;
		case DILL: return "Dill "; break;
	}
};

std::string getSauses(Sauses& index)
{
	switch (index)
	{
		case KETCHUP: return "Ketchup "; break;
		case MAYONNAISE: return "Mayonnaise "; break;
		case MUSTARD: return "Mustard "; break;
	}
};

std::string getBumpers(Bumpers& index)
{
	switch (index)
	{
	case SAUSAGE: return "Sausage "; break;
	case CHEESE: return "Cheese "; break;
	}
}

class Pizza
{
private:
	static const short count = 10;
	std::string ingridients[count] = {};
	std::string title;
	short size;

public:
	void showPizza()
	{
		std::cout << this->title << std::endl;
		std::cout << "Pizza size is " << this->size << std::endl;
		std::cout << "Additives: " << std::endl;
		for (int i{}; i < this->count; ++i)
		{
			std::cout << ingridients[i] << ' ';
		}
	}
	
	virtual void setTitle(std::string title) { this->title = title; }
	virtual void setSize(short size) { this->size = size; }

	short getSize() { return this->size; }
	std::string getTitle() { return this->title; }
	std::string* getIngridients() { return ingridients; }
};

class Builder
{
protected: 
	Pizza* pizza;
public: 
	Builder(Pizza* pizza) :
		pizza{ pizza }
	{}

	virtual Pizza* addMeat(Meat& meat) = 0;
	virtual Pizza* addCheese(Cheese& cheese) = 0;
	virtual Pizza* addMushrooms(Mushrooms& mushrooms) = 0;
	virtual Pizza* addVegetables(Vegetables& vegetables) = 0;
	virtual Pizza* addGreenery(Greenery& greenery) = 0;
	virtual Pizza* addSauses(Sauses& sauses) = 0;
	virtual Pizza* addBumpers(Bumpers& bumpers) = 0;
	
	Pizza* getPizza() { return this->pizza; }

	virtual ~Builder() {}
};

class MeatPizza : public Builder
{
public:
	MeatPizza(Pizza* pizza) :
		Builder{pizza}
	{}

	virtual Pizza* addMeat(Meat& meat) override 
	{
		*pizza->getIngridients() += getMeat(meat); 
		return pizza;
	}

	virtual Pizza* addMushrooms(Mushrooms& mushrooms) override
	{
		*pizza->getIngridients() += getMushrooms(mushrooms);
		return pizza;
	}

	virtual Pizza* addSauses(Sauses& sauses) override
	{
		*pizza->getIngridients() += getSauses(sauses);
		return pizza;
	}

	virtual Pizza* addCheese(Cheese& cheese) override { return nullptr; }
	virtual Pizza* addVegetables(Vegetables& vegetables) override { return nullptr; }
	virtual Pizza* addGreenery(Greenery& greenery) override { return nullptr; }
	virtual Pizza* addBumpers(Bumpers& bumpers) override { return nullptr; }
};

class VegetablePizza : public Builder
{
public:
	VegetablePizza(Pizza* pizza) :
		Builder{ pizza }
	{}

	virtual Pizza* addSauses(Sauses& sauses) override
	{
		*pizza->getIngridients() += getSauses(sauses);
		return pizza;
	}

	virtual Pizza* addGreenery(Greenery& greenery) override
	{
		*pizza->getIngridients() += getGreenery(greenery);
		return pizza;
	}

	virtual Pizza* addVegetables(Vegetables& vegetables) override
	{
		*pizza->getIngridients() += getVegetables(vegetables);
		return pizza;
	}

	virtual Pizza* addMeat(Meat& meat) override { return nullptr; }
	virtual Pizza* addMushrooms(Mushrooms& mushrooms) override { return nullptr; }
	virtual Pizza* addCheese(Cheese& cheese) override { return nullptr; }
	virtual Pizza* addBumpers(Bumpers& bumpers) override { return nullptr; }
};

class CustomPizza : public Builder
{
public:
	int switchNum{};

	CustomPizza(Pizza* pizza) :
		Builder{ pizza }
	{}
	virtual Pizza* addMeat(Meat& meat) override
	{
		std::cout << "Выберите мясо, которое хотите добавить: " << std::endl;
		std::cout << "1 - курятина\n2 - говядина\n3 - свинина" << std::endl;
		std::cin >> switchNum;
		if (switchNum == 1)
		{
			meat = { CHIKEN };
			*pizza->getIngridients() += getMeat(meat);
			return pizza;
		}
		else if (switchNum == 2)
		{
			meat = { BEEF };
			*pizza->getIngridients() += getMeat(meat);
			return pizza;
		}
		else if (switchNum == 3)
		{
			meat = { PORK };
			*pizza->getIngridients() += getMeat(meat);
			return pizza;
		}
		else std::cout << "Error..."; exit(0);
	}

	virtual Pizza* addVegetables(Vegetables& vegetables) override
	{
		std::cout << "Выберите овощи, которое хотите добавить: " << std::endl;
		std::cout << "1 - помидоры\n2 - огурцы\n3 - перец" << std::endl;
		std::cin >> switchNum;
		if (switchNum == 1)
		{
			vegetables = { TOMATO };
			*pizza->getIngridients() += getVegetables(vegetables);
			return pizza;
		}
		else if (switchNum == 2)
		{
			vegetables = { CUCUMBER };
			*pizza->getIngridients() += getVegetables(vegetables);
			return pizza;
		}
		else if (switchNum == 3)
		{
			vegetables = { PEPER };
			*pizza->getIngridients() += getVegetables(vegetables);
			return pizza;
		}
		else std::cout << "Error..."; exit(0);
	}

	virtual Pizza* addMushrooms(Mushrooms& mushrooms) override
	{
		std::cout << "Выберите грибы, которое хотите добавить: " << std::endl;
		std::cout << "1 - шампиньйоны\n2 - лисички\n" << std::endl;
		std::cin >> switchNum;
		if (switchNum == 1)
		{
			mushrooms = { CHAMPIGNON };
			*pizza->getIngridients() += getMushrooms(mushrooms);
			return pizza;
		}
		else if (switchNum == 2)
		{
			mushrooms = { CHANTERELLES };
			*pizza->getIngridients() += getMushrooms(mushrooms);
			return pizza;
		}
		else std::cout << "Error..."; exit(0);
	}

	virtual Pizza* addCheese(Cheese& cheese) override
	{
		std::cout << "Выберите сыр, который хотите добавить: " << std::endl;
		std::cout << "1 - янтарь\n2 - моццарелла\n3 - аллмете" << std::endl;
		std::cin >> switchNum;
		if (switchNum == 1)
		{
			cheese = { AMBER };
			*pizza->getIngridients() += getCheese(cheese);
			return pizza;
		}
		else if (switchNum == 2)
		{
			cheese = { MOZZARELLA };
			*pizza->getIngridients() += getCheese(cheese);
			return pizza;
		}
		else if (switchNum == 3)
		{
			cheese = { ALMETTE };
			*pizza->getIngridients() += getCheese(cheese);
			return pizza;
		}
		else std::cout << "Error..."; exit(0);
	}
	
	virtual Pizza* addGreenery(Greenery& greenery) override
	{
		std::cout << "Выберите зелень, которую хотите добавить: " << std::endl;
		std::cout << "1 - лук\n2 - петрушка\n3 - укроп" << std::endl;
		std::cin >> switchNum;
		if (switchNum == 1)
		{
			greenery = { ONION };
			*pizza->getIngridients() += getGreenery(greenery);
			return pizza;
		}
		else if (switchNum == 2)
		{
			greenery = { PARSLEY };
			*pizza->getIngridients() += getGreenery(greenery);
			return pizza;
		}
		else if (switchNum == 3)
		{
			greenery = { DILL };
			*pizza->getIngridients() += getGreenery(greenery);
			return pizza;
		}
		else std::cout << "Error..."; exit(0);
	}
	
	virtual Pizza* addSauses(Sauses& sauses) override
	{
		std::cout << "Выберите соус, который хотите добавить: " << std::endl;
		std::cout << "1 - кетчуп\n2 - майонез\n3 - горчица" << std::endl;
		std::cin >> switchNum;
		if (switchNum == 1)
		{
			sauses = { KETCHUP };
			*pizza->getIngridients() += getSauses(sauses);
			return pizza;
		}
		else if (switchNum == 2)
		{
			sauses = { MAYONNAISE };
			*pizza->getIngridients() += getSauses(sauses);
			return pizza;
		}
		else if (switchNum == 3)
		{
			sauses = { MUSTARD };
			*pizza->getIngridients() += getSauses(sauses);
			return pizza;
		}
		else std::cout << "Error..."; exit(0);
	}
	
	virtual Pizza* addBumpers(Bumpers& bumpers) override
	{	
		std::cout << "Выберите бортики, которые хотите добавить: " << std::endl;
		std::cout << "1 - сосисочные\n2 - сырные\n" << std::endl;
		std::cin >> switchNum;
		if (switchNum == 1)
		{
			bumpers = { SAUSAGE };
			*pizza->getIngridients() += getBumpers(bumpers);
			return pizza;
		}
		else if (switchNum == 2)
		{
			bumpers = { CHEESE };
			*pizza->getIngridients() += getBumpers(bumpers);
			return pizza;
		}
		else std::cout << "Error..."; exit(0);
	}
};

class ReportDirector
{
public:
	Pizza* createBigMeatPizza(Builder* builder, Meat& meat, Mushrooms& mushrooms, Sauses& sauses)
	{
		builder->getPizza()->setSize(30);
		builder->getPizza()->setTitle("Meat Pizza");
		builder->addMeat(meat);
		builder->addMushrooms(mushrooms);
		builder->addSauses(sauses);
		return builder->getPizza();
	}

	Pizza* createSmallMeatPizza(Builder* builder, Meat& meat, Mushrooms& mushrooms, Sauses& sauses)
	{
		builder->getPizza()->setSize(15);
		builder->getPizza()->setTitle("Meat Pizza");
		builder->addMeat(meat);
		builder->addMushrooms(mushrooms);
		builder->addSauses(sauses);
		return builder->getPizza();
	}

	Pizza* createBigVegetablePizza(Builder* builder, Vegetables& vegetables, Greenery& greenery, Sauses& sauses)
	{
		builder->getPizza()->setSize(30);
		builder->getPizza()->setTitle("Vegetable Pizza");
		builder->addVegetables(vegetables);
		builder->addGreenery(greenery);
		builder->addSauses(sauses);
		return builder->getPizza();
	}

	Pizza* createSmallVegetablePizza(Builder* builder, Vegetables& vegetables, Greenery& greenery, Sauses& sauses)
	{
		builder->getPizza()->setSize(15);
		builder->getPizza()->setTitle("Vegetable Pizza");
		builder->addVegetables(vegetables);
		builder->addGreenery(greenery);
		builder->addSauses(sauses);
		return builder->getPizza();
	}

	Pizza* createCustomPizza(Builder* builder)
	{
		std::cout << "Выберите размер пиццы (от 10 до 40 см): ";
		int size = builder->getPizza()->getSize();
		std::cin >> size;
		if (size > 40 || size < 10)
		{
			std::cout << "Error..";
			exit(0);
		}
		builder->getPizza()->setSize(size);
		builder->getPizza()->setTitle("Custom Pizza");
		bool whileNum{ true };
		std::cout << "Конструктор пиццы" << std::endl;
		std::cout << "Выберите ингредиент для вашей пиццы: " << std::endl;
		while (whileNum)
		{
			std::cout << "Мясо - 1\nОвощи - 2\nГрибы - 3\nСыр - 4\nЗелень - 5\nСоус - 6\nБортики - 7" << std::endl;
			std::cout << "Завершить создание пиццы - 0" << std::endl;
			int switchNumCreate;
			std::cin >> switchNumCreate;
			switch (switchNumCreate)
			{
			case 0: whileNum = false; break;
			case 1: Meat meat;
				builder->addMeat(meat);
				whileNum = true; break;
			case 2: Vegetables vegetables;
				builder->addVegetables(vegetables);
				whileNum = true; break;
			case 3: Mushrooms mushrooms;
				builder->addMushrooms(mushrooms);
				whileNum = true; break;
			case 4: Cheese cheese;
				builder->addCheese(cheese);
				whileNum = true; break;
			case 5: Greenery greenery;
				builder->addGreenery(greenery);
				whileNum = true; break;
			case 6: Sauses sauses;
				builder->addSauses(sauses);
				whileNum = true; break;
			case 7: Bumpers bumpers;
				builder->addBumpers(bumpers);
				whileNum = true; break;
			default: std::cout << "Error.."; whileNum = true; break;
			}
		}
		return builder->getPizza();
	};
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Pizza* pizzabaze = new Pizza{};

	ReportDirector* director = new ReportDirector{};

	Pizza* pizza = director->createCustomPizza(new CustomPizza{ pizzabaze });
	pizza->showPizza();
	return 0;
}