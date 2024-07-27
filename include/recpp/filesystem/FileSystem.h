#pragma once

#include <recpp/rx/Single.h>

#include <filesystem>

namespace recpp::filesystem
{
	recpp::rx::Single<std::filesystem::path> rxAbsolute(const std::filesystem::path &path);
	recpp::rx::Single<std::filesystem::path> rxCanonical(const std::filesystem::path &path);
	recpp::rx::Single<std::filesystem::path> rxWeaklyCanonical(const std::filesystem::path &path);
	recpp::rx::Single<std::filesystem::path> rxRelative(const std::filesystem::path &path);
	recpp::rx::Single<std::filesystem::path> rxRelative(const std::filesystem::path &path, const std::filesystem::path &base);
	recpp::rx::Single<std::filesystem::path> rxProximate(const std::filesystem::path &path);
	recpp::rx::Single<std::filesystem::path> rxProximate(const std::filesystem::path &path, const std::filesystem::path &base);
	recpp::rx::Completable					 rxCopy(const std::filesystem::path &from, const std::filesystem::path &to);
	recpp::rx::Completable					 rxCopy(const std::filesystem::path &from, const std::filesystem::path &to, std::filesystem::copy_options options);
	recpp::rx::Completable					 rxCopyFile(const std::filesystem::path &from, const std::filesystem::path &to);
	recpp::rx::Completable	rxCopyFile(const std::filesystem::path &from, const std::filesystem::path &to, std::filesystem::copy_options options);
	recpp::rx::Completable	rxCopySymlink(const std::filesystem::path &from, const std::filesystem::path &to);
	recpp::rx::Single<bool> rxCreateDirectory(const std::filesystem::path &path);
	recpp::rx::Single<bool> rxCreateDirectory(const std::filesystem::path &path, const std::filesystem::path &existingPath);
	recpp::rx::Single<bool> rxCreateDirectories(const std::filesystem::path &path);
	recpp::rx::Completable	rxCreateHardLink(const std::filesystem::path &target, const std::filesystem::path &link);
	recpp::rx::Completable	rxCreateSymlink(const std::filesystem::path &target, const std::filesystem::path &link);
	recpp::rx::Completable	rxCreateDirectorySymlink(const std::filesystem::path &target, const std::filesystem::path &link);
	recpp::rx::Single<std::filesystem::path>		   rxCurrentPath();
	recpp::rx::Completable							   rxCurrentPath(const std::filesystem::path &path);
	recpp::rx::Single<bool>							   rxExists(const std::filesystem::path &path);
	recpp::rx::Single<bool>							   rxEquivalent(const std::filesystem::path &path1, const std::filesystem::path &path2);
	recpp::rx::Single<std::uintmax_t>				   rxFileSize(const std::filesystem::path &path);
	recpp::rx::Single<std::uintmax_t>				   rxHardLinkCount(const std::filesystem::path &path);
	recpp::rx::Single<bool>							   rxIsBlockFile(const std::filesystem::path &path);
	recpp::rx::Single<bool>							   rxIsCharacterFile(const std::filesystem::path &path);
	recpp::rx::Single<bool>							   rxIsDirectory(const std::filesystem::path &path);
	recpp::rx::Single<bool>							   rxIsEmpty(const std::filesystem::path &path);
	recpp::rx::Single<bool>							   rxIsFifo(const std::filesystem::path &path);
	recpp::rx::Single<bool>							   rxIsOther(const std::filesystem::path &path);
	recpp::rx::Single<bool>							   rxIsRegularFile(const std::filesystem::path &path);
	recpp::rx::Single<bool>							   rxIsSocket(const std::filesystem::path &path);
	recpp::rx::Single<bool>							   rxIsSymlink(const std::filesystem::path &path);
	recpp::rx::Single<std::filesystem::file_time_type> rxLastWriteTime(const std::filesystem::path &path);
	recpp::rx::Completable							   rxLastWriteTime(const std::filesystem::path &path, std::filesystem::file_time_type newTime);
	recpp::rx::Completable							   rxPermissions(const std::filesystem::path &path, std::filesystem::perms permissions,
																	 std::filesystem::perm_options options = std::filesystem::perm_options::replace);
	recpp::rx::Single<std::filesystem::path>		   rxReadSymlink(const std::filesystem::path &path);
	recpp::rx::Single<bool>							   rxRemove(const std::filesystem::path &path);
	recpp::rx::Single<std::uintmax_t>				   rxRemoveAll(const std::filesystem::path &path);
	recpp::rx::Completable							   rxRename(const std::filesystem::path &oldPath, const std::filesystem::path &newPath);
	recpp::rx::Completable							   rxResizeFile(const std::filesystem::path &path, std::uintmax_t newSize);
	recpp::rx::Single<std::filesystem::space_info>	   rxSpace(const std::filesystem::path &path);
	recpp::rx::Single<std::filesystem::file_status>	   rxStatus(const std::filesystem::path &path);
	recpp::rx::Single<std::filesystem::file_status>	   rxSymlinkStatus(const std::filesystem::path &path);
	recpp::rx::Single<std::filesystem::path>		   rxTempDirectoryPath();

	class FileSystem
	{
	public:
		FileSystem(recpp::async::Scheduler &scheduler);

