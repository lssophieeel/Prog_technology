#include <iostream>
#include <memory>
#include <string>

class medium {
public:
    virtual void render() = 0;
    virtual ~medium() = default;
};

class oil_paint_medium : public medium {
public:
    void render() override {
        std::cout << "Rendering with oil paint" << std::endl;
    }
};

class watercolor_medium : public medium {
public:
    void render() override {
        std::cout << "Rendering with watercolor" << std::endl;
    }
};

class colored_pencil_medium : public medium {
public:
    void render() override {
        std::cout << "Rendering with colored pencils" << std::endl;
    }
};

class medium_factory {
public:
    virtual medium* create_medium() = 0;
    virtual ~medium_factory() = default; 
};

class oil_paint_factory : public medium_factory {
public:
    medium* create_medium() override {
        return new oil_paint_medium();
    }
};

class watercolor_factory : public medium_factory {
public:
    medium* create_medium() override {
        return new watercolor_medium();
    }
};

class colored_pencil_factory : public medium_factory {
public:
    medium* create_medium() override {
        return new colored_pencil_medium();
    }
};

int main() {
    std::cout << "Enter a medium type \nexamples: oilpaint watercolor coloredpencil\n";
    std::string mediumType;
    std::cin >> mediumType;

    medium_factory* factory = nullptr;
    if (mediumType == "oilpaint") {
        factory = new oil_paint_factory();
    } else if (mediumType == "watercolor") {
        factory = new watercolor_factory();
    } else if (mediumType == "coloredpencil") {
        factory = new colored_pencil_factory();
    } else {
        std::cout << "Unknown medium type\n";
        return 1;
    }

    medium* artMedium = factory->create_medium();
    artMedium->render();

    delete factory;
    delete artMedium;

    return 0;
}
