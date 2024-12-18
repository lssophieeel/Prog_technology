#include <iostream>
#include <string>
#include <memory>

class Plant {
public:
    virtual ~Plant() = default;
    virtual std::string getDescription() = 0;
    virtual int getPrice() = 0;
};

class BasicPlant : public Plant {
public:
    std::string getDescription() override {
        return "Basic plant ";
    }

    int getPrice() override {
        return 50;
    }
};

class PlantDecorator : public Plant {
protected:
    std::unique_ptr<Plant> plant;

public:
    PlantDecorator(std::unique_ptr<Plant> plant_) : plant(std::move(plant_)) { }
};

class BaublesDecorator : public PlantDecorator {
public:
    BaublesDecorator(std::unique_ptr<Plant> plant_) : PlantDecorator(std::move(plant_)) { }

    std::string getDescription() override {
        return plant->getDescription() + ", decorated with baubles";
    }

    int getPrice() override {
        return plant->getPrice() + 25;
    }

};

class TopperDecorator : public PlantDecorator {
public:
    TopperDecorator(std::unique_ptr<Plant> plant_) : PlantDecorator(std::move(plant_)) { }

    std::string getDescription() override {
        return plant->getDescription() + ", topped with a star";
    }

    int getPrice() override {
        return plant->getPrice() + 10;
    }

};

class LightsDecorator : public PlantDecorator {
public:
    LightsDecorator(std::unique_ptr<Plant> plant_) : PlantDecorator(std::move(plant_)) { }

    std::string getDescription() override {
        return plant->getDescription() + ", adorned with lights";
    }

    int getPrice() override {
        return plant->getPrice() + 15;
    }

};

int main() {
    std::unique_ptr<Plant> plant = std::make_unique<LightsDecorator>(
        std::make_unique<TopperDecorator>(
            std::make_unique<BaublesDecorator>(
                std::make_unique<BasicPlant>())));

    std::cout << "Description: " << plant->getDescription() << std::endl;
    std::cout << "Price: $" << plant->getPrice() << std::endl;

    return 0;
}
