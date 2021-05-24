// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/log_files/log_files.proto)

#include "log_files/log_files.grpc.pb.h"
#include "plugins/log_files/log_files.h"

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

template<typename LogFiles = LogFiles, typename LazyPlugin = LazyPlugin<LogFiles>>
class LogFilesServiceImpl final : public rpc::log_files::LogFilesService::Service {
public:
    LogFilesServiceImpl(LazyPlugin& lazy_plugin) : _lazy_plugin(lazy_plugin) {}

    template<typename ResponseType>
    void fillResponseWithResult(ResponseType* response, mavsdk::LogFiles::Result& result) const
    {
        auto rpc_result = translateToRpcResult(result);

        auto* rpc_log_files_result = new rpc::log_files::LogFilesResult();
        rpc_log_files_result->set_result(rpc_result);
        std::stringstream ss;
        ss << result;
        rpc_log_files_result->set_result_str(ss.str());

        response->set_allocated_log_files_result(rpc_log_files_result);
    }

    static std::unique_ptr<rpc::log_files::ProgressData>
    translateToRpcProgressData(const mavsdk::LogFiles::ProgressData& progress_data)
    {
        auto rpc_obj = std::make_unique<rpc::log_files::ProgressData>();

        rpc_obj->set_progress(progress_data.progress);

        return rpc_obj;
    }

    static mavsdk::LogFiles::ProgressData
    translateFromRpcProgressData(const rpc::log_files::ProgressData& progress_data)
    {
        mavsdk::LogFiles::ProgressData obj;

        obj.progress = progress_data.progress();

        return obj;
    }

    static std::unique_ptr<rpc::log_files::Entry>
    translateToRpcEntry(const mavsdk::LogFiles::Entry& entry)
    {
        auto rpc_obj = std::make_unique<rpc::log_files::Entry>();

        rpc_obj->set_id(entry.id);

        rpc_obj->set_date(entry.date);

        rpc_obj->set_size_bytes(entry.size_bytes);

        return rpc_obj;
    }

    static mavsdk::LogFiles::Entry translateFromRpcEntry(const rpc::log_files::Entry& entry)
    {
        mavsdk::LogFiles::Entry obj;

        obj.id = entry.id();

        obj.date = entry.date();

        obj.size_bytes = entry.size_bytes();

        return obj;
    }

