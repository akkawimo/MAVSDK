// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/winch/winch.proto)

#include "winch/winch.grpc.pb.h"
#include "plugins/winch/winch.h"

#include "mavsdk.h"

#include "lazy_plugin.h"

#include "log.h"
#include <atomic>
#include <cmath>
#include <future>
#include <limits>
#include <memory>
#include <sstream>
#include <vector>

namespace mavsdk {
namespace mavsdk_server {


template<typename Winch = Winch, typename LazyPlugin = LazyPlugin<Winch>>

class WinchServiceImpl final : public rpc::winch::WinchService::Service {
public:

    WinchServiceImpl(LazyPlugin& lazy_plugin) : _lazy_plugin(lazy_plugin) {}



    template<typename ResponseType>
    void fillResponseWithResult(ResponseType* response, mavsdk::Winch::Result& result) const
    {
        auto rpc_result = translateToRpcResult(result);

        auto* rpc_winch_result = new rpc::winch::WinchResult();
        rpc_winch_result->set_result(rpc_result);
        std::stringstream ss;
        ss << result;
        rpc_winch_result->set_result_str(ss.str());

        response->set_allocated_winch_result(rpc_winch_result);
    }


    static rpc::winch::WinchAction translateToRpcWinchAction(const mavsdk::Winch::WinchAction& winch_action)
    {
        switch (winch_action) {
            default:
                LogErr() << "Unknown winch_action enum value: " << static_cast<int>(winch_action);
            // FALLTHROUGH
            case mavsdk::Winch::WinchAction::Relaxed:
                return rpc::winch::WINCH_ACTION_RELAXED;
            case mavsdk::Winch::WinchAction::RelativeLengthControl:
                return rpc::winch::WINCH_ACTION_RELATIVE_LENGTH_CONTROL;
            case mavsdk::Winch::WinchAction::RateControl:
                return rpc::winch::WINCH_ACTION_RATE_CONTROL;
            case mavsdk::Winch::WinchAction::Lock:
                return rpc::winch::WINCH_ACTION_LOCK;
            case mavsdk::Winch::WinchAction::Deliver:
                return rpc::winch::WINCH_ACTION_DELIVER;
            case mavsdk::Winch::WinchAction::Hold:
                return rpc::winch::WINCH_ACTION_HOLD;
            case mavsdk::Winch::WinchAction::Retract:
                return rpc::winch::WINCH_ACTION_RETRACT;
            case mavsdk::Winch::WinchAction::LoadLine:
                return rpc::winch::WINCH_ACTION_LOAD_LINE;
            case mavsdk::Winch::WinchAction::AbandonLine:
                return rpc::winch::WINCH_ACTION_ABANDON_LINE;
            case mavsdk::Winch::WinchAction::LoadPayload:
                return rpc::winch::WINCH_ACTION_LOAD_PAYLOAD;
        }
    }

    static mavsdk::Winch::WinchAction translateFromRpcWinchAction(const rpc::winch::WinchAction winch_action)
    {
        switch (winch_action) {
            default:
                LogErr() << "Unknown winch_action enum value: " << static_cast<int>(winch_action);
            // FALLTHROUGH
            case rpc::winch::WINCH_ACTION_RELAXED:
                return mavsdk::Winch::WinchAction::Relaxed;
            case rpc::winch::WINCH_ACTION_RELATIVE_LENGTH_CONTROL:
                return mavsdk::Winch::WinchAction::RelativeLengthControl;
            case rpc::winch::WINCH_ACTION_RATE_CONTROL:
                return mavsdk::Winch::WinchAction::RateControl;
            case rpc::winch::WINCH_ACTION_LOCK:
                return mavsdk::Winch::WinchAction::Lock;
            case rpc::winch::WINCH_ACTION_DELIVER:
                return mavsdk::Winch::WinchAction::Deliver;
            case rpc::winch::WINCH_ACTION_HOLD:
                return mavsdk::Winch::WinchAction::Hold;
            case rpc::winch::WINCH_ACTION_RETRACT:
                return mavsdk::Winch::WinchAction::Retract;
            case rpc::winch::WINCH_ACTION_LOAD_LINE:
                return mavsdk::Winch::WinchAction::LoadLine;
            case rpc::winch::WINCH_ACTION_ABANDON_LINE:
                return mavsdk::Winch::WinchAction::AbandonLine;
            case rpc::winch::WINCH_ACTION_LOAD_PAYLOAD:
                return mavsdk::Winch::WinchAction::LoadPayload;
        }
    }


