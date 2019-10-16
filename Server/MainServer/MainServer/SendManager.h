#pragma once

struct MappedMemoryUnit;
template <typename _MemoryType> class MappedMemoryPool;
class Session;

/*
	!0. 기본 싱글턴.. 정적 객체 사용하며 생성자 비호출되어야함.
*/
namespace WonSY
{
	class SendManager /* Singleton */
	{
		enum class SINGLETON_INSTANCE { DEFAULT = 0 };
	
	public:
		SendManager() = delete;
		SendManager(SINGLETON_INSTANCE);
		SendManager(const SendManager& other) = delete;
		SendManager& operator=(const SendManager&) = delete;

		inline static SendManager& GetInstance() noexcept { return SendManager::instance; }
	
	public:
		void SendData(_DataType* data, Session* session) noexcept;
		void PushMemory(MappedMemoryUnit*) noexcept;
	
	private:
		_NODISCARD MappedMemoryUnit* PopMemoryUnit(_MemoryPoolIndex) noexcept;
	
	private:
		/*inline*/ static SendManager instance;
		inline static std::atomic<bool> instanceFlag{false};
	
		unique_ptr<MappedMemoryPool<MappedMemoryUnit>> sendMemoryPool;
	};
}