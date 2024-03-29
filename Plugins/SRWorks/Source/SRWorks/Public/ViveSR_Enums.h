//========= Copyright 2018, HTC Corporation. All rights reserved. ===========
#pragma once

namespace ViveSR
{
    /** @enum ModuleStatus
    An enum type for module status.
    */
	enum ModuleStatus {
		CREATE				= 0,
		INITIAL				= 1,
		START				= 2,
		STOP				= 3,
		RELEASE				= 4,
		DESTROY				= 5,
        BLOCKED             = 6
	};

    /** @enum Error
    An enum type for error code of SRWorks engine.
    */
	enum Error {
		RUNTIME_NOT_FOUND	= -3, // please follows SRWorks SDK guide to install SR_Runtime first
		NOT_INITIAL			= -2,
		FAILED				= -1,
		WORK				= 0,
		INVALID_INPUT		= 1,
		FILE_NOT_FOUND		= 2,
		DATA_NOT_FOUND		= 13,
		UNDEFINED			= 319,
		INITIAL_FAILED		= 1001,
		NOT_IMPLEMENTED		= 1003,
		NULL_POINTER		= 1004,
		OVER_MAX_LENGTH		= 1005,
		FILE_INVALID		= 1006,
		UNINSTALL_STEAM		= 1007,
		MEMCPY_FAIL			= 1008,
		NOT_MATCH			= 1009,
		NODE_NOT_EXIST		= 1010,
		UNKONW_MODULE		= 1011,
		MODULE_FULL			= 1012,
		UNKNOW_TYPE			= 1013,
		INVALID_MODULE		= 1014,
		INVALID_TYPE		= 1015,
		MEMORY_NOT_ENOUGH	= 1016,
		BUSY				= 1017,
		NOT_SUPPORTED		= 1018,
		INVALID_VALUE		= 1019,
		COMING_SOON			= 1020,
		INVALID_CHANGE		= 1021, // this/these module parameter can't be changed dynamic
		TIMEOUT				= 1022,
		DEVICE_NOT_FOUND	= 1023,
		INVALID_DEVICE		= 1024,
		NOT_AUTHORIZED		= 1025,
		ALREADY				= 1026,
		INTERNAL			= 1027,
		CONNECTION_FAILED	= 1028,
		ALLOCATION_FAILED	= 1029,
		OPERATION_FAILED	= 1030,
		NOT_AVAILABLE		= 1031,
		CALLBACK_IN_PROGRESS= 1032,
		SERVICE_NOT_FOUND	= 1033,
        DISABLED_BY_USER    = 1034,
        EULA_NOT_ACCEPT     = 1035,
        NO_NEW_DATA         = 1036,
        OPENCL_NOT_SUPPORT  = 1037,
        // 1038 - 1050 reserved
        JSON_LOAD_FAILED    = 1051,
        CAMERA_NOT_ENABLED  = 1052,
        GPU_MEMORY_FULL     = 1053,
        CUDA_NOT_SUPPORT    = 1054,
        CUDA_RUNTIME_ERROR  = 1055,
        CUDA_DRIVER_ERROR   = 1056,
        UNKNOWN_ERROR       = 1057
	};
	/** @enum VRDevice
    An enum type of the VR device.
    */
    enum VRDevice {
        None,
        VIVE_PRO,
        COSMOS,
    };
    enum SharedMemorySizeSetting {
        OUTPUT_HAS_NOT_SELFMODULE = 3,
        OUTPUT_HAS_ONE_SELFMODULE = 4
    };
    enum EulaChoice {
        EULA_DENY,
        EULA_ALLOW,
    };
}
