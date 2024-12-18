#include <iostream>
#include <memory>

class Appliance {
public:
    virtual ~Appliance() = default;
    virtual bool isOn() = 0;

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;

    virtual int getVolumeLevel() = 0;
    virtual void setVolumeLevel(int) = 0;

    virtual int getStation() = 0;
    virtual void setStation(int) = 0;

protected:
    bool on;
    int volumeLevel;
    int station;
};

class Speaker : public Appliance {
public:
    Speaker() {
        on = false;
        volumeLevel = 25;
        station = 40;
    }

    bool isOn() override {
        return on;
    }

    void turnOn() override {
        on = true;
        std::cout << "Speaker turned on\n";
    }

    void turnOff() override {
        on = false;
        std::cout << "Speaker turned off\n";
    }

    int getVolumeLevel() override {
        return volumeLevel;
    }
    void setVolumeLevel(int volume_) override {
        volumeLevel = volume_;
        std::cout << "Speaker volume level: " << volumeLevel << "\n";
    }
    int getStation() override {
        return station;
    }
    void setStation(int station_) override {
        station = station_;
        std::cout << "Speaker station: " << station << "\n";
    }
};

class Controller {
public:
    Controller(std::shared_ptr<Appliance> appliance_) : appliance(appliance_) {}

    void togglePower() {
        if (appliance->isOn()) {
            appliance->turnOff();
        }
        else {
            appliance->turnOn();
        }
    }

    void decreaseVolume() {
        appliance->setVolumeLevel(appliance->getVolumeLevel() - 1);
    }

    void increaseVolume() {
        appliance->setVolumeLevel(appliance->getVolumeLevel() + 1);
    }

    void decreaseStation() {
        appliance->setStation(appliance->getStation() - 1);
    }

    void increaseStation() {
        appliance->setStation(appliance->getStation() + 1);
    }

protected:
    std::shared_ptr<Appliance> appliance;
};

class AdvancedController : public Controller {
public:
    AdvancedController(std::shared_ptr<Appliance> appliance_) : Controller(appliance_) {}

    void mute() {
        appliance->setVolumeLevel(0);
        std::cout << "Appliance muted\n";
    }
};

int main() {
    std::shared_ptr<Appliance> speaker = std::make_shared<Speaker>();
    Controller controller(speaker);
    AdvancedController advancedController(speaker);

    std::cout << "Controller, speaker:\n";
    controller.togglePower();
    controller.increaseVolume();
    controller.decreaseStation();

    std::cout << std::endl;

    std::cout << "Advanced controller, speaker: \n";
    advancedController.togglePower();
    advancedController.decreaseVolume();
    advancedController.mute();

    return 0;
}