		recpp::rx::Single<std::filesystem::path> rxAbsolute(const std::filesystem::path &path) const;
		recpp::rx::Single<std::filesystem::path> rxCanonical(const std::filesystem::path &path) const;
		recpp::rx::Single<std::filesystem::path> rxWeaklyCanonical(const std::filesystem::path &path) const;
		recpp::rx::Single<std::filesystem::path> rxRelative(const std::filesystem::path &path) const;
		recpp::rx::Single<std::filesystem::path> rxRelative(const std::filesystem::path &path, const std::filesystem::path &base) const;
		recpp::rx::Single<std::filesystem::path> rxProximate(const std::filesystem::path &path) const;
		recpp::rx::Single<std::filesystem::path> rxProximate(const std::filesystem::path &path, const std::filesystem::path &base) const;
		recpp::rx::Completable					 rxCopy(const std::filesystem::path &from, const std::filesystem::path &to) const;
		recpp::rx::Completable	rxCopy(const std::filesystem::path &from, const std::filesystem::path &to, std::filesystem::copy_options options) const;
		recpp::rx::Completable	rxCopyFile(const std::filesystem::path &from, const std::filesystem::path &to) const;
		recpp::rx::Completable	rxCopyFile(const std::filesystem::path &from, const std::filesystem::path &to, std::filesystem::copy_options options) const;
		recpp::rx::Completable	rxCopySymlink(const std::filesystem::path &from, const std::filesystem::path &to) const;
		recpp::rx::Single<bool> rxCreateDirectory(const std::filesystem::path &path) const;
		recpp::rx::Single<bool> rxCreateDirectory(const std::filesystem::path &path, const std::filesystem::path &existingPath) const;
		recpp::rx::Single<bool> rxCreateDirectories(const std::filesystem::path &path) const;
		recpp::rx::Completable	rxCreateHardLink(const std::filesystem::path &target, const std::filesystem::path &link) const;
		recpp::rx::Completable	rxCreateSymlink(const std::filesystem::path &target, const std::filesystem::path &link) const;
		recpp::rx::Completable	rxCreateDirectorySymlink(const std::filesystem::path &target, const std::filesystem::path &link) const;
		recpp::rx::Single<std::filesystem::path>		   rxCurrentPath() const;
		recpp::rx::Completable							   rxCurrentPath(const std::filesystem::path &path) const;
		recpp::rx::Single<bool>							   rxExists(const std::filesystem::path &path) const;
		recpp::rx::Single<bool>							   rxEquivalent(const std::filesystem::path &path1, const std::filesystem::path &path2) const;
		recpp::rx::Single<std::uintmax_t>				   rxFileSize(const std::filesystem::path &path) const;
		recpp::rx::Single<std::uintmax_t>				   rxHardLinkCount(const std::filesystem::path &path) const;
		recpp::rx::Single<bool>							   rxIsBlockFile(const std::filesystem::path &path) const;
		recpp::rx::Single<bool>							   rxIsCharacterFile(const std::filesystem::path &path) const;
		recpp::rx::Single<bool>							   rxIsDirectory(const std::filesystem::path &path) const;
		recpp::rx::Single<bool>							   rxIsEmpty(const std::filesystem::path &path) const;
		recpp::rx::Single<bool>							   rxIsFifo(const std::filesystem::path &path) const;
		recpp::rx::Single<bool>							   rxIsOther(const std::filesystem::path &path) const;
		recpp::rx::Single<bool>							   rxIsRegularFile(const std::filesystem::path &path) const;
		recpp::rx::Single<bool>							   rxIsSocket(const std::filesystem::path &path) const;
		recpp::rx::Single<bool>							   rxIsSymlink(const std::filesystem::path &path) const;
		recpp::rx::Single<std::filesystem::file_time_type> rxLastWriteTime(const std::filesystem::path &path) const;
		recpp::rx::Completable							   rxLastWriteTime(const std::filesystem::path &path, std::filesystem::file_time_type newTime) const;
		recpp::rx::Completable							   rxPermissions(const std::filesystem::path &path, std::filesystem::perms permissions,
																		 std::filesystem::perm_options options = std::filesystem::perm_options::replace) const;
		recpp::rx::Single<std::filesystem::path>		   rxReadSymlink(const std::filesystem::path &path) const;
		recpp::rx::Single<bool>							   rxRemove(const std::filesystem::path &path) const;
		recpp::rx::Single<std::uintmax_t>				   rxRemoveAll(const std::filesystem::path &path) const;
		recpp::rx::Completable							   rxRename(const std::filesystem::path &oldPath, const std::filesystem::path &newPath) const;
		recpp::rx::Completable							   rxResizeFile(const std::filesystem::path &path, std::uintmax_t newSize) const;
		recpp::rx::Single<std::filesystem::space_info>	   rxSpace(const std::filesystem::path &path) const;
		recpp::rx::Single<std::filesystem::file_status>	   rxStatus(const std::filesystem::path &path) const;
		recpp::rx::Single<std::filesystem::file_status>	   rxSymlinkStatus(const std::filesystem::path &path) const;
		recpp::rx::Single<std::filesystem::path>		   rxTempDirectoryPath() const;

	private:
		recpp::async::Scheduler &m_scheduler;
	};
} // namespace recpp::filesystem
