// system_monitor.h
#ifndef SYSTEM_MONITOR_H
#define SYSTEM_MONITOR_H

#include <sys/sysinfo.h>
#include <fstream>

class SystemMonitor {
public:
    struct SystemStatus {
        double cpu_load;
        double memory_usage;
        double disk_usage;
        // 添加更多监控指标...
    };

    SystemStatus get_current_status() {
        return {get_cpu_load(), get_memory_usage(), get_disk_usage()};
    }

private:
    double get_cpu_load() {
        // 使用/proc/stat计算CPU负载
        std::ifstream proc_stat("/proc/stat");
        // 实现CPU负载计算逻辑...
        return 0.0;
    }

    double get_memory_usage() {
        struct sysinfo mem_info;
        sysinfo(&mem_info);
        return (mem_info.totalram - mem_info.freeram) * 100.0 / mem_info.totalram;
    }

    double get_disk_usage() {
        // 使用statvfs获取磁盘使用情况
        struct statvfs vfs;
        statvfs("/", &vfs);
        return (vfs.f_blocks - vfs.f_bfree) * 100.0 / vfs.f_blocks;
    }
};
#endif
