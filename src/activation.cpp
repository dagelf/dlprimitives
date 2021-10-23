#include <dlprim/definitions.hpp>

namespace dlprim {
    StandardActivations activation_from_name(std::string const &name)
    {
        if(name == "identity")
            return StandardActivations::identity;
        if(name == "relu")
            return StandardActivations::relu;
        if(name == "tanh")
            return StandardActivations::tanh;
        if(name == "sigmoid")
            return StandardActivations::sigmoid;
        if(name == "relu6")
            return StandardActivations::relu6;
        throw ValidationError("Invalid cativation name:" + name);
    }
    char const *activation_to_name(StandardActivations act)
    {
        switch(act) {
        case StandardActivations::identity:
            return "identity";
        case StandardActivations::relu:
            return "relu";
        case StandardActivations::tanh:
            return "tanh";
        case StandardActivations::sigmoid:
            return "sigmoid";
        case StandardActivations::relu6:
            return "relu6";
        }
        throw ValidationError("Internal error invalid cativation");
    }
    std::string activation_equation(StandardActivations act,std::string const &variable)
    {
        switch(act) {
        case StandardActivations::identity:
            return "(" + variable + ")";
        case StandardActivations::relu:
            return "(max(("+variable + "),(dtype)(0)))";
        case StandardActivations::tanh:
            return "(tanh((" + variable + ")))";
        case StandardActivations::sigmoid:
            return "((dtype)(1) / ((dtype)(1) + exp(-("+variable+"))))";
        case StandardActivations::relu6:
            return "(min(max((" + variable + "),(dtype)(0)),(dtype)(6)))";
        }
        throw ValidationError("Internal error invalid cativation");
    }
} // dlprim


