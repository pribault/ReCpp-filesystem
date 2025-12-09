#include "recpp/filesystem/AsyncFile.h"

using namespace recpp::async;
using namespace recpp::filesystem;
using namespace recpp::rx;
using namespace std;

AsyncFile::AsyncFile(Scheduler *scheduler)
	: m_scheduler(scheduler)
	, m_stream(make_shared<fstream>())
{
}

AsyncFile::~AsyncFile() = default;

Completable AsyncFile::rxOpen(const std::filesystem::path &filename, ios_base::openmode mode)
{
	auto result = Completable::defer(
		[this, filename, mode]()
		{
			try
			{
				m_stream->open(filename, mode);
			}
			catch (...)
			{
				return Completable::error(current_exception());
			}

			if (!m_stream->is_open())
				return Completable::error(runtime_error("couldn't open '" + filename.string() + "'"));
			return Completable::complete();
		});
	return m_scheduler ? result.subscribeOn(*m_scheduler) : result;
}

Completable AsyncFile::rxClose()
{
	auto result = Completable::defer(
		[this]()
		{
			try
			{
				m_stream->close();
			}
			catch (...)
			{
				return Completable::error(current_exception());
			}

			if (m_stream->fail())
				return Completable::error(runtime_error("Error during stream close"));
			return Completable::complete();
		});
	return m_scheduler ? result.subscribeOn(*m_scheduler) : result;
}

Single<string> AsyncFile::rxRead(streamsize count)
{
	auto result = Single<string>::defer(
		[this, count]()
		{
			try
			{
				string result(count, '\0');
				m_stream->read(result.data(), count);
				return Single<string>::just(result);
			}
			catch (...)
			{
				return Single<string>::error(current_exception());
			}
		});
	return m_scheduler ? result.subscribeOn(*m_scheduler) : result;
}

Completable AsyncFile::rxWrite(const string &data)
{
	auto result = Completable::defer(
		[this, data]()
		{
			try
			{
				m_stream->write(data.data(), data.size());
			}
			catch (...)
			{
				return Completable::error(current_exception());
			}

			return Completable::complete();
		});
	return m_scheduler ? result.subscribeOn(*m_scheduler) : result;
}
