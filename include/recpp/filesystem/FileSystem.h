#pragma once

#include <recpp/rx/Single.h>

#include <filesystem>

namespace recpp::filesystem
{
	recpp::rx::Single<std::filesystem::path> rxAbsolute(const std::filesystem::path &path);
	recpp::rx::Single<std::filesystem::path> rxCanonical(const std::filesystem::path &path);
	recpp::rx::Single<std::filesystem::path> rxWeaklyCanonical(const std::filesystem::path &path);
	recpp::rx::Single<std::filesystem::path> rxRelative(const std::filesystem::path &path, const std::filesystem::path &base = std::filesystem::current_path());
	recpp::rx::Single<std::filesystem::path> rxProximate(const std::filesystem::path &path,
														 const std::filesystem::path &base = std::filesystem::current_path());
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
	recpp::rx::Single<bool>							   rxIsBlockFile(const std::filesystem::path &path);
	recpp::rx::Single<bool>							   rxIsCharacterFile(const std::filesystem::path &path);
	recpp::rx::Single<bool>							   rxIsDirectory(const std::filesystem::path &path);
	recpp::rx::Single<bool>							   rxIsEmpty(const std::filesystem::path &path);
	recpp::rx::Single<bool>							   rxIsFifo(const std::filesystem::path &path);
	recpp::rx::Single<bool>							   rxIsOther(const std::filesystem::path &path);
	recpp::rx::Single<bool>							   rxIsRegularFile(const std::filesystem::path &path);
	recpp::rx::Single<bool>							   rxIsSocket(const std::filesystem::path &path);
	recpp::rx::Single<bool>							   rxIsSymlink(const std::filesystem::path &path);

	/**
	 * @brief FileSystem is a convenience class to work with a filesystem in a reactive way, and using a specific recpp::async::Scheduler to use for all
	 * blocking operations
	 */
	class FileSystem
	{
	public:
		/**
		 * @brief Construct a new FileSystem object.
		 *
		 * @param scheduler The recpp::async::Scheduler to use for all blocking operations
		 */
		FileSystem(recpp::async::Scheduler &scheduler);

