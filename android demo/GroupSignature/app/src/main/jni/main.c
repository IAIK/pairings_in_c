#include "iaik_at_groupsignature_MainActivity.h"
#include <stdio.h>
#include "types.h"
#include "hash/hashing.h"
#include "bigint/bi.h"
#include <string.h>
#include <time.h>
#include "gss/sdh_zk.h"

#define DEBUG 1
#if DEBUG
#include <android/log.h>
#  define  D(x...)  __android_log_print(ANDROID_LOG_INFO,"Native-Code",x)
#else
#  define  D(...)  do {} while (0)
#endif

/*
 * Class:     iaik_at_groupsignature_MainActivity
 * Method:    verify
 * Signature: (Ljava/lang/String;Liaik/at/groupsignature/GroupPublicKey;Liaik/at/groupsignature/SdhSignature;)I
 */
JNIEXPORT jint JNICALL Java_iaik_at_groupsignature_MainActivity_verify
        (JNIEnv *env, jclass jcls, jstring message, jobject gpk_object, jobject sig_object)
{
    // local for library methods
    group_public_key gpk;
    sdh_signiture sig;

    // get class object of gpk
    jclass clsTest = (*env)->GetObjectClass(env, gpk_object);

    // get u_object with "L$YOUR_PACKAGE.CLASS_NAME$;"
    jfieldID fidTest = (*env)->GetFieldID(env, clsTest, "u", "Liaik/at/groupsignature/EcPoint_Fp;");
    jobject u_object = (*env)->GetObjectField(env, gpk_object, fidTest);
    // get x int-array out of the class
    jclass cls = (*env)->GetObjectClass(env, u_object);
    // "[I" ---> int-array
    jfieldID fid = (*env)->GetFieldID(env, cls, "x", "[I");
    jobject data = (*env)->GetObjectField(env, u_object, fid);
    jintArray *array = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, gpk.u.x);
    // get y int-array out of the class
    fid = (*env)->GetFieldID(env, cls, "y", "[I");
    data = (*env)->GetObjectField(env, u_object, fid);
    jintArray *array1 = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, gpk.u.y);
    gpk.u.infinity = 0;

    // repeat for all similar classes in gpk
    fidTest = (*env)->GetFieldID(env, clsTest, "h", "Liaik/at/groupsignature/EcPoint_Fp;");
    jobject h_object = (*env)->GetObjectField(env, gpk_object, fidTest);
    cls = (*env)->GetObjectClass(env, h_object);
    fid = (*env)->GetFieldID(env, cls, "x", "[I");
    data = (*env)->GetObjectField(env, h_object, fid);
    array = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, gpk.h.x);

    fid = (*env)->GetFieldID(env, cls, "y", "[I");
    data = (*env)->GetObjectField(env, h_object, fid);
    array1 = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, gpk.h.y);
    gpk.h.infinity = 0;

    fidTest = (*env)->GetFieldID(env, clsTest, "v", "Liaik/at/groupsignature/EcPoint_Fp;");
    jobject v_object = (*env)->GetObjectField(env, gpk_object, fidTest);
    cls = (*env)->GetObjectClass(env, v_object);
    fid = (*env)->GetFieldID(env, cls, "x", "[I");
    data = (*env)->GetObjectField(env, v_object, fid);
    array = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, gpk.v.x);

    fid = (*env)->GetFieldID(env, cls, "y", "[I");
    data = (*env)->GetObjectField(env, v_object, fid);
    array1 = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, gpk.v.y);
    gpk.v.infinity = 0;


    fidTest = (*env)->GetFieldID(env, clsTest, "g1", "Liaik/at/groupsignature/EcPoint_Fp;");
    jobject g1_object = (*env)->GetObjectField(env, gpk_object, fidTest);
    cls = (*env)->GetObjectClass(env, g1_object);
    fid = (*env)->GetFieldID(env, cls, "x", "[I");
    data = (*env)->GetObjectField(env, g1_object, fid);
    array = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, gpk.g1.x);

    fid = (*env)->GetFieldID(env, cls, "y", "[I");
    data = (*env)->GetObjectField(env, g1_object, fid);
    array1 = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, gpk.g1.y);
    gpk.g1.infinity = 0;

    // do the same thing for other classes with other parameters
    ecpoint_fp2 w;
    fidTest = (*env)->GetFieldID(env, clsTest, "w", "Liaik/at/groupsignature/EcPoint_Fp2;");
    jobject w_object = (*env)->GetObjectField(env, gpk_object, fidTest);
    cls = (*env)->GetObjectClass(env, w_object);
    fid = (*env)->GetFieldID(env, cls, "x", "[[I");
    data = (*env)->GetObjectField(env, w_object, fid);
    jobjectArray *objArray = (jobjectArray*) (data);
    array = (jintArray*) (*env)->GetObjectArrayElement(env, objArray, 0);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, gpk.w.x[0]);
    array1 = (jintArray*) (*env)->GetObjectArrayElement(env, objArray, 1);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, gpk.w.x[1]);

    fid = (*env)->GetFieldID(env, cls, "y", "[[I");
    data = (*env)->GetObjectField(env, w_object, fid);
    objArray = (jobjectArray*) (data);
    array = (jintArray*) (*env)->GetObjectArrayElement(env, objArray, 0);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, gpk.w.y[0]);
    array1 = (jintArray*) (*env)->GetObjectArrayElement(env, objArray, 1);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, gpk.w.y[1]);
    gpk.w.infinity = 0;

    ecpoint_fp2 g2;
    fidTest = (*env)->GetFieldID(env, clsTest, "g2", "Liaik/at/groupsignature/EcPoint_Fp2;");
    jobject g2_object = (*env)->GetObjectField(env, gpk_object, fidTest);
    cls = (*env)->GetObjectClass(env, g2_object);
    fid = (*env)->GetFieldID(env, cls, "x", "[[I");
    data = (*env)->GetObjectField(env, g2_object, fid);

    objArray = (jobjectArray*) (data);
    array = (jintArray*) (*env)->GetObjectArrayElement(env, objArray, 0);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, gpk.g2.x[0]);
    array1 = (jintArray*) (*env)->GetObjectArrayElement(env, objArray, 1);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, gpk.g2.x[1]);

    fid = (*env)->GetFieldID(env, cls, "y", "[[I");
    data = (*env)->GetObjectField(env, g2_object, fid);
    objArray = (jobjectArray*) (data);
    array = (jintArray*) (*env)->GetObjectArrayElement(env, objArray, 0);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, gpk.g2.y[0]);
    array1 = (jintArray*) (*env)->GetObjectArrayElement(env, objArray, 1);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, gpk.g2.y[1]);
    gpk.g2.infinity = 0;

    // the same process for the signature, adapted for the new class
    clsTest = (*env)->GetObjectClass(env, sig_object);
    fid = (*env)->GetFieldID(env, clsTest, "c", "[I");
    jintArray *c = (jintArray*) (*env)->GetObjectField(env, sig_object, fid);
    (*env)->GetIntArrayRegion(env, c, 0, BI_WORDS, sig.c);

    fid = (*env)->GetFieldID(env, clsTest, "s_alpha", "[I");
    jintArray *s_alpha = (jintArray*) (*env)->GetObjectField(env, sig_object, fid);
    (*env)->GetIntArrayRegion(env, s_alpha, 0, BI_WORDS, sig.s_alpha);

    fid = (*env)->GetFieldID(env, clsTest, "s_beta", "[I");
    jintArray *s_beta = (jintArray*) (*env)->GetObjectField(env, sig_object, fid);
    (*env)->GetIntArrayRegion(env, s_beta, 0, BI_WORDS, sig.s_beta);

    fid = (*env)->GetFieldID(env, clsTest, "s_x", "[I");
    jintArray *s_x = (jintArray*) (*env)->GetObjectField(env, sig_object, fid);
    (*env)->GetIntArrayRegion(env, s_x, 0, BI_WORDS, sig.s_x);

    fid = (*env)->GetFieldID(env, clsTest, "s_delta1", "[I");
    jintArray *s_delta1 = (jintArray*) (*env)->GetObjectField(env, sig_object, fid);
    (*env)->GetIntArrayRegion(env, s_delta1, 0, BI_WORDS, sig.s_delta1);

    fid = (*env)->GetFieldID(env, clsTest, "s_delta2", "[I");
    jintArray *s_delta2 = (jintArray*) (*env)->GetObjectField(env, sig_object, fid);
    (*env)->GetIntArrayRegion(env, s_delta2, 0, BI_WORDS, sig.s_delta2);

    // get object
    fidTest = (*env)->GetFieldID(env, clsTest, "T_1", "Liaik/at/groupsignature/EcPoint_Fp;");
    jobject T1_object = (*env)->GetObjectField(env, sig_object, fidTest);

    cls = (*env)->GetObjectClass(env, T1_object);
    fid = (*env)->GetFieldID(env, cls, "x", "[I");
    data = (*env)->GetObjectField(env, T1_object, fid);
    array = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, sig.T_1.x);

    fid = (*env)->GetFieldID(env, cls, "y", "[I");
    data = (*env)->GetObjectField(env, T1_object, fid);
    array1 = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, sig.T_1.y);

    // get object
    fidTest = (*env)->GetFieldID(env, clsTest, "T_2", "Liaik/at/groupsignature/EcPoint_Fp;");
    jobject T2_object = (*env)->GetObjectField(env, sig_object, fidTest);

    cls = (*env)->GetObjectClass(env, T2_object);
    fid = (*env)->GetFieldID(env, cls, "x", "[I");
    data = (*env)->GetObjectField(env, T2_object, fid);
    array = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, sig.T_2.x);

    fid = (*env)->GetFieldID(env, cls, "y", "[I");
    data = (*env)->GetObjectField(env, T2_object, fid);
    array1 = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, sig.T_2.y);

    // get object
    fidTest = (*env)->GetFieldID(env, clsTest, "T_3", "Liaik/at/groupsignature/EcPoint_Fp;");
    jobject T3_object = (*env)->GetObjectField(env, sig_object, fidTest);

    cls = (*env)->GetObjectClass(env, T3_object);
    fid = (*env)->GetFieldID(env, cls, "x", "[I");
    data = (*env)->GetObjectField(env, T3_object, fid);
    array = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, sig.T_3.x);

    fid = (*env)->GetFieldID(env, cls, "y", "[I");
    data = (*env)->GetObjectField(env, T3_object, fid);
    array1 = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, sig.T_3.y);

    const char *var_a = (char*)(*env)->GetStringUTFChars(env, message, NULL);
    // verify the signature if every structure needed is initialized
    clock_t t;
    t = clock();
    sbyte verify = sgs_verify(gpk, sig, var_a);
    t = clock() - t;
    D("TIME: %f", ((double)t)/CLOCKS_PER_SEC);
    // return the result
    return verify;
}