    static rpc::winch::WinchResult::Result translateToRpcResult(const mavsdk::Winch::Result& result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case mavsdk::Winch::Result::Unknown:
                return rpc::winch::WinchResult_Result_RESULT_UNKNOWN;
            case mavsdk::Winch::Result::Success:
                return rpc::winch::WinchResult_Result_RESULT_SUCCESS;
            case mavsdk::Winch::Result::NoSystem:
                return rpc::winch::WinchResult_Result_RESULT_NO_SYSTEM;
            case mavsdk::Winch::Result::ConnectionError:
                return rpc::winch::WinchResult_Result_RESULT_CONNECTION_ERROR;
            case mavsdk::Winch::Result::Busy:
                return rpc::winch::WinchResult_Result_RESULT_BUSY;
            case mavsdk::Winch::Result::CommandDenied:
                return rpc::winch::WinchResult_Result_RESULT_COMMAND_DENIED;
            case mavsdk::Winch::Result::CommandDeniedLandedStateUnknown:
                return rpc::winch::WinchResult_Result_RESULT_COMMAND_DENIED_LANDED_STATE_UNKNOWN;
            case mavsdk::Winch::Result::CommandDeniedNotLanded:
                return rpc::winch::WinchResult_Result_RESULT_COMMAND_DENIED_NOT_LANDED;
            case mavsdk::Winch::Result::Timeout:
                return rpc::winch::WinchResult_Result_RESULT_TIMEOUT;
            case mavsdk::Winch::Result::VtolTransitionSupportUnknown:
                return rpc::winch::WinchResult_Result_RESULT_VTOL_TRANSITION_SUPPORT_UNKNOWN;
            case mavsdk::Winch::Result::NoVtolTransitionSupport:
                return rpc::winch::WinchResult_Result_RESULT_NO_VTOL_TRANSITION_SUPPORT;
            case mavsdk::Winch::Result::ParameterError:
                return rpc::winch::WinchResult_Result_RESULT_PARAMETER_ERROR;
            case mavsdk::Winch::Result::Unsupported:
                return rpc::winch::WinchResult_Result_RESULT_UNSUPPORTED;
            case mavsdk::Winch::Result::Failed:
                return rpc::winch::WinchResult_Result_RESULT_FAILED;
        }
    }

    static mavsdk::Winch::Result translateFromRpcResult(const rpc::winch::WinchResult::Result result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case rpc::winch::WinchResult_Result_RESULT_UNKNOWN:
                return mavsdk::Winch::Result::Unknown;
            case rpc::winch::WinchResult_Result_RESULT_SUCCESS:
                return mavsdk::Winch::Result::Success;
            case rpc::winch::WinchResult_Result_RESULT_NO_SYSTEM:
                return mavsdk::Winch::Result::NoSystem;
            case rpc::winch::WinchResult_Result_RESULT_CONNECTION_ERROR:
                return mavsdk::Winch::Result::ConnectionError;
            case rpc::winch::WinchResult_Result_RESULT_BUSY:
                return mavsdk::Winch::Result::Busy;
            case rpc::winch::WinchResult_Result_RESULT_COMMAND_DENIED:
                return mavsdk::Winch::Result::CommandDenied;
            case rpc::winch::WinchResult_Result_RESULT_COMMAND_DENIED_LANDED_STATE_UNKNOWN:
                return mavsdk::Winch::Result::CommandDeniedLandedStateUnknown;
            case rpc::winch::WinchResult_Result_RESULT_COMMAND_DENIED_NOT_LANDED:
                return mavsdk::Winch::Result::CommandDeniedNotLanded;
            case rpc::winch::WinchResult_Result_RESULT_TIMEOUT:
                return mavsdk::Winch::Result::Timeout;
            case rpc::winch::WinchResult_Result_RESULT_VTOL_TRANSITION_SUPPORT_UNKNOWN:
                return mavsdk::Winch::Result::VtolTransitionSupportUnknown;
            case rpc::winch::WinchResult_Result_RESULT_NO_VTOL_TRANSITION_SUPPORT:
                return mavsdk::Winch::Result::NoVtolTransitionSupport;
            case rpc::winch::WinchResult_Result_RESULT_PARAMETER_ERROR:
                return mavsdk::Winch::Result::ParameterError;
            case rpc::winch::WinchResult_Result_RESULT_UNSUPPORTED:
                return mavsdk::Winch::Result::Unsupported;
            case rpc::winch::WinchResult_Result_RESULT_FAILED:
                return mavsdk::Winch::Result::Failed;
        }
    }




