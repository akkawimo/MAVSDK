// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/geofence/geofence.proto)

#include "geofence/geofence.grpc.pb.h"
#include "plugins/geofence/geofence.h"

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


template<typename Geofence = Geofence, typename LazyPlugin = LazyPlugin<Geofence>>

class GeofenceServiceImpl final : public rpc::geofence::GeofenceService::Service {
public:

    GeofenceServiceImpl(LazyPlugin& lazy_plugin) : _lazy_plugin(lazy_plugin) {}



    template<typename ResponseType>
    void fillResponseWithResult(ResponseType* response, mavsdk::Geofence::Result& result) const
    {
        auto rpc_result = translateToRpcResult(result);

        auto* rpc_geofence_result = new rpc::geofence::GeofenceResult();
        rpc_geofence_result->set_result(rpc_result);
        std::stringstream ss;
        ss << result;
        rpc_geofence_result->set_result_str(ss.str());

        response->set_allocated_geofence_result(rpc_geofence_result);
    }


    static rpc::geofence::FenceType translateToRpcFenceType(const mavsdk::Geofence::FenceType& fence_type)
    {
        switch (fence_type) {
            default:
                LogErr() << "Unknown fence_type enum value: " << static_cast<int>(fence_type);
            // FALLTHROUGH
            case mavsdk::Geofence::FenceType::Inclusion:
                return rpc::geofence::FENCE_TYPE_INCLUSION;
            case mavsdk::Geofence::FenceType::Exclusion:
                return rpc::geofence::FENCE_TYPE_EXCLUSION;
        }
    }

    static mavsdk::Geofence::FenceType translateFromRpcFenceType(const rpc::geofence::FenceType fence_type)
    {
        switch (fence_type) {
            default:
                LogErr() << "Unknown fence_type enum value: " << static_cast<int>(fence_type);
            // FALLTHROUGH
            case rpc::geofence::FENCE_TYPE_INCLUSION:
                return mavsdk::Geofence::FenceType::Inclusion;
            case rpc::geofence::FENCE_TYPE_EXCLUSION:
                return mavsdk::Geofence::FenceType::Exclusion;
        }
    }



    static std::unique_ptr<rpc::geofence::Point> translateToRpcPoint(const mavsdk::Geofence::Point &point)
    {
        auto rpc_obj = std::make_unique<rpc::geofence::Point>();


            
        rpc_obj->set_latitude_deg(point.latitude_deg);
            
        
            
        rpc_obj->set_longitude_deg(point.longitude_deg);
            
        

        return rpc_obj;
    }

    static mavsdk::Geofence::Point translateFromRpcPoint(const rpc::geofence::Point& point)
    {
        mavsdk::Geofence::Point obj;


            
        obj.latitude_deg = point.latitude_deg();
            
        
            
        obj.longitude_deg = point.longitude_deg();
            
        
        return obj;
    }





    static std::unique_ptr<rpc::geofence::Polygon> translateToRpcPolygon(const mavsdk::Geofence::Polygon &polygon)
    {
        auto rpc_obj = std::make_unique<rpc::geofence::Polygon>();


            
                
        for (const auto& elem : polygon.points) {
            auto* ptr = rpc_obj->add_points();
            ptr->CopyFrom(*translateToRpcPoint(elem).release());
        }
                
            
        
            
                
        rpc_obj->set_fence_type(translateToRpcFenceType(polygon.fence_type));
                
            
        

        return rpc_obj;
    }

    static mavsdk::Geofence::Polygon translateFromRpcPolygon(const rpc::geofence::Polygon& polygon)
    {
        mavsdk::Geofence::Polygon obj;


            
                for (const auto& elem : polygon.points()) {
                    obj.points.push_back(translateFromRpcPoint(static_cast<mavsdk::rpc::geofence::Point>(elem)));
                }
            
        
            
        obj.fence_type = translateFromRpcFenceType(polygon.fence_type());
            
        
        return obj;
    }





    static std::unique_ptr<rpc::geofence::Circle> translateToRpcCircle(const mavsdk::Geofence::Circle &circle)
    {
        auto rpc_obj = std::make_unique<rpc::geofence::Circle>();


            
                
        rpc_obj->set_allocated_point(translateToRpcPoint(circle.point).release());
                
            
        
            
        rpc_obj->set_radius(circle.radius);
            
        
            
                
        rpc_obj->set_fence_type(translateToRpcFenceType(circle.fence_type));
                
            
        

        return rpc_obj;
    }

    static mavsdk::Geofence::Circle translateFromRpcCircle(const rpc::geofence::Circle& circle)
    {
        mavsdk::Geofence::Circle obj;


            
        obj.point = translateFromRpcPoint(circle.point());
            
        
            
        obj.radius = circle.radius();
            
        
            
        obj.fence_type = translateFromRpcFenceType(circle.fence_type());
            
        
        return obj;
    }





