#pragma once

#include "plugins/winch/winch.h"

#include "plugin_impl_base.h"


namespace mavsdk {


class WinchImpl : public PluginImplBase {
public:
    explicit WinchImpl(System& system);
    explicit WinchImpl(std::shared_ptr<System> system);

    ~WinchImpl() override;

    void init() override;
    void deinit() override;

    void enable() override;
    void disable() override;

    void winch_relax_async(uint32_t instance, const Winch::ResultCallback callback);



    Winch::Result winch_relax(uint32_t instance);



    void winch_relative_length_control_async(uint32_t instance, float length, float rate, const Winch::ResultCallback callback);



    Winch::Result winch_relative_length_control(uint32_t instance, float length, float rate);



    void winch_rate_control_async(uint32_t instance, float rate, const Winch::ResultCallback callback);



    Winch::Result winch_rate_control(uint32_t instance, float rate);



    void winch_lock_async(uint32_t instance, const Winch::ResultCallback callback);



    Winch::Result winch_lock(uint32_t instance);



    void winch_deliver_async(uint32_t instance, const Winch::ResultCallback callback);



    Winch::Result winch_deliver(uint32_t instance);



    void winch_hold_async(uint32_t instance, const Winch::ResultCallback callback);



    Winch::Result winch_hold(uint32_t instance);



    void winch_retract_async(uint32_t instance, const Winch::ResultCallback callback);



    Winch::Result winch_retract(uint32_t instance);



    void winch_load_line_async(uint32_t instance, const Winch::ResultCallback callback);



    Winch::Result winch_load_line(uint32_t instance);



    void winch_abandon_line_async(uint32_t instance, const Winch::ResultCallback callback);



    Winch::Result winch_abandon_line(uint32_t instance);



    void winch_load_payload_async(uint32_t instance, const Winch::ResultCallback callback);



    Winch::Result winch_load_payload(uint32_t instance);



private:
    static Winch::Result winch_result_from_command_result(MavlinkCommandSender::Result result);

    void command_result_callback(
        MavlinkCommandSender::Result command_result, const Winch::ResultCallback& callback) const;
};

} // namespace mavsdk