#include <iostream>
#include <memory>

class Action {
public:
    virtual ~Action() = default;
    virtual void execute() = 0;
};

class File { //receiver
public:
    void store() {
        std::cout << "File saved.\n";
    }
};

class SaveAction : public Action {
public:
    SaveAction(std::shared_ptr<File> file_) : file(file_) {}

    void execute() override {
        file->store();
    }

private:
    std::shared_ptr<File> file;
};

class Trigger {
public:
    virtual ~Trigger() = default;
    virtual void press() = 0;
};

class Switch : public Trigger {
public:
    Switch(std::shared_ptr<Action> action_) : action(action_) {}

    void press() override {
        std::cout << "Switch pressed.\n";
        action->execute();
    }

private:
    std::shared_ptr<Action> action;
};

class KeyPress : public Trigger {
public:
    KeyPress(std::shared_ptr<Action> action_) : action(action_) {}

    void press() override {
        std::cout << "Key press detected.\n";
        action->execute();
    }

private:
    std::shared_ptr<Action> action;
};

int main() {
    auto file = std::make_shared<File>();

    auto saveAction = std::make_shared<SaveAction>(file);

    Switch switchInvoker(saveAction);
    switchInvoker.press();

    KeyPress keyPressInvoker(saveAction);
    keyPressInvoker.press();

    return 0;
}
