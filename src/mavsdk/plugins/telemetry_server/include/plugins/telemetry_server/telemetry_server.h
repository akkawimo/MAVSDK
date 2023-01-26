// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see
// https://github.com/mavlink/MAVSDK-Proto/blob/main/protos/telemetry_server/telemetry_server.proto)

#pragma once

#include <array>
#include <cmath>
#include <functional>
#include <limits>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "server_plugin_base.h"

#include "handle.h"

namespace mavsdk {

class ServerComponent;
class TelemetryServerImpl;

/**
 * @brief Allow users to provide vehicle telemetry and state information
 * (e.g. battery, GPS, RC connection, flight mode etc.) and set telemetry update rates.
 */
class TelemetryServer : public ServerPluginBase {
public:
    /**
     * @brief Constructor. Creates the plugin for a ServerComponent instance.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto telemetry_server = TelemetryServer(server_component);
     *     ```
     *
     * @param server_component The ServerComponent instance associated with this server plugin.
     */
    explicit TelemetryServer(std::shared_ptr<ServerComponent> server_component);

    /**
     * @brief Destructor (internal use only).
     */
    ~TelemetryServer() override;

    /**
     * @brief GPS fix type.
     */
    enum class FixType {
        NoGps, /**< @brief No GPS connected. */
        NoFix, /**< @brief No position information, GPS is connected. */
        Fix2D, /**< @brief 2D position. */
        Fix3D, /**< @brief 3D position. */
        FixDgps, /**< @brief DGPS/SBAS aided 3D position. */
        RtkFloat, /**< @brief RTK float, 3D position. */
        RtkFixed, /**< @brief RTK Fixed, 3D position. */
    };

    /**
     * @brief Stream operator to print information about a `TelemetryServer::FixType`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, TelemetryServer::FixType const& fix_type);

    /**
     * @brief Maps to MAV_VTOL_STATE
     */
    enum class VtolState {
        Undefined, /**< @brief Not VTOL. */
        TransitionToFw, /**< @brief Transitioning to fixed-wing. */
        TransitionToMc, /**< @brief Transitioning to multi-copter. */
        Mc, /**< @brief Multi-copter. */
        Fw, /**< @brief Fixed-wing. */
    };

    /**
     * @brief Stream operator to print information about a `TelemetryServer::VtolState`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, TelemetryServer::VtolState const& vtol_state);

    /**
     * @brief Status types.
     */
    enum class StatusTextType {
        Debug, /**< @brief Debug. */
        Info, /**< @brief Information. */
        Notice, /**< @brief Notice. */
        Warning, /**< @brief Warning. */
        Error, /**< @brief Error. */
        Critical, /**< @brief Critical. */
        Alert, /**< @brief Alert. */
        Emergency, /**< @brief Emergency. */
    };

    /**
     * @brief Stream operator to print information about a `TelemetryServer::StatusTextType`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, TelemetryServer::StatusTextType const& status_text_type);

    /**
     * @brief Landed State enumeration.
     */
    enum class LandedState {
        Unknown, /**< @brief Landed state is unknown. */
        OnGround, /**< @brief The vehicle is on the ground. */
        InAir, /**< @brief The vehicle is in the air. */
        TakingOff, /**< @brief The vehicle is taking off. */
        Landing, /**< @brief The vehicle is landing. */
    };

    /**
     * @brief Stream operator to print information about a `TelemetryServer::LandedState`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, TelemetryServer::LandedState const& landed_state);

    /**
     * @brief Position type in global coordinates.
     */
    struct Position {
        double latitude_deg{double(NAN)}; /**< @brief Latitude in degrees (range: -90 to +90) */
        double longitude_deg{double(NAN)}; /**< @brief Longitude in degrees (range: -180 to +180) */
        float absolute_altitude_m{
            float(NAN)}; /**< @brief Altitude AMSL (above mean sea level) in metres */
        float relative_altitude_m{
            float(NAN)}; /**< @brief Altitude relative to takeoff altitude in metres */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::Position` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const TelemetryServer::Position& lhs, const TelemetryServer::Position& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::Position`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, TelemetryServer::Position const& position);

