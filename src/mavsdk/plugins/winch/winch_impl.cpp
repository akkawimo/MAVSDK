#include "winch_impl.h"

namespace mavsdk {


WinchImpl::WinchImpl(System& system) : PluginImplBase(system)
{
    _parent->register_plugin(this);
}

WinchImpl::WinchImpl(std::shared_ptr<System> system) : PluginImplBase(std::move(system))
{
    _parent->register_plugin(this);
}


WinchImpl::~WinchImpl()
{

    _parent->unregister_plugin(this);

}

void WinchImpl::init() {}

void WinchImpl::deinit() {}


void WinchImpl::enable() {}

void WinchImpl::disable() {}




void WinchImpl::winch_relax_async(uint32_t instance, const Winch::ResultCallback callback)
{
    
    // UNUSED(instance);
    
    // UNUSED(callback);
}



Winch::Result WinchImpl::winch_relax(uint32_t instance)
{
    
    // UNUSED(instance);
    

    // TODO :)
    return {};
}



void WinchImpl::relative_length_control_async(uint32_t instance, float length, float rate, const Winch::ResultCallback callback)
{
    
    // UNUSED(instance);
    
    // UNUSED(callback);
}



Winch::Result WinchImpl::relative_length_control(uint32_t instance, float length, float rate)
{
    
    // UNUSED(instance);
    

    // TODO :)
    return {};
}

void WinchImpl::rate_control_async(uint32_t instance, float rate, const Winch::ResultCallback callback)
{
    
    // UNUSED(instance);
    
    // UNUSED(callback);
}



Winch::Result WinchImpl::rate_control(uint32_t instance, float rate)
{
    
    // UNUSED(instance);
    

    // TODO :)
    return {};
}

void WinchImpl::lock_async(uint32_t instance, const Winch::ResultCallback callback)
{
    
    // UNUSED(instance);
    
    // UNUSED(callback);
}



Winch::Result WinchImpl::lock(uint32_t instance)
{
    
    // UNUSED(instance);
    

    // TODO :)
    return {};
}

void WinchImpl::deliver_async(uint32_t instance, const Winch::ResultCallback callback)
{
    
    // UNUSED(instance);
    
    // UNUSED(callback);
}



Winch::Result WinchImpl::deliver(uint32_t instance)
{
    
    // UNUSED(instance);
    

    // TODO :)
    return {};
}

void WinchImpl::hold_async(uint32_t instance, const Winch::ResultCallback callback)
{
    
    // UNUSED(instance);
    
    // UNUSED(callback);
}



Winch::Result WinchImpl::hold(uint32_t instance)
{
    
    // UNUSED(instance);
    

    // TODO :)
    return {};
}

void WinchImpl::retract_async(uint32_t instance, const Winch::ResultCallback callback)
{
    
    // UNUSED(instance);
    
    // UNUSED(callback);
}



Winch::Result WinchImpl::retract(uint32_t instance)
{
    
    // UNUSED(instance);
    

    // TODO :)
    return {};
}

void WinchImpl::load_line_async(uint32_t instance, const Winch::ResultCallback callback)
{
    
    // UNUSED(instance);
    
    // UNUSED(callback);
}



Winch::Result WinchImpl::load_line(uint32_t instance)
{
    
    // UNUSED(instance);
    

    // TODO :)
    return {};
}

void WinchImpl::abandon_line_async(uint32_t instance, const Winch::ResultCallback callback)
{
    
    // UNUSED(instance);
    
    // UNUSED(callback);
}



Winch::Result WinchImpl::abandon_line(uint32_t instance)
{
    
    // UNUSED(instance);
    

    // TODO :)
    return {};
}

void WinchImpl::load_payload_async(uint32_t instance, const Winch::ResultCallback callback)
{
    
    // UNUSED(instance);
    
    // UNUSED(callback);
}



Winch::Result WinchImpl::load_payload(uint32_t instance)
{
    
    // UNUSED(instance);
    

    // TODO :)
    return {};
}

Winch::Result WinchImpl::winch_result_from_command_result(MavlinkCommandSender::Result result)
{
    switch (result) {
        case MavlinkCommandSender::Result::Success:
            return Winch::Result::Success;
        case MavlinkCommandSender::Result::NoSystem:
            return Winch::Result::NoSystem;
        case MavlinkCommandSender::Result::ConnectionError:
            return Winch::Result::ConnectionError;
        case MavlinkCommandSender::Result::Busy:
            return Winch::Result::Busy;
        case MavlinkCommandSender::Result::Denied:
            // Fallthrough
        case MavlinkCommandSender::Result::TemporarilyRejected:
            return Winch::Result::CommandDenied;
        case MavlinkCommandSender::Result::Failed:
            return Winch::Result::Failed;
        case MavlinkCommandSender::Result::Timeout:
            return Winch::Result::Timeout;
        case MavlinkCommandSender::Result::Unsupported:
            return Winch::Result::Unsupported;
        default:
            return Winch::Result::Unknown;
    }
}

void WinchImpl::command_result_callback(
    MavlinkCommandSender::Result command_result, const Winch::ResultCallback& callback) const
{
    Winch::Result action_result = winch_result_from_command_result(command_result);

    if (callback) {
        auto temp_callback = callback;
        _parent->call_user_callback(
            [temp_callback, action_result]() { temp_callback(action_result); });
    }
}


} // namespace mavsdk