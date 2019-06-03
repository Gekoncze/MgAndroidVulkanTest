#ifndef CZ_MG_VULKAN_VULKANSURFACE_H
#define CZ_MG_VULKAN_VULKANSURFACE_H

#include "Vulkan.h"

namespace cz::mg::vulkan
{
    class VulkanInstance;
}

namespace cz::mg::vulkan
{
    class VulkanSurface
    {
        NOCOPY(VulkanSurface)

        protected:
            VkSurfaceKHR surface;
            VulkanInstance* instance;

        protected:
            VulkanSurface(VulkanInstance& instance);

        public:
            virtual ~VulkanSurface();

            inline VkSurfaceKHR& getVk()
            {
                return surface;
            }
    };
}

#endif //CZ_MG_VULKAN_VULKANSURFACE_H
