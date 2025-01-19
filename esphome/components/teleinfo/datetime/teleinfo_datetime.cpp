
#include "teleinfo_datetime.h"

#ifdef USE_DATETIME_DATETIME

#include "esphome/core/log.h"

namespace esphome {
namespace teleinfo {
static const char *const TAG = "teleinfo_datetime";

TeleInfoDateTime::TeleInfoDateTime(const char *tag) { this->tag = std::string(tag); }

void TeleInfoDateTime::publish_val(const std::string &, const std::string &timestamp) {
  char saison;
  uint16_t year;
  uint8_t month;
  uint8_t day;
  uint8_t hour;
  uint8_t minute;
  uint8_t second;

  if (sscanf(timestamp.c_str(), "%c%02hu%02hhu%02hhu%02hhu%02hhu%02hhu",  // NOLINT
             &saison,                                                     // NOLINT
             &year,                                                       // NOLINT
             &month,                                                      // NOLINT
             &day,                                                        // NOLINT
             &hour,                                                       // NOLINT
             &minute,                                                     // NOLINT
             &second) == 7) {                                             // NOLINT
    this->year_ = 2000 + year;
    this->month_ = month;
    this->day_ = day;
    this->hour_ = hour;
    this->minute_ = minute;
    this->second_ = second;
    publish_state();
  }
}

void TeleInfoDateTime::dump_config() { LOG_DATETIME_DATETIME("  ", "Teleinfo DateTime", this); }

}  // namespace teleinfo
}  // namespace esphome

#endif  // USE_DATETIME_DATETIME
