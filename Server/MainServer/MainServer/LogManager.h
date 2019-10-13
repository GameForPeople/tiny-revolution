#pragma once
namespace WonSY
{
#define __FUNCTION_NAME__ __FUNCTION__
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define SOURCE_LOCATION __FILENAME__, __LINE__, __FUNCTION_NAME__

	enum class LOG_TYPE
	{
		WARNING_LOG
		, ERROR_LOG
		, DEV_LOG
	};

	struct SourceLocation
	{
		const char* fileName;
		int fileLine;
		const char* functionName;
		std::wstring outputString;

		SourceLocation(const char* fileName, int fileLine, const char* functionName)
			: fileName(fileName), fileLine(fileLine), functionName(functionName), outputString()
		{
			outputString = // 비용이 너무 높은데..
				UNICODE_UTIL::StringToWString(
					std::string(fileName)
					+ ':'
					+ std::to_string(fileLine)
					+ " "
					+ std::string(functionName)
				);
		}
	};

	class LogManager
	{
		enum class SINGLETON_INSTANCE { DEFAULT = 0 };

	public:
		_NODISCARD static inline LogManager& GetInstance() noexcept { return LogManager::instance; };

#ifdef OLD_CODE
		static void MakeInstance();
		static void DeleteInstance();
#endif

		void AddLog(const LOG_TYPE, const std::wstring_view& logString, const SourceLocation&);
		void SaveLog();

	public:
		LogManager(SINGLETON_INSTANCE);
		LogManager() = delete;
		~LogManager() = default;
		LogManager(const LogManager&) = delete;
		LogManager& operator=(const LogManager&) = delete;

		inline static atomic<bool> instanceFlag{false};

	private:
		static LogManager instance;
		const std::filesystem::path logFilePath;
		concurrency::concurrent_vector<std::pair<LOG_TYPE, std::wstring>> logCont;
		std::atomic<bool> saveFlag;
#ifdef _DEBUG
		std::mutex printLock;
#endif
	};
}