    /**
     * @brief Heading type used for global position
     */
    struct Heading {
        double heading_deg{double(NAN)}; /**< @brief Heading in degrees (range: 0 to +360) */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::Heading` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const TelemetryServer::Heading& lhs, const TelemetryServer::Heading& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::Heading`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, TelemetryServer::Heading const& heading);

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
        float w{float(NAN)}; /**< @brief Quaternion entry 0, also denoted as a */
        float x{float(NAN)}; /**< @brief Quaternion entry 1, also denoted as b */
        float y{float(NAN)}; /**< @brief Quaternion entry 2, also denoted as c */
        float z{float(NAN)}; /**< @brief Quaternion entry 3, also denoted as d */
        uint64_t timestamp_us{}; /**< @brief Timestamp in microseconds */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::Quaternion` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const TelemetryServer::Quaternion& lhs, const TelemetryServer::Quaternion& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::Quaternion`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, TelemetryServer::Quaternion const& quaternion);

    /**
     * @brief Euler angle type.
     *
     * All rotations and axis systems follow the right-hand rule.
     * The Euler angles follow the convention of a 3-2-1 intrinsic Tait-Bryan rotation sequence.
     *
     * For more info see https://en.wikipedia.org/wiki/Euler_angles
     */
    struct EulerAngle {
        float roll_deg{
            float(NAN)}; /**< @brief Roll angle in degrees, positive is banking to the right */
        float pitch_deg{
            float(NAN)}; /**< @brief Pitch angle in degrees, positive is pitching nose up */
        float yaw_deg{
            float(NAN)}; /**< @brief Yaw angle in degrees, positive is clock-wise seen from above */
        uint64_t timestamp_us{}; /**< @brief Timestamp in microseconds */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::EulerAngle` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const TelemetryServer::EulerAngle& lhs, const TelemetryServer::EulerAngle& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::EulerAngle`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, TelemetryServer::EulerAngle const& euler_angle);

    /**
     * @brief Angular velocity type.
     */
    struct AngularVelocityBody {
        float roll_rad_s{float(NAN)}; /**< @brief Roll angular velocity */
        float pitch_rad_s{float(NAN)}; /**< @brief Pitch angular velocity */
        float yaw_rad_s{float(NAN)}; /**< @brief Yaw angular velocity */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::AngularVelocityBody` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(
        const TelemetryServer::AngularVelocityBody& lhs,
        const TelemetryServer::AngularVelocityBody& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::AngularVelocityBody`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(
        std::ostream& str, TelemetryServer::AngularVelocityBody const& angular_velocity_body);

    /**
     * @brief GPS information type.
     */
    struct GpsInfo {
        int32_t num_satellites{0}; /**< @brief Number of visible satellites in use */
        FixType fix_type{}; /**< @brief Fix type */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::GpsInfo` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const TelemetryServer::GpsInfo& lhs, const TelemetryServer::GpsInfo& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::GpsInfo`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, TelemetryServer::GpsInfo const& gps_info);

    /**
     * @brief Raw GPS information type.
     *
     * Warning: this is an advanced type! If you want the location of the drone, use
     * the position instead. This message exposes the raw values of the GNSS sensor.
     */
    struct RawGps {
        uint64_t timestamp_us{}; /**< @brief Timestamp in microseconds (UNIX Epoch time or time
                                    since system boot, to be inferred) */
        double latitude_deg{}; /**< @brief Latitude in degrees (WGS84, EGM96 ellipsoid) */
        double longitude_deg{}; /**< @brief Longitude in degrees (WGS84, EGM96 ellipsoid) */
        float absolute_altitude_m{}; /**< @brief Altitude AMSL (above mean sea level) in metres */
        float hdop{}; /**< @brief GPS HDOP horizontal dilution of position (unitless). If unknown,
                         set to NaN */
        float vdop{}; /**< @brief GPS VDOP vertical dilution of position (unitless). If unknown, set
                         to NaN */
        float velocity_m_s{}; /**< @brief Ground velocity in metres per second */
        float cog_deg{}; /**< @brief Course over ground (NOT heading, but direction of movement) in
                            degrees. If unknown, set to NaN */
        float
            altitude_ellipsoid_m{}; /**< @brief Altitude in metres (above WGS84, EGM96 ellipsoid) */
        float horizontal_uncertainty_m{}; /**< @brief Position uncertainty in metres */
        float vertical_uncertainty_m{}; /**< @brief Altitude uncertainty in metres */
        float velocity_uncertainty_m_s{}; /**< @brief Velocity uncertainty in metres per second */
        float heading_uncertainty_deg{}; /**< @brief Heading uncertainty in degrees */
        float yaw_deg{}; /**< @brief Yaw in earth frame from north. */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::RawGps` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const TelemetryServer::RawGps& lhs, const TelemetryServer::RawGps& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::RawGps`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, TelemetryServer::RawGps const& raw_gps);