    static std::unique_ptr<rpc::geofence::GeofenceData> translateToRpcGeofenceData(const mavsdk::Geofence::GeofenceData &geofence_data)
    {
        auto rpc_obj = std::make_unique<rpc::geofence::GeofenceData>();


            
                
        for (const auto& elem : geofence_data.polygons) {
            auto* ptr = rpc_obj->add_polygons();
            ptr->CopyFrom(*translateToRpcPolygon(elem).release());
        }
                
            
        
            
                
        for (const auto& elem : geofence_data.circles) {
            auto* ptr = rpc_obj->add_circles();
            ptr->CopyFrom(*translateToRpcCircle(elem).release());
        }
                
            
        

        return rpc_obj;
    }

    static mavsdk::Geofence::GeofenceData translateFromRpcGeofenceData(const rpc::geofence::GeofenceData& geofence_data)
    {
        mavsdk::Geofence::GeofenceData obj;


            
                for (const auto& elem : geofence_data.polygons()) {
                    obj.polygons.push_back(translateFromRpcPolygon(static_cast<mavsdk::rpc::geofence::Polygon>(elem)));
                }
            
        
            
                for (const auto& elem : geofence_data.circles()) {
                    obj.circles.push_back(translateFromRpcCircle(static_cast<mavsdk::rpc::geofence::Circle>(elem)));
                }
            
        
        return obj;
    }




    static rpc::geofence::GeofenceResult::Result translateToRpcResult(const mavsdk::Geofence::Result& result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case mavsdk::Geofence::Result::Unknown:
                return rpc::geofence::GeofenceResult_Result_RESULT_UNKNOWN;
            case mavsdk::Geofence::Result::Success:
                return rpc::geofence::GeofenceResult_Result_RESULT_SUCCESS;
            case mavsdk::Geofence::Result::Error:
                return rpc::geofence::GeofenceResult_Result_RESULT_ERROR;
            case mavsdk::Geofence::Result::TooManyGeofenceItems:
                return rpc::geofence::GeofenceResult_Result_RESULT_TOO_MANY_GEOFENCE_ITEMS;
            case mavsdk::Geofence::Result::Busy:
                return rpc::geofence::GeofenceResult_Result_RESULT_BUSY;
            case mavsdk::Geofence::Result::Timeout:
                return rpc::geofence::GeofenceResult_Result_RESULT_TIMEOUT;
            case mavsdk::Geofence::Result::InvalidArgument:
                return rpc::geofence::GeofenceResult_Result_RESULT_INVALID_ARGUMENT;
            case mavsdk::Geofence::Result::NoSystem:
                return rpc::geofence::GeofenceResult_Result_RESULT_NO_SYSTEM;
        }
    }

    static mavsdk::Geofence::Result translateFromRpcResult(const rpc::geofence::GeofenceResult::Result result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case rpc::geofence::GeofenceResult_Result_RESULT_UNKNOWN:
                return mavsdk::Geofence::Result::Unknown;
            case rpc::geofence::GeofenceResult_Result_RESULT_SUCCESS:
                return mavsdk::Geofence::Result::Success;
            case rpc::geofence::GeofenceResult_Result_RESULT_ERROR:
                return mavsdk::Geofence::Result::Error;
            case rpc::geofence::GeofenceResult_Result_RESULT_TOO_MANY_GEOFENCE_ITEMS:
                return mavsdk::Geofence::Result::TooManyGeofenceItems;
            case rpc::geofence::GeofenceResult_Result_RESULT_BUSY:
                return mavsdk::Geofence::Result::Busy;
            case rpc::geofence::GeofenceResult_Result_RESULT_TIMEOUT:
                return mavsdk::Geofence::Result::Timeout;
            case rpc::geofence::GeofenceResult_Result_RESULT_INVALID_ARGUMENT:
                return mavsdk::Geofence::Result::InvalidArgument;
            case rpc::geofence::GeofenceResult_Result_RESULT_NO_SYSTEM:
                return mavsdk::Geofence::Result::NoSystem;
        }
    }




    grpc::Status UploadGeofence(
        grpc::ServerContext* /* context */,
        const rpc::geofence::UploadGeofenceRequest* request,
        rpc::geofence::UploadGeofenceResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            
            if (response != nullptr) {
                auto result = mavsdk::Geofence::Result::NoSystem;
                fillResponseWithResult(response, result);
            }
            
            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "UploadGeofence sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }
            
        
        auto result = _lazy_plugin.maybe_plugin()->upload_geofence(translateFromRpcGeofenceData(request->geofence_data()));
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status ClearGeofence(
        grpc::ServerContext* /* context */,
        const rpc::geofence::ClearGeofenceRequest* /* request */,
        rpc::geofence::ClearGeofenceResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            
            if (response != nullptr) {
                auto result = mavsdk::Geofence::Result::NoSystem;
                fillResponseWithResult(response, result);
            }
            
            return grpc::Status::OK;
        }

        
        auto result = _lazy_plugin.maybe_plugin()->clear_geofence();
        

        
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