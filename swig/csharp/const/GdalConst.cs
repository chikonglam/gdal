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

public class GdalConst {
  public static readonly int GDT_Unknown = GdalConstPINVOKE.GDT_Unknown_get();
  public static readonly int GDT_Byte = GdalConstPINVOKE.GDT_Byte_get();
  public static readonly int GDT_UInt16 = GdalConstPINVOKE.GDT_UInt16_get();
  public static readonly int GDT_Int16 = GdalConstPINVOKE.GDT_Int16_get();
  public static readonly int GDT_UInt32 = GdalConstPINVOKE.GDT_UInt32_get();
  public static readonly int GDT_Int32 = GdalConstPINVOKE.GDT_Int32_get();
  public static readonly int GDT_Float32 = GdalConstPINVOKE.GDT_Float32_get();
  public static readonly int GDT_Float64 = GdalConstPINVOKE.GDT_Float64_get();
  public static readonly int GDT_CInt16 = GdalConstPINVOKE.GDT_CInt16_get();
  public static readonly int GDT_CInt32 = GdalConstPINVOKE.GDT_CInt32_get();
  public static readonly int GDT_CFloat32 = GdalConstPINVOKE.GDT_CFloat32_get();
  public static readonly int GDT_CFloat64 = GdalConstPINVOKE.GDT_CFloat64_get();
  public static readonly int GDT_TypeCount = GdalConstPINVOKE.GDT_TypeCount_get();
  public static readonly int GA_ReadOnly = GdalConstPINVOKE.GA_ReadOnly_get();
  public static readonly int GA_Update = GdalConstPINVOKE.GA_Update_get();
  public static readonly int GF_Read = GdalConstPINVOKE.GF_Read_get();
  public static readonly int GF_Write = GdalConstPINVOKE.GF_Write_get();
  public static readonly int GCI_Undefined = GdalConstPINVOKE.GCI_Undefined_get();
  public static readonly int GCI_GrayIndex = GdalConstPINVOKE.GCI_GrayIndex_get();
  public static readonly int GCI_PaletteIndex = GdalConstPINVOKE.GCI_PaletteIndex_get();
  public static readonly int GCI_RedBand = GdalConstPINVOKE.GCI_RedBand_get();
  public static readonly int GCI_GreenBand = GdalConstPINVOKE.GCI_GreenBand_get();
  public static readonly int GCI_BlueBand = GdalConstPINVOKE.GCI_BlueBand_get();
  public static readonly int GCI_AlphaBand = GdalConstPINVOKE.GCI_AlphaBand_get();
  public static readonly int GCI_HueBand = GdalConstPINVOKE.GCI_HueBand_get();
  public static readonly int GCI_SaturationBand = GdalConstPINVOKE.GCI_SaturationBand_get();
  public static readonly int GCI_LightnessBand = GdalConstPINVOKE.GCI_LightnessBand_get();
  public static readonly int GCI_CyanBand = GdalConstPINVOKE.GCI_CyanBand_get();
  public static readonly int GCI_MagentaBand = GdalConstPINVOKE.GCI_MagentaBand_get();
  public static readonly int GCI_YellowBand = GdalConstPINVOKE.GCI_YellowBand_get();
  public static readonly int GCI_BlackBand = GdalConstPINVOKE.GCI_BlackBand_get();
  public static readonly int GCI_YCbCr_YBand = GdalConstPINVOKE.GCI_YCbCr_YBand_get();
  public static readonly int GCI_YCbCr_CrBand = GdalConstPINVOKE.GCI_YCbCr_CrBand_get();
  public static readonly int GCI_YCbCr_CbBand = GdalConstPINVOKE.GCI_YCbCr_CbBand_get();
  public static readonly int GRA_NearestNeighbour = GdalConstPINVOKE.GRA_NearestNeighbour_get();
  public static readonly int GRA_Bilinear = GdalConstPINVOKE.GRA_Bilinear_get();
  public static readonly int GRA_Cubic = GdalConstPINVOKE.GRA_Cubic_get();
  public static readonly int GRA_CubicSpline = GdalConstPINVOKE.GRA_CubicSpline_get();
  public static readonly int GRA_Lanczos = GdalConstPINVOKE.GRA_Lanczos_get();
  public static readonly int GPI_Gray = GdalConstPINVOKE.GPI_Gray_get();
  public static readonly int GPI_RGB = GdalConstPINVOKE.GPI_RGB_get();
  public static readonly int GPI_CMYK = GdalConstPINVOKE.GPI_CMYK_get();
  public static readonly int GPI_HLS = GdalConstPINVOKE.GPI_HLS_get();
  public static readonly int CXT_Element = GdalConstPINVOKE.CXT_Element_get();
  public static readonly int CXT_Text = GdalConstPINVOKE.CXT_Text_get();
  public static readonly int CXT_Attribute = GdalConstPINVOKE.CXT_Attribute_get();
  public static readonly int CXT_Comment = GdalConstPINVOKE.CXT_Comment_get();
  public static readonly int CXT_Literal = GdalConstPINVOKE.CXT_Literal_get();
  public static readonly int CE_None = GdalConstPINVOKE.CE_None_get();
  public static readonly int CE_Debug = GdalConstPINVOKE.CE_Debug_get();
  public static readonly int CE_Warning = GdalConstPINVOKE.CE_Warning_get();
  public static readonly int CE_Failure = GdalConstPINVOKE.CE_Failure_get();
  public static readonly int CE_Fatal = GdalConstPINVOKE.CE_Fatal_get();
  public static readonly int CPLE_None = GdalConstPINVOKE.CPLE_None_get();
  public static readonly int CPLE_AppDefined = GdalConstPINVOKE.CPLE_AppDefined_get();
  public static readonly int CPLE_OutOfMemory = GdalConstPINVOKE.CPLE_OutOfMemory_get();
  public static readonly int CPLE_FileIO = GdalConstPINVOKE.CPLE_FileIO_get();
  public static readonly int CPLE_OpenFailed = GdalConstPINVOKE.CPLE_OpenFailed_get();
  public static readonly int CPLE_IllegalArg = GdalConstPINVOKE.CPLE_IllegalArg_get();
  public static readonly int CPLE_NotSupported = GdalConstPINVOKE.CPLE_NotSupported_get();
  public static readonly int CPLE_AssertionFailed = GdalConstPINVOKE.CPLE_AssertionFailed_get();
  public static readonly int CPLE_NoWriteAccess = GdalConstPINVOKE.CPLE_NoWriteAccess_get();
  public static readonly int CPLE_UserInterrupt = GdalConstPINVOKE.CPLE_UserInterrupt_get();
  public static readonly string GDAL_DMD_LONGNAME = GdalConstPINVOKE.GDAL_DMD_LONGNAME_get();
  public static readonly string GDAL_DMD_HELPTOPIC = GdalConstPINVOKE.GDAL_DMD_HELPTOPIC_get();
  public static readonly string GDAL_DMD_MIMETYPE = GdalConstPINVOKE.GDAL_DMD_MIMETYPE_get();
  public static readonly string GDAL_DMD_EXTENSION = GdalConstPINVOKE.GDAL_DMD_EXTENSION_get();
  public static readonly string GDAL_DMD_CREATIONOPTIONLIST = GdalConstPINVOKE.GDAL_DMD_CREATIONOPTIONLIST_get();
  public static readonly string GDAL_DMD_CREATIONDATATYPES = GdalConstPINVOKE.GDAL_DMD_CREATIONDATATYPES_get();
  public static readonly string GDAL_DCAP_CREATE = GdalConstPINVOKE.GDAL_DCAP_CREATE_get();
  public static readonly string GDAL_DCAP_CREATECOPY = GdalConstPINVOKE.GDAL_DCAP_CREATECOPY_get();
  public static readonly string GDAL_DCAP_VIRTUALIO = GdalConstPINVOKE.GDAL_DCAP_VIRTUALIO_get();
  public static readonly int CPLES_BackslashQuotable = GdalConstPINVOKE.CPLES_BackslashQuotable_get();
  public static readonly int CPLES_XML = GdalConstPINVOKE.CPLES_XML_get();
  public static readonly int CPLES_URL = GdalConstPINVOKE.CPLES_URL_get();
  public static readonly int CPLES_SQL = GdalConstPINVOKE.CPLES_SQL_get();
  public static readonly int CPLES_CSV = GdalConstPINVOKE.CPLES_CSV_get();
  public static readonly int GFT_Integer = GdalConstPINVOKE.GFT_Integer_get();
  public static readonly int GFT_Real = GdalConstPINVOKE.GFT_Real_get();
  public static readonly int GFT_String = GdalConstPINVOKE.GFT_String_get();
  public static readonly int GFU_Generic = GdalConstPINVOKE.GFU_Generic_get();
  public static readonly int GFU_PixelCount = GdalConstPINVOKE.GFU_PixelCount_get();
  public static readonly int GFU_Name = GdalConstPINVOKE.GFU_Name_get();
  public static readonly int GFU_Min = GdalConstPINVOKE.GFU_Min_get();
  public static readonly int GFU_Max = GdalConstPINVOKE.GFU_Max_get();
  public static readonly int GFU_MinMax = GdalConstPINVOKE.GFU_MinMax_get();
  public static readonly int GFU_Red = GdalConstPINVOKE.GFU_Red_get();
  public static readonly int GFU_Green = GdalConstPINVOKE.GFU_Green_get();
  public static readonly int GFU_Blue = GdalConstPINVOKE.GFU_Blue_get();
  public static readonly int GFU_Alpha = GdalConstPINVOKE.GFU_Alpha_get();
  public static readonly int GFU_RedMin = GdalConstPINVOKE.GFU_RedMin_get();
  public static readonly int GFU_GreenMin = GdalConstPINVOKE.GFU_GreenMin_get();
  public static readonly int GFU_BlueMin = GdalConstPINVOKE.GFU_BlueMin_get();
  public static readonly int GFU_AlphaMin = GdalConstPINVOKE.GFU_AlphaMin_get();
  public static readonly int GFU_RedMax = GdalConstPINVOKE.GFU_RedMax_get();
  public static readonly int GFU_GreenMax = GdalConstPINVOKE.GFU_GreenMax_get();
  public static readonly int GFU_BlueMax = GdalConstPINVOKE.GFU_BlueMax_get();
  public static readonly int GFU_AlphaMax = GdalConstPINVOKE.GFU_AlphaMax_get();
  public static readonly int GFU_MaxCount = GdalConstPINVOKE.GFU_MaxCount_get();
  public static readonly int GMF_ALL_VALID = GdalConstPINVOKE.GMF_ALL_VALID_get();
  public static readonly int GMF_PER_DATASET = GdalConstPINVOKE.GMF_PER_DATASET_get();
  public static readonly int GMF_ALPHA = GdalConstPINVOKE.GMF_ALPHA_get();
  public static readonly int GMF_NODATA = GdalConstPINVOKE.GMF_NODATA_get();
}

}