    /**
     * @brief Battery type.
     */
    struct Battery {
        float voltage_v{float(NAN)}; /**< @brief Voltage in volts */
        float remaining_percent{
            float(NAN)}; /**< @brief Estimated battery remaining (range: 0.0 to 1.0) */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::Battery` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const TelemetryServer::Battery& lhs, const TelemetryServer::Battery& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::Battery`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, TelemetryServer::Battery const& battery);

    /**
     * @brief Remote control status type.
     */
    struct RcStatus {
        bool was_available_once{false}; /**< @brief True if an RC signal has been available once */
        bool is_available{false}; /**< @brief True if the RC signal is available now */
        float signal_strength_percent{
            float(NAN)}; /**< @brief Signal strength (range: 0 to 100, NaN if unknown) */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::RcStatus` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const TelemetryServer::RcStatus& lhs, const TelemetryServer::RcStatus& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::RcStatus`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, TelemetryServer::RcStatus const& rc_status);

    /**
     * @brief StatusText information type.
     */
    struct StatusText {
        StatusTextType type{}; /**< @brief Message type */
        std::string text{}; /**< @brief MAVLink status message */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::StatusText` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const TelemetryServer::StatusText& lhs, const TelemetryServer::StatusText& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::StatusText`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, TelemetryServer::StatusText const& status_text);

    /**
     * @brief Actuator control target type.
     */
    struct ActuatorControlTarget {
        int32_t group{0}; /**< @brief An actuator control group is e.g. 'attitude' for the core
                             flight controls, or 'gimbal' for a payload. */
        std::vector<float>
            controls{}; /**< @brief Controls normed from -1 to 1, where 0 is neutral position. */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::ActuatorControlTarget` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(
        const TelemetryServer::ActuatorControlTarget& lhs,
        const TelemetryServer::ActuatorControlTarget& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::ActuatorControlTarget`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(
        std::ostream& str, TelemetryServer::ActuatorControlTarget const& actuator_control_target);

    /**
     * @brief Actuator output status type.
     */
    struct ActuatorOutputStatus {
        uint32_t active{0}; /**< @brief Active outputs */
        std::vector<float> actuator{}; /**< @brief Servo/motor output values */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::ActuatorOutputStatus` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(
        const TelemetryServer::ActuatorOutputStatus& lhs,
        const TelemetryServer::ActuatorOutputStatus& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::ActuatorOutputStatus`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(
        std::ostream& str, TelemetryServer::ActuatorOutputStatus const& actuator_output_status);

    /**
     * @brief Covariance type.
     *
     * Row-major representation of a 6x6 cross-covariance matrix
     * upper right triangle.
     * Set first to NaN if unknown.
     */
    struct Covariance {
        std::vector<float>
            covariance_matrix{}; /**< @brief Representation of a covariance matrix. */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::Covariance` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const TelemetryServer::Covariance& lhs, const TelemetryServer::Covariance& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::Covariance`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, TelemetryServer::Covariance const& covariance);

    /**
     * @brief Velocity type, represented in the Body (X Y Z) frame and in metres/second.
     */
    struct VelocityBody {
        float x_m_s{}; /**< @brief Velocity in X in metres/second */
        float y_m_s{}; /**< @brief Velocity in Y in metres/second */
        float z_m_s{}; /**< @brief Velocity in Z in metres/second */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::VelocityBody` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const TelemetryServer::VelocityBody& lhs, const TelemetryServer::VelocityBody& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::VelocityBody`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, TelemetryServer::VelocityBody const& velocity_body);

