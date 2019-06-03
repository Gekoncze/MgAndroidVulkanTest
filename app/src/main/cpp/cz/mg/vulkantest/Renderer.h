#ifndef CZ_MG_VULKANTEST_RENDERER_H
#define CZ_MG_VULKANTEST_RENDERER_H

#include "../utilities/Utilities.h"
#include "ExecutionManager.h"

struct ANativeWindow;

namespace cz::mg::vulkan
{
    class Vulkan;
    class VulkanInstance;
    class VulkanDebugReport;
    class VulkanAndroidSurface;
}

namespace cz::mg::vulkantest
{
    class Renderer
    {
        NOCOPY(Renderer)

        private:
            cz::mg::vulkan::Vulkan* vulkan = nullptr;
            cz::mg::vulkan::VulkanInstance* instance = nullptr;
            cz::mg::vulkan::VulkanDebugReport* debugReport = nullptr;
            cz::mg::vulkan::VulkanAndroidSurface* surface = nullptr;

            ExecutionManager* executionManager = nullptr;

        public:
            Renderer(ANativeWindow* window);
            ~Renderer();
            void resize(int w, int h);
    };
}

#endif //CZ_MG_VULKANTEST_RENDERER_H