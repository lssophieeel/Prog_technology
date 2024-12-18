#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void notify(int) = 0;
};

class User : public Observer {
public:
    User(const std::string& username_) : username(username_) { }

    void notify(int age) override {
        std::cout << username << " received birthday notification: " << age << "\n";
    }

private:
    std::string username;
};

class SocialMedia {
public:
    SocialMedia(int age_) : age(age_) { }

    void addObserver(std::shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }

    void removeObserver(std::shared_ptr<Observer> observer) {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notifyObservers() {
        for (const auto& observer : observers) {
            observer->notify(age);
        }
    }

    void celebrateBirthday() {
        age++;
        std::cout << "User's birthday:  " << age << "\n";
        notifyObservers();
    }

    int getAge() const { return age; }

private:
    std::vector<std::shared_ptr<Observer>> observers;
    int age;
};

int main() {
    SocialMedia socialMedia(25);

    auto JeanUser = std::make_shared<User>("Jean");
    auto AliceUser = std::make_shared<User>("Alice");
    auto DanielUser = std::make_shared<User>("Daniel");

    socialMedia.addObserver(JeanUser);
    socialMedia.addObserver(AliceUser);
    socialMedia.addObserver(DanielUser);

    socialMedia.celebrateBirthday();

    std::cout << std::endl;
    std::cout << "Alice unsubscribed.\n";
    socialMedia.removeObserver(AliceUser);

    socialMedia.celebrateBirthday();

    return 0;
}