/*
 * Class:     iaik_at_groupsignature_MainActivity
 * Method:    sign
 * Signature: (Ljava/lang/String;Liaik/at/groupsignature/GroupPublicKey;Liaik/at/groupsignature/GroupSecretKey;)Liaik/at/groupsignature/SdhSignature;
 */
JNIEXPORT jobject JNICALL Java_iaik_at_groupsignature_MainActivity_sign
        (JNIEnv *env, jobject obj, jstring message, jobject gpk_object, jobject gsk_object)
{
    clock_t t_with_jni;
    t_with_jni = clock();

    group_public_key gpk;
    group_secret_key gsk;

    jclass clsTest = (*env)->GetObjectClass(env, gpk_object);


    // get u_object
    jfieldID fidTest = (*env)->GetFieldID(env, clsTest, "u", "Liaik/at/groupsignature/EcPoint_Fp;");
    jobject u_object = (*env)->GetObjectField(env, gpk_object, fidTest);

    jclass cls = (*env)->GetObjectClass(env, u_object);
    jfieldID fid = (*env)->GetFieldID(env, cls, "x", "[I");
    jobject data = (*env)->GetObjectField(env, u_object, fid);
    jintArray *array = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, gpk.u.x);

    fid = (*env)->GetFieldID(env, cls, "y", "[I");
    data = (*env)->GetObjectField(env, u_object, fid);
    jintArray *array1 = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, gpk.u.y);
    //ecpoint_fp u;
    gpk.u.infinity = 0;

    fidTest = (*env)->GetFieldID(env, clsTest, "h", "Liaik/at/groupsignature/EcPoint_Fp;");
    jobject h_object = (*env)->GetObjectField(env, gpk_object, fidTest);
    cls = (*env)->GetObjectClass(env, h_object);
    fid = (*env)->GetFieldID(env, cls, "x", "[I");
    data = (*env)->GetObjectField(env, h_object, fid);
    array = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, gpk.h.x);

    fid = (*env)->GetFieldID(env, cls, "y", "[I");
    data = (*env)->GetObjectField(env, h_object, fid);
    array1 = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, gpk.h.y);
    gpk.h.infinity = 0;

    fidTest = (*env)->GetFieldID(env, clsTest, "v", "Liaik/at/groupsignature/EcPoint_Fp;");
    jobject v_object = (*env)->GetObjectField(env, gpk_object, fidTest);
    cls = (*env)->GetObjectClass(env, v_object);
    fid = (*env)->GetFieldID(env, cls, "x", "[I");
    data = (*env)->GetObjectField(env, v_object, fid);
    array = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, gpk.v.x);

    fid = (*env)->GetFieldID(env, cls, "y", "[I");
    data = (*env)->GetObjectField(env, v_object, fid);
    array1 = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, gpk.v.y);
    gpk.v.infinity = 0;


    fidTest = (*env)->GetFieldID(env, clsTest, "g1", "Liaik/at/groupsignature/EcPoint_Fp;");
    jobject g1_object = (*env)->GetObjectField(env, gpk_object, fidTest);
    cls = (*env)->GetObjectClass(env, g1_object);
    fid = (*env)->GetFieldID(env, cls, "x", "[I");
    data = (*env)->GetObjectField(env, g1_object, fid);
    array = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, gpk.g1.x);

    fid = (*env)->GetFieldID(env, cls, "y", "[I");
    data = (*env)->GetObjectField(env, g1_object, fid);
    array1 = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, gpk.g1.y);
    gpk.g1.infinity = 0;

    ecpoint_fp2 w;
    fidTest = (*env)->GetFieldID(env, clsTest, "w", "Liaik/at/groupsignature/EcPoint_Fp2;");
    jobject w_object = (*env)->GetObjectField(env, gpk_object, fidTest);
    cls = (*env)->GetObjectClass(env, w_object);
    fid = (*env)->GetFieldID(env, cls, "x", "[[I");
    data = (*env)->GetObjectField(env, w_object, fid);
    jobjectArray *objArray = (jobjectArray*) (data);
    array = (jintArray*) (*env)->GetObjectArrayElement(env, objArray, 0);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, gpk.w.x[0]);
    array1 = (jintArray*) (*env)->GetObjectArrayElement(env, objArray, 1);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, gpk.w.x[1]);

    fid = (*env)->GetFieldID(env, cls, "y", "[[I");
    data = (*env)->GetObjectField(env, w_object, fid);
    objArray = (jobjectArray*) (data);
    array = (jintArray*) (*env)->GetObjectArrayElement(env, objArray, 0);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, gpk.w.y[0]);
    array1 = (jintArray*) (*env)->GetObjectArrayElement(env, objArray, 1);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, gpk.w.y[1]);
    gpk.w.infinity = 0;

    ecpoint_fp2 g2;
    fidTest = (*env)->GetFieldID(env, clsTest, "g2", "Liaik/at/groupsignature/EcPoint_Fp2;");
    jobject g2_object = (*env)->GetObjectField(env, gpk_object, fidTest);
    cls = (*env)->GetObjectClass(env, g2_object);
    fid = (*env)->GetFieldID(env, cls, "x", "[[I");
    data = (*env)->GetObjectField(env, g2_object, fid);

    objArray = (jobjectArray*) (data);
    array = (jintArray*) (*env)->GetObjectArrayElement(env, objArray, 0);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, gpk.g2.x[0]);
    array1 = (jintArray*) (*env)->GetObjectArrayElement(env, objArray, 1);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, gpk.g2.x[1]);

    fid = (*env)->GetFieldID(env, cls, "y", "[[I");
    data = (*env)->GetObjectField(env, g2_object, fid);
    objArray = (jobjectArray*) (data);
    array = (jintArray*) (*env)->GetObjectArrayElement(env, objArray, 0);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, gpk.g2.y[0]);
    array1 = (jintArray*) (*env)->GetObjectArrayElement(env, objArray, 1);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, gpk.g2.y[1]);
    gpk.g2.infinity = 0;

    clsTest = (*env)->GetObjectClass(env, gsk_object);

    fidTest = (*env)->GetFieldID(env, clsTest, "A", "Liaik/at/groupsignature/EcPoint_Fp;");
    jobject A_object = (*env)->GetObjectField(env, gsk_object, fidTest);

    cls = (*env)->GetObjectClass(env, A_object);
    fid = (*env)->GetFieldID(env, cls, "x", "[I");
    data = (*env)->GetObjectField(env, A_object, fid);
    array = (jintArray*) (data);
    int *A_x = (*env)->GetIntArrayElements(env, array, 0);

    fid = (*env)->GetFieldID(env, cls, "y", "[I");
    data = (*env)->GetObjectField(env, A_object, fid);
    array = (jintArray*) (data);
    int *A_y = (*env)->GetIntArrayElements(env, array, 0);

    fid = (*env)->GetFieldID(env, clsTest, "x", "[I");
    data = (*env)->GetObjectField(env, gsk_object, fid);
    array1 = (jintArray*) (data);
    int *x_array = (*env)->GetIntArrayElements(env, array1, 0);

    bigint_t x;
    int i = 0;
    ecpoint_fp A;
    for (i = 0; i < BI_WORDS; ++i) {
        A.x[i] = *(A_x+i);
        A.y[i] = *(A_y+i);
        x[i] = *(x_array+i);
    }
    A.infinity = 0;

    ecfp_copy(&gsk.A, &A);
    bi_copy(gsk.x, x);

    sdh_signiture sig;
    const char *var_a = (char*)(*env)->GetStringUTFChars(env, message, NULL);
    // after everything is initialized generate the signature
    clock_t t;
    t = clock();
    sgs_sign(gpk, gsk, &sig, var_a);
    t = clock() - t;
    D("TIME: %f", ((double)t)/CLOCKS_PER_SEC);
    /*
    t = clock();
    sbyte verify = sgs_verify(gpk, sig, var_a);
    t = clock() - t;
    D("TIME ver: %f", ((double)t)/CLOCKS_PER_SEC);

    hwang_signing_key sk;
    hwang_public_parameters parameters;
    hwang_signature sig_hwang;

    hwang_init_parameters(&parameters);

    hwang_generate_usk(&sk, &parameters);

    t = clock();
    hwang_sign(&sig_hwang, &parameters, &sk);
    t = clock() - t;
    D("TIME hwang: %f", ((double)t)/CLOCKS_PER_SEC);

    t = clock();
    hwang_verify(&parameters, &sig_hwang);
    t = clock() - t;
    D("TIME hwang-ver: %f", ((double)t)/CLOCKS_PER_SEC);
    */

    // get the class for returning the signature (must be equal to the structure in C)
    jclass outCls = (*env)->FindClass(env, "iaik/at/groupsignature/SdhSignature");
    // get the constructor
    jmethodID constructor = (*env)->GetMethodID(env, outCls, "<init>", "()V");;
    // initialize the object
    jobject jresult = (*env)->NewObject(env, outCls, constructor);
    // copy all parameters of the signature to the new result-object
    jfieldID fidOut = (*env)->GetFieldID(env, outCls, "c", "[I");
    jintArray c = (jintArray) (*env)->GetObjectField(env, jresult, fidOut);
    (*env)->SetIntArrayRegion(env, c, 0, BI_WORDS, sig.c);

    fidOut = (*env)->GetFieldID(env, outCls, "s_alpha", "[I");
    jintArray s_alpha = (jintArray) (*env)->GetObjectField(env, jresult, fidOut);
    (*env)->SetIntArrayRegion(env, s_alpha, 0, BI_WORDS, sig.s_alpha);

    fidOut = (*env)->GetFieldID(env, outCls, "s_beta", "[I");
    jintArray s_beta = (jintArray) (*env)->GetObjectField(env, jresult, fidOut);
    (*env)->SetIntArrayRegion(env, s_beta, 0, BI_WORDS, sig.s_beta);

    fidOut = (*env)->GetFieldID(env, outCls, "s_x", "[I");
    jintArray s_x = (jintArray) (*env)->GetObjectField(env, jresult, fidOut);
    (*env)->SetIntArrayRegion(env, s_x, 0, BI_WORDS, sig.s_x);

    fidOut = (*env)->GetFieldID(env, outCls, "s_delta1", "[I");
    jintArray s_delta1 = (jintArray) (*env)->GetObjectField(env, jresult, fidOut);
    (*env)->SetIntArrayRegion(env, s_delta1, 0, BI_WORDS, sig.s_delta1);

    fidOut = (*env)->GetFieldID(env, outCls, "s_delta2", "[I");
    jintArray s_delta2 = (jintArray) (*env)->GetObjectField(env, jresult, fidOut);
    (*env)->SetIntArrayRegion(env, s_delta2, 0, BI_WORDS, sig.s_delta2);

    fidOut = (*env)->GetFieldID(env, outCls, "T_1", "Liaik/at/groupsignature/EcPoint_Fp;");
    jobject t1_object = (*env)->GetObjectField(env, jresult, fidOut);
    cls = (*env)->GetObjectClass(env, t1_object);
    fid = (*env)->GetFieldID(env, cls, "x", "[I");
    jintArray ec_out_x = (jintArray) (*env)->GetObjectField(env, t1_object, fid);
    (*env)->SetIntArrayRegion(env, ec_out_x, 0, BI_WORDS, sig.T_1.x);

    fid = (*env)->GetFieldID(env, cls, "y", "[I");
    jintArray ec_out_y = (jintArray) (*env)->GetObjectField(env, t1_object, fid);
    (*env)->SetIntArrayRegion(env, ec_out_y, 0, BI_WORDS, sig.T_1.y);

    fid = (*env)->GetFieldID(env, cls, "infinity", "B");
    (*env)->SetByteField(env, t1_object, fid, sig.T_1.infinity);

    fidOut = (*env)->GetFieldID(env, outCls, "T_2", "Liaik/at/groupsignature/EcPoint_Fp;");
    jobject t2_object = (*env)->GetObjectField(env, jresult, fidOut);
    cls = (*env)->GetObjectClass(env, t2_object);
    fid = (*env)->GetFieldID(env, cls, "x", "[I");
    ec_out_x = (jintArray) (*env)->GetObjectField(env, t2_object, fid);
    (*env)->SetIntArrayRegion(env, ec_out_x, 0, BI_WORDS, sig.T_2.x);

    fid = (*env)->GetFieldID(env, cls, "y", "[I");
    ec_out_y = (jintArray) (*env)->GetObjectField(env, t2_object, fid);
    (*env)->SetIntArrayRegion(env, ec_out_y, 0, BI_WORDS, sig.T_2.y);

    fid = (*env)->GetFieldID(env, cls, "infinity", "B");
    (*env)->SetByteField(env, t2_object, fid, sig.T_2.infinity);

    fidOut = (*env)->GetFieldID(env, outCls, "T_3", "Liaik/at/groupsignature/EcPoint_Fp;");
    jobject t3_object = (*env)->GetObjectField(env, jresult, fidOut);
    cls = (*env)->GetObjectClass(env, t3_object);
    fid = (*env)->GetFieldID(env, cls, "x", "[I");
    ec_out_x = (jintArray) (*env)->GetObjectField(env, t3_object, fid);
    (*env)->SetIntArrayRegion(env, ec_out_x, 0, BI_WORDS, sig.T_3.x);

    fid = (*env)->GetFieldID(env, cls, "y", "[I");
    ec_out_y = (jintArray) (*env)->GetObjectField(env, t3_object, fid);
    (*env)->SetIntArrayRegion(env, ec_out_y, 0, BI_WORDS, sig.T_3.y);

    fid = (*env)->GetFieldID(env, cls, "infinity", "B");
    (*env)->SetByteField(env, t3_object, fid, sig.T_3.infinity);
    // return result
    t_with_jni = clock() - t_with_jni;
    D("TIME in C with JNI: %f", ((double)t_with_jni)/CLOCKS_PER_SEC);
    return jresult;
}

