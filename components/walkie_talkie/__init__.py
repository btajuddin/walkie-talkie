import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components.microphone import Microphone
from esphome.components.speaker import Speaker
from esphome.components.udp import UDPComponent, CONF_UDP_ID
from esphome.const import (
    CONF_ID,
    CONF_MICROPHONE, CONF_SPEAKER,
)

walkie_talkie_ns = cg.esphome_ns.namespace("walkie_talkie")
WalkieTalkieComponent = walkie_talkie_ns.class_("WalkieTalkieComponent", cg.Component)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(WalkieTalkieComponent),
        cv.Required(CONF_MICROPHONE): cv.use_id(Microphone),
        cv.Required(CONF_SPEAKER): cv.use_id(Speaker),
        cv.Required(CONF_UDP_ID): cv.use_id(UDPComponent)
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    cg.add(var.set_microphone(config[CONF_MICROPHONE]))
    cg.add(var.set_speaker(config[CONF_SPEAKER]))
    cg.add(var.set_udp(config[CONF_UDP_ID]))
