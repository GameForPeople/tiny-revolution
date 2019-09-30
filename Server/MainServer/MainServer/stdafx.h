#pragma once

// C++
#include <iostream>
#include <cwchar>
#include <string>

// C++11 
#include <mutex>
#include <atomic>
#include <thread>

#include <chrono>

// C++17
#include <shared_mutex>

// STL
#include <unordered_set>
#include <array>
#include <vector>
#include <list>

// PPL
#include <concurrent_queue.h>

// Boost.Asio
#include <boost/bind.hpp>
#include <boost/asio.hpp>

// Attributes
#define		_NORETURN		[[noreturn]]
#define		_DEPRECATED		[[deprecated]]
#define		_MAYBE_UNUSED	[[maybe_unused]]
#define		_FALLTHROUGH	[[fallthrough]]
#define		_NODISCARD		[[nodiscard]]

// Using Namespace
using namespace std::chrono;
using namespace concurrency;