// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/param_server/param_server.proto)

#include <iomanip>

#include "param_server_impl.h"
#include "plugins/param_server/param_server.h"

namespace mavsdk {

using IntParam = ParamServer::IntParam;
using FloatParam = ParamServer::FloatParam;
using CustomParam = ParamServer::CustomParam;
using AllParams = ParamServer::AllParams;




ParamServer::ParamServer(std::shared_ptr<ServerComponent> server_component) : ServerPluginBase(), _impl{std::make_unique<ParamServerImpl>(server_component)} {}


ParamServer::~ParamServer() {}





std::pair<ParamServer::Result, int32_t> ParamServer::retrieve_param_int(std::string name) const
{
    return _impl->retrieve_param_int(name);
}





ParamServer::Result ParamServer::provide_param_int(std::string name, int32_t value) const
{
    return _impl->provide_param_int(name, value);
}





std::pair<ParamServer::Result, float> ParamServer::retrieve_param_float(std::string name) const
{
    return _impl->retrieve_param_float(name);
}





ParamServer::Result ParamServer::provide_param_float(std::string name, float value) const
{
    return _impl->provide_param_float(name, value);
}





std::pair<ParamServer::Result, std::string> ParamServer::retrieve_param_custom(std::string name) const
{
    return _impl->retrieve_param_custom(name);
}





ParamServer::Result ParamServer::provide_param_custom(std::string name, std::string value) const
{
    return _impl->provide_param_custom(name, value);
}





ParamServer::AllParams ParamServer::retrieve_all_params() const
{
    return _impl->retrieve_all_params();
}



bool operator==(const ParamServer::IntParam& lhs, const ParamServer::IntParam& rhs)
{
    return
        (rhs.name == lhs.name) &&
        (rhs.value == lhs.value);
}

std::ostream& operator<<(std::ostream& str, ParamServer::IntParam const& int_param)
{
    str << std::setprecision(15);
    str << "int_param:" << '\n'
        << "{\n";
    str << "    name: " << int_param.name << '\n';
    str << "    value: " << int_param.value << '\n';
    str << '}';
    return str;
}


bool operator==(const ParamServer::FloatParam& lhs, const ParamServer::FloatParam& rhs)
{
    return
        (rhs.name == lhs.name) &&
        ((std::isnan(rhs.value) && std::isnan(lhs.value)) || rhs.value == lhs.value);
}

std::ostream& operator<<(std::ostream& str, ParamServer::FloatParam const& float_param)
{
    str << std::setprecision(15);
    str << "float_param:" << '\n'
        << "{\n";
    str << "    name: " << float_param.name << '\n';
    str << "    value: " << float_param.value << '\n';
    str << '}';
    return str;
}


bool operator==(const ParamServer::CustomParam& lhs, const ParamServer::CustomParam& rhs)
{
    return
        (rhs.name == lhs.name) &&
        (rhs.value == lhs.value);
}

std::ostream& operator<<(std::ostream& str, ParamServer::CustomParam const& custom_param)
{
    str << std::setprecision(15);
    str << "custom_param:" << '\n'
        << "{\n";
    str << "    name: " << custom_param.name << '\n';
    str << "    value: " << custom_param.value << '\n';
    str << '}';
    return str;
}


bool operator==(const ParamServer::AllParams& lhs, const ParamServer::AllParams& rhs)
{
    return
        (rhs.int_params == lhs.int_params) &&
        (rhs.float_params == lhs.float_params) &&
        (rhs.custom_params == lhs.custom_params);
}

std::ostream& operator<<(std::ostream& str, ParamServer::AllParams const& all_params)
{
    str << std::setprecision(15);
    str << "all_params:" << '\n'
        << "{\n";
    str << "    int_params: [";
    for (auto it = all_params.int_params.begin(); it != all_params.int_params.end(); ++it) {
        str << *it;
        str << (it + 1 != all_params.int_params.end() ? ", " : "]\n");
    }
    str << "    float_params: [";
    for (auto it = all_params.float_params.begin(); it != all_params.float_params.end(); ++it) {
        str << *it;
        str << (it + 1 != all_params.float_params.end() ? ", " : "]\n");
    }
    str << "    custom_params: [";
    for (auto it = all_params.custom_params.begin(); it != all_params.custom_params.end(); ++it) {
        str << *it;
        str << (it + 1 != all_params.custom_params.end() ? ", " : "]\n");
    }
    str << '}';
    return str;
}



std::ostream& operator<<(std::ostream& str, ParamServer::Result const& result)
{
    switch (result) {
        case ParamServer::Result::Unknown:
            return str << "Unknown";
        case ParamServer::Result::Success:
            return str << "Success";
        case ParamServer::Result::NotFound:
            return str << "Not Found";
        case ParamServer::Result::WrongType:
            return str << "Wrong Type";
        case ParamServer::Result::ParamNameTooLong:
            return str << "Param Name Too Long";
        case ParamServer::Result::NoSystem:
            return str << "No System";
        case ParamServer::Result::ParamValueTooLong:
            return str << "Param Value Too Long";
        default:
            return str << "Unknown";
    }
}




} // namespace mavsdk