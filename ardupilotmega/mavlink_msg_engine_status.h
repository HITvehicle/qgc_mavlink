#pragma once
// MESSAGE ENGINE_STATUS PACKING

#define MAVLINK_MSG_ID_ENGINE_STATUS 166


typedef struct __mavlink_engine_status_t {
 uint64_t timestamp; /*<  Timestamp in milliseconds since system boot*/
 uint16_t engine_rpm[6]; /*<  engine rpm, unit rpm.*/
 int16_t pos_sensor_left_roll; /*<  left roll servo pos.*/
 int16_t pos_sensor_right_roll; /*<  right roll servo pos.*/
 int16_t pos_sensor_left_pitch; /*<  left pitch servo pos.*/
 int16_t pos_sensor_right_pitch; /*<  right pitch servo pos.*/
 uint8_t engine_state[6]; /*<  engine state.*/
 uint8_t vehicle_oil; /*<  vehicle oil, uint mm.*/
} mavlink_engine_status_t;

#define MAVLINK_MSG_ID_ENGINE_STATUS_LEN 35
#define MAVLINK_MSG_ID_ENGINE_STATUS_MIN_LEN 35
#define MAVLINK_MSG_ID_166_LEN 35
#define MAVLINK_MSG_ID_166_MIN_LEN 35

#define MAVLINK_MSG_ID_ENGINE_STATUS_CRC 179
#define MAVLINK_MSG_ID_166_CRC 179

#define MAVLINK_MSG_ENGINE_STATUS_FIELD_ENGINE_RPM_LEN 6
#define MAVLINK_MSG_ENGINE_STATUS_FIELD_ENGINE_STATE_LEN 6

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ENGINE_STATUS { \
    166, \
    "ENGINE_STATUS", \
    8, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_engine_status_t, timestamp) }, \
         { "engine_rpm", NULL, MAVLINK_TYPE_UINT16_T, 6, 8, offsetof(mavlink_engine_status_t, engine_rpm) }, \
         { "engine_state", NULL, MAVLINK_TYPE_UINT8_T, 6, 28, offsetof(mavlink_engine_status_t, engine_state) }, \
         { "pos_sensor_left_roll", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_engine_status_t, pos_sensor_left_roll) }, \
         { "pos_sensor_right_roll", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_engine_status_t, pos_sensor_right_roll) }, \
         { "pos_sensor_left_pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_engine_status_t, pos_sensor_left_pitch) }, \
         { "pos_sensor_right_pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 26, offsetof(mavlink_engine_status_t, pos_sensor_right_pitch) }, \
         { "vehicle_oil", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_engine_status_t, vehicle_oil) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ENGINE_STATUS { \
    "ENGINE_STATUS", \
    8, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_engine_status_t, timestamp) }, \
         { "engine_rpm", NULL, MAVLINK_TYPE_UINT16_T, 6, 8, offsetof(mavlink_engine_status_t, engine_rpm) }, \
         { "engine_state", NULL, MAVLINK_TYPE_UINT8_T, 6, 28, offsetof(mavlink_engine_status_t, engine_state) }, \
         { "pos_sensor_left_roll", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_engine_status_t, pos_sensor_left_roll) }, \
         { "pos_sensor_right_roll", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_engine_status_t, pos_sensor_right_roll) }, \
         { "pos_sensor_left_pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_engine_status_t, pos_sensor_left_pitch) }, \
         { "pos_sensor_right_pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 26, offsetof(mavlink_engine_status_t, pos_sensor_right_pitch) }, \
         { "vehicle_oil", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_engine_status_t, vehicle_oil) }, \
         } \
}
#endif

