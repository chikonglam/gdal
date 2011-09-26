/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.39
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace OSGeo.GDAL {

using System;
using System.Runtime.InteropServices;

public class Driver : MajorObject {
  private HandleRef swigCPtr;

  public Driver(IntPtr cPtr, bool cMemoryOwn, object parent) : base(GdalPINVOKE.DriverUpcast(cPtr), cMemoryOwn, parent) {
    swigCPtr = new HandleRef(this, cPtr);
  }

  public static HandleRef getCPtr(Driver obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }
  public static HandleRef getCPtrAndDisown(Driver obj, object parent) {
    if (obj != null)
    {
      obj.swigCMemOwn = false;
      obj.swigParentRef = parent;
      return obj.swigCPtr;
    }
    else
    {
      return new HandleRef(null, IntPtr.Zero);
    }
  }
  public static HandleRef getCPtrAndSetReference(Driver obj, object parent) {
    if (obj != null)
    {
      obj.swigParentRef = parent;
      return obj.swigCPtr;
    }
    else
    {
      return new HandleRef(null, IntPtr.Zero);
    }
  }

  public override void Dispose() {
    lock(this) {
      if(swigCPtr.Handle != IntPtr.Zero && swigCMemOwn) {
        swigCMemOwn = false;
        throw new MethodAccessException("C++ destructor does not have public access");
      }
      swigCPtr = new HandleRef(null, IntPtr.Zero);
      GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public string ShortName {
    get {
      string ret = GdalPINVOKE.Driver_ShortName_get(swigCPtr);
      if (GdalPINVOKE.SWIGPendingException.Pending) throw GdalPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public string LongName {
    get {
      string ret = GdalPINVOKE.Driver_LongName_get(swigCPtr);
      if (GdalPINVOKE.SWIGPendingException.Pending) throw GdalPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public string HelpTopic {
    get {
      string ret = GdalPINVOKE.Driver_HelpTopic_get(swigCPtr);
      if (GdalPINVOKE.SWIGPendingException.Pending) throw GdalPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public Dataset Create(string utf8_path, int xsize, int ysize, int bands, DataType eType, string[] options) {
    IntPtr cPtr = GdalPINVOKE.Driver_Create(swigCPtr, System.Text.Encoding.Default.GetString(System.Text.Encoding.UTF8.GetBytes(utf8_path)), xsize, ysize, bands, (int)eType, (options != null)? new GdalPINVOKE.StringListMarshal(options)._ar : null);
    Dataset ret = (cPtr == IntPtr.Zero) ? null : new Dataset(cPtr, true, ThisOwn_true());
    if (GdalPINVOKE.SWIGPendingException.Pending) throw GdalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public Dataset CreateCopy(string utf8_path, Dataset src, int strict, string[] options, Gdal.GDALProgressFuncDelegate callback, string callback_data) {
    IntPtr cPtr = GdalPINVOKE.Driver_CreateCopy(swigCPtr, System.Text.Encoding.Default.GetString(System.Text.Encoding.UTF8.GetBytes(utf8_path)), Dataset.getCPtr(src), strict, (options != null)? new GdalPINVOKE.StringListMarshal(options)._ar : null, callback, callback_data);
    Dataset ret = (cPtr == IntPtr.Zero) ? null : new Dataset(cPtr, true, ThisOwn_true());
    if (GdalPINVOKE.SWIGPendingException.Pending) throw GdalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int Delete(string utf8_path) {
    int ret = GdalPINVOKE.Driver_Delete(swigCPtr, System.Text.Encoding.Default.GetString(System.Text.Encoding.UTF8.GetBytes(utf8_path)));
    if (GdalPINVOKE.SWIGPendingException.Pending) throw GdalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int Rename(string newName, string oldName) {
    int ret = GdalPINVOKE.Driver_Rename(swigCPtr, newName, oldName);
    if (GdalPINVOKE.SWIGPendingException.Pending) throw GdalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int CopyFiles(string newName, string oldName) {
    int ret = GdalPINVOKE.Driver_CopyFiles(swigCPtr, newName, oldName);
    if (GdalPINVOKE.SWIGPendingException.Pending) throw GdalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int Register() {
    int ret = GdalPINVOKE.Driver_Register(swigCPtr);
    if (GdalPINVOKE.SWIGPendingException.Pending) throw GdalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Deregister() {
    GdalPINVOKE.Driver_Deregister(swigCPtr);
    if (GdalPINVOKE.SWIGPendingException.Pending) throw GdalPINVOKE.SWIGPendingException.Retrieve();
  }

}

}
