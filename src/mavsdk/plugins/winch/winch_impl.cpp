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




void WinchImpl::relax_async(uint32_t instance, const Winch::ResultCallback callback)
{
    
    MavlinkCommandSender::CommandLong command{};

    command.command = MAV_CMD_DO_WINCH;
    command.params.maybe_param1 = instance;
    command.params.maybe_param2 = static_cast<float>(Winch::WinchAction::Relaxed);

    command.target_component_id = MAV_TYPE::MAV_TYPE_WINCH;

    _parent->send_command_async(
        command, [this, callback](MavlinkCommandSender::Result result, float) {
            command_result_callback(result, callback);
        });
}



Winch::Result WinchImpl::relax(uint32_t instance)
{
    
    auto prom = std::promise<Winch::Result>();
    auto fut = prom.get_future();

    relax_async(instance, [&prom](Winch::Result result) {
        prom.set_value(result);
    });

    return fut.get();
}



void WinchImpl::relative_length_control_async(uint32_t instance, float length, float rate, const Winch::ResultCallback callback)
{
    
    MavlinkCommandSender::CommandLong command{};

    command.command = MAV_CMD_DO_WINCH;
    command.params.maybe_param1 = instance;
    command.params.maybe_param2 = static_cast<float>(Winch::WinchAction::RelativeLengthControl);
    command.params.maybe_param3 = length;
    command.params.maybe_param4 = rate;

    command.target_component_id = MAV_TYPE::MAV_TYPE_WINCH;

    _parent->send_command_async(
        command, [this, callback](MavlinkCommandSender::Result result, float) {
            command_result_callback(result, callback);
        });
}



Winch::Result WinchImpl::relative_length_control(uint32_t instance, float length, float rate)
{
    
    auto prom = std::promise<Winch::Result>();
    auto fut = prom.get_future();

    relative_length_control_async(instance, length, rate, [&prom](Winch::Result result) {
        prom.set_value(result);
    });

    return fut.get();
}

void WinchImpl::rate_control_async(uint32_t instance, float rate, const Winch::ResultCallback callback)
{
    
    MavlinkCommandSender::CommandLong command{};

    command.command = MAV_CMD_DO_WINCH;
    command.params.maybe_param1 = instance;
    command.params.maybe_param2 = static_cast<float>(Winch::WinchAction::RateControl);
    command.params.maybe_param4 = rate;

    command.target_component_id = MAV_TYPE::MAV_TYPE_WINCH;

    _parent->send_command_async(
        command, [this, callback](MavlinkCommandSender::Result result, float) {
            command_result_callback(result, callback);
        });
}



Winch::Result WinchImpl::rate_control(uint32_t instance, float rate)
{
    
    auto prom = std::promise<Winch::Result>();
    auto fut = prom.get_future();

    rate_control_async(instance, rate, [&prom](Winch::Result result) {
        prom.set_value(result);
    });

    return fut.get();
}

void WinchImpl::lock_async(uint32_t instance, const Winch::ResultCallback callback)
{
    
    MavlinkCommandSender::CommandLong command{};

    command.command = MAV_CMD_DO_WINCH;
    command.params.maybe_param1 = instance;
    command.params.maybe_param2 = static_cast<float>(Winch::WinchAction::Lock);

    command.target_component_id = MAV_TYPE::MAV_TYPE_WINCH;

    _parent->send_command_async(
        command, [this, callback](MavlinkCommandSender::Result result, float) {
            command_result_callback(result, callback);
        });
}



Winch::Result WinchImpl::lock(uint32_t instance)
{
    
    auto prom = std::promise<Winch::Result>();
    auto fut = prom.get_future();

    lock_async(instance, [&prom](Winch::Result result) {
        prom.set_value(result);
    });

    return fut.get();
}

void WinchImpl::deliver_async(uint32_t instance, const Winch::ResultCallback callback)
{
    
    MavlinkCommandSender::CommandLong command{};

    command.command = MAV_CMD_DO_WINCH;
    command.params.maybe_param1 = instance;
    command.params.maybe_param2 = static_cast<float>(Winch::WinchAction::Deliver);

    command.target_component_id = MAV_TYPE::MAV_TYPE_WINCH;

    _parent->send_command_async(
        command, [this, callback](MavlinkCommandSender::Result result, float) {
            command_result_callback(result, callback);
        });
}



