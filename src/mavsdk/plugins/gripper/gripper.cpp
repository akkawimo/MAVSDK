// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/gripper/gripper.proto)

#include <iomanip>

#include "gripper_impl.h"
#include "plugins/gripper/gripper.h"

namespace mavsdk {

Gripper::Gripper(System& system) : PluginBase(), _impl{std::make_unique<GripperImpl>(system)} {}

Gripper::Gripper(std::shared_ptr<System> system) :
    PluginBase(),
    _impl{std::make_unique<GripperImpl>(system)}
{}

Gripper::~Gripper() {}

void Gripper::gripper_grab_async(uint32_t instance, const ResultCallback callback)
{
    _impl->gripper_grab_async(instance, callback);
}

Gripper::Result Gripper::gripper_grab(uint32_t instance) const
{
    return _impl->gripper_grab(instance);
}

void Gripper::gripper_release_async(uint32_t instance, const ResultCallback callback)
{
    _impl->gripper_release_async(instance, callback);
}

Gripper::Result Gripper::gripper_release(uint32_t instance) const
{
    return _impl->gripper_release(instance);
}

std::ostream& operator<<(std::ostream& str, Gripper::Result const& result)
{
    switch (result) {
        case Gripper::Result::Unknown:
            return str << "Unknown";
        case Gripper::Result::Success:
            return str << "Success";
        case Gripper::Result::NoSystem:
            return str << "No System";
        case Gripper::Result::ConnectionError:
            return str << "Connection Error";
        case Gripper::Result::Busy:
            return str << "Busy";
        case Gripper::Result::CommandDenied:
            return str << "Command Denied";
        case Gripper::Result::CommandDeniedLandedStateUnknown:
            return str << "Command Denied Landed State Unknown";
        case Gripper::Result::CommandDeniedNotLanded:
            return str << "Command Denied Not Landed";
        case Gripper::Result::Timeout:
            return str << "Timeout";
        case Gripper::Result::VtolTransitionSupportUnknown:
            return str << "Vtol Transition Support Unknown";
        case Gripper::Result::NoVtolTransitionSupport:
            return str << "No Vtol Transition Support";
        case Gripper::Result::ParameterError:
            return str << "Parameter Error";
        case Gripper::Result::Unsupported:
            return str << "Unsupported";
        case Gripper::Result::Failed:
            return str << "Failed";
        default:
            return str << "Unknown";
    }
}

std::ostream& operator<<(std::ostream& str, Gripper::GripperAction const& gripper_action)
{
    switch (gripper_action) {
        case Gripper::GripperAction::Release:
            return str << "Release";
        case Gripper::GripperAction::Grab:
            return str << "Grab";
        default:
            return str << "Unknown";
    }
}

} // namespace mavsdk