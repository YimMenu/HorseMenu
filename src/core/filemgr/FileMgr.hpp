#pragma once
#include <filesystem>
#include "File.hpp"
#include "Folder.hpp"

namespace Terminus
{
    class FileMgr final
    {
    private:
        FileMgr() = default;

    public:
        virtual ~FileMgr() = default;

        FileMgr(const FileMgr&) = delete;
        FileMgr(FileMgr&&) noexcept = delete;
        FileMgr& operator=(const FileMgr&) = delete;
        FileMgr& operator=(FileMgr&&) noexcept = delete;

        static void Init(const std::filesystem::path& rootFolder);

        [[nodiscard]] static File GetProjectFile(const std::filesystem::path& file)
        { return GetInstance().GetProjectFileImpl(file); }
        [[nodiscard]] static Folder GetProjectFolder(const std::filesystem::path& folder)
        { return GetInstance().GetProjectFolderImpl(folder); }
        [[nodiscard]] static std::optional<std::filesystem::path> MakeAbsPath(const fs::path& root, const fs::path& other)
		{ return GetInstance().MakeAbsPathImpl(root, other); }

        static const std::filesystem::path& CreateFolderIfNotExists(const std::filesystem::path& folder);
        static const std::filesystem::path& EnsureFileCanBeCreated(const std::filesystem::path& file);

    private:
        void InitImpl(const std::filesystem::path& rootFolder);

        File GetProjectFileImpl(const std::filesystem::path& file) const;
        Folder GetProjectFolderImpl(const std::filesystem::path& folder) const;

        std::optional<std::filesystem::path> MakeAbsPathImpl(const fs::path& root, const fs::path& other);

        static FileMgr& GetInstance()
        {
            static FileMgr i {};

            return i;
        }

    private:
        std::filesystem::path m_RootFolder;

    };
}