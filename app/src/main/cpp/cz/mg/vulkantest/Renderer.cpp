#include "Renderer.h"
#include <string>
#include <vector>
#include <android/log.h>
#include "../vulkan/VulkanException.h"
#include "../vulkan/VulkanInstance.h"
#include "../vulkan/VulkanDebugReport.h"
#include "../vulkan/VulkanPhysicalDevice.h"
#include "../vulkan/VulkanQueueFamily.h"
#include "../vulkan/VulkanDevice.h"
#include "../vulkan/VulkanCommandPool.h"
#include "../vulkan/VulkanCommandBuffer.h"
#include "../vulkan/VulkanAndroidSurface.h"
#include "../vulkan/Vulkan.h"
#include "../vulkan/VulkanInstance.h"

using namespace cz::mg::vulkan;
using namespace cz::mg::vulkantest;

VkBool32 VKAPI_PTR debugCallback(
        VkDebugReportFlagsEXT                       flags,
        VkDebugReportObjectTypeEXT                  objectType,
        uint64_t                                    object,
        size_t                                      location,
        int32_t                                     messageCode,
        const char*                                 pLayerPrefix,
        const char*                                 pMessage,
        void*                                       pUserData)
{
    __android_log_print(ANDROID_LOG_DEBUG, "#####", "%s: %s %s", "DEBUG", vulkanDebugReportFlagsToString(flags).c_str(), pMessage);
    return VK_FALSE;
}

cz::mg::vulkantest::Renderer::Renderer(ANativeWindow* window)
{
    uint32_t layerCount = 5;
    const char* layers[] = {
            "VK_LAYER_GOOGLE_threading",
            "VK_LAYER_LUNARG_parameter_validation",
            "VK_LAYER_LUNARG_object_tracker",
            "VK_LAYER_LUNARG_core_validation",
            "VK_LAYER_GOOGLE_unique_objects"
    };

    uint32_t extensionCount = 3;
    const char* extensions[] = {
            "VK_KHR_surface",
            "VK_KHR_android_surface",
            "VK_EXT_debug_report"
    };

    try
    {
        vulkan = new Vulkan();

        for(auto& layer : vulkan->getAvailableLayers()) __android_log_print(ANDROID_LOG_DEBUG, "#####", "%s: %s", "LAYER", layer.layerName);
        for(auto& extension : vulkan->getAvailableExtensions()) __android_log_print(ANDROID_LOG_DEBUG, "#####", "%s: %s", "EXTENSION", extension.extensionName);

        instance = new VulkanInstance(*vulkan, VK_VERSION_1_0, "VulkanTest", 1, "VulkanTestEngine", 1, layerCount, layers, extensionCount, extensions);
        debugReport = new VulkanDebugReport(*instance, debugCallback, nullptr);
        surface = new VulkanAndroidSurface(*instance, window);

        std::vector<VulkanPhysicalDevice> physicalDevices = instance->getPhysicalDevices();
        for(auto& physicalDevice : physicalDevices)
        {
            __android_log_print(ANDROID_LOG_DEBUG, "#####", "%s: %s", "PHYSICAL DEVICE", physicalDevice.getProperties().deviceName);
            for(auto& queueFamily : physicalDevice.getQueueFamilies())
            {
                __android_log_print(ANDROID_LOG_DEBUG, "#####", "%s: %i %s %i %s",
                                    "    QUEUE FAMILY",
                                    queueFamily.getIndex(),
                                    vulkanQueueFlagsToString(queueFamily.getProperties().queueFlags).c_str(),
                                    queueFamily.getProperties().queueFlags,
                                    vulkanBoolToString(queueFamily.canPresentOnSurface(*surface)).c_str()
                );
            }
        }
        VulkanPhysicalDevice physicalDevice = physicalDevices[0];

        executionManager = new ExecutionManager(physicalDevice, *surface);

        VulkanDevice& device = executionManager->getDevice();

        //VulkanQueue queue = device.getQueue(queueFamily, 0);
        //VulkanCommandPool commandPool(device, queueFamily);
        //VulkanCommandBuffer commandBuffer(device, commandPool, VK_COMMAND_BUFFER_LEVEL_PRIMARY);

        __android_log_print(ANDROID_LOG_DEBUG, "#####", "%s", "DONE");
    }
    catch(VulkanException& e)
    {
        __android_log_print(ANDROID_LOG_DEBUG, "#####", "%s %s %s", "ERROR: VulkanException", vulkanResultToString(e.getResult()).c_str(), e.getMessage());
        SAFE_DELETE(executionManager);
        SAFE_DELETE(surface);
        SAFE_DELETE(debugReport);
        SAFE_DELETE(instance);
        SAFE_DELETE(vulkan);
        throw;
    }
    catch(...)
    {
        __android_log_print(ANDROID_LOG_DEBUG, "#####", "%s", "ERROR: OtherException");
        SAFE_DELETE(executionManager);
        SAFE_DELETE(surface);
        SAFE_DELETE(debugReport);
        SAFE_DELETE(instance);
        SAFE_DELETE(vulkan);
        throw;
    }
}

cz::mg::vulkantest::Renderer::~Renderer()
{
    SAFE_DELETE(executionManager);
    SAFE_DELETE(surface);
    SAFE_DELETE(debugReport);
    SAFE_DELETE(instance);
    SAFE_DELETE(vulkan);
}

void cz::mg::vulkantest::Renderer::resize(int w, int h)
{

}
