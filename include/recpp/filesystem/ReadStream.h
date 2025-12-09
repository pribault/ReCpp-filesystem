#pragma once

#include <recpp/filesystem/StreamBase.h>
#include <recpp/rx/Single.h>

namespace recpp::filesystem
{
	/**
	 * @brief ReadStream represents a stream that can be read from
	 *
	 * @tparam T The type of the data to read from the stream
	 */
	template <typename T>
	class ReadStream : public virtual StreamBase<T>
	{
	public:
		/**
		 * @brief Asynchronously extracts data from stream
		 *
		 * @param count Number of elements to read
		 * @return The resulting data as a recpp::rx::Single
		 */
		virtual recpp::rx::Single<T> rxRead(std::streamsize count) = 0;
	};
} // namespace recpp::filesystem
