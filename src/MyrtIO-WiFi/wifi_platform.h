#pragma once

#include <Attotime.h>
#include <MyrtIO/device/unit.h>
#include "i_wifi_platform.h"

#ifndef IO_WIFI_TIMEOUT
#define IO_WIFI_TIMEOUT 15000
#endif

namespace io {
	class WiFiPlatform : public Unit, public IWiFiPlatform {
	public:
		WiFiPlatform(
			const char* ssid,
			const char* password,
			const char* hostname
		) :
			ssid_(ssid),
			password_(password),
			hostname_(hostname) {}

		void setup() override;
		void loop() override;

		void setTimeout(size_t timeoutMs);
		const char* hostname();
		bool connected();
		WiFiState state();

		virtual void onStateChange(WiFiState state) {}
		virtual void onSetup() {}

	protected:
		virtual bool shouldConnect() {
			return true;
		}

	private:
		WiFiState state_ = Disconnected;
		Timer timeout_;
		size_t timeoutMs_ = IO_WIFI_TIMEOUT;
		const char* ssid_;
		const char* password_;
		const char* hostname_;
		void connect_();
		void setState_(WiFiState state);
	};
}
