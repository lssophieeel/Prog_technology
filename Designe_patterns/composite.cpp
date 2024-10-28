#include <iostream>
#include <vector>

class product {
public:
    virtual ~product() = default;
    virtual int get_cost() const = 0;
    virtual void display_details() const = 0;
};

class individual_product : public product {
public:
    individual_product(const std::string& title, int cost) : title(title), cost(cost) {}

    int get_cost() const override {
        return cost;
    }

    void display_details() const override {
        std::cout << "Product: " << title << ", Cost: " << cost << "\n";
    }

private:
    std::string title;
    int cost;
};

class product_bundle : public product {
public:
    void add_product(product* item) {
        items.push_back(item);
    }

    int get_cost() const override {
        int total_cost = 0;
        for (product* item : items) {
            total_cost += item->get_cost(); 
        }
        return total_cost;
    }

    void display_details() const override {
        std::cout << "Product Bundle, Total Cost: " << get_cost() << "\n";
        for (product* item : items) {
            item->display_details(); 
        }
    }

    ~product_bundle() {
        for (product* item : items) {
            delete item;
        }
    }

private:
    std::vector<product*> items;
};

int main() {
    product* novel = new individual_product("Novel", 2500);
    product* pencil = new individual_product("Pencil", 30);

    product_bundle* bundle = new product_bundle();
    bundle->add_product(novel);
    bundle->add_product(pencil);

    bundle->display_details();

    delete bundle; 

    return 0;
}
