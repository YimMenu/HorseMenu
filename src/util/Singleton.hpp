template<typename T>
class Singleton
{
public:
	static void Destroy()
	{
	}

protected:
	Singleton() = default;
	virtual ~Singleton() = default;

	Singleton(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton& operator=(Singleton&&) = delete;

	static T& GetInstance()
	{
		static T instance{};
		return instance;
	}
};
