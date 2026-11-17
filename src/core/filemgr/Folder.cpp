#include "Folder.hpp"
#include "FileMgr.hpp"

namespace Terminus
{
    Folder::Folder(const std::filesystem::path& path) :
        BaseObj(path)
    {
    }
}