    static rpc::log_files::LogFilesResult::Result
    translateToRpcResult(const mavsdk::LogFiles::Result& result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case mavsdk::LogFiles::Result::Unknown:
                return rpc::log_files::LogFilesResult_Result_RESULT_UNKNOWN;
            case mavsdk::LogFiles::Result::Success:
                return rpc::log_files::LogFilesResult_Result_RESULT_SUCCESS;
            case mavsdk::LogFiles::Result::Next:
                return rpc::log_files::LogFilesResult_Result_RESULT_NEXT;
            case mavsdk::LogFiles::Result::NoLogfiles:
                return rpc::log_files::LogFilesResult_Result_RESULT_NO_LOGFILES;
            case mavsdk::LogFiles::Result::Timeout:
                return rpc::log_files::LogFilesResult_Result_RESULT_TIMEOUT;
            case mavsdk::LogFiles::Result::InvalidArgument:
                return rpc::log_files::LogFilesResult_Result_RESULT_INVALID_ARGUMENT;
            case mavsdk::LogFiles::Result::FileOpenFailed:
                return rpc::log_files::LogFilesResult_Result_RESULT_FILE_OPEN_FAILED;
            case mavsdk::LogFiles::Result::NoSystem:
                return rpc::log_files::LogFilesResult_Result_RESULT_NO_SYSTEM;
        }
    }

    static mavsdk::LogFiles::Result
    translateFromRpcResult(const rpc::log_files::LogFilesResult::Result result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case rpc::log_files::LogFilesResult_Result_RESULT_UNKNOWN:
                return mavsdk::LogFiles::Result::Unknown;
            case rpc::log_files::LogFilesResult_Result_RESULT_SUCCESS:
                return mavsdk::LogFiles::Result::Success;
            case rpc::log_files::LogFilesResult_Result_RESULT_NEXT:
                return mavsdk::LogFiles::Result::Next;
            case rpc::log_files::LogFilesResult_Result_RESULT_NO_LOGFILES:
                return mavsdk::LogFiles::Result::NoLogfiles;
            case rpc::log_files::LogFilesResult_Result_RESULT_TIMEOUT:
                return mavsdk::LogFiles::Result::Timeout;
            case rpc::log_files::LogFilesResult_Result_RESULT_INVALID_ARGUMENT:
                return mavsdk::LogFiles::Result::InvalidArgument;
            case rpc::log_files::LogFilesResult_Result_RESULT_FILE_OPEN_FAILED:
                return mavsdk::LogFiles::Result::FileOpenFailed;
            case rpc::log_files::LogFilesResult_Result_RESULT_NO_SYSTEM:
                return mavsdk::LogFiles::Result::NoSystem;
        }
    }

    grpc::Status GetEntries(
        grpc::ServerContext* /* context */,
        const rpc::log_files::GetEntriesRequest* /* request */,
        rpc::log_files::GetEntriesResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::LogFiles::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->get_entries();

        if (response != nullptr) {
            fillResponseWithResult(response, result.first);

            for (auto elem : result.second) {
                auto* ptr = response->add_entries();
                ptr->CopyFrom(*translateToRpcEntry(elem).release());
            }
        }

        return grpc::Status::OK;
    }

    grpc::Status SubscribeDownloadLogFile(
        grpc::ServerContext* /* context */,
        const mavsdk::rpc::log_files::SubscribeDownloadLogFileRequest* request,
        grpc::ServerWriter<rpc::log_files::DownloadLogFileResponse>* writer) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            rpc::log_files::DownloadLogFileResponse rpc_response;
            auto result = mavsdk::LogFiles::Result::NoSystem;
            fillResponseWithResult(&rpc_response, result);
            writer->Write(rpc_response);

            return grpc::Status::OK;
        }

        auto stream_closed_promise = std::make_shared<std::promise<void>>();
        auto stream_closed_future = stream_closed_promise->get_future();
        register_stream_stop_promise(stream_closed_promise);

        auto is_finished = std::make_shared<bool>(false);
        auto subscribe_mutex = std::make_shared<std::mutex>();

        _lazy_plugin.maybe_plugin()->download_log_file_async(
            translateFromRpcEntry(request->entry()),
            request->path(),
            [this, &writer, &stream_closed_promise, is_finished, subscribe_mutex](
                mavsdk::LogFiles::Result result,
                const mavsdk::LogFiles::ProgressData download_log_file) {
                rpc::log_files::DownloadLogFileResponse rpc_response;

                rpc_response.set_allocated_progress(
                    translateToRpcProgressData(download_log_file).release());

                auto rpc_result = translateToRpcResult(result);
                auto* rpc_log_files_result = new rpc::log_files::LogFilesResult();
                rpc_log_files_result->set_result(rpc_result);
                std::stringstream ss;
                ss << result;
                rpc_log_files_result->set_result_str(ss.str());
                rpc_response.set_allocated_log_files_result(rpc_log_files_result);

                std::unique_lock<std::mutex> lock(*subscribe_mutex);
                if (!*is_finished && !writer->Write(rpc_response)) {
                    *is_finished = true;
                    unregister_stream_stop_promise(stream_closed_promise);
                    stream_closed_promise->set_value();
                }
            });

        stream_closed_future.wait();
        std::unique_lock<std::mutex> lock(*subscribe_mutex);
        *is_finished = true;

        return grpc::Status::OK;
    }

    void stop()
    {
        _stopped.store(true);
        for (auto& prom : _stream_stop_promises) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        }
    }

private:
    void register_stream_stop_promise(std::weak_ptr<std::promise<void>> prom)
    {
        // If we have already stopped, set promise immediately and don't add it to list.
        if (_stopped.load()) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        } else {
            _stream_stop_promises.push_back(prom);
        }
    }

    void unregister_stream_stop_promise(std::shared_ptr<std::promise<void>> prom)
    {
        for (auto it = _stream_stop_promises.begin(); it != _stream_stop_promises.end();
             /* ++it */) {
            if (it->lock() == prom) {
                it = _stream_stop_promises.erase(it);
            } else {
                ++it;
            }
        }
    }

    LazyPlugin& _lazy_plugin;
    std::atomic<bool> _stopped{false};
    std::vector<std::weak_ptr<std::promise<void>>> _stream_stop_promises{};
};

} // namespace mavsdk_server
} // namespace mavsdk