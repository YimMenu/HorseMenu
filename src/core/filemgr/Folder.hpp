#pragma once
#include "BaseObj.hpp"

namespace Terminus
{
    class Folder final : public BaseObj
    {
    public:
        Folder(const std::filesystem::path& folder);

    };
}