#pragma once //make sure file is included once

#include "beatsaber-hook/shared/config/config-utils.hpp" //include config utils
#include "beatsaber-hook/shared/utils/hooking.hpp" //include hooking

#include "paper/shared/logger.hpp" //include paper logger

#define LOG_INFO(string, ...) Paper::Logger::fmtLogTag<Paper::LogLevel::INF>(string, "Replay" __VA_OPT__(,) __VA_ARGS__) //define LOG_INFO(string, *extra variables*) that logs given string, argument and amount of args in the context "Replay"
#define LOG_DEBUG(string, ...) Paper::Logger::fmtLogTag<Paper::LogLevel::DBG>(string, "Replay" __VA_OPT__(,) __VA_ARGS__) //define LOG_DEBUG(string, *extra variables*) that logs given string, argument and amount of args in the context "Replay"
#define LOG_ERROR(string, ...) Paper::Logger::fmtLogTag<Paper::LogLevel::ERR>(string, "Replay" __VA_OPT__(,) __VA_ARGS__) //define LOG_ERROR(string, *extra variables*) that logs given string, argument and amount of args in the context "Replay"

extern ModInfo modInfo; //get modinfo from main.cpp when this is included

inline auto RendersFolder = "/sdcard/Renders"; //inline (for speed) request render folder

void SelectLevelOnNextSongRefresh(bool render = true, int idx = 0); //define function with default, render true and index 0

extern bool recorderInstalled; //get recorder installed (if bl or scoresbr is installed) from main.cpp