    /**
     * @brief Position type, represented in the Body (X Y Z) frame
     */
    struct PositionBody {
        float x_m{}; /**< @brief X Position in metres. */
        float y_m{}; /**< @brief Y Position in metres. */
        float z_m{}; /**< @brief Z Position in metres. */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::PositionBody` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const TelemetryServer::PositionBody& lhs, const TelemetryServer::PositionBody& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::PositionBody`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, TelemetryServer::PositionBody const& position_body);

    /**
     * @brief Odometry message type.
     */
    struct Odometry {
        /**
         * @brief Mavlink frame id
         */
        enum class MavFrame {
            Undef, /**< @brief Frame is undefined.. */
            BodyNed, /**< @brief Setpoint in body NED frame. This makes sense if all position
                        control is externalized - e.g. useful to command 2 m/s^2 acceleration to the
                        right.. */
            VisionNed, /**< @brief Odometry local coordinate frame of data given by a vision
                          estimation system, Z-down (x: north, y: east, z: down).. */
            EstimNed, /**< @brief Odometry local coordinate frame of data given by an estimator
                         running onboard the vehicle, Z-down (x: north, y: east, z: down).. */
        };

        /**
         * @brief Stream operator to print information about a `TelemetryServer::MavFrame`.
         *
         * @return A reference to the stream.
         */
        friend std::ostream&
        operator<<(std::ostream& str, TelemetryServer::Odometry::MavFrame const& mav_frame);

        uint64_t time_usec{}; /**< @brief Timestamp (0 to use Backend timestamp). */
        MavFrame frame_id{}; /**< @brief Coordinate frame of reference for the pose data. */
        MavFrame child_frame_id{}; /**< @brief Coordinate frame of reference for the velocity in
                                      free space (twist) data. */
        PositionBody position_body{}; /**< @brief Position. */
        Quaternion
            q{}; /**< @brief Quaternion components, w, x, y, z (1 0 0 0 is the null-rotation). */
        VelocityBody velocity_body{}; /**< @brief Linear velocity (m/s). */
        AngularVelocityBody angular_velocity_body{}; /**< @brief Angular velocity (rad/s). */
        Covariance pose_covariance{}; /**< @brief Pose cross-covariance matrix. */
        Covariance velocity_covariance{}; /**< @brief Velocity cross-covariance matrix. */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::Odometry` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const TelemetryServer::Odometry& lhs, const TelemetryServer::Odometry& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::Odometry`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, TelemetryServer::Odometry const& odometry);

    /**
     * @brief DistanceSensor message type.
     */
    struct DistanceSensor {
        float minimum_distance_m{
            float(NAN)}; /**< @brief Minimum distance the sensor can measure, NaN if unknown. */
        float maximum_distance_m{
            float(NAN)}; /**< @brief Maximum distance the sensor can measure, NaN if unknown. */
        float current_distance_m{
            float(NAN)}; /**< @brief Current distance reading, NaN if unknown. */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::DistanceSensor` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(
        const TelemetryServer::DistanceSensor& lhs, const TelemetryServer::DistanceSensor& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::DistanceSensor`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, TelemetryServer::DistanceSensor const& distance_sensor);

    /**
     * @brief Scaled Pressure message type.
     */
    struct ScaledPressure {
        uint64_t timestamp_us{}; /**< @brief Timestamp (time since system boot) */
        float absolute_pressure_hpa{}; /**< @brief Absolute pressure in hPa */
        float differential_pressure_hpa{}; /**< @brief Differential pressure 1 in hPa */
        float temperature_deg{}; /**< @brief Absolute pressure temperature (in celsius) */
        float differential_pressure_temperature_deg{}; /**< @brief Differential pressure temperature
                                                          (in celsius, 0 if not available) */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::ScaledPressure` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(
        const TelemetryServer::ScaledPressure& lhs, const TelemetryServer::ScaledPressure& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::ScaledPressure`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, TelemetryServer::ScaledPressure const& scaled_pressure);

    /**
     * @brief PositionNed message type.
     */
    struct PositionNed {
        float north_m{float(NAN)}; /**< @brief Position along north direction in metres */
        float east_m{float(NAN)}; /**< @brief Position along east direction in metres */
        float down_m{float(NAN)}; /**< @brief Position along down direction in metres */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::PositionNed` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const TelemetryServer::PositionNed& lhs, const TelemetryServer::PositionNed& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::PositionNed`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, TelemetryServer::PositionNed const& position_ned);

