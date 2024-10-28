#include <iostream>

class screen_device {
public:
    virtual void build() = 0; 
    virtual ~screen_device() = default;
};

class processing_unit {
public:
    virtual void build() = 0;
    virtual ~processing_unit() = default;
};

class acer_screen_device : public screen_device {
public:
    void build() override {
        std::cout << "Acer Screen" << std::endl;
    }
};

class acer_processing_unit : public processing_unit {
public:
    void build() override {
        std::cout << "Acer Processing Unit" << std::endl;
    }
};

class dell_screen_device : public screen_device {
public:
    void build() override {
        std::cout << "Dell Screen" << std::endl;
    }
};

class dell_processing_unit : public processing_unit {
public:
    void build() override {
        std::cout << "Dell Processing Unit" << std::endl;
    }
};

class factory_interface {
public:
    virtual screen_device* create_screen() = 0; 
    virtual processing_unit* create_processing_unit() = 0;    
};

class acer_factory : public factory_interface {
public:
    screen_device* create_screen() override {
        return new acer_screen_device();
    }
    processing_unit* create_processing_unit() override {
        return new acer_processing_unit();
    }
};

class dell_factory : public factory_interface {
public:
    screen_device* create_screen() override {
        return new dell_screen_device();
    }
    processing_unit* create_processing_unit() override {
        return new dell_processing_unit();
    }
};

int main() {
    factory_interface* acer_factory_instance = new acer_factory();
    screen_device* acer_screen_instance = acer_factory_instance->create_screen();
    processing_unit* acer_processing_instance = acer_factory_instance->create_processing_unit();

    acer_screen_instance->build();
    acer_processing_instance->build();     

    delete acer_screen_instance;
    delete acer_processing_instance;
    delete acer_factory_instance;

    factory_interface* dell_factory_instance = new dell_factory();
    screen_device* dell_screen_instance = dell_factory_instance->create_screen();
    processing_unit* dell_processing_instance = dell_factory_instance->create_processing_unit();

    dell_screen_instance->build(); 
    dell_processing_instance->build();     

    delete dell_screen_instance;
    delete dell_processing_instance;
    delete dell_factory_instance;

    return 0;
}