    grpc::Status Relax(
        grpc::ServerContext* /* context */,
        const rpc::winch::RelaxRequest* request,
        rpc::winch::RelaxResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            
            if (response != nullptr) {
                auto result = mavsdk::Winch::Result::NoSystem;
                fillResponseWithResult(response, result);
            }
            
            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "Relax sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }
            
        
        auto result = _lazy_plugin.maybe_plugin()->relax(request->instance());
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status RelativeLengthControl(
        grpc::ServerContext* /* context */,
        const rpc::winch::RelativeLengthControlRequest* request,
        rpc::winch::RelativeLengthControlResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            
            if (response != nullptr) {
                auto result = mavsdk::Winch::Result::NoSystem;
                fillResponseWithResult(response, result);
            }
            
            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "RelativeLengthControl sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }
            
        
            
        
            
        
        auto result = _lazy_plugin.maybe_plugin()->relative_length_control(request->instance(), request->length(), request->rate());
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status RateControl(
        grpc::ServerContext* /* context */,
        const rpc::winch::RateControlRequest* request,
        rpc::winch::RateControlResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            
            if (response != nullptr) {
                auto result = mavsdk::Winch::Result::NoSystem;
                fillResponseWithResult(response, result);
            }
            
            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "RateControl sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }
            
        
            
        
        auto result = _lazy_plugin.maybe_plugin()->rate_control(request->instance(), request->rate());
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status Lock(
        grpc::ServerContext* /* context */,
        const rpc::winch::LockRequest* request,
        rpc::winch::LockResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            
            if (response != nullptr) {
                auto result = mavsdk::Winch::Result::NoSystem;
                fillResponseWithResult(response, result);
            }
            
            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "Lock sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }
            
        
        auto result = _lazy_plugin.maybe_plugin()->lock(request->instance());
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status Deliver(
        grpc::ServerContext* /* context */,
        const rpc::winch::DeliverRequest* request,
        rpc::winch::DeliverResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            
            if (response != nullptr) {
                auto result = mavsdk::Winch::Result::NoSystem;
                fillResponseWithResult(response, result);
            }
            
            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "Deliver sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }
            
        
        auto result = _lazy_plugin.maybe_plugin()->deliver(request->instance());
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status Hold(
        grpc::ServerContext* /* context */,
        const rpc::winch::HoldRequest* request,
        rpc::winch::HoldResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            
            if (response != nullptr) {
                auto result = mavsdk::Winch::Result::NoSystem;
                fillResponseWithResult(response, result);
            }
            
            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "Hold sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }
            
        
        auto result = _lazy_plugin.maybe_plugin()->hold(request->instance());
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status Retract(
        grpc::ServerContext* /* context */,
        const rpc::winch::RetractRequest* request,
        rpc::winch::RetractResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            
            if (response != nullptr) {
                auto result = mavsdk::Winch::Result::NoSystem;
                fillResponseWithResult(response, result);
            }
            
            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "Retract sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }
            
        
        auto result = _lazy_plugin.maybe_plugin()->retract(request->instance());
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status LoadLine(
        grpc::ServerContext* /* context */,
        const rpc::winch::LoadLineRequest* request,
        rpc::winch::LoadLineResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            
            if (response != nullptr) {
                auto result = mavsdk::Winch::Result::NoSystem;
                fillResponseWithResult(response, result);
            }
            
            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "LoadLine sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }
            
        
        auto result = _lazy_plugin.maybe_plugin()->load_line(request->instance());
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status AbandonLine(
        grpc::ServerContext* /* context */,
        const rpc::winch::AbandonLineRequest* request,
        rpc::winch::AbandonLineResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            
            if (response != nullptr) {
                auto result = mavsdk::Winch::Result::NoSystem;
                fillResponseWithResult(response, result);
            }
            
            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "AbandonLine sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }
            
        
        auto result = _lazy_plugin.maybe_plugin()->abandon_line(request->instance());
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status LoadPayload(
        grpc::ServerContext* /* context */,
        const rpc::winch::LoadPayloadRequest* request,
        rpc::winch::LoadPayloadResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            
            if (response != nullptr) {
                auto result = mavsdk::Winch::Result::NoSystem;
                fillResponseWithResult(response, result);
            }
            
            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "LoadPayload sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }
            
        
        auto result = _lazy_plugin.maybe_plugin()->load_payload(request->instance());
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }


    void stop() {
        _stopped.store(true);
        for (auto& prom : _stream_stop_promises) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        }
    }

private:
    void register_stream_stop_promise(std::weak_ptr<std::promise<void>> prom) {
        // If we have already stopped, set promise immediately and don't add it to list.
        if (_stopped.load()) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        } else {
            _stream_stop_promises.push_back(prom);
        }
    }

    void unregister_stream_stop_promise(std::shared_ptr<std::promise<void>> prom) {
        for (auto it = _stream_stop_promises.begin(); it != _stream_stop_promises.end(); /* ++it */) {
            if (it->lock() == prom) {
                it = _stream_stop_promises.erase(it);
            } else {
                ++it;
            }
        }
    }


    LazyPlugin& _lazy_plugin;

    std::atomic<bool> _stopped{false};
    std::vector<std::weak_ptr<std::promise<void>>> _stream_stop_promises {};
};

} // namespace mavsdk_server
} // namespace mavsdk