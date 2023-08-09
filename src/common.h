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
#include <vector>
#include <memory>


#define DL_INFO(x) spdlog::info(x)
#define DL_TRACE(x) spdlog::trace(x)
#define DL_WARN(x) spdlog::warn(x)
#define DL_ERROR(x) spdlog::error(x)
