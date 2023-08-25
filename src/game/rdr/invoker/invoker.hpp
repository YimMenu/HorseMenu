#pragma once

namespace YimMenu
{
	typedef DWORD Void;
	typedef DWORD Any;
	typedef DWORD uint;
	typedef DWORD Hash;
	typedef int Entity;
	typedef int Player;
	typedef int FireId;
	typedef int Ped;
	typedef int Vehicle;
	typedef int Cam;
	typedef int CarGenerator;
	typedef int Group;
	typedef int Train;
	typedef int Pickup;
	typedef int Object;
	typedef int Weapon;
	typedef int Interior;
	typedef int Blip;
	typedef int Texture;
	typedef int TextureDict;
	typedef int CoverPoint;
	typedef int Camera;
	typedef int TaskSequence;
	typedef int ColourIndex;
	typedef int Sphere;
	typedef int INT, ScrHandle;
	typedef int AnimScene;
	typedef int Volume;
	typedef int ItemSet;
	typedef int PropSet;
	typedef int PopZone;
	typedef int PersChar;
	typedef int Prompt;

	struct Vector3
	{
		float x;
		float y;
		float z;
	};
	using scrNativeHash    = std::uint64_t;

	class scrNativeCallContext
	{
	public:
		void reset()
		{
			m_arg_count  = 0;
			m_data_count = 0;
		}

		template<typename T>
		void push_arg(T&& value)
		{
			static_assert(sizeof(T) <= sizeof(std::uint64_t));
			*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(reinterpret_cast<std::uint64_t*>(m_args) + (m_arg_count++)) = std::forward<T>(value);
		}

		template<typename T>
		T& get_arg(std::size_t index)
		{
			static_assert(sizeof(T) <= sizeof(std::uint64_t));
			return *reinterpret_cast<T*>(reinterpret_cast<std::uint64_t*>(m_args) + index);
		}

		template<typename T>
		void set_arg(std::size_t index, T&& value)
		{
			static_assert(sizeof(T) <= sizeof(std::uint64_t));
			*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(reinterpret_cast<std::uint64_t*>(m_args) + index) = std::forward<T>(value);
		}

		template<typename T>
		T* get_return_value()
		{
			return reinterpret_cast<T*>(m_return_value);
		}

		template<typename T>
		void set_return_value(T&& value)
		{
			*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(m_return_value) = std::forward<T>(value);
		}

		template<typename T>
		void set_return_value(T& value)
		{
			*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(m_return_value) = std::forward<T>(value);
		}

	protected:
		void* m_return_value;
		std::uint32_t m_arg_count;
		void* m_args;
		std::int32_t m_data_count;
		std::uint32_t m_data[48];
	};
	static_assert(sizeof(scrNativeCallContext) == 0xE0);

	using scrNativeHandler = void (*)(scrNativeCallContext*);

	class native_call_context : public scrNativeCallContext
	{
	public:
		native_call_context();

	private:
		uint64_t m_return_stack[10];
		uint64_t m_arg_stack[100];
	};

	class native_invoker
	{
	public:
		explicit native_invoker() = default;
		~native_invoker()         = default;

		void begin_call();
		void end_call(scrNativeHash hash);

		template<typename T>
		void push_arg(T&& value)
		{
			m_call_context.push_arg(std::forward<T>(value));
		}

		template<typename T>
		T& get_return_value()
		{
			return *m_call_context.get_return_value<T>();
		}

	public:
		native_call_context m_call_context;
		bool m_handlers_cached = false;
	};

	inline native_invoker g_native_invoker;
}