    /**
     * @brief VelocityNed message type.
     */
    struct VelocityNed {
        float north_m_s{}; /**< @brief Velocity along north direction in metres per second */
        float east_m_s{}; /**< @brief Velocity along east direction in metres per second */
        float down_m_s{}; /**< @brief Velocity along down direction in metres per second */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::VelocityNed` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const TelemetryServer::VelocityNed& lhs, const TelemetryServer::VelocityNed& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::VelocityNed`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, TelemetryServer::VelocityNed const& velocity_ned);

    /**
     * @brief PositionVelocityNed message type.
     */
    struct PositionVelocityNed {
        PositionNed position{}; /**< @brief Position (NED) */
        VelocityNed velocity{}; /**< @brief Velocity (NED) */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::PositionVelocityNed` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(
        const TelemetryServer::PositionVelocityNed& lhs,
        const TelemetryServer::PositionVelocityNed& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::PositionVelocityNed`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(
        std::ostream& str, TelemetryServer::PositionVelocityNed const& position_velocity_ned);

    /**
     * @brief GroundTruth message type.
     */
    struct GroundTruth {
        double latitude_deg{double(NAN)}; /**< @brief Latitude in degrees (range: -90 to +90) */
        double longitude_deg{double(NAN)}; /**< @brief Longitude in degrees (range: -180 to 180) */
        float absolute_altitude_m{
            float(NAN)}; /**< @brief Altitude AMSL (above mean sea level) in metres */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::GroundTruth` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const TelemetryServer::GroundTruth& lhs, const TelemetryServer::GroundTruth& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::GroundTruth`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, TelemetryServer::GroundTruth const& ground_truth);

    /**
     * @brief FixedwingMetrics message type.
     */
    struct FixedwingMetrics {
        float airspeed_m_s{
            float(NAN)}; /**< @brief Current indicated airspeed (IAS) in metres per second */
        float throttle_percentage{float(NAN)}; /**< @brief Current throttle setting (0 to 100) */
        float climb_rate_m_s{float(NAN)}; /**< @brief Current climb rate in metres per second */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::FixedwingMetrics` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(
        const TelemetryServer::FixedwingMetrics& lhs, const TelemetryServer::FixedwingMetrics& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::FixedwingMetrics`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, TelemetryServer::FixedwingMetrics const& fixedwing_metrics);

    /**
     * @brief AccelerationFrd message type.
     */
    struct AccelerationFrd {
        float forward_m_s2{
            float(NAN)}; /**< @brief Acceleration in forward direction in metres per second^2 */
        float right_m_s2{
            float(NAN)}; /**< @brief Acceleration in right direction in metres per second^2 */
        float down_m_s2{
            float(NAN)}; /**< @brief Acceleration in down direction in metres per second^2 */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::AccelerationFrd` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(
        const TelemetryServer::AccelerationFrd& lhs, const TelemetryServer::AccelerationFrd& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::AccelerationFrd`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, TelemetryServer::AccelerationFrd const& acceleration_frd);

    /**
     * @brief AngularVelocityFrd message type.
     */
    struct AngularVelocityFrd {
        float forward_rad_s{
            float(NAN)}; /**< @brief Angular velocity in forward direction in radians per second */
        float right_rad_s{
            float(NAN)}; /**< @brief Angular velocity in right direction in radians per second */
        float down_rad_s{
            float(NAN)}; /**< @brief Angular velocity in Down direction in radians per second */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::AngularVelocityFrd` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(
        const TelemetryServer::AngularVelocityFrd& lhs,
        const TelemetryServer::AngularVelocityFrd& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::AngularVelocityFrd`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, TelemetryServer::AngularVelocityFrd const& angular_velocity_frd);

    /**
     * @brief MagneticFieldFrd message type.
     */
    struct MagneticFieldFrd {
        float forward_gauss{
            float(NAN)}; /**< @brief Magnetic field in forward direction measured in Gauss */
        float right_gauss{
            float(NAN)}; /**< @brief Magnetic field in East direction measured in Gauss */
        float down_gauss{
            float(NAN)}; /**< @brief Magnetic field in Down direction measured in Gauss */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::MagneticFieldFrd` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(
        const TelemetryServer::MagneticFieldFrd& lhs, const TelemetryServer::MagneticFieldFrd& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::MagneticFieldFrd`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, TelemetryServer::MagneticFieldFrd const& magnetic_field_frd);

