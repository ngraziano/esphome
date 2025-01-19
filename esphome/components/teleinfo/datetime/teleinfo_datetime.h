#pragma once

#include "esphome/components/teleinfo/teleinfo.h"

#ifdef USE_DATETIME_DATETIME

#include "esphome/components/datetime/datetime_entity.h"

namespace esphome {
namespace teleinfo {
class TeleInfoDateTime : public TeleInfoListener, public datetime::DateTimeEntity, public Component {
 public:
  TeleInfoDateTime(const char *tag);
  void publish_val(const std::string &, const std::string &timestamp) override;
  void dump_config() override;
};
}  // namespace teleinfo
}  // namespace esphome

#endif  // USE_DATETIME_DATETIME
