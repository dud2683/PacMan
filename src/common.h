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
#include <functional>
#include "Pos.h"

#define DL_INFO(x)	SPDLOG_INFO(x)
#define DL_TRACE(x)	SPDLOG_TRACE(x)
#define DL_WARN(x)	SPDLOG_WARN(x)
#define DL_ERROR(x) SPDLOG_ERROR(x)

#define GL_SHADER_CHECK(shaderID) \
	{\
	int  success;\
	char infoLog[512];\
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);\
	if (!success) {\
		int maxLength = 0;\
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);\
		DL_ERROR("SHADER compilation failed");\
		std::vector<char> errorLog(maxLength);\
		glGetShaderInfoLog(shaderID, maxLength, &maxLength, &errorLog[0]);\
		const std::string str(errorLog.begin(), errorLog.end());\
		DL_ERROR(str);\
	}\
	}\
