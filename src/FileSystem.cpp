#include "recpp/filesystem/FileSystem.h"

using namespace recpp::async;
using namespace recpp::rx;

Single<std::filesystem::path> recpp::filesystem::rxAbsolute(const std::filesystem::path &path)
{
	return Single<std::filesystem::path>::defer(
		[path]()
		{
			try
			{
				return Single<std::filesystem::path>::just(std::filesystem::absolute(path));
			}
			catch (const std::exception &exception)
			{
				return Single<std::filesystem::path>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<std::filesystem::path> recpp::filesystem::rxCanonical(const std::filesystem::path &path)
{
	return Single<std::filesystem::path>::defer(
		[path]()
		{
			try
			{
				return Single<std::filesystem::path>::just(std::filesystem::canonical(path));
			}
			catch (const std::exception &exception)
			{
				return Single<std::filesystem::path>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<std::filesystem::path> recpp::filesystem::rxWeaklyCanonical(const std::filesystem::path &path)
{
	return Single<std::filesystem::path>::defer(
		[path]()
		{
			try
			{
				return Single<std::filesystem::path>::just(std::filesystem::weakly_canonical(path));
			}
			catch (const std::exception &exception)
			{
				return Single<std::filesystem::path>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<std::filesystem::path> recpp::filesystem::rxRelative(const std::filesystem::path &path, const std::filesystem::path &base)
{
	return Single<std::filesystem::path>::defer(
		[path, base]()
		{
			try
			{
				return Single<std::filesystem::path>::just(std::filesystem::relative(path, base));
			}
			catch (const std::exception &exception)
			{
				return Single<std::filesystem::path>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<std::filesystem::path> recpp::filesystem::rxProximate(const std::filesystem::path &path, const std::filesystem::path &base)
{
	return Single<std::filesystem::path>::defer(
		[path, base]()
		{
			try
			{
				return Single<std::filesystem::path>::just(std::filesystem::proximate(path, base));
			}
			catch (const std::exception &exception)
			{
				return Single<std::filesystem::path>::error(std::make_exception_ptr(exception));
			}
		});
}

Completable recpp::filesystem::rxCopy(const std::filesystem::path &from, const std::filesystem::path &to)
{
	return Completable::defer(
		[from, to]()
		{
			try
			{
				std::filesystem::copy(from, to);
			}
			catch (const std::exception &exception)
			{
				return Completable::error(std::make_exception_ptr(exception));
			}
			return Completable::complete();
		});
}

Completable recpp::filesystem::rxCopy(const std::filesystem::path &from, const std::filesystem::path &to, std::filesystem::copy_options options)
{
	return Completable::defer(
		[from, to, options]()
		{
			try
			{
				std::filesystem::copy(from, to, options);
			}
			catch (const std::exception &exception)
			{
				return Completable::error(std::make_exception_ptr(exception));
			}
			return Completable::complete();
		});
}

Completable recpp::filesystem::rxCopyFile(const std::filesystem::path &from, const std::filesystem::path &to)
{
	return Completable::defer(
		[from, to]()
		{
			try
			{
				std::filesystem::copy_file(from, to);
			}
			catch (const std::exception &exception)
			{
				return Completable::error(std::make_exception_ptr(exception));
			}
			return Completable::complete();
		});
}

Completable recpp::filesystem::rxCopyFile(const std::filesystem::path &from, const std::filesystem::path &to, std::filesystem::copy_options options)
{
	return Completable::defer(
		[from, to, options]()
		{
			try
			{
				std::filesystem::copy_file(from, to, options);
			}
			catch (const std::exception &exception)
			{
				return Completable::error(std::make_exception_ptr(exception));
			}
			return Completable::complete();
		});
}

Completable recpp::filesystem::rxCopySymlink(const std::filesystem::path &from, const std::filesystem::path &to)
{
	return Completable::defer(
		[from, to]()
		{
			try
			{
				std::filesystem::copy_symlink(from, to);
			}
			catch (const std::exception &exception)
			{
				return Completable::error(std::make_exception_ptr(exception));
			}
			return Completable::complete();
		});
}

Single<bool> recpp::filesystem::rxCreateDirectory(const std::filesystem::path &path)
{
	return Single<bool>::defer(
		[path]()
		{
			try
			{
				return Single<bool>::just(std::filesystem::create_directory(path));
			}
			catch (const std::exception &exception)
			{
				return Single<bool>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<bool> recpp::filesystem::rxCreateDirectory(const std::filesystem::path &path, const std::filesystem::path &existingPath)
{
	return Single<bool>::defer(
		[path, existingPath]()
		{
			try
			{
				return Single<bool>::just(std::filesystem::create_directory(path, existingPath));
			}
			catch (const std::exception &exception)
			{
				return Single<bool>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<bool> recpp::filesystem::rxCreateDirectories(const std::filesystem::path &path)
{
	return Single<bool>::defer(
		[path]()
		{
			try
			{
				return Single<bool>::just(std::filesystem::create_directories(path));
			}
			catch (const std::exception &exception)
			{
				return Single<bool>::error(std::make_exception_ptr(exception));
			}
		});
}

Completable recpp::filesystem::rxCreateHardLink(const std::filesystem::path &target, const std::filesystem::path &link)
{
	return Completable::defer(
		[target, link]()
		{
			try
			{
				std::filesystem::create_hard_link(target, link);
			}
			catch (const std::exception &exception)
			{
				return Completable::error(std::make_exception_ptr(exception));
			}
			return Completable::complete();
		});
}

Completable recpp::filesystem::rxCreateSymlink(const std::filesystem::path &target, const std::filesystem::path &link)
{
	return Completable::defer(
		[target, link]()
		{
			try
			{
				std::filesystem::create_symlink(target, link);
			}
			catch (const std::exception &exception)
			{
				return Completable::error(std::make_exception_ptr(exception));
			}
			return Completable::complete();
		});
}

Completable recpp::filesystem::rxCreateDirectorySymlink(const std::filesystem::path &target, const std::filesystem::path &link)
{
	return Completable::defer(
		[target, link]()
		{
			try
			{
				std::filesystem::create_directory_symlink(target, link);
			}
			catch (const std::exception &exception)
			{
				return Completable::error(std::make_exception_ptr(exception));
			}
			return Completable::complete();
		});
}

Single<std::filesystem::path> recpp::filesystem::rxCurrentPath()
{
	return Single<std::filesystem::path>::defer(
		[]()
		{
			try
			{
				return Single<std::filesystem::path>::just(std::filesystem::current_path());
			}
			catch (const std::exception &exception)
			{
				return Single<std::filesystem::path>::error(std::make_exception_ptr(exception));
			}
		});
}

Completable recpp::filesystem::rxCurrentPath(const std::filesystem::path &path)
{
	return Completable::defer(
		[path]()
		{
			try
			{
				std::filesystem::current_path(path);
			}
			catch (const std::exception &exception)
			{
				return Completable::error(std::make_exception_ptr(exception));
			}
			return Completable::complete();
		});
}

Single<bool> recpp::filesystem::rxExists(const std::filesystem::path &path)
{
	return Single<bool>::defer(
		[path]()
		{
			try
			{
				return Single<bool>::just(std::filesystem::exists(path));
			}
			catch (const std::exception &exception)
			{
				return Single<bool>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<bool> recpp::filesystem::rxEquivalent(const std::filesystem::path &path1, const std::filesystem::path &path2)
{
	return Single<bool>::defer(
		[path1, path2]()
		{
			try
			{
				return Single<bool>::just(std::filesystem::equivalent(path1, path2));
			}
			catch (const std::exception &exception)
			{
				return Single<bool>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<uintmax_t> recpp::filesystem::rxFileSize(const std::filesystem::path &path)
{
	return Single<uintmax_t>::defer(
		[path]()
		{
			try
			{
				return Single<uintmax_t>::just(std::filesystem::file_size(path));
			}
			catch (const std::exception &exception)
			{
				return Single<uintmax_t>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<uintmax_t> recpp::filesystem::rxHardLinkCount(const std::filesystem::path &path)
{
	return Single<uintmax_t>::defer(
		[path]()
		{
			try
			{
				return Single<uintmax_t>::just(std::filesystem::hard_link_count(path));
			}
			catch (const std::exception &exception)
			{
				return Single<uintmax_t>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<bool> recpp::filesystem::rxIsBlockFile(const std::filesystem::path &path)
{
	return Single<bool>::defer(
		[path]()
		{
			try
			{
				return Single<bool>::just(std::filesystem::is_block_file(path));
			}
			catch (const std::exception &exception)
			{
				return Single<bool>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<bool> recpp::filesystem::rxIsCharacterFile(const std::filesystem::path &path)
{
	return Single<bool>::defer(
		[path]()
		{
			try
			{
				return Single<bool>::just(std::filesystem::is_character_file(path));
			}
			catch (const std::exception &exception)
			{
				return Single<bool>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<bool> recpp::filesystem::rxIsDirectory(const std::filesystem::path &path)
{
	return Single<bool>::defer(
		[path]()
		{
			try
			{
				return Single<bool>::just(std::filesystem::is_directory(path));
			}
			catch (const std::exception &exception)
			{
				return Single<bool>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<bool> recpp::filesystem::rxIsEmpty(const std::filesystem::path &path)
{
	return Single<bool>::defer(
		[path]()
		{
			try
			{
				return Single<bool>::just(std::filesystem::is_empty(path));
			}
			catch (const std::exception &exception)
			{
				return Single<bool>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<bool> recpp::filesystem::rxIsFifo(const std::filesystem::path &path)
{
	return Single<bool>::defer(
		[path]()
		{
			try
			{
				return Single<bool>::just(std::filesystem::is_fifo(path));
			}
			catch (const std::exception &exception)
			{
				return Single<bool>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<bool> recpp::filesystem::rxIsOther(const std::filesystem::path &path)
{
	return Single<bool>::defer(
		[path]()
		{
			try
			{
				return Single<bool>::just(std::filesystem::is_other(path));
			}
			catch (const std::exception &exception)
			{
				return Single<bool>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<bool> recpp::filesystem::rxIsRegularFile(const std::filesystem::path &path)
{
	return Single<bool>::defer(
		[path]()
		{
			try
			{
				return Single<bool>::just(std::filesystem::is_regular_file(path));
			}
			catch (const std::exception &exception)
			{
				return Single<bool>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<bool> recpp::filesystem::rxIsSocket(const std::filesystem::path &path)
{
	return Single<bool>::defer(
		[path]()
		{
			try
			{
				return Single<bool>::just(std::filesystem::is_socket(path));
			}
			catch (const std::exception &exception)
			{
				return Single<bool>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<bool> recpp::filesystem::rxIsSymlink(const std::filesystem::path &path)
{
	return Single<bool>::defer(
		[path]()
		{
			try
			{
				return Single<bool>::just(std::filesystem::is_symlink(path));
			}
			catch (const std::exception &exception)
			{
				return Single<bool>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<std::filesystem::file_time_type> recpp::filesystem::rxLastWriteTime(const std::filesystem::path &path)
{
	return Single<std::filesystem::file_time_type>::defer(
		[path]()
		{
			try
			{
				return Single<std::filesystem::file_time_type>::just(std::filesystem::last_write_time(path));
			}
			catch (const std::exception &exception)
			{
				return Single<std::filesystem::file_time_type>::error(std::make_exception_ptr(exception));
			}
		});
}

Completable recpp::filesystem::rxLastWriteTime(const std::filesystem::path &path, std::filesystem::file_time_type newTime)
{
	return Completable::defer(
		[path, newTime]()
		{
			try
			{
				std::filesystem::last_write_time(path, newTime);
			}
			catch (const std::exception &exception)
			{
				return Completable::error(std::make_exception_ptr(exception));
			}
			return Completable::complete();
		});
}

Completable recpp::filesystem::rxPermissions(const std::filesystem::path &path, std::filesystem::perms permissions, std::filesystem::perm_options options)
{
	return Completable::defer(
		[path, permissions, options]()
		{
			try
			{
				std::filesystem::permissions(path, permissions, options);
			}
			catch (const std::exception &exception)
			{
				return Completable::error(std::make_exception_ptr(exception));
			}
			return Completable::complete();
		});
}

Single<std::filesystem::path> recpp::filesystem::rxReadSymlink(const std::filesystem::path &path)
{
	return Single<std::filesystem::path>::defer(
		[path]()
		{
			try
			{
				return Single<std::filesystem::path>::just(std::filesystem::read_symlink(path));
			}
			catch (const std::exception &exception)
			{
				return Single<std::filesystem::path>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<bool> recpp::filesystem::rxRemove(const std::filesystem::path &path)
{
	return Single<bool>::defer(
		[path]()
		{
			try
			{
				return Single<bool>::just(std::filesystem::remove(path));
			}
			catch (const std::exception &exception)
			{
				return Single<bool>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<uintmax_t> recpp::filesystem::rxRemoveAll(const std::filesystem::path &path)
{
	return Single<uintmax_t>::defer(
		[path]()
		{
			try
			{
				return Single<uintmax_t>::just(std::filesystem::remove_all(path));
			}
			catch (const std::exception &exception)
			{
				return Single<uintmax_t>::error(std::make_exception_ptr(exception));
			}
		});
}

Completable recpp::filesystem::rxRename(const std::filesystem::path &oldPath, const std::filesystem::path &newPath)
{
	return Completable::defer(
		[oldPath, newPath]()
		{
			try
			{
				std::filesystem::rename(oldPath, newPath);
				return Completable::complete();
			}
			catch (const std::exception &exception)
			{
				return Completable::error(std::make_exception_ptr(exception));
			}
		});
}

Completable recpp::filesystem::rxResizeFile(const std::filesystem::path &path, std::uintmax_t newSize)
{
	return Completable::defer(
		[path, newSize]()
		{
			try
			{
				std::filesystem::resize_file(path, newSize);
			}
			catch (const std::exception &exception)
			{
				return Completable::error(std::make_exception_ptr(exception));
			}
			return Completable::complete();
		});
}

Single<std::filesystem::space_info> recpp::filesystem::rxSpace(const std::filesystem::path &path)
{
	return Single<std::filesystem::space_info>::defer(
		[path]()
		{
			try
			{
				return Single<std::filesystem::space_info>::just(std::filesystem::space(path));
			}
			catch (const std::exception &exception)
			{
				return Single<std::filesystem::space_info>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<std::filesystem::file_status> recpp::filesystem::rxStatus(const std::filesystem::path &path)
{
	return Single<std::filesystem::file_status>::defer(
		[path]()
		{
			try
			{
				return Single<std::filesystem::file_status>::just(std::filesystem::status(path));
			}
			catch (const std::exception &exception)
			{
				return Single<std::filesystem::file_status>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<std::filesystem::file_status> recpp::filesystem::rxSymlinkStatus(const std::filesystem::path &path)
{
	return Single<std::filesystem::file_status>::defer(
		[path]()
		{
			try
			{
				return Single<std::filesystem::file_status>::just(symlink_status(path));
			}
			catch (const std::exception &exception)
			{
				return Single<std::filesystem::file_status>::error(std::make_exception_ptr(exception));
			}
		});
}

Single<std::filesystem::path> recpp::filesystem::rxTempDirectoryPath()
{
	return Single<std::filesystem::path>::defer(
		[]()
		{
			try
			{
				return Single<std::filesystem::path>::just(std::filesystem::temp_directory_path());
			}
			catch (const std::exception &exception)
			{
				return Single<std::filesystem::path>::error(std::make_exception_ptr(exception));
			}
		});
}

recpp::filesystem::FileSystem::FileSystem(Scheduler &scheduler)
	: m_scheduler(scheduler)
{
}

Single<std::filesystem::path> recpp::filesystem::FileSystem::rxAbsolute(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxAbsolute(path).subscribeOn(m_scheduler);
}

Single<std::filesystem::path> recpp::filesystem::FileSystem::rxCanonical(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxCanonical(path).subscribeOn(m_scheduler);
}

Single<std::filesystem::path> recpp::filesystem::FileSystem::rxWeaklyCanonical(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxWeaklyCanonical(path).subscribeOn(m_scheduler);
}

Single<std::filesystem::path> recpp::filesystem::FileSystem::rxRelative(const std::filesystem::path &path, const std::filesystem::path &base) const
{
	return recpp::filesystem::rxRelative(path, base).subscribeOn(m_scheduler);
}

Single<std::filesystem::path> recpp::filesystem::FileSystem::rxProximate(const std::filesystem::path &path, const std::filesystem::path &base) const
{
	return recpp::filesystem::rxProximate(path, base).subscribeOn(m_scheduler);
}

Completable recpp::filesystem::FileSystem::rxCopy(const std::filesystem::path &from, const std::filesystem::path &to) const
{
	return recpp::filesystem::rxCopy(from, to).subscribeOn(m_scheduler);
}

Completable recpp::filesystem::FileSystem::rxCopy(const std::filesystem::path &from, const std::filesystem::path &to,
												  std::filesystem::copy_options options) const
{
	return recpp::filesystem::rxCopy(from, to, options).subscribeOn(m_scheduler);
}

Completable recpp::filesystem::FileSystem::rxCopyFile(const std::filesystem::path &from, const std::filesystem::path &to) const
{
	return recpp::filesystem::rxCopyFile(from, to).subscribeOn(m_scheduler);
}

Completable recpp::filesystem::FileSystem::rxCopyFile(const std::filesystem::path &from, const std::filesystem::path &to,
													  std::filesystem::copy_options options) const
{
	return recpp::filesystem::rxCopyFile(from, to, options).subscribeOn(m_scheduler);
}

Completable recpp::filesystem::FileSystem::rxCopySymlink(const std::filesystem::path &from, const std::filesystem::path &to) const
{
	return recpp::filesystem::rxCopySymlink(from, to).subscribeOn(m_scheduler);
}

Single<bool> recpp::filesystem::FileSystem::rxCreateDirectory(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxCreateDirectory(path).subscribeOn(m_scheduler);
}

Single<bool> recpp::filesystem::FileSystem::rxCreateDirectory(const std::filesystem::path &path, const std::filesystem::path &existingPath) const
{
	return recpp::filesystem::rxCreateDirectory(path, existingPath).subscribeOn(m_scheduler);
}

Single<bool> recpp::filesystem::FileSystem::rxCreateDirectories(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxCreateDirectories(path).subscribeOn(m_scheduler);
}

Completable recpp::filesystem::FileSystem::rxCreateHardLink(const std::filesystem::path &target, const std::filesystem::path &link) const
{
	return recpp::filesystem::rxCreateHardLink(target, link).subscribeOn(m_scheduler);
}

Completable recpp::filesystem::FileSystem::rxCreateSymlink(const std::filesystem::path &target, const std::filesystem::path &link) const
{
	return recpp::filesystem::rxCreateSymlink(target, link).subscribeOn(m_scheduler);
}

Completable recpp::filesystem::FileSystem::rxCreateDirectorySymlink(const std::filesystem::path &target, const std::filesystem::path &link) const
{
	return recpp::filesystem::rxCreateDirectorySymlink(target, link).subscribeOn(m_scheduler);
}

Single<std::filesystem::path> recpp::filesystem::FileSystem::rxCurrentPath() const
{
	return recpp::filesystem::rxCurrentPath().subscribeOn(m_scheduler);
}

Completable recpp::filesystem::FileSystem::rxCurrentPath(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxCurrentPath(path).subscribeOn(m_scheduler);
}

Single<bool> recpp::filesystem::FileSystem::rxExists(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxExists(path).subscribeOn(m_scheduler);
}

Single<bool> recpp::filesystem::FileSystem::rxEquivalent(const std::filesystem::path &path1, const std::filesystem::path &path2) const
{
	return recpp::filesystem::rxEquivalent(path1, path2).subscribeOn(m_scheduler);
}

Single<uintmax_t> recpp::filesystem::FileSystem::rxFileSize(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxFileSize(path).subscribeOn(m_scheduler);
}

Single<uintmax_t> recpp::filesystem::FileSystem::rxHardLinkCount(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxHardLinkCount(path).subscribeOn(m_scheduler);
}

Single<bool> recpp::filesystem::FileSystem::rxIsBlockFile(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxIsBlockFile(path).subscribeOn(m_scheduler);
}

Single<bool> recpp::filesystem::FileSystem::rxIsCharacterFile(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxIsCharacterFile(path).subscribeOn(m_scheduler);
}

Single<bool> recpp::filesystem::FileSystem::rxIsDirectory(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxIsDirectory(path).subscribeOn(m_scheduler);
}

Single<bool> recpp::filesystem::FileSystem::rxIsEmpty(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxIsEmpty(path).subscribeOn(m_scheduler);
}

Single<bool> recpp::filesystem::FileSystem::rxIsFifo(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxIsFifo(path).subscribeOn(m_scheduler);
}

Single<bool> recpp::filesystem::FileSystem::rxIsOther(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxIsOther(path).subscribeOn(m_scheduler);
}

Single<bool> recpp::filesystem::FileSystem::rxIsRegularFile(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxIsRegularFile(path).subscribeOn(m_scheduler);
}

Single<bool> recpp::filesystem::FileSystem::rxIsSocket(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxIsSocket(path).subscribeOn(m_scheduler);
}

Single<bool> recpp::filesystem::FileSystem::rxIsSymlink(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxIsSymlink(path).subscribeOn(m_scheduler);
}

Single<std::filesystem::file_time_type> recpp::filesystem::FileSystem::rxLastWriteTime(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxLastWriteTime(path).subscribeOn(m_scheduler);
}

Completable recpp::filesystem::FileSystem::rxLastWriteTime(const std::filesystem::path &path, std::filesystem::file_time_type newTime) const
{
	return recpp::filesystem::rxLastWriteTime(path, newTime).subscribeOn(m_scheduler);
}

Completable recpp::filesystem::FileSystem::rxPermissions(const std::filesystem::path &path, std::filesystem::perms permissions,
														 std::filesystem::perm_options options) const
{
	return recpp::filesystem::rxPermissions(path, permissions, options).subscribeOn(m_scheduler);
}

Single<std::filesystem::path> recpp::filesystem::FileSystem::rxReadSymlink(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxReadSymlink(path).subscribeOn(m_scheduler);
}

Single<bool> recpp::filesystem::FileSystem::rxRemove(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxRemove(path).subscribeOn(m_scheduler);
}

Single<uintmax_t> recpp::filesystem::FileSystem::rxRemoveAll(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxRemoveAll(path).subscribeOn(m_scheduler);
}

Completable recpp::filesystem::FileSystem::rxRename(const std::filesystem::path &oldPath, const std::filesystem::path &newPath) const
{
	return recpp::filesystem::rxRename(oldPath, newPath).subscribeOn(m_scheduler);
}

Completable recpp::filesystem::FileSystem::rxResizeFile(const std::filesystem::path &path, std::uintmax_t newSize) const
{
	return recpp::filesystem::rxResizeFile(path, newSize).subscribeOn(m_scheduler);
}

Single<std::filesystem::space_info> recpp::filesystem::FileSystem::rxSpace(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxSpace(path).subscribeOn(m_scheduler);
}

Single<std::filesystem::file_status> recpp::filesystem::FileSystem::rxStatus(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxStatus(path).subscribeOn(m_scheduler);
}

Single<std::filesystem::file_status> recpp::filesystem::FileSystem::rxSymlinkStatus(const std::filesystem::path &path) const
{
	return recpp::filesystem::rxSymlinkStatus(path).subscribeOn(m_scheduler);
}

Single<std::filesystem::path> recpp::filesystem::FileSystem::rxTempDirectoryPath() const
{
	return recpp::filesystem::rxTempDirectoryPath().subscribeOn(m_scheduler);
}
