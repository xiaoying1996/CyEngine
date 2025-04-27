// SharedMemoryDefs.h
#pragma once
#include <windows.h>
#include <string>
#include <vector>

// 强制1字节对齐，确保跨进程结构布局一致
#pragma pack(push, 1)

// 共享内存头信息
struct SharedMemoryHeader {
    DWORD dwVersion;        // 版本号 (0x00010001)
    DWORD dwChecksum;       // 数据校验和
    SIZE_T nDataOffset;     // 数据区域偏移量
    SIZE_T nDataSize;       // 数据区域大小
    SYSTEMTIME lastUpdated; // 最后更新时间
};

// 带指针的数据结构（需要特殊处理）
struct ComplexData {
    int dataType;
    SIZE_T stringOffset;    // 字符串数据的偏移量
    SIZE_T arrayOffset;     // 数组数据的偏移量
    SIZE_T arraySize;       // 数组元素个数
};

#pragma pack(pop)

// 共享内存名称和大小
constexpr LPCWSTR SHARED_MEM_NAME = L"MyAppSharedMemory";
constexpr DWORD SHARED_MEM_SIZE = 4096; // 4KB

// 互斥锁名称
constexpr LPCWSTR SHARED_MUTEX_NAME = L"MyAppSharedMutex";