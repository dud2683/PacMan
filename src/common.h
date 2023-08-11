#pragma once
#ifdef DEBUG
#define SPDLOG_ACTIVE_LEVEL	 SPDLOG_LEVEL_TRACE
#elif RELEASE
#define	SPDLOG_ACTIVE_LEVEL	 SPDLOG_LEVEL_INFO
#else
#define	SPDLOG_ACTIVE_LEVEL	 SPDLOG_LEVEL_OFF
#endif
#include <spdlog/spdlog.h>

#include <string>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <chrono>


#define DL_INFO(x)	SPDLOG_INFO(x)
#define DL_TRACE(x)	SPDLOG_TRACE(x)
#define DL_WARN(x)	SPDLOG_WARN(x)
#define DL_ERROR(x) SPDLOG_ERROR(x)
