#ifndef PROVINCE_H
#define PROVINCE_H

#include <string>

class Province {
public:
    Province();

    void setName(const std::string& n);
    std::string getName() const;

private:
    std::string name;
    bool conquered;
};

#endif // PROVINCE_H