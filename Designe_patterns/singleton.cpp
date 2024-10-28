#include <iostream>

class singleton_parser {
public:
    static singleton_parser* get_instance() {
        if (!instance) {
            instance = new singleton_parser();
        }
        return instance;
    }

    void process() {
        std::cout << "Tokens have been processed\n";
    }

private:
    singleton_parser() = default;
    static singleton_parser* instance;

};

singleton_parser* singleton_parser::instance = nullptr;

int main() {
    singleton_parser* parser1 = singleton_parser::get_instance();
    parser1->process();

    singleton_parser* parser2 = singleton_parser::get_instance();
    parser2->process();

    if (parser1 == parser2) {
        std::cout << "Both parsers are the same instance" << std::endl;
    }

    return 0;
}
