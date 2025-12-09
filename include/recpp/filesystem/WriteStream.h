#pragma once

#include <recpp/filesystem/StreamBase.h>

namespace recpp::filesystem
{
	/**
	 * @brief WriteStream represents a stream that can be written to
	 *
	 * @tparam T The type of the data to write to the stream
	 */
	template <typename T>
	class WriteStream : public virtual StreamBase<T>
	{
	public:
		/**
		 * @brief Asynchronously write to stream
		 *
		 * @param data The data to write
		 * @return The resulting recpp::rx::Completable
		 */
		virtual recpp::rx::Completable rxWrite(const T &data) = 0;
	};
} // namespace recpp::filesystem
