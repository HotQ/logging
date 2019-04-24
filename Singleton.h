#ifndef SINGLETON_H
#define SINGLETON_H

#include <memory>

namespace logging {

	template <typename T>
	class Singleton
	{
	private:
		static std::shared_ptr<Singleton<T>> instance;
		std::shared_ptr<T> m_instance;

		Singleton<T>() {
			m_instance = std::make_shared<T>();
		};

	public:
		Singleton(const Singleton&) = delete;
		Singleton& operator = (const Singleton& t) = delete;

		static std::shared_ptr<T> getInstance() {
			return instance->m_instance;
		}

	};

	template <typename T>
	std::shared_ptr<Singleton<T>> Singleton<T>::instance(new Singleton<T>());

} // namespace logging
#endif // SINGLETON_H