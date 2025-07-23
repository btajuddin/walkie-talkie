//
// Created by brian on 7/23/25.
//

#include "walkie_talkie.h"

namespace esphome {
namespace walkie_talkie {

void WalkieTalkieComponent::setup() {
  this->microphone_->add_data_callback(this->microphone_callback_);
  this->udp_->add_listener(this->network_callback_);
}

void WalkieTalkieComponent::microphone_callback_(const std::vector<uint8_t> &payload) const {
  this->udp_->send_packet(payload);
}

void WalkieTalkieComponent::network_callback_(const std::vector<uint8_t> &payload) const {
  this->speaker_->play(payload);
}

}  // namespace walkie_talkie
}  // namespace esphome