/**
 * @brief Pack a engine_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  Timestamp in milliseconds since system boot
 * @param engine_rpm  engine rpm, unit rpm.
 * @param engine_state  engine state.
 * @param pos_sensor_left_roll  left roll servo pos.
 * @param pos_sensor_right_roll  right roll servo pos.
 * @param pos_sensor_left_pitch  left pitch servo pos.
 * @param pos_sensor_right_pitch  right pitch servo pos.
 * @param vehicle_oil  vehicle oil, uint mm.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_engine_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, const uint16_t *engine_rpm, const uint8_t *engine_state, int16_t pos_sensor_left_roll, int16_t pos_sensor_right_roll, int16_t pos_sensor_left_pitch, int16_t pos_sensor_right_pitch, uint8_t vehicle_oil)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ENGINE_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_int16_t(buf, 20, pos_sensor_left_roll);
    _mav_put_int16_t(buf, 22, pos_sensor_right_roll);
    _mav_put_int16_t(buf, 24, pos_sensor_left_pitch);
    _mav_put_int16_t(buf, 26, pos_sensor_right_pitch);
    _mav_put_uint8_t(buf, 34, vehicle_oil);
    _mav_put_uint16_t_array(buf, 8, engine_rpm, 6);
    _mav_put_uint8_t_array(buf, 28, engine_state, 6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ENGINE_STATUS_LEN);
#else
    mavlink_engine_status_t packet;
    packet.timestamp = timestamp;
    packet.pos_sensor_left_roll = pos_sensor_left_roll;
    packet.pos_sensor_right_roll = pos_sensor_right_roll;
    packet.pos_sensor_left_pitch = pos_sensor_left_pitch;
    packet.pos_sensor_right_pitch = pos_sensor_right_pitch;
    packet.vehicle_oil = vehicle_oil;
    mav_array_memcpy(packet.engine_rpm, engine_rpm, sizeof(uint16_t)*6);
    mav_array_memcpy(packet.engine_state, engine_state, sizeof(uint8_t)*6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ENGINE_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ENGINE_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ENGINE_STATUS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_STATUS_LEN, MAVLINK_MSG_ID_ENGINE_STATUS_CRC);
}

/**
 * @brief Pack a engine_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  Timestamp in milliseconds since system boot
 * @param engine_rpm  engine rpm, unit rpm.
 * @param engine_state  engine state.
 * @param pos_sensor_left_roll  left roll servo pos.
 * @param pos_sensor_right_roll  right roll servo pos.
 * @param pos_sensor_left_pitch  left pitch servo pos.
 * @param pos_sensor_right_pitch  right pitch servo pos.
 * @param vehicle_oil  vehicle oil, uint mm.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_engine_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,const uint16_t *engine_rpm,const uint8_t *engine_state,int16_t pos_sensor_left_roll,int16_t pos_sensor_right_roll,int16_t pos_sensor_left_pitch,int16_t pos_sensor_right_pitch,uint8_t vehicle_oil)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ENGINE_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_int16_t(buf, 20, pos_sensor_left_roll);
    _mav_put_int16_t(buf, 22, pos_sensor_right_roll);
    _mav_put_int16_t(buf, 24, pos_sensor_left_pitch);
    _mav_put_int16_t(buf, 26, pos_sensor_right_pitch);
    _mav_put_uint8_t(buf, 34, vehicle_oil);
    _mav_put_uint16_t_array(buf, 8, engine_rpm, 6);
    _mav_put_uint8_t_array(buf, 28, engine_state, 6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ENGINE_STATUS_LEN);
#else
    mavlink_engine_status_t packet;
    packet.timestamp = timestamp;
    packet.pos_sensor_left_roll = pos_sensor_left_roll;
    packet.pos_sensor_right_roll = pos_sensor_right_roll;
    packet.pos_sensor_left_pitch = pos_sensor_left_pitch;
    packet.pos_sensor_right_pitch = pos_sensor_right_pitch;
    packet.vehicle_oil = vehicle_oil;
    mav_array_memcpy(packet.engine_rpm, engine_rpm, sizeof(uint16_t)*6);
    mav_array_memcpy(packet.engine_state, engine_state, sizeof(uint8_t)*6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ENGINE_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ENGINE_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ENGINE_STATUS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_STATUS_LEN, MAVLINK_MSG_ID_ENGINE_STATUS_CRC);
}

/**
 * @brief Encode a engine_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param engine_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_engine_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_engine_status_t* engine_status)
{
    return mavlink_msg_engine_status_pack(system_id, component_id, msg, engine_status->timestamp, engine_status->engine_rpm, engine_status->engine_state, engine_status->pos_sensor_left_roll, engine_status->pos_sensor_right_roll, engine_status->pos_sensor_left_pitch, engine_status->pos_sensor_right_pitch, engine_status->vehicle_oil);
}

/**
 * @brief Encode a engine_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param engine_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_engine_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_engine_status_t* engine_status)
{
    return mavlink_msg_engine_status_pack_chan(system_id, component_id, chan, msg, engine_status->timestamp, engine_status->engine_rpm, engine_status->engine_state, engine_status->pos_sensor_left_roll, engine_status->pos_sensor_right_roll, engine_status->pos_sensor_left_pitch, engine_status->pos_sensor_right_pitch, engine_status->vehicle_oil);
}

/**
 * @brief Send a engine_status message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  Timestamp in milliseconds since system boot
 * @param engine_rpm  engine rpm, unit rpm.
 * @param engine_state  engine state.
 * @param pos_sensor_left_roll  left roll servo pos.
 * @param pos_sensor_right_roll  right roll servo pos.
 * @param pos_sensor_left_pitch  left pitch servo pos.
 * @param pos_sensor_right_pitch  right pitch servo pos.
 * @param vehicle_oil  vehicle oil, uint mm.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_engine_status_send(mavlink_channel_t chan, uint64_t timestamp, const uint16_t *engine_rpm, const uint8_t *engine_state, int16_t pos_sensor_left_roll, int16_t pos_sensor_right_roll, int16_t pos_sensor_left_pitch, int16_t pos_sensor_right_pitch, uint8_t vehicle_oil)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ENGINE_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_int16_t(buf, 20, pos_sensor_left_roll);
    _mav_put_int16_t(buf, 22, pos_sensor_right_roll);
    _mav_put_int16_t(buf, 24, pos_sensor_left_pitch);
    _mav_put_int16_t(buf, 26, pos_sensor_right_pitch);
    _mav_put_uint8_t(buf, 34, vehicle_oil);
    _mav_put_uint16_t_array(buf, 8, engine_rpm, 6);
    _mav_put_uint8_t_array(buf, 28, engine_state, 6);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENGINE_STATUS, buf, MAVLINK_MSG_ID_ENGINE_STATUS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_STATUS_LEN, MAVLINK_MSG_ID_ENGINE_STATUS_CRC);
#else
    mavlink_engine_status_t packet;
    packet.timestamp = timestamp;
    packet.pos_sensor_left_roll = pos_sensor_left_roll;
    packet.pos_sensor_right_roll = pos_sensor_right_roll;
    packet.pos_sensor_left_pitch = pos_sensor_left_pitch;
    packet.pos_sensor_right_pitch = pos_sensor_right_pitch;
    packet.vehicle_oil = vehicle_oil;
    mav_array_memcpy(packet.engine_rpm, engine_rpm, sizeof(uint16_t)*6);
    mav_array_memcpy(packet.engine_state, engine_state, sizeof(uint8_t)*6);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENGINE_STATUS, (const char *)&packet, MAVLINK_MSG_ID_ENGINE_STATUS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_STATUS_LEN, MAVLINK_MSG_ID_ENGINE_STATUS_CRC);
#endif
}

/**
 * @brief Send a engine_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_engine_status_send_struct(mavlink_channel_t chan, const mavlink_engine_status_t* engine_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_engine_status_send(chan, engine_status->timestamp, engine_status->engine_rpm, engine_status->engine_state, engine_status->pos_sensor_left_roll, engine_status->pos_sensor_right_roll, engine_status->pos_sensor_left_pitch, engine_status->pos_sensor_right_pitch, engine_status->vehicle_oil);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENGINE_STATUS, (const char *)engine_status, MAVLINK_MSG_ID_ENGINE_STATUS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_STATUS_LEN, MAVLINK_MSG_ID_ENGINE_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_ENGINE_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_engine_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, const uint16_t *engine_rpm, const uint8_t *engine_state, int16_t pos_sensor_left_roll, int16_t pos_sensor_right_roll, int16_t pos_sensor_left_pitch, int16_t pos_sensor_right_pitch, uint8_t vehicle_oil)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_int16_t(buf, 20, pos_sensor_left_roll);
    _mav_put_int16_t(buf, 22, pos_sensor_right_roll);
    _mav_put_int16_t(buf, 24, pos_sensor_left_pitch);
    _mav_put_int16_t(buf, 26, pos_sensor_right_pitch);
    _mav_put_uint8_t(buf, 34, vehicle_oil);
    _mav_put_uint16_t_array(buf, 8, engine_rpm, 6);
    _mav_put_uint8_t_array(buf, 28, engine_state, 6);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENGINE_STATUS, buf, MAVLINK_MSG_ID_ENGINE_STATUS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_STATUS_LEN, MAVLINK_MSG_ID_ENGINE_STATUS_CRC);
#else
    mavlink_engine_status_t *packet = (mavlink_engine_status_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->pos_sensor_left_roll = pos_sensor_left_roll;
    packet->pos_sensor_right_roll = pos_sensor_right_roll;
    packet->pos_sensor_left_pitch = pos_sensor_left_pitch;
    packet->pos_sensor_right_pitch = pos_sensor_right_pitch;
    packet->vehicle_oil = vehicle_oil;
    mav_array_memcpy(packet->engine_rpm, engine_rpm, sizeof(uint16_t)*6);
    mav_array_memcpy(packet->engine_state, engine_state, sizeof(uint8_t)*6);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENGINE_STATUS, (const char *)packet, MAVLINK_MSG_ID_ENGINE_STATUS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_STATUS_LEN, MAVLINK_MSG_ID_ENGINE_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE ENGINE_STATUS UNPACKING


/**
 * @brief Get field timestamp from engine_status message
 *
 * @return  Timestamp in milliseconds since system boot
 */
