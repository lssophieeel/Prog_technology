#include <iostream>
#include <memory>

class Processor {
public:
    virtual ~Processor() = default;

    void setNextProcessor(std::shared_ptr<Processor> nextProcessor_) {
        nextProcessor = nextProcessor_;
    }

    virtual void processRequest(const std::string& request) {
        if (nextProcessor) {
            nextProcessor->processRequest(request);
        }
        else {
            std::cout << "No processor available for: " << request << std::endl;
        }
    }

protected:
    std::shared_ptr<Processor> nextProcessor = nullptr;
};

class LexicalProcessor : public Processor {
public:
    virtual void processRequest(const std::string& request) override {
        if (request == "lexical") {
            std::cout << "Handling lexical processing: " << request << std::endl;
        }
        else {
            Processor::processRequest(request);
        }
    }
};

class GrammarProcessor : public Processor {
public:
    virtual void processRequest(const std::string& request) override {
        if (request == "grammar") {
            std::cout << "Handling grammar processing: " << request << std::endl;
        }
        else {
            Processor::processRequest(request);
        }
    }
};

class LogicalProcessor : public Processor {
public:
    virtual void processRequest(const std::string& request) override {
        if (request == "logical") {
            std::cout << "Handling logical processing: " << request << std::endl;
        }
        else {
            Processor::processRequest(request);
        }
    }
};

int main() {
    auto lexicalProcessor = std::make_shared<LexicalProcessor>();
    auto grammarProcessor = std::make_shared<GrammarProcessor>();
    auto logicalProcessor = std::make_shared<LogicalProcessor>();

    lexicalProcessor->setNextProcessor(grammarProcessor);
    grammarProcessor->setNextProcessor(logicalProcessor);

    lexicalProcessor->processRequest("lexical");
    lexicalProcessor->processRequest("grammar");
    lexicalProcessor->processRequest("logical");
    lexicalProcessor->processRequest("unknown");

    return 0;
}
