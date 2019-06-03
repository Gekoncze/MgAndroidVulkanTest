#include "VulkanInstance.h"
#include "VulkanException.h"

using namespace cz::mg::vulkan;

cz::mg::vulkan::VulkanInstance::VulkanInstance(Vulkan& vulkan, uint32_t apiVersion, const char* applicationName, uint32_t applicationVersion, const char* engineName, uint32_t engineVersion, uint32_t layerCount, const char* const* layers, uint32_t extensionCount, const char* const* extensions)
{
    (void)vulkan;

    VkApplicationInfo applicationInfo = {};
    applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    applicationInfo.pNext = NULL;
    applicationInfo.pApplicationName = applicationName;
    applicationInfo.applicationVersion = applicationVersion;
    applicationInfo.pEngineName = engineName;
    applicationInfo.engineVersion = engineVersion;
    applicationInfo.apiVersion = apiVersion;

    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pNext = NULL;
    createInfo.flags = 0;
    createInfo.pApplicationInfo = &applicationInfo;
    createInfo.enabledLayerCount = layerCount;
    createInfo.ppEnabledLayerNames = layers;
    createInfo.enabledExtensionCount = extensionCount;
    createInfo.ppEnabledExtensionNames = extensions;

    VkResult result = vkCreateInstance(&createInfo, NULL, &instance);
    if(result != VK_SUCCESS)
    {
        throw VulkanException(result, "Could not create vulkan instance.");
    }
}

cz::mg::vulkan::VulkanInstance::~VulkanInstance()
{
    vkDestroyInstance(instance, nullptr);
}

std::vector<VulkanPhysicalDevice> cz::mg::vulkan::VulkanInstance::getPhysicalDevices()
{
    VkResult result;
    uint32_t count;
    if((result = vkEnumeratePhysicalDevices(instance, &count, nullptr)) != VK_SUCCESS) throw VulkanException(result, "Could not enumerate physical devices.");
    std::vector<VkPhysicalDevice> devices(count);
    if((result = vkEnumeratePhysicalDevices(instance, &count, devices.data())) != VK_SUCCESS) throw VulkanException(result, "Could not enumerate physical devices.");
    std::vector<VulkanPhysicalDevice> pdevices;
    for(VkPhysicalDevice d : devices) pdevices.push_back(VulkanPhysicalDevice(d));
    return pdevices;
}

PFN_vkVoidFunction VulkanInstance::loadFunction(const char* fname)
{
    PFN_vkVoidFunction f = vkGetInstanceProcAddr(instance, fname);
    if(f == nullptr) throw VulkanException(VK_RESULT_MAX_ENUM, fname);
    return f;
}
