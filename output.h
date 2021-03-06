#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>

#include "action.h"

class Output final : public Action {
public:
    Output();
    ~Output();
    explicit Output(std::string new_output);
    void exec() const;
private:
    std::string message;
};

#endif
