LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CFLAGS := -w
LOCAL_C_INCLUDES := C:/Users/Work/AndroidStudioProjects/GroupSignature/app/src/main/jni/include

LOCAL_MODULE    := ndkLib

LOCAL_SRC_FILES := main.c
LOCAL_SRC_FILES += ./src/hash/hashing.c
LOCAL_SRC_FILES += ./src/hash/Keccak-compact.c
LOCAL_SRC_FILES += ./src/hash/sha1.c
LOCAL_SRC_FILES += ./src/param.c
LOCAL_SRC_FILES += ./src/rand.c
LOCAL_SRC_FILES += ./src/base/std/ec/ecfp.c
LOCAL_SRC_FILES += ./src/base/std/ec/ecfp2.c
LOCAL_SRC_FILES += ./src/base/std/bigint/bi.c
LOCAL_SRC_FILES += ./src/base/std/bigint/bi_const.c
LOCAL_SRC_FILES += ./src/base/std/fp/fp.c
LOCAL_SRC_FILES += ./src/base/std/fp/fp2.c
LOCAL_SRC_FILES += ./src/base/std/fp/fp4.c
LOCAL_SRC_FILES += ./src/base/std/fp/fp12.c
LOCAL_SRC_FILES += ./src/base/std/pbc/pbc_bn.c
LOCAL_SRC_FILES += ./src/sdh/sdh_zk.c
include $(BUILD_SHARED_LIBRARY)

LOCAL_PATH := $(call my-dir)