#pragma once

#include <recpp/rx/Completable.h>

namespace recpp::filesystem
{
	/**
	 * @brief StreamBase
	 */
	template <typename T>
	class StreamBase
	{
	public:
		virtual ~StreamBase();

		virtual recpp::rx::Completable rxClose() = 0;
	};
} // namespace recpp::filesystem

#include <recpp/filesystem/inl/StreamBase.inl>
