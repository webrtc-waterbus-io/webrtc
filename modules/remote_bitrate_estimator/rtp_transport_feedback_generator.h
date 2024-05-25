/*
 *  Copyright (c) 2024 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef MODULES_REMOTE_BITRATE_ESTIMATOR_RTP_TRANSPORT_FEEDBACK_GENERATOR_H_
#define MODULES_REMOTE_BITRATE_ESTIMATOR_RTP_TRANSPORT_FEEDBACK_GENERATOR_H_

#include "api/units/data_rate.h"
#include "api/units/data_size.h"
#include "api/units/time_delta.h"
#include "api/units/timestamp.h"
#include "modules/rtp_rtcp/source/rtp_packet_received.h"

namespace webrtc {

class RtpTransportFeedbackGenerator {
 public:
  virtual ~RtpTransportFeedbackGenerator() = default;

  virtual void OnReceivedPacket(const RtpPacketReceived& packet) = 0;

  // Sends periodic feedback if it is time to send it.
  // Returns time until next call to Process should be made.
  virtual TimeDelta Process(Timestamp now) = 0;

  virtual void OnSendBandwidthEstimateChanged(DataRate estimate) = 0;

  // Overhead from transport layers below RTP. Ie, IP, SRTP.
  virtual void SetTransportOverhead(DataSize overhead_per_packet) = 0;
};

}  // namespace webrtc

#endif  // MODULES_REMOTE_BITRATE_ESTIMATOR_RTP_TRANSPORT_FEEDBACK_GENERATOR_H_