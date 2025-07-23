//
// Created by brian on 7/23/25.
//

#ifndef WALKIE_TALKIE_H
#define WALKIE_TALKIE_H

#include "esphome/core/component.h"
#include "esphome/components/microphone/microphone.h"
#include "esphome/components/speaker/speaker.h"
#include "esphome/components/udp/udp_component.h"

namespace esphome {
namespace walkie_talkie {
class WalkieTalkieComponent : public Component {
 public:
  void setup() override;
  void loop() override;

  void set_microphone(microphone::Microphone *microphone) { this->microphone_ = microphone; }
  void set_speaker(speaker::Speaker *speaker) { this->speaker_ = speaker; }
  void set_udp(udp::UDPComponent *udp) { this->udp_ = udp; }

 private:
  microphone::Microphone *microphone_;
  speaker::Speaker *speaker_;
  udp::UDPComponent *udp_;

  void microphone_callback_(const std::vector<uint8_t> &payload) const;
  void network_callback_(const std::vector<uint8_t> &payload) const;
};
}  // namespace walkie_talkie
}  // namespace esphome
#endif  // WALKIE_TALKIE_H
