#ifndef CZ_MG_VULKAN_VULKANANDROIDSURFACE_H
#define CZ_MG_VULKAN_VULKANANDROIDSURFACE_H

#include "Vulkan.h"
#include "VulkanSurface.h"

namespace cz::mg::vulkan
{
    class VulkanInstance;
}

namespace cz::mg::vulkan
{
    class VulkanAndroidSurface : public VulkanSurface
    {
        NOCOPY(VulkanAndroidSurface)

        public:
            VulkanAndroidSurface(VulkanInstance& instance, ANativeWindow* window);
    };
}

#endif //CZ_MG_VULKAN_VULKANANDROIDSURFACE_H
