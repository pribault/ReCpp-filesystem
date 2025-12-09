#pragma once

#include <recpp/filesystem/ReadStream.h>
#include <recpp/filesystem/WriteStream.h>

#include <filesystem>
#include <fstream>
#include <memory>
#include <string>

namespace recpp::filesystem
{
	/**
	 * @brief AsyncFile represents a file that can be read and written to asynchronously
	 */
	class AsyncFile final : public ReadStream<std::string>, public WriteStream<std::string>
	{
	public:
		/**
		 * @brief Construct a new AsyncFile object.
		 *
		 * @param scheduler The recpp::async::Scheduler to use for all blocking operations
		 */
		AsyncFile(recpp::async::Scheduler *m_scheduler = nullptr);

		/**
		 * @brief Destroy this {@link AsyncFile} instance
		 */
		~AsyncFile() final;

		/**
		 * @brief Asynchronously opens and associates the file with name filename with the file stream
		 *
		 * @param filename The name of the file to be opened
		 * @param mode Specifies stream open mode
		 * @return The resulting recpp::rx::Completable
		 */
		recpp::rx::Completable rxOpen(const std::filesystem::path &filename, std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);

		/**
		 * @brief Asynchronously closes the associated file
		 *
		 * @return The resulting recpp::rx::Completable
		 */
		recpp::rx::Completable rxClose() final;

		/**
		 * @brief Asynchronously extracts characters from stream
		 *
		 * @param count Number of characters to read
		 * @return The resulting string as a recpp::rx::Single
		 */
		recpp::rx::Single<std::string> rxRead(std::streamsize count) final;

		/**
		 * @brief Asynchronously write characters to stream
		 *
		 * @param data The string to write
		 * @return The resulting recpp::rx::Completable
		 */
		recpp::rx::Completable rxWrite(const std::string &data) final;

	private:
		recpp::async::Scheduler		 *m_scheduler = nullptr;
		std::shared_ptr<std::fstream> m_stream;
	};
} // namespace recpp::filesystem
