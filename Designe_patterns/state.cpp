#include <iostream>
#include <memory>

class LightState {
public:
    virtual ~LightState() = default;
    virtual void switchLight() = 0;
};

class LightControl {
public:
    LightControl(std::shared_ptr<LightState> initialState) : currentState(initialState) {}

    void updateState(std::shared_ptr<LightState> newState) {
        currentState = newState;
    }

    void switchLight() {
        currentState->switchLight();
    }

private:
    std::shared_ptr<LightState> currentState;
};

class GreenState : public LightState {
public:
    void switchLight() override {
        std::cout << "Green state\n";
    }
};

class YellowState : public LightState {
public:
    void switchLight() override {
        std::cout << "Yellow state\n";
    }
};

class RedState : public LightState {
public:
    void switchLight() override {
        std::cout << "Red state\n";
    }
};

int main() {
    auto greenLightState = std::make_shared<GreenState>();
    LightControl lightControl(greenLightState);

    lightControl.switchLight();
    lightControl.updateState(std::make_shared<YellowState>());
    lightControl.switchLight();
    lightControl.updateState(std::make_shared<RedState>());
    lightControl.switchLight();

    return 0;
}