		/**
		 * @brief Asynchronously retrieve a path referencing the same file system location as @p path, for which filesystem::path::is_absolute() is true.
		 *
		 * @param path The path to convert to absolute form
		 * @return An absolute (although not necessarily canonical) pathname referencing the same file as @p path as a recpp::rx::Single
		 */
		recpp::rx::Single<std::filesystem::path> rxAbsolute(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously onverts path @p path to a canonical absolute path, i.e. an absolute path that has no dot, dot-dot elements or symbolic links in
		 * its generic format representation. If @p path is not an absolute path, the function behaves as if it is first made absolute by
		 * std::filesystem::absolute(p). The path @p path must exist.
		 *
		 * @param path A path which may be absolute or relative; for canonical it must be an existing path
		 * @return An absolute path that resolves to the same file as std::filesystem::absolute(@p path) as a recpp::rx::Single
		 */
		recpp::rx::Single<std::filesystem::path> rxCanonical(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously returns a path composed by operator/= from the result of calling std::filesystem::canonical() with a path argument composed of
		 * the leading elements of @p path that exist (as determined by std::filesystem::status(p) or std::filesystem::status(p, ec)), if any, followed by the
		 * elements of @p path that do not exist. The resulting path is in normal form.
		 *
		 * @param path A path which may be absolute or relative; for canonical it must be an existing path
		 * @return A normal path of the form canonical(x)/y as a recpp::rx::Single, where x is a path composed of the longest leading sequence of elements in @p
		 * path that exist, and y is a path composed of the remaining trailing non-existent elements of @p path
		 */
		recpp::rx::Single<std::filesystem::path> rxWeaklyCanonical(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously returns @p path made relative to @p base. Resolves symlinks and normalizes both @p path and @p base before other processing.
		 * Effectively returns std::filesystem::weakly_canonical(p).lexically_relative(std::filesystem::weakly_canonical(base)) or
		 * std::filesystem::weakly_canonical(p, ec).lexically_relative(std::filesystem::weakly_canonical(base, ec)).
		 *
		 * @param path An existing path
		 * @param base Base path, against which @p path will be made relative
		 * @return @p path made relative against @p base as a recpp::rx::Single
		 */
		recpp::rx::Single<std::filesystem::path> rxRelative(const std::filesystem::path &path,
															const std::filesystem::path &base = std::filesystem::current_path()) const;

		/**
		 * @brief Asynchronously returns std::filesystem::weakly_canonical(p).lexically_proximate(std::filesystem::weakly_canonical(base)) or
		 * std::filesystem::weakly_canonical(p, ec).lexically_proximate(std::filesystem::weakly_canonical(base, ec)).
		 *
		 * @param path An existing path
		 * @param base Base path, against which @p path will be made proximate
		 * @return @p path made proximate against @p base as a recpp::rx::Single
		 */
		recpp::rx::Single<std::filesystem::path> rxProximate(const std::filesystem::path &path,
															 const std::filesystem::path &base = std::filesystem::current_path()) const;

		/**
		 * @brief Asynchronously copies files and directories, equivalent to rxCopy with std::filesystem::copy_options::none used as options.
		 * <p>
		 * Please refer to the std::filesystem::copy documentation for more informations about this method behaviour.
		 *
		 * @param from Path to the source file, directory, or symlink
		 * @param to Path to the target file, directory, or symlink
		 * @return The resulting recpp::rx::Completable
		 */
		recpp::rx::Completable rxCopy(const std::filesystem::path &from, const std::filesystem::path &to) const;

		/**
		 * @brief Asynchronously copies the file or directory @p from to file or directory @p to, using the copy options indicated by @p options. The
		 * behavior is undefined if there is more than one option in any of the std::filesystem::copy_options option group present in @p options (even in the
		 * copy_file group).
		 * <p>
		 * Please refer to the std::filesystem::copy documentation for more informations about this method behaviour.
		 *
		 * @param from Path to the source file, directory, or symlink
		 * @param to Path to the target file, directory, or symlink
		 * @param options The copy options
		 * @return The resulting recpp::rx::Completable
		 */
		recpp::rx::Completable rxCopy(const std::filesystem::path &from, const std::filesystem::path &to, std::filesystem::copy_options options) const;

		/**
		 * @brief Asynchronously copies a single file from @p from to @p to, equivalent to rxCopyFile with std::filesystem::copy_options::none used as options.
		 * <p>
		 * Please refer to the std::filesystem::copy_file documentation for more informations about this method behaviour.
		 *
		 * @param from Path to the source file
		 * @param to Path to the target file
		 * @return The resulting recpp::rx::Completable
		 */
		recpp::rx::Completable rxCopyFile(const std::filesystem::path &from, const std::filesystem::path &to) const;

		/**
		 * @brief Asynchronously copies a single file from from to to, using the copy options indicated by options. The behavior is undefined if there is more
		 * than one option in any of the copy_options option group present in options (even in the groups not relevant to filesystem::copy_file). <p> Please
		 * refer to the std::filesystem::copy_file documentation for more informations about this method behaviour.
		 *
		 * @param from Path to the source file
		 * @param to Path to the target file
		 * @param options The copy options
		 * @return The resulting recpp::rx::Completable
		 */
		recpp::rx::Completable rxCopyFile(const std::filesystem::path &from, const std::filesystem::path &to, std::filesystem::copy_options options) const;

		/**
		 * @brief Asynchronously copies a symlink to another location. Effectively calls f(std::filesystem::read_symlink(@p from), @p to) where f is
		 * std::filesystem::create_symlink or std::filesystem::create_directory_symlink depending on whether @p from resolves to a file or directory.
		 *
		 * @param from Path to a symbolic link to copy
		 * @param to Destination path of the new symlink
		 * @return The resulting recpp::rx::Completable
		 */
		recpp::rx::Completable rxCopySymlink(const std::filesystem::path &from, const std::filesystem::path &to) const;

		/**
		 * @brief Asynchronously creates the directory @p path as if by POSIX mkdir() with a second argument of static_cast<int>(std::filesystem::perms::all)
		 * (the parent directory must already exist). If the function fails because @p path resolves to an existing directory, no error is reported. Otherwise
		 * on failure an error is reported.
		 *
		 * @param path The path to the new directory to create
		 * @return The resulting boolean as a recpp::rx::Single. True if a directory was newly created for the directory @p path resolves to, false otherwise
		 */
		recpp::rx::Single<bool> rxCreateDirectory(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously creates the directory @p path, the attributes of the new directory are copied from @p existingPath (which must be a directory
		 * that exists). It is OS-dependent which attributes are copied.
		 *
		 * @param path The path to the new directory to create
		 * @param existingPath The path to a directory to copy the attributes from
		 * @return The resulting boolean as a recpp::rx::Single. True if a directory was newly created for the directory @p path resolves to, false otherwise
		 */
		recpp::rx::Single<bool> rxCreateDirectory(const std::filesystem::path &path, const std::filesystem::path &existingPath) const;

		/**
		 * @brief Asynchronously executes std::filesystem::create_directory for every element of @p path that does not already exist. If @p path already exists,
		 * the function does nothing (this condition is not treated as an error).
		 *
		 * @param path The path to the new directory to create
		 * @return The resulting boolean as a recpp::rx::Single. True if a directory was newly created for the directory @p path resolves to, false otherwise
		 */
		recpp::rx::Single<bool> rxCreateDirectories(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously creates a hard link @p link with its target set to @p target as if by POSIX link(): the pathname @p target must exist.
		 * <p>
		 * Once created, @p link and @p target are two logical names that refer to the same file (they are equivalent). Even if the original name @p target is
		 * deleted, the file continues to exist and is accessible as @p link.
		 *
		 * @param target Path of the file or directory to link to
		 * @param link Path of the new hard link
		 * @return The resulting recpp::rx::Completable
		 */
		recpp::rx::Completable rxCreateHardLink(const std::filesystem::path &target, const std::filesystem::path &link) const;

		/**
		 * @brief Asynchronously creates a symbolic link @p link with its target set to @p target as if by POSIX symlink(): the pathname @p target may be
		 * invalid or non-existing. <p> Some operating systems require symlink creation to identify that the link is to a directory. Portable code should use
		 * rxCreateDirectorySymlink to create directory symlinks rather than rxCreateSymlink, even though there is no distinction on POSIX systems.
		 *
		 * @param target Path to point the symlink to, does not have to exist
		 * @param link Path of the new symbolic link
		 * @return The resulting recpp::rx::Completable
		 */
		recpp::rx::Completable rxCreateSymlink(const std::filesystem::path &target, const std::filesystem::path &link) const;

		/**
		 * @brief Asynchronously creates a symbolic link @p link with its target set to @p target as if by POSIX symlink(): the pathname @p target may be
		 * invalid or non-existing. <p> Some operating systems require symlink creation to identify that the link is to a directory. Portable code should use
		 * rxCreateDirectorySymlink to create directory symlinks rather than rxCreateSymlink, even though there is no distinction on POSIX systems.
		 *
		 * @param target Path to point the symlink to, does not have to exist
		 * @param link Path of the new symbolic link
		 * @return The resulting recpp::rx::Completable
		 */
		recpp::rx::Completable rxCreateDirectorySymlink(const std::filesystem::path &target, const std::filesystem::path &link) const;

		/**
		 * @brief Asynchronously returns the absolute path of the current working directory, obtained as if (in native format) by POSIX getcwd.
		 *
		 * @return Returns the current working directory as a recpp::rx::Single.
		 */
		recpp::rx::Single<std::filesystem::path> rxCurrentPath() const;

		/**
		 * @brief Asynchronously changes the current working directory to @p path, as if by POSIX chdir.
		 *
		 * @param path Path to change the current working directory to
		 * @return The resulting recpp::rx::Completable
		 */
		recpp::rx::Completable rxCurrentPath(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously checks if the given file status or path corresponds to an existing file or directory.
		 * <p>
		 * Let s be a std::filesystem::file_status determined as if by std::filesystem::status(@p path) or std::filesystem::status(@p path, ec) (symlinks are
		 * followed), respectively. Returns std::filesystem::exists(s).
		 *
		 * @param path Path to examine
		 * @return The resulting boolean as a recpp::rx::Single. True if the given path corresponds to an existing file or directory, false otherwise
		 */
		recpp::rx::Single<bool> rxExists(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously checks whether the paths @p path1 and @p path2 resolve to the same file system entity.
		 * <p>
		 * If either @p path1 or @p path2 does not exist, an error is reported.
		 *
		 * @param path1 First path to check for equivalence
		 * @param path2 Second path to check for equivalence
		 * @return The resulting boolean as a recpp::rx::Single. True if the p1 and p2 refer to the same file or directory and their file status is the same.
		 * false otherwise
		 */
		recpp::rx::Single<bool> rxEquivalent(const std::filesystem::path &path1, const std::filesystem::path &path2) const;

		/**
		 * @brief If @p path does not exist, reports an error.
		 * <p>
		 * For a regular file @p path, asynchronously returns the size determined as if by reading the st_size member of the structure obtained by POSIX stat
		 * (symlinks are followed).
		 * <p>
		 * The result of attempting to determine the size of a directory (as well as any other file that is not a regular file or a
		 * symlink) is implementation-defined.
		 *
		 * @param path Path to examine
		 * @return The size of the file as a recpp::rx::Single, in bytes
		 */
		recpp::rx::Single<std::uintmax_t> rxFileSize(const std::filesystem::path &path) const;

		/**
		 * @brief Returns the number of hard links for the filesystem object identified by path @p path.
		 *
		 * @param path Path to examine
		 * @return The number of hard links for @p path as a recpp::rx::Single
		 */
		recpp::rx::Single<std::uintmax_t> rxHardLinkCount(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously returns the time of the last modification of @p path, determined as if by accessing the member st_mtime of the POSIX stat
		 * (symlinks are followed). The non-throwing overload returns std::filesystem::file_time_type::min() on errors.
		 *
		 * @param path Path to examine
		 * @return The time of the last modification of @p path as a recpp::rx::Single
		 */
		recpp::rx::Single<std::filesystem::file_time_type> rxLastWriteTime(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously changes the time of the last modification of @p path, as if by POSIX futimens (symlinks are followed).
		 *
		 * @param path Path to modify
		 * @param newTime New modification time
		 * @return The resulting recpp::rx::Completable
		 */
		recpp::rx::Completable rxLastWriteTime(const std::filesystem::path &path, std::filesystem::file_time_type newTime) const;

		/**
		 * @brief Asynchronously changes access permissions of the file to which @p path resolves, as if by POSIX fchmodat. Symlinks are followed unless
		 * perm_options::nofollow is set in @p options.
		 *
		 * @param path Path to examine
		 * @param permissions Permissions to set, add, or remove
		 * @param options Options controlling the action taken by this function
		 * @return The resulting recpp::rx::Completable
		 */
		recpp::rx::Completable rxPermissions(const std::filesystem::path &path, std::filesystem::perms permissions,
											 std::filesystem::perm_options options = std::filesystem::perm_options::replace) const;

		/**
		 * @brief If the path @p path refers to a symbolic link, asynchronously returns a new path object which refers to the target of that symbolic link.
		 * <p>
		 * It is an error if @p path does not refer to a symbolic link.
		 *
		 * @param path Path to a symlink
		 * @return The target of the symlink (which may not necessarily exist) as a recpp::rx::Single
		 */
		recpp::rx::Single<std::filesystem::path> rxReadSymlink(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously deletes the file or empty directory identified by the path @p path as if by the POSIX remove. Symlinks are not followed
		 * (symlink is removed, not its target).
		 *
		 * @param path Path to delete
		 * @return The resulting boolean as a recpp::rx::Single. True if the file was deleted, false if it did not exist. The overload that takes error_code&
		 * argument returns false on errors
		 */
		recpp::rx::Single<bool> rxRemove(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously deletes the contents of @p path (if it is a directory) and the contents of all its subdirectories, recursively, then deletes @p
		 * path itself as if by repeatedly applying the POSIX remove. Symlinks are not followed (symlink is removed, not its target).
		 *
		 * @param path Path to delete
		 * @return Returns the number of files and directories that were deleted (which may be zero if @p path did not exist to begin with) as a
		 * recpp::rx::Single
		 */
		recpp::rx::Single<std::uintmax_t> rxRemoveAll(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously moves or renames the filesystem object identified by @p oldPath to @p newPath as if by the POSIX rename.
		 *
		 * @param oldPath Path to move or rename
		 * @param newPath Target path for the move/rename operation
		 * @return The resulting recpp::rx::Completable
		 */
		recpp::rx::Completable rxRename(const std::filesystem::path &oldPath, const std::filesystem::path &newPath) const;

		/**
		 * @brief Asynchronously changes the size of the regular file named by @p path as if by POSIX truncate: if the file size was previously larger than @p
		 * newSize, the remainder of the file is discarded. If the file was previously smaller than @p newSize, the file size is increased and the new area
		 * appears as if zero-filled.
		 *
		 * @param path Path to resize
		 * @param newSize Size that the file will now have
		 * @return The resulting recpp::rx::Completable
		 */
		recpp::rx::Completable rxResizeFile(const std::filesystem::path &path, std::uintmax_t newSize) const;

		/**
		 * @brief Asynchronously determines the information about the filesystem on which the pathname @p path is located, as if by POSIX statvfs.
		 *
		 * @param path Path to examine
		 * @return The filesystem information (a filesystem::space_info object) as a recpp::rx::Single
		 */
		recpp::rx::Single<std::filesystem::space_info> rxSpace(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously determines the type and attributes of the filesystem object identified by @p path as if by POSIX stat (symlinks are followed to
		 * their targets).
		 *
		 * @param path Path to examine
		 * @return The file status (a filesystem::file_status object) as a recpp::rx::Single
		 */
		recpp::rx::Single<std::filesystem::file_status> rxStatus(const std::filesystem::path &path) const;

		/**
		 * @brief Same as rxStatus except that the behavior is as if the POSIX lstat is used (symlinks are not followed).
		 *
		 * @param path Path to examine
		 * @return The file status (a filesystem::file_status object) as a recpp::rx::Single
		 */
		recpp::rx::Single<std::filesystem::file_status> rxSymlinkStatus(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously returns the directory location suitable for temporary files.
		 *
		 * @return A directory suitable for temporary files as a recpp::rx::Single. The path is guaranteed to exist and to be a directory.
		 */
		recpp::rx::Single<std::filesystem::path> rxTempDirectoryPath() const;

		/**
		 * @brief Asynchronously checks if the given path corresponds to a block special file, as if determined by the POSIX S_ISBLK. Examples of block special
		 * files are block devices such as /dev/sda or /dev/loop0 on Linux.
		 *
		 * @param path Path to examine
		 * @return The resulting boolean as a recpp::rx::Single. True if the file indicated by @p path or if the type indicated s refers to a block device.
		 */
		recpp::rx::Single<bool> rxIsBlockFile(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously checks if the given path corresponds to a character special file, as if determined by POSIX S_ISCHR. Examples of character
		 * special files are character devices such as /dev/null, /dev/tty, /dev/audio, or /dev/nvram on Linux.
		 *
		 * @param path Path to examine
		 * @return The resulting boolean as a recpp::rx::Single. True if the file indicated by @p path or if the type indicated s refers to a character device,
		 * false otherwise
		 */
		recpp::rx::Single<bool> rxIsCharacterFile(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously checks if the given file status or path corresponds to a directory.
		 *
		 * @param path Path to query
		 * @return The resulting boolean as a recpp::rx::Single. True if the file indicated by @p path or if the type indicated s refers to a directory, false
		 * otherwise
		 */
		recpp::rx::Single<bool> rxIsDirectory(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously checks whether the given path refers to an empty file or directory.
		 *
		 * @param path Path to examine
		 * @return The resulting boolean as a recpp::rx::Single. True if the path indicated by @p path refers to an empty file or directory, false otherwise
		 */
		recpp::rx::Single<bool> rxIsEmpty(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously checks if the given file status or path corresponds to a FIFO or pipe file as if determined by POSIX S_ISFIFO.
		 *
		 * @param path Path to query
		 * @return The resulting boolean as a recpp::rx::Single. True if the file indicated by @p path or if the type indicated s refers to a FIFO pipe, false
		 * otherwise
		 */
		recpp::rx::Single<bool> rxIsFifo(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously checks if the given file status or path corresponds to a file of type other type. That is, the file exists, but is neither
		 * regular file, nor directory nor a symlink.
		 *
		 * @param path Path to examine
		 * @return The resulting boolean as a recpp::rx::Single. True if the file indicated by p or if the type indicated s refers to a file that is not regular
		 * file, directory, or a symlink, false otherwise
		 */
		recpp::rx::Single<bool> rxIsOther(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously checks if the given file status or path corresponds to a regular file.
		 *
		 * @param path Path to examine
		 * @return The resulting boolean as a recpp::rx::Single. True if the file indicated by p or if the type indicated by s refers to a regular file, false
		 * otherwise
		 */
		recpp::rx::Single<bool> rxIsRegularFile(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously checks if the given file status or path corresponds to a named IPC socket, as if determined by the POSIX S_IFSOCK.
		 *
		 * @param path Path to examine
		 * @return The resulting boolean as a recpp::rx::Single. True if the file indicated by p or if the type indicated s refers to a named socket
		 */
		recpp::rx::Single<bool> rxIsSocket(const std::filesystem::path &path) const;

		/**
		 * @brief Asynchronously checks if the given file status or path corresponds to a symbolic link, as if determined by the POSIX S_IFLNK.
		 *
		 * @param path Path to examine
		 * @return The resulting boolean as a recpp::rx::Single. True if the file indicated by p or if the type indicated s refers to a symbolic link
		 */
		recpp::rx::Single<bool> rxIsSymlink(const std::filesystem::path &path) const;

	private:
		recpp::async::Scheduler &m_scheduler;
	};
} // namespace recpp::filesystem