static inline uint64_t mavlink_msg_engine_status_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field engine_rpm from engine_status message
 *
 * @return  engine rpm, unit rpm.
 */
static inline uint16_t mavlink_msg_engine_status_get_engine_rpm(const mavlink_message_t* msg, uint16_t *engine_rpm)
{
    return _MAV_RETURN_uint16_t_array(msg, engine_rpm, 6,  8);
}

/**
 * @brief Get field engine_state from engine_status message
 *
 * @return  engine state.
 */
static inline uint16_t mavlink_msg_engine_status_get_engine_state(const mavlink_message_t* msg, uint8_t *engine_state)
{
    return _MAV_RETURN_uint8_t_array(msg, engine_state, 6,  28);
}

/**
 * @brief Get field pos_sensor_left_roll from engine_status message
 *
 * @return  left roll servo pos.
 */
static inline int16_t mavlink_msg_engine_status_get_pos_sensor_left_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field pos_sensor_right_roll from engine_status message
 *
 * @return  right roll servo pos.
 */
static inline int16_t mavlink_msg_engine_status_get_pos_sensor_right_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  22);
}

/**
 * @brief Get field pos_sensor_left_pitch from engine_status message
 *
 * @return  left pitch servo pos.
 */
static inline int16_t mavlink_msg_engine_status_get_pos_sensor_left_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  24);
}