Winch::Result WinchImpl::deliver(uint32_t instance)
{
    
    auto prom = std::promise<Winch::Result>();
    auto fut = prom.get_future();

    deliver_async(instance, [&prom](Winch::Result result) {
        prom.set_value(result);
    });

    return fut.get();
}

void WinchImpl::hold_async(uint32_t instance, const Winch::ResultCallback callback)
{
    
    MavlinkCommandSender::CommandLong command{};

    command.command = MAV_CMD_DO_WINCH;
    command.params.maybe_param1 = instance;
    command.params.maybe_param2 = static_cast<float>(Winch::WinchAction::Hold);

    command.target_component_id = MAV_TYPE::MAV_TYPE_WINCH;

    _parent->send_command_async(
        command, [this, callback](MavlinkCommandSender::Result result, float) {
            command_result_callback(result, callback);
        });
}



Winch::Result WinchImpl::hold(uint32_t instance)
{
    
    auto prom = std::promise<Winch::Result>();
    auto fut = prom.get_future();

    hold_async(instance, [&prom](Winch::Result result) {
        prom.set_value(result);
    });

    return fut.get();
}

void WinchImpl::retract_async(uint32_t instance, const Winch::ResultCallback callback)
{
    
    MavlinkCommandSender::CommandLong command{};

    command.command = MAV_CMD_DO_WINCH;
    command.params.maybe_param1 = instance;
    command.params.maybe_param2 = static_cast<float>(Winch::WinchAction::Retract);

    command.target_component_id = MAV_TYPE::MAV_TYPE_WINCH;

    _parent->send_command_async(
        command, [this, callback](MavlinkCommandSender::Result result, float) {
            command_result_callback(result, callback);
        });
}



Winch::Result WinchImpl::retract(uint32_t instance)
{
    
    auto prom = std::promise<Winch::Result>();
    auto fut = prom.get_future();

    retract_async(instance, [&prom](Winch::Result result) {
        prom.set_value(result);
    });

    return fut.get();
}

void WinchImpl::load_line_async(uint32_t instance, const Winch::ResultCallback callback)
{
    
    MavlinkCommandSender::CommandLong command{};

    command.command = MAV_CMD_DO_WINCH;
    command.params.maybe_param1 = instance;
    command.params.maybe_param2 = static_cast<float>(Winch::WinchAction::LoadLine);

    command.target_component_id = MAV_TYPE::MAV_TYPE_WINCH;

    _parent->send_command_async(
        command, [this, callback](MavlinkCommandSender::Result result, float) {
            command_result_callback(result, callback);
        });
}



Winch::Result WinchImpl::load_line(uint32_t instance)
{
    
    auto prom = std::promise<Winch::Result>();
    auto fut = prom.get_future();

    load_line_async(instance, [&prom](Winch::Result result) {
        prom.set_value(result);
    });

    return fut.get();
}

void WinchImpl::abandon_line_async(uint32_t instance, const Winch::ResultCallback callback)
{
    
    MavlinkCommandSender::CommandLong command{};

    command.command = MAV_CMD_DO_WINCH;
    command.params.maybe_param1 = instance;
    command.params.maybe_param2 = static_cast<float>(Winch::WinchAction::AbandonLine);

    command.target_component_id = MAV_TYPE::MAV_TYPE_WINCH;

    _parent->send_command_async(
        command, [this, callback](MavlinkCommandSender::Result result, float) {
            command_result_callback(result, callback);
        });
}



Winch::Result WinchImpl::abandon_line(uint32_t instance)
{
    
    auto prom = std::promise<Winch::Result>();
    auto fut = prom.get_future();

    abandon_line_async(instance, [&prom](Winch::Result result) {
        prom.set_value(result);
    });

    return fut.get();
}

void WinchImpl::load_payload_async(uint32_t instance, const Winch::ResultCallback callback)
{
    
    MavlinkCommandSender::CommandLong command{};

    command.command = MAV_CMD_DO_WINCH;
    command.params.maybe_param1 = instance;
    command.params.maybe_param2 = static_cast<float>(Winch::WinchAction::LoadPayload);

    command.target_component_id = MAV_TYPE::MAV_TYPE_WINCH;

    _parent->send_command_async(
        command, [this, callback](MavlinkCommandSender::Result result, float) {
            command_result_callback(result, callback);
        });
}



Winch::Result WinchImpl::load_payload(uint32_t instance)
{
    
    auto prom = std::promise<Winch::Result>();
    auto fut = prom.get_future();

    load_payload_async(instance, [&prom](Winch::Result result) {
        prom.set_value(result);
    });

    return fut.get();
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