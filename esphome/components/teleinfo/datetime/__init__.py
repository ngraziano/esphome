import esphome.codegen as cg
from esphome.components import datetime
from esphome.const import CONF_ID

from .. import CONF_TAG_NAME, CONF_TELEINFO_ID, TELEINFO_LISTENER_SCHEMA, teleinfo_ns

TeleInfoDateTime = teleinfo_ns.class_(
    "TeleInfoDateTime", datetime.DateTimeEntity, cg.Component
)

CONFIG_SCHEMA = datetime.datetime_schema(TeleInfoDateTime).extend(
    TELEINFO_LISTENER_SCHEMA
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID], config[CONF_TAG_NAME])
    await cg.register_component(var, config)
    await datetime.register_datetime(var, config)
    teleinfo = await cg.get_variable(config[CONF_TELEINFO_ID])
    cg.add(teleinfo.register_teleinfo_listener(var))
