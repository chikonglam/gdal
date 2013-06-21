/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace OSGeo.OGR {

using System;
using System.Runtime.InteropServices;

public class Ogr {

  internal class OgrObject : IDisposable {
	public virtual void Dispose() {
      
    }
  }
  internal static OgrObject theOgrObject = new OgrObject();
  protected static object ThisOwn_true() { return null; }
  protected static object ThisOwn_false() { return theOgrObject; }

  public static void UseExceptions() {
    OgrPINVOKE.UseExceptions();
  }

  public static void DontUseExceptions() {
    OgrPINVOKE.DontUseExceptions();
  }

  internal static void StringListDestroy(IntPtr buffer_ptr) {
    OgrPINVOKE.StringListDestroy(buffer_ptr);
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
  }

public delegate void GDALErrorHandlerDelegate(int eclass, int code, IntPtr msg);
  public static Geometry CreateGeometryFromWkb(int len, IntPtr bin_string, OSGeo.OSR.SpatialReference reference) {
    IntPtr cPtr = OgrPINVOKE.CreateGeometryFromWkb(len, bin_string, OSGeo.OSR.SpatialReference.getCPtr(reference));
    Geometry ret = (cPtr == IntPtr.Zero) ? null : new Geometry(cPtr, true, ThisOwn_true());
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static Geometry CreateGeometryFromWkt(ref string val, OSGeo.OSR.SpatialReference reference) {
    IntPtr cPtr = OgrPINVOKE.CreateGeometryFromWkt(ref val, OSGeo.OSR.SpatialReference.getCPtr(reference));
    Geometry ret = (cPtr == IntPtr.Zero) ? null : new Geometry(cPtr, true, ThisOwn_true());
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static Geometry CreateGeometryFromGML(string input_string) {
    IntPtr cPtr = OgrPINVOKE.CreateGeometryFromGML(input_string);
    Geometry ret = (cPtr == IntPtr.Zero) ? null : new Geometry(cPtr, true, ThisOwn_true());
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static Geometry CreateGeometryFromJson(string input_string) {
    IntPtr cPtr = OgrPINVOKE.CreateGeometryFromJson(input_string);
    Geometry ret = (cPtr == IntPtr.Zero) ? null : new Geometry(cPtr, true, ThisOwn_true());
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static Geometry BuildPolygonFromEdges(Geometry hLineCollection, int bBestEffort, int bAutoClose, double dfTolerance) {
    IntPtr cPtr = OgrPINVOKE.BuildPolygonFromEdges(Geometry.getCPtr(hLineCollection), bBestEffort, bAutoClose, dfTolerance);
    Geometry ret = (cPtr == IntPtr.Zero) ? null : new Geometry(cPtr, true, ThisOwn_true());
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static Geometry ApproximateArcAngles(double dfCenterX, double dfCenterY, double dfZ, double dfPrimaryRadius, double dfSecondaryAxis, double dfRotation, double dfStartAngle, double dfEndAngle, double dfMaxAngleStepSizeDegrees) {
    IntPtr cPtr = OgrPINVOKE.ApproximateArcAngles(dfCenterX, dfCenterY, dfZ, dfPrimaryRadius, dfSecondaryAxis, dfRotation, dfStartAngle, dfEndAngle, dfMaxAngleStepSizeDegrees);
    Geometry ret = (cPtr == IntPtr.Zero) ? null : new Geometry(cPtr, true, ThisOwn_true());
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static Geometry ForceToPolygon(Geometry geom_in) {
    IntPtr cPtr = OgrPINVOKE.ForceToPolygon(Geometry.getCPtr(geom_in));
    Geometry ret = (cPtr == IntPtr.Zero) ? null : new Geometry(cPtr, true, ThisOwn_true());
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static Geometry ForceToLineString(Geometry geom_in) {
    IntPtr cPtr = OgrPINVOKE.ForceToLineString(Geometry.getCPtr(geom_in));
    Geometry ret = (cPtr == IntPtr.Zero) ? null : new Geometry(cPtr, true, ThisOwn_true());
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static Geometry ForceToMultiPolygon(Geometry geom_in) {
    IntPtr cPtr = OgrPINVOKE.ForceToMultiPolygon(Geometry.getCPtr(geom_in));
    Geometry ret = (cPtr == IntPtr.Zero) ? null : new Geometry(cPtr, true, ThisOwn_true());
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static Geometry ForceToMultiPoint(Geometry geom_in) {
    IntPtr cPtr = OgrPINVOKE.ForceToMultiPoint(Geometry.getCPtr(geom_in));
    Geometry ret = (cPtr == IntPtr.Zero) ? null : new Geometry(cPtr, true, ThisOwn_true());
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static Geometry ForceToMultiLineString(Geometry geom_in) {
    IntPtr cPtr = OgrPINVOKE.ForceToMultiLineString(Geometry.getCPtr(geom_in));
    Geometry ret = (cPtr == IntPtr.Zero) ? null : new Geometry(cPtr, true, ThisOwn_true());
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static int GetDriverCount() {
    int ret = OgrPINVOKE.GetDriverCount();
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static int GetOpenDSCount() {
    int ret = OgrPINVOKE.GetOpenDSCount();
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static int SetGenerate_DB2_V72_BYTE_ORDER(int bGenerate_DB2_V72_BYTE_ORDER) {
    int ret = OgrPINVOKE.SetGenerate_DB2_V72_BYTE_ORDER(bGenerate_DB2_V72_BYTE_ORDER);
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static void RegisterAll() {
    OgrPINVOKE.RegisterAll();
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
  }

  public static string GeometryTypeToName(wkbGeometryType eType) {
    string ret = OgrPINVOKE.GeometryTypeToName((int)eType);
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static string GetFieldTypeName(FieldType type) {
    string ret = OgrPINVOKE.GetFieldTypeName((int)type);
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static DataSource GetOpenDS(int ds_number) {
    IntPtr cPtr = OgrPINVOKE.GetOpenDS(ds_number);
    DataSource ret = (cPtr == IntPtr.Zero) ? null : new DataSource(cPtr, false, ThisOwn_false());
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static DataSource Open(string utf8_path, int update) {
    IntPtr cPtr = OgrPINVOKE.Open(System.Text.Encoding.Default.GetString(System.Text.Encoding.UTF8.GetBytes(utf8_path)), update);
    DataSource ret = (cPtr == IntPtr.Zero) ? null : new DataSource(cPtr, true, ThisOwn_true());
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static DataSource OpenShared(string utf8_path, int update) {
    IntPtr cPtr = OgrPINVOKE.OpenShared(System.Text.Encoding.Default.GetString(System.Text.Encoding.UTF8.GetBytes(utf8_path)), update);
    DataSource ret = (cPtr == IntPtr.Zero) ? null : new DataSource(cPtr, true, ThisOwn_true());
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static Driver GetDriverByName(string name) {
    IntPtr cPtr = OgrPINVOKE.GetDriverByName(name);
    Driver ret = (cPtr == IntPtr.Zero) ? null : new Driver(cPtr, false, ThisOwn_false());
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static Driver GetDriver(int driver_number) {
    IntPtr cPtr = OgrPINVOKE.GetDriver(driver_number);
    Driver ret = (cPtr == IntPtr.Zero) ? null : new Driver(cPtr, false, ThisOwn_false());
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static string[] GeneralCmdLineProcessor(string[] papszArgv, int nOptions) {
        /* %typemap(csout) char**options */
        IntPtr cPtr = OgrPINVOKE.GeneralCmdLineProcessor((papszArgv != null)? new OgrPINVOKE.StringListMarshal(papszArgv)._ar : null, nOptions);
        IntPtr objPtr;
        int count = 0;
        if (cPtr != IntPtr.Zero) {
            while (Marshal.ReadIntPtr(cPtr, count*IntPtr.Size) != IntPtr.Zero)
                ++count;
        }
        string[] ret = new string[count];
        if (count > 0) {       
	        for(int cx = 0; cx < count; cx++) {
                objPtr = System.Runtime.InteropServices.Marshal.ReadIntPtr(cPtr, cx * System.Runtime.InteropServices.Marshal.SizeOf(typeof(IntPtr)));
                ret[cx]= (objPtr == IntPtr.Zero) ? null : System.Runtime.InteropServices.Marshal.PtrToStringAnsi(objPtr);
            }
        }
        
    if (OgrPINVOKE.SWIGPendingException.Pending) throw OgrPINVOKE.SWIGPendingException.Retrieve();
        return ret;
}

  public static readonly int wkb25DBit = OgrPINVOKE.wkb25DBit_get();
  public static readonly int ogrZMarker = OgrPINVOKE.ogrZMarker_get();
  public static readonly int OGRNullFID = OgrPINVOKE.OGRNullFID_get();
  public static readonly int OGRUnsetMarker = OgrPINVOKE.OGRUnsetMarker_get();
  public static readonly string OLCRandomRead = OgrPINVOKE.OLCRandomRead_get();
  public static readonly string OLCSequentialWrite = OgrPINVOKE.OLCSequentialWrite_get();
  public static readonly string OLCRandomWrite = OgrPINVOKE.OLCRandomWrite_get();
  public static readonly string OLCFastSpatialFilter = OgrPINVOKE.OLCFastSpatialFilter_get();
  public static readonly string OLCFastFeatureCount = OgrPINVOKE.OLCFastFeatureCount_get();
  public static readonly string OLCFastGetExtent = OgrPINVOKE.OLCFastGetExtent_get();
  public static readonly string OLCCreateField = OgrPINVOKE.OLCCreateField_get();
  public static readonly string OLCDeleteField = OgrPINVOKE.OLCDeleteField_get();
  public static readonly string OLCReorderFields = OgrPINVOKE.OLCReorderFields_get();
  public static readonly string OLCAlterFieldDefn = OgrPINVOKE.OLCAlterFieldDefn_get();
  public static readonly string OLCTransactions = OgrPINVOKE.OLCTransactions_get();
  public static readonly string OLCDeleteFeature = OgrPINVOKE.OLCDeleteFeature_get();
  public static readonly string OLCFastSetNextByIndex = OgrPINVOKE.OLCFastSetNextByIndex_get();
  public static readonly string OLCStringsAsUTF8 = OgrPINVOKE.OLCStringsAsUTF8_get();
  public static readonly string ODsCCreateLayer = OgrPINVOKE.ODsCCreateLayer_get();
  public static readonly string ODsCDeleteLayer = OgrPINVOKE.ODsCDeleteLayer_get();
  public static readonly string ODrCCreateDataSource = OgrPINVOKE.ODrCCreateDataSource_get();
  public static readonly string ODrCDeleteDataSource = OgrPINVOKE.ODrCDeleteDataSource_get();
  public static readonly int OGRERR_NONE = OgrPINVOKE.OGRERR_NONE_get();
  public static readonly int OGRERR_NOT_ENOUGH_DATA = OgrPINVOKE.OGRERR_NOT_ENOUGH_DATA_get();
  public static readonly int OGRERR_NOT_ENOUGH_MEMORY = OgrPINVOKE.OGRERR_NOT_ENOUGH_MEMORY_get();
  public static readonly int OGRERR_UNSUPPORTED_GEOMETRY_TYPE = OgrPINVOKE.OGRERR_UNSUPPORTED_GEOMETRY_TYPE_get();
  public static readonly int OGRERR_UNSUPPORTED_OPERATION = OgrPINVOKE.OGRERR_UNSUPPORTED_OPERATION_get();
  public static readonly int OGRERR_CORRUPT_DATA = OgrPINVOKE.OGRERR_CORRUPT_DATA_get();
  public static readonly int OGRERR_FAILURE = OgrPINVOKE.OGRERR_FAILURE_get();
  public static readonly int OGRERR_UNSUPPORTED_SRS = OgrPINVOKE.OGRERR_UNSUPPORTED_SRS_get();
}

}
