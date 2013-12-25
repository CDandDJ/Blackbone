#pragma once

#include "NativeStructures.h"

namespace blackbone
{

// NtCreateEvent
typedef NTSTATUS( NTAPI* fnNtCreateEvent )
    ( 
        OUT PHANDLE             EventHandle,
        IN ACCESS_MASK          DesiredAccess,
        IN POBJECT_ATTRIBUTES   ObjectAttributes OPTIONAL,
        IN ULONG                EventType,
        IN BOOLEAN              InitialState 
    );

// NtOpenEvent
typedef NTSTATUS( NTAPI* fnNtOpenEvent )
    ( 
        OUT PHANDLE             EventHandle,
        IN ACCESS_MASK          DesiredAccess,
        IN POBJECT_ATTRIBUTES   ObjectAttributes
    );

// NtQueryVirtualMemory
typedef NTSTATUS( NTAPI* fnNtQueryVirtualMemory )
    (
        IN HANDLE   ProcessHandle,
        IN PVOID    BaseAddress,
        IN MEMORY_INFORMATION_CLASS MemoryInformationClass,
        OUT PVOID   MemoryInformation,
        IN SIZE_T   MemoryInformationLength,
        OUT PSIZE_T ReturnLength
    );

// NtWow64QueryInformationProcess64
typedef NTSTATUS( NTAPI *fnNtWow64QueryInformationProcess64 )
    (
        IN  HANDLE ProcessHandle,
        IN  ULONG  ProcessInformationClass,
        OUT PVOID  ProcessInformation64,
        IN  ULONG  Length,
        OUT PULONG ReturnLength OPTIONAL
    );

// NtWow64ReadVirtualMemory64
typedef NTSTATUS( NTAPI *fnNtWow64ReadVirtualMemory64 )
    (
        IN  HANDLE   ProcessHandle,
        IN  ULONG64  BaseAddress,
        OUT PVOID    Buffer,
        IN  ULONG64  BufferLength,
        OUT PULONG64 ReturnLength OPTIONAL
    );

// NtWow64WriteVirtualMemory64
typedef fnNtWow64ReadVirtualMemory64 fnNtWow64WriteVirtualMemory64;

// NtWow64AllocateVirtualMemory64
typedef NTSTATUS( NTAPI *fnNtWow64AllocateVirtualMemory64 )
    (
        IN  HANDLE   ProcessHandle,
        IN  PULONG64 BaseAddress,
        IN  ULONG64  ZeroBits,
        IN  PULONG64 Size,
        IN  ULONG    AllocationType,
        IN  ULONG    Protection
    );

// NtWow64QueryVirtualMemory64
typedef NTSTATUS( NTAPI *fnNtWow64QueryVirtualMemory64 )
    (
        IN HANDLE   ProcessHandle,
        IN ULONG64  BaseAddress,
        IN DWORD    MemoryInformationClass,
        OUT PVOID   Buffer,
        IN ULONG64  Length,
        OUT PULONG  ResultLength OPTIONAL
    );

// RtlDosApplyFileIsolationRedirection_Ustr
typedef NTSTATUS( NTAPI *fnRtlDosApplyFileIsolationRedirection_Ustr )
    (
        IN ULONG Flags,
        IN PUNICODE_STRING OriginalName,
        IN PUNICODE_STRING Extension,
        IN OUT PUNICODE_STRING StaticString,
        IN OUT PUNICODE_STRING DynamicString,
        IN OUT PUNICODE_STRING *NewName,
        IN PULONG  NewFlags,
        IN PSIZE_T FileNameSize,
        IN PSIZE_T RequiredLength
    );

// RtlHashUnicodeString
typedef NTSTATUS( NTAPI *fnRtlHashUnicodeString )
    ( 
        IN   PCUNICODE_STRING String,
        IN   BOOLEAN CaseInSensitive,
        IN   ULONG HashAlgorithm,
        OUT  PULONG HashValue
    );

// RtlRemoteCall
typedef NTSTATUS( NTAPI *fnRtlRemoteCall )
    (
        IN HANDLE Process,
        IN HANDLE Thread,
        IN PVOID CallSite,
        IN ULONG ArgumentCount,
        IN PULONG Arguments,
        IN BOOLEAN PassContext,
        IN BOOLEAN AlreadySuspended
    );

// NtCreateThreadEx
typedef NTSTATUS( NTAPI* fnNtCreateThreadEx )
    (
        OUT PHANDLE hThread,
        IN ACCESS_MASK DesiredAccess,
        IN LPVOID ObjectAttributes,
        IN HANDLE ProcessHandle,
        IN LPTHREAD_START_ROUTINE lpStartAddress,
        IN LPVOID lpParameter,
        IN BOOL CreateSuspended,
        IN SIZE_T StackZeroBits,
        IN SIZE_T SizeOfStackCommit,
        IN SIZE_T SizeOfStackReserve,
        OUT LPVOID lpBytesBuffer
    );

// NtLockVirtualMemory
typedef NTSTATUS( NTAPI* fnNtLockVirtualMemory )
    (
        IN HANDLE process, 
        IN OUT PVOID* baseAddress, 
        IN OUT ULONG* size, 
        IN ULONG flags
    );

// RtlRbInsertNodeEx
typedef int ( NTAPI* fnRtlRbInsertNodeEx )
    (
        PRTL_RB_TREE 	    Tree,
        PRTL_BALANCED_NODE 	Parent,
        BOOLEAN             Right,
        PRTL_BALANCED_NODE 	Node
    );

// NtSetInformationProcess
typedef NTSTATUS ( NTAPI* fnNtSetInformationProcess)
    (
        IN HANDLE   ProcessHandle,
        IN PROCESS_INFORMATION_CLASS ProcessInformationClass,
        IN PVOID    ProcessInformation,
        IN ULONG    ProcessInformationLength 
    );

// RtlRbRemoveNode
typedef int (NTAPI* fnRtlRbRemoveNode)
    (
        PRTL_RB_TREE        Tree,
        PRTL_BALANCED_NODE 	Node
    );

// RtlUpcaseUnicodeChar
typedef WCHAR( NTAPI *fnRtlUpcaseUnicodeChar )
    (
        WCHAR chr
    );

// RtlEncodeSystemPointer
typedef PVOID( NTAPI *fnRtlEncodeSystemPointer )
    (
        IN PVOID Pointer
    );

// NtLoadDriver
typedef NTSTATUS( NTAPI* fnNtLoadDriver )
    (
        IN PUNICODE_STRING path
    );

// NtUnloadDriver
typedef NTSTATUS( NTAPI* fnNtUnloadDriver )
    (
        IN PUNICODE_STRING path
    );


// RtlInitUnicodeString
typedef decltype(&RtlInitUnicodeString) fnRtlInitUnicodeString;

// RtlFreeUnicodeString
typedef decltype(&RtlFreeUnicodeString) fnRtlFreeUnicodeString;

// NtQueryInformationProcess
typedef decltype(&NtQueryInformationProcess) fnNtQueryInformationProcess;

// NtQueryInformationThread
typedef decltype(&NtQueryInformationThread) fnNtQueryInformationThread;

}