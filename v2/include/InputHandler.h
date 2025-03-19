#include <string>
#include <regex>

class InputHandler {
public:
    static int getIntegerInput(const std::string& prompt);
    static std::string getStringInput(const std::string& prompt);
    static std::string getValidatedDate(const std::string& prompt);
    static std::string getValidatedEmail(const std::string& prompt);
};