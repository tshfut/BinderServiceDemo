LOCAL_PATH := $(call my-dir)

#生成binder service的服务端

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
    libbinder 

LOCAL_MODULE    := TestServer

LOCAL_SRC_FILES := \
    main_tprimetestservice.cpp \
    TPrimeTestService.cpp \
    ITest.cpp
LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)
 
#生成binder service的测试client端
include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
    libbinder 
LOCAL_MODULE    := TestClient
LOCAL_SRC_FILES := \
    TestClient.cpp \
    ITest.cpp
LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)