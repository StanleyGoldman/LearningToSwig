//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class codebase_wrapper {
  public static int processDataByReference(DataStruct data) {
    int ret = codebase_wrapperPINVOKE.processDataByReference(DataStruct.getCPtr(data));
    if (codebase_wrapperPINVOKE.SWIGPendingException.Pending) throw codebase_wrapperPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static int processDataByPointer(DataStruct data) {
    int ret = codebase_wrapperPINVOKE.processDataByPointer(DataStruct.getCPtr(data));
    return ret;
  }

  public static SWIGTYPE_p_p_DataStruct createDynamicArray(int count) {
    global::System.IntPtr cPtr = codebase_wrapperPINVOKE.createDynamicArray(count);
    SWIGTYPE_p_p_DataStruct ret = (cPtr == global::System.IntPtr.Zero) ? null : new SWIGTYPE_p_p_DataStruct(cPtr, false);
    return ret;
  }

  public static int sumDynamicArray(SWIGTYPE_p_p_DataStruct data, int count) {
    int ret = codebase_wrapperPINVOKE.sumDynamicArray(SWIGTYPE_p_p_DataStruct.getCPtr(data), count);
    return ret;
  }

}
