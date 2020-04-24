// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/mocap/mocap.proto)

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

namespace mavsdk {

class System;
class MocapImpl;

/**
 * @brief *
 * Allows interfacing a vehicle with a motion capture system in
 * order to allow navigation without global positioning sources available
 * (e.g. indoors, or when flying under a bridge. etc.).
 */
class Mocap : public PluginBase {
public:
    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto mocap = std::make_shared<Mocap>(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit Mocap(System& system);

    /**
     * @brief Destructor (internal use only).
     */
    ~Mocap();

    /**
     * @brief Body position type
     */
    struct PositionBody {
        float x_m{}; /**< @brief X position in metres. */
        float y_m{}; /**< @brief Y position in metres. */
        float z_m{}; /**< @brief Z position in metres. */
    };

    /**
     * @brief Equal operator to compare two `Mocap::PositionBody` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Mocap::PositionBody& lhs, const Mocap::PositionBody& rhs);

    /**
     * @brief Stream operator to print information about a `Mocap::PositionBody`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Mocap::PositionBody const& position_body);

    /**
     * @brief Body angle type
     */
    struct AngleBody {
        float roll_rad{}; /**< @brief Roll angle in radians. */
        float pitch_rad{}; /**< @brief Pitch angle in radians. */
        float yaw_rad{}; /**< @brief Yaw angle in radians. */
    };

    /**
     * @brief Equal operator to compare two `Mocap::AngleBody` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Mocap::AngleBody& lhs, const Mocap::AngleBody& rhs);

    /**
     * @brief Stream operator to print information about a `Mocap::AngleBody`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Mocap::AngleBody const& angle_body);

    /**
     * @brief Speed type, represented in the Body (X Y Z) frame and in metres/second.
     */
    struct SpeedBody {
        float x_m_s{}; /**< @brief Velocity in X in metres/second. */
        float y_m_s{}; /**< @brief Velocity in Y in metres/second. */
        float z_m_s{}; /**< @brief Velocity in Z in metres/second. */
    };

    /**
     * @brief Equal operator to compare two `Mocap::SpeedBody` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Mocap::SpeedBody& lhs, const Mocap::SpeedBody& rhs);

    /**
     * @brief Stream operator to print information about a `Mocap::SpeedBody`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Mocap::SpeedBody const& speed_body);

    /**
     * @brief Angular velocity type
     */
    struct AngularVelocityBody {
        float roll_rad_s{}; /**< @brief Roll angular velocity in radians/second. */
        float pitch_rad_s{}; /**< @brief Pitch angular velocity in radians/second. */
        float yaw_rad_s{}; /**< @brief Yaw angular velocity in radians/second. */
    };

    /**
     * @brief Equal operator to compare two `Mocap::AngularVelocityBody` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const Mocap::AngularVelocityBody& lhs, const Mocap::AngularVelocityBody& rhs);

    /**
     * @brief Stream operator to print information about a `Mocap::AngularVelocityBody`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, Mocap::AngularVelocityBody const& angular_velocity_body);

    /**
     * @brief Covariance type.
     * Row-major representation of a 6x6 cross-covariance matrix upper
     * right triangle.
     * Needs to be 21 entries or 1 entry with NaN if unknown.
     */
    struct Covariance {
        std::vector<float> covariance_matrix{}; /**< @brief The covariance matrix */
    };

    /**
     * @brief Equal operator to compare two `Mocap::Covariance` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Mocap::Covariance& lhs, const Mocap::Covariance& rhs);

    /**
     * @brief Stream operator to print information about a `Mocap::Covariance`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Mocap::Covariance const& covariance);

    /**
     * @brief Quaternion type.
     *
     * All rotations and axis systems follow the right-hand rule.
     * The Hamilton quaternion product definition is used.
     * A zero-rotation quaternion is represented by (1,0,0,0).
     * The quaternion could also be written as w + xi + yj + zk.
     *
     * For more info see: https://en.wikipedia.org/wiki/Quaternion
     */
    struct Quaternion {
        float w{}; /**< @brief Quaternion entry 0, also denoted as a */
        float x{}; /**< @brief Quaternion entry 1, also denoted as b */
        float y{}; /**< @brief Quaternion entry 2, also denoted as c */
        float z{}; /**< @brief Quaternion entry 3, also denoted as d */
    };

    /**
     * @brief Equal operator to compare two `Mocap::Quaternion` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Mocap::Quaternion& lhs, const Mocap::Quaternion& rhs);

    /**
     * @brief Stream operator to print information about a `Mocap::Quaternion`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Mocap::Quaternion const& quaternion);

    /**
     * @brief Global position/attitude estimate from a vision source.
     */
    struct VisionPositionEstimate {
        uint64_t time_usec{}; /**< @brief PositionBody frame timestamp UNIX Epoch time (0 to use
                                 Backend timestamp) */
        PositionBody position_body{}; /**< @brief Global position (m) */
        AngleBody angle_body{}; /**< @brief Body angle (rad). */
        Covariance pose_covariance{}; /**< @brief Pose cross-covariance matrix. */
    };

    /**
     * @brief Equal operator to compare two `Mocap::VisionPositionEstimate` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const Mocap::VisionPositionEstimate& lhs, const Mocap::VisionPositionEstimate& rhs);

    /**
     * @brief Stream operator to print information about a `Mocap::VisionPositionEstimate`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, Mocap::VisionPositionEstimate const& vision_position_estimate);

    /**
     * @brief Motion capture attitude and position
     */
    struct AttitudePositionMocap {
        uint64_t time_usec{}; /**< @brief PositionBody frame timestamp UNIX Epoch time (0 to use
                                 Backend timestamp) */
        Quaternion
            q{}; /**< @brief Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0) */
        PositionBody position_body{}; /**< @brief Body Position (NED) */
        Covariance pose_covariance{}; /**< @brief Pose cross-covariance matrix. */
    };

    /**
     * @brief Equal operator to compare two `Mocap::AttitudePositionMocap` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const Mocap::AttitudePositionMocap& lhs, const Mocap::AttitudePositionMocap& rhs);

    /**
     * @brief Stream operator to print information about a `Mocap::AttitudePositionMocap`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, Mocap::AttitudePositionMocap const& attitude_position_mocap);

    /**
     * @brief Odometry message to communicate odometry information with an external interface.
     */
    struct Odometry {
        /**
         * @brief Mavlink frame id
         */
        enum class MavFrame {
            MocapNed, /**< @brief MAVLink number: 14. Odometry local coordinate frame of data given
                         by a motion capture system, Z-down (x: north, y: east, z: down).. */
            LocalFrd, /**< @brief MAVLink number: 20. Forward, Right, Down coordinate frame. This is
                         a local frame with Z-down and arbitrary F/R alignment (i.e. not aligned
                         with NED/earth frame). Replacement for MAV_FRAME_MOCAP_NED,
                         MAV_FRAME_VISION_NED, MAV_FRAME_ESTIM_NED.. */
        };

        /**
         * @brief Stream operator to print information about a `Mocap::MavFrame`.
         *
         * @return A reference to the stream.
         */
        friend std::ostream&
        operator<<(std::ostream& str, Mocap::Odometry::MavFrame const& mav_frame);

        uint64_t time_usec{}; /**< @brief Timestamp (0 to use Backend timestamp). */
        MavFrame frame_id{}; /**< @brief Coordinate frame of reference for the pose data. */
        PositionBody position_body{}; /**< @brief Body Position. */
        Quaternion
            q{}; /**< @brief Quaternion components, w, x, y, z (1 0 0 0 is the null-rotation). */
        SpeedBody speed_body{}; /**< @brief Linear speed (m/s). */
        AngularVelocityBody angular_velocity_body{}; /**< @brief Angular speed (rad/s). */
        Covariance pose_covariance{}; /**< @brief Pose cross-covariance matrix. */
        Covariance velocity_covariance{}; /**< @brief Velocity cross-covariance matrix. */
    };

    /**
     * @brief Equal operator to compare two `Mocap::Odometry` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Mocap::Odometry& lhs, const Mocap::Odometry& rhs);

    /**
     * @brief Stream operator to print information about a `Mocap::Odometry`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Mocap::Odometry const& odometry);

    /**
     * @brief Possible results returned for mocap requests
     */
    enum class Result {
        Unknown, /**< @brief Unknown error. */
        Success, /**< @brief Request succeeded. */
        NoSystem, /**< @brief No system is connected. */
        ConnectionError, /**< @brief Connection error. */
        InvalidRequestData, /**< @brief Invalid request data. */
    };

    /**
     * @brief Stream operator to print information about a `Mocap::Result`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Mocap::Result const& result);

    /**
     * @brief Callback type for asynchronous Mocap calls.
     */
    typedef std::function<void(Result)> result_callback_t;

    /**
     * @brief Synchronous wrapper for set_vision_position_estimate_async().
     *
     * @return Result of request.
     */
    Result set_vision_position_estimate(VisionPositionEstimate vision_position_estimate) const;

    /**
     * @brief Synchronous wrapper for set_attitude_position_mocap_async().
     *
     * @return Result of request.
     */
    Result set_attitude_position_mocap(AttitudePositionMocap attitude_position_mocap) const;

    /**
     * @brief Synchronous wrapper for set_odometry_async().
     *
     * @return Result of request.
     */
    Result set_odometry(Odometry odometry) const;

    /**
     * @brief Returns a human-readable English string for a Result.
     *
     * @param result The enum value for which a human readable string is required.
     * @return Human readable string for the Result.
     */
    static const char* result_str(Result result);

    /**
     * @brief Copy constructor (object is not copyable).
     */
    Mocap(const Mocap&) = delete;

    /**
     * @brief Equality operator (object is not copyable).
     */
    const Mocap& operator=(const Mocap&) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    std::unique_ptr<MocapImpl> _impl;
};

} // namespace mavsdk