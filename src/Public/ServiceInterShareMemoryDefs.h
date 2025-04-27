// SharedMemoryDefs.h
#pragma once
#include <windows.h>
#include <string>
#include <vector>

// ǿ��1�ֽڶ��룬ȷ������̽ṹ����һ��
#pragma pack(push, 1)

// �����ڴ�ͷ��Ϣ
struct SharedMemoryHeader {
    DWORD dwVersion;        // �汾�� (0x00010001)
    DWORD dwChecksum;       // ����У���
    SIZE_T nDataOffset;     // ��������ƫ����
    SIZE_T nDataSize;       // ���������С
    SYSTEMTIME lastUpdated; // ������ʱ��
};

// ��ָ������ݽṹ����Ҫ���⴦��
struct ComplexData {
    int dataType;
    SIZE_T stringOffset;    // �ַ������ݵ�ƫ����
    SIZE_T arrayOffset;     // �������ݵ�ƫ����
    SIZE_T arraySize;       // ����Ԫ�ظ���
};

#pragma pack(pop)

// �����ڴ����ƺʹ�С
constexpr LPCWSTR SHARED_MEM_NAME = L"MyAppSharedMemory";
constexpr DWORD SHARED_MEM_SIZE = 4096; // 4KB

// ����������
constexpr LPCWSTR SHARED_MUTEX_NAME = L"MyAppSharedMutex";