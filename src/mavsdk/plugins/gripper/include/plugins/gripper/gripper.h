// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/main/protos/gripper/gripper.proto)

#pragma once

#include <array>
#include <cmath>
#include <functional>
#include <limits>
#include <memory>
#include <string>
#include <utility>
#include <vector>


#include "plugin_base.h"

#include "handle.h"

namespace mavsdk {


class System;class GripperImpl;

/**
 * @brief 
 */
class Gripper : public PluginBase {
public:

    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto gripper = Gripper(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit Gripper(System& system); // deprecated

    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto gripper = Gripper(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit Gripper(std::shared_ptr<System> system); // new


    /**
     * @brief Destructor (internal use only).
     */
    ~Gripper() override;


    /**
     * @brief 
     */
    enum class GripperAction {
        Release, /**< @brief. */
        Grab, /**< @brief. */
    };

    /**
     * @brief Stream operator to print information about a `Gripper::GripperAction`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Gripper::GripperAction const& gripper_action);





    /**
     * @brief Possible results returned for action requests.
     */
    enum class Result {
        Unknown, /**< @brief Unknown result. */
        Success, /**< @brief Request was successful. */
        NoSystem, /**< @brief No system is connected. */
        ConnectionError, /**< @brief Connection error. */
        Busy, /**< @brief Vehicle is busy. */
        CommandDenied, /**< @brief Command refused by vehicle. */
        CommandDeniedLandedStateUnknown, /**< @brief Command refused because landed state is unknown. */
        CommandDeniedNotLanded, /**< @brief Command refused because vehicle not landed. */
        Timeout, /**< @brief Request timed out. */
        VtolTransitionSupportUnknown, /**< @brief Hybrid/VTOL transition support is unknown. */
        NoVtolTransitionSupport, /**< @brief Vehicle does not support hybrid/VTOL transitions. */
        ParameterError, /**< @brief Error getting or setting parameter. */
        Unsupported, /**< @brief Action not supported. */
        Failed, /**< @brief Action failed. */
    };

    /**
     * @brief Stream operator to print information about a `Gripper::Result`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Gripper::Result const& result);



    /**
     * @brief Callback type for asynchronous Gripper calls.
     */
    using ResultCallback = std::function<void(Result)>;




    /**
     * @brief Gripper grab cargo.
     *
     * This function is non-blocking. See 'gripper_grab' for the blocking counterpart.
     */
    void gripper_grab_async(uint32_t instance, const ResultCallback callback);



    /**
     * @brief Gripper grab cargo.
     *
     * This function is blocking. See 'gripper_grab_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    Result gripper_grab(uint32_t instance) const;




    /**
     * @brief Gripper release cargo.
     *
     * This function is non-blocking. See 'gripper_release' for the blocking counterpart.
     */
    void gripper_release_async(uint32_t instance, const ResultCallback callback);



    /**
     * @brief Gripper release cargo.
     *
     * This function is blocking. See 'gripper_release_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    Result gripper_release(uint32_t instance) const;




    /**
     * @brief Copy constructor.
     */
    Gripper(const Gripper& other);

    /**
     * @brief Equality operator (object is not copyable).
     */
    const Gripper& operator=(const Gripper&) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    std::unique_ptr<GripperImpl> _impl;
};

} // namespace mavsdk