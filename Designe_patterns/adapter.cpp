#include <string>
#include <iostream>

class print_interface {
public:
    virtual void output(const std::string& content) = 0;
    virtual ~print_interface() = default;
};

class outdated_printer {
public:
    void print_obsolete(const std::string& content) {
        std::cout << "Outdated Printer: " << content << std::endl;
    }
};

class print_adapter : public print_interface {
public:
    print_adapter(outdated_printer* obsoletePrinter) : obsoletePrinter(obsoletePrinter) {}

    void output(const std::string& content) override {
        obsoletePrinter->print_obsolete(content);
    }

private:
    outdated_printer* obsoletePrinter;
};

int main() {
    outdated_printer oldPrinterInstance;
    print_adapter adapter(&oldPrinterInstance);

    adapter.output("printing new content");

    return 0;
}
