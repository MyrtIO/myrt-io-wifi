#pragma once

#include <stdint.h>

enum WiFiState : uint8_t {
	Disconnected,
	Connecting,
	Connected
};

class IWiFiPlatform {
  public:
	virtual bool connected() = 0;
	virtual const char* hostname() = 0;
	virtual WiFiState state() = 0;
};