/**
 * @brief Get field pos_sensor_right_pitch from engine_status message
 *
 * @return  right pitch servo pos.
 */
static inline int16_t mavlink_msg_engine_status_get_pos_sensor_right_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  26);
}

/**
 * @brief Get field vehicle_oil from engine_status message
 *
 * @return  vehicle oil, uint mm.
 */
static inline uint8_t mavlink_msg_engine_status_get_vehicle_oil(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  34);
}

/**
 * @brief Decode a engine_status message into a struct
 *
 * @param msg The message to decode
 * @param engine_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_engine_status_decode(const mavlink_message_t* msg, mavlink_engine_status_t* engine_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    engine_status->timestamp = mavlink_msg_engine_status_get_timestamp(msg);
    mavlink_msg_engine_status_get_engine_rpm(msg, engine_status->engine_rpm);
    engine_status->pos_sensor_left_roll = mavlink_msg_engine_status_get_pos_sensor_left_roll(msg);
    engine_status->pos_sensor_right_roll = mavlink_msg_engine_status_get_pos_sensor_right_roll(msg);
    engine_status->pos_sensor_left_pitch = mavlink_msg_engine_status_get_pos_sensor_left_pitch(msg);
    engine_status->pos_sensor_right_pitch = mavlink_msg_engine_status_get_pos_sensor_right_pitch(msg);
    mavlink_msg_engine_status_get_engine_state(msg, engine_status->engine_state);
    engine_status->vehicle_oil = mavlink_msg_engine_status_get_vehicle_oil(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ENGINE_STATUS_LEN? msg->len : MAVLINK_MSG_ID_ENGINE_STATUS_LEN;
        memset(engine_status, 0, MAVLINK_MSG_ID_ENGINE_STATUS_LEN);
    memcpy(engine_status, _MAV_PAYLOAD(msg), len);
#endif
}