    /**
     * @brief Imu message type.
     */
    struct Imu {
        AccelerationFrd acceleration_frd{}; /**< @brief Acceleration */
        AngularVelocityFrd angular_velocity_frd{}; /**< @brief Angular velocity */
        MagneticFieldFrd magnetic_field_frd{}; /**< @brief Magnetic field */
        float temperature_degc{float(NAN)}; /**< @brief Temperature */
        uint64_t timestamp_us{}; /**< @brief Timestamp in microseconds */
    };

    /**
     * @brief Equal operator to compare two `TelemetryServer::Imu` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const TelemetryServer::Imu& lhs, const TelemetryServer::Imu& rhs);

    /**
     * @brief Stream operator to print information about a `TelemetryServer::Imu`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, TelemetryServer::Imu const& imu);

    /**
     * @brief Possible results returned for telemetry requests.
     */
    enum class Result {
        Unknown, /**< @brief Unknown result. */
        Success, /**< @brief Success: the telemetry command was accepted by the vehicle. */
        NoSystem, /**< @brief No system connected. */
        ConnectionError, /**< @brief Connection error. */
        Busy, /**< @brief Vehicle is busy. */
        CommandDenied, /**< @brief Command refused by vehicle. */
        Timeout, /**< @brief Request timed out. */
        Unsupported, /**< @brief Request not supported. */
    };

    /**
     * @brief Stream operator to print information about a `TelemetryServer::Result`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, TelemetryServer::Result const& result);

    /**
     * @brief Callback type for asynchronous TelemetryServer calls.
     */
    using ResultCallback = std::function<void(Result)>;

    /**
     * @brief Publish to 'position' updates.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result publish_position(Position position, VelocityNed velocity_ned, Heading heading) const;

    /**
     * @brief Publish to 'home position' updates.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result publish_home(Position home) const;

    /**
     * @brief Publish 'sys status' updates.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result publish_sys_status(
        Battery battery,
        bool rc_receiver_status,
        bool gyro_status,
        bool accel_status,
        bool mag_status,
        bool gps_status) const;

    /**
     * @brief Publish 'extended sys state' updates.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result publish_extended_sys_state(VtolState vtol_state, LandedState landed_state) const;

    /**
     * @brief Publish to 'Raw GPS' updates.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result publish_raw_gps(RawGps raw_gps, GpsInfo gps_info) const;

    /**
     * @brief Publish to 'battery' updates.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result publish_battery(Battery battery) const;

    /**
     * @brief Publish to 'status text' updates.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result publish_status_text(StatusText status_text) const;

    /**
     * @brief Publish to 'odometry' updates.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result publish_odometry(Odometry odometry) const;

    /**
     * @brief Publish to 'position velocity' updates.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result publish_position_velocity_ned(PositionVelocityNed position_velocity_ned) const;

    /**
     * @brief Publish to 'ground truth' updates.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result publish_ground_truth(GroundTruth ground_truth) const;

    /**
     * @brief Publish to 'IMU' updates (in SI units in NED body frame).
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result publish_imu(Imu imu) const;

    /**
     * @brief Publish to 'Scaled IMU' updates.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result publish_scaled_imu(Imu imu) const;

    /**
     * @brief Publish to 'Raw IMU' updates.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result publish_raw_imu(Imu imu) const;

    /**
     * @brief Publish to 'unix epoch time' updates.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result publish_unix_epoch_time(uint64_t time_us) const;

    /**
     * @brief Publish to "distance sensor" updates.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result publish_distance_sensor(DistanceSensor distance_sensor) const;

    /**
     * @brief Copy constructor.
     */
    TelemetryServer(const TelemetryServer& other);

    /**
     * @brief Equality operator (object is not copyable).
     */
    const TelemetryServer& operator=(const TelemetryServer&) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    std::unique_ptr<TelemetryServerImpl> _impl;
};

} // namespace mavsdk