/*
 * Class:     iaik_at_groupsignature_MainActivity
 * Method:    open
 * Signature: (Liaik/at/groupsignature/GroupMasterSecretKey;Liaik/at/groupsignature/SdhSignature;)[I
 */
JNIEXPORT jobject JNICALL Java_iaik_at_groupsignature_MainActivity_open
        (JNIEnv *env, jclass jcls, jobject gmsk_object, jobject sig_object)
{
    // basically the same things are used in this method than in the methods above
    sdh_signiture sig;
    group_master_secret_key gmsk;

    jclass clsTest = (*env)->GetObjectClass(env, sig_object);
    // get object
    jfieldID fidTest = (*env)->GetFieldID(env, clsTest, "T_1", "Liaik/at/groupsignature/EcPoint_Fp;");
    jobject T1_object = (*env)->GetObjectField(env, sig_object, fidTest);

    jclass cls = (*env)->GetObjectClass(env, T1_object);
    jfieldID fid = (*env)->GetFieldID(env, cls, "x", "[I");
    jobject data = (*env)->GetObjectField(env, T1_object, fid);
    jintArray *array = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, sig.T_1.x);

    fid = (*env)->GetFieldID(env, cls, "y", "[I");
    data = (*env)->GetObjectField(env, T1_object, fid);
    jintArray *array1 = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, sig.T_1.y);
    sig.T_2.infinity = 0;

    // get object
    fidTest = (*env)->GetFieldID(env, clsTest, "T_2", "Liaik/at/groupsignature/EcPoint_Fp;");
    jobject T2_object = (*env)->GetObjectField(env, sig_object, fidTest);

    cls = (*env)->GetObjectClass(env, T2_object);
    fid = (*env)->GetFieldID(env, cls, "x", "[I");
    data = (*env)->GetObjectField(env, T2_object, fid);
    array = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, sig.T_2.x);

    fid = (*env)->GetFieldID(env, cls, "y", "[I");
    data = (*env)->GetObjectField(env, T2_object, fid);
    array1 = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, sig.T_2.y);
    sig.T_2.infinity = 0;
    // get object
    fidTest = (*env)->GetFieldID(env, clsTest, "T_3", "Liaik/at/groupsignature/EcPoint_Fp;");
    jobject T3_object = (*env)->GetObjectField(env, sig_object, fidTest);

    cls = (*env)->GetObjectClass(env, T3_object);
    fid = (*env)->GetFieldID(env, cls, "x", "[I");
    data = (*env)->GetObjectField(env, T3_object, fid);
    array = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, sig.T_3.x);

    fid = (*env)->GetFieldID(env, cls, "y", "[I");
    data = (*env)->GetObjectField(env, T3_object, fid);
    array1 = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array1, 0, BI_WORDS, sig.T_3.y);
    sig.T_3.infinity = 0;

    clsTest = (*env)->GetObjectClass(env, gmsk_object);
    // get object
    fid = (*env)->GetFieldID(env, clsTest, "xi1", "[I");
    data = (*env)->GetObjectField(env, gmsk_object, fid);
    array = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, gmsk.xi1);

    fid = (*env)->GetFieldID(env, clsTest, "xi2", "[I");
    data = (*env)->GetObjectField(env, gmsk_object, fid);
    array = (jintArray*) (data);
    (*env)->GetIntArrayRegion(env, array, 0, BI_WORDS, gmsk.xi2);

    ecpoint_fp A;
    sgs_open(gmsk, sig, &A);

    jclass outCls = (*env)->FindClass(env, "iaik/at/groupsignature/EcPoint_Fp");
    jmethodID constructor = (*env)->GetMethodID(env, outCls, "<init>", "()V");
    jfieldID fidOut = (*env)->GetFieldID(env, outCls, "x", "[I");

    jobject jresult = (*env)->NewObject(env, outCls, constructor);

    jintArray x = (jintArray) (*env)->GetObjectField(env, jresult, fidOut);
    (*env)->SetIntArrayRegion(env, x, 0, BI_WORDS, A.x);

    fidOut = (*env)->GetFieldID(env, outCls, "y", "[I");
    jintArray y = (jintArray) (*env)->GetObjectField(env, jresult, fidOut);
    (*env)->SetIntArrayRegion(env, y, 0, BI_WORDS, A.y);
    return jresult;
}