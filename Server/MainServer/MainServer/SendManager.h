#pragma once

struct MappedMemoryUnit;
template <typename _MemoryType> class MappedMemoryPool;
class Session;

/*
	!0. 기본 싱글턴.. 정적 객체 사용하며 생성자 비호출되어야함.
*/
class SendManager /* Singleton */
{
	enum class SINGLETON_INSTANCE
	{
		DEFAULT = 0
	};

public:
	SendManager() = delete;
	SendManager(SINGLETON_INSTANCE);
	SendManager(const SendManager& other) = delete;

	static SendManager& GetInstance() noexcept;

public:
	void SendData(_DataType* data, Session* session) noexcept;
	void PushMemory(MappedMemoryUnit*) noexcept;

private:
	_NODISCARD MappedMemoryUnit* PopMemoryUnit(_MemoryPoolIndex) noexcept;

private:
	/*inline*/ static SendManager instance;
	inline static atomic<bool> onceFlag{false};

	unique_ptr<MappedMemoryPool<MappedMemoryUnit>> sendMemoryPool;
};