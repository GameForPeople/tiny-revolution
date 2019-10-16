#pragma once

// C++
#include <iostream>
#include <string>
#include <fstream>

// Ctype
#include <cwchar>
#include <cassert>
#include <cstddef>
#include <cstring>

// C++11 
#include <mutex>
#include <atomic>
#include <thread>

#include <chrono>

// C++17
#include <shared_mutex>
#include <filesystem>

// C++20
#include <concepts>

// c++ experimental

// STL
#include <unordered_set>
#include <array>
#include <vector>
#include <list>

// PPL
#include <concurrent_queue.h>
#include <concurrent_vector.h>
#include <concurrent_priority_queue.h>

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
using namespace std;
using namespace std::chrono;
using namespace concurrency;
using namespace std::literals;
using boost::asio::ip::tcp;

using namespace WonSY;

//---------
#define FOR_SERVER
#include "../../../Define.hh"
#include "Concepts.hh"
//---------