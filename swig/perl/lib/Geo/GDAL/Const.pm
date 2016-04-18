# This file was automatically generated by SWIG (http://www.swig.org).
# Version 2.0.12
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.

package Geo::GDAL::Const;
use base qw(Exporter);
use base qw(DynaLoader);
package Geo::GDAL::Constc;
bootstrap Geo::GDAL::Const;
package Geo::GDAL::Const;
@EXPORT = qw();

# ---------- BASE METHODS -------------

package Geo::GDAL::Const;

sub TIEHASH {
    my ($classname,$obj) = @_;
    return bless $obj, $classname;
}

sub CLEAR { }

sub FIRSTKEY { }

sub NEXTKEY { }

sub FETCH {
    my ($self,$field) = @_;
    my $member_func = "swig_${field}_get";
    $self->$member_func();
}

sub STORE {
    my ($self,$field,$newval) = @_;
    my $member_func = "swig_${field}_set";
    $self->$member_func($newval);
}

sub this {
    my $ptr = shift;
    return tied(%$ptr);
}


# ------- FUNCTION WRAPPERS --------

package Geo::GDAL::Const;


# ------- VARIABLE STUBS --------

package Geo::GDAL::Const;

*GDT_Unknown = *Geo::GDAL::Constc::GDT_Unknown;
*GDT_Byte = *Geo::GDAL::Constc::GDT_Byte;
*GDT_UInt16 = *Geo::GDAL::Constc::GDT_UInt16;
*GDT_Int16 = *Geo::GDAL::Constc::GDT_Int16;
*GDT_UInt32 = *Geo::GDAL::Constc::GDT_UInt32;
*GDT_Int32 = *Geo::GDAL::Constc::GDT_Int32;
*GDT_Float32 = *Geo::GDAL::Constc::GDT_Float32;
*GDT_Float64 = *Geo::GDAL::Constc::GDT_Float64;
*GDT_CInt16 = *Geo::GDAL::Constc::GDT_CInt16;
*GDT_CInt32 = *Geo::GDAL::Constc::GDT_CInt32;
*GDT_CFloat32 = *Geo::GDAL::Constc::GDT_CFloat32;
*GDT_CFloat64 = *Geo::GDAL::Constc::GDT_CFloat64;
*GDT_TypeCount = *Geo::GDAL::Constc::GDT_TypeCount;
*GA_ReadOnly = *Geo::GDAL::Constc::GA_ReadOnly;
*GA_Update = *Geo::GDAL::Constc::GA_Update;
*GF_Read = *Geo::GDAL::Constc::GF_Read;
*GF_Write = *Geo::GDAL::Constc::GF_Write;
*GRIORA_NearestNeighbour = *Geo::GDAL::Constc::GRIORA_NearestNeighbour;
*GRIORA_Bilinear = *Geo::GDAL::Constc::GRIORA_Bilinear;
*GRIORA_Cubic = *Geo::GDAL::Constc::GRIORA_Cubic;
*GRIORA_CubicSpline = *Geo::GDAL::Constc::GRIORA_CubicSpline;
*GRIORA_Lanczos = *Geo::GDAL::Constc::GRIORA_Lanczos;
*GRIORA_Average = *Geo::GDAL::Constc::GRIORA_Average;
*GRIORA_Mode = *Geo::GDAL::Constc::GRIORA_Mode;
*GRIORA_Gauss = *Geo::GDAL::Constc::GRIORA_Gauss;
*GCI_Undefined = *Geo::GDAL::Constc::GCI_Undefined;
*GCI_GrayIndex = *Geo::GDAL::Constc::GCI_GrayIndex;
*GCI_PaletteIndex = *Geo::GDAL::Constc::GCI_PaletteIndex;
*GCI_RedBand = *Geo::GDAL::Constc::GCI_RedBand;
*GCI_GreenBand = *Geo::GDAL::Constc::GCI_GreenBand;
*GCI_BlueBand = *Geo::GDAL::Constc::GCI_BlueBand;
*GCI_AlphaBand = *Geo::GDAL::Constc::GCI_AlphaBand;
*GCI_HueBand = *Geo::GDAL::Constc::GCI_HueBand;
*GCI_SaturationBand = *Geo::GDAL::Constc::GCI_SaturationBand;
*GCI_LightnessBand = *Geo::GDAL::Constc::GCI_LightnessBand;
*GCI_CyanBand = *Geo::GDAL::Constc::GCI_CyanBand;
*GCI_MagentaBand = *Geo::GDAL::Constc::GCI_MagentaBand;
*GCI_YellowBand = *Geo::GDAL::Constc::GCI_YellowBand;
*GCI_BlackBand = *Geo::GDAL::Constc::GCI_BlackBand;
*GCI_YCbCr_YBand = *Geo::GDAL::Constc::GCI_YCbCr_YBand;
*GCI_YCbCr_CrBand = *Geo::GDAL::Constc::GCI_YCbCr_CrBand;
*GCI_YCbCr_CbBand = *Geo::GDAL::Constc::GCI_YCbCr_CbBand;
*GRA_NearestNeighbour = *Geo::GDAL::Constc::GRA_NearestNeighbour;
*GRA_Bilinear = *Geo::GDAL::Constc::GRA_Bilinear;
*GRA_Cubic = *Geo::GDAL::Constc::GRA_Cubic;
*GRA_CubicSpline = *Geo::GDAL::Constc::GRA_CubicSpline;
*GRA_Lanczos = *Geo::GDAL::Constc::GRA_Lanczos;
*GRA_Average = *Geo::GDAL::Constc::GRA_Average;
*GRA_Mode = *Geo::GDAL::Constc::GRA_Mode;
*GPI_Gray = *Geo::GDAL::Constc::GPI_Gray;
*GPI_RGB = *Geo::GDAL::Constc::GPI_RGB;
*GPI_CMYK = *Geo::GDAL::Constc::GPI_CMYK;
*GPI_HLS = *Geo::GDAL::Constc::GPI_HLS;
*CXT_Element = *Geo::GDAL::Constc::CXT_Element;
*CXT_Text = *Geo::GDAL::Constc::CXT_Text;
*CXT_Attribute = *Geo::GDAL::Constc::CXT_Attribute;
*CXT_Comment = *Geo::GDAL::Constc::CXT_Comment;
*CXT_Literal = *Geo::GDAL::Constc::CXT_Literal;
*CE_None = *Geo::GDAL::Constc::CE_None;
*CE_Debug = *Geo::GDAL::Constc::CE_Debug;
*CE_Warning = *Geo::GDAL::Constc::CE_Warning;
*CE_Failure = *Geo::GDAL::Constc::CE_Failure;
*CE_Fatal = *Geo::GDAL::Constc::CE_Fatal;
*CPLE_None = *Geo::GDAL::Constc::CPLE_None;
*CPLE_AppDefined = *Geo::GDAL::Constc::CPLE_AppDefined;
*CPLE_OutOfMemory = *Geo::GDAL::Constc::CPLE_OutOfMemory;
*CPLE_FileIO = *Geo::GDAL::Constc::CPLE_FileIO;
*CPLE_OpenFailed = *Geo::GDAL::Constc::CPLE_OpenFailed;
*CPLE_IllegalArg = *Geo::GDAL::Constc::CPLE_IllegalArg;
*CPLE_NotSupported = *Geo::GDAL::Constc::CPLE_NotSupported;
*CPLE_AssertionFailed = *Geo::GDAL::Constc::CPLE_AssertionFailed;
*CPLE_NoWriteAccess = *Geo::GDAL::Constc::CPLE_NoWriteAccess;
*CPLE_UserInterrupt = *Geo::GDAL::Constc::CPLE_UserInterrupt;
*OF_ALL = *Geo::GDAL::Constc::OF_ALL;
*OF_RASTER = *Geo::GDAL::Constc::OF_RASTER;
*OF_VECTOR = *Geo::GDAL::Constc::OF_VECTOR;
*OF_GNM = *Geo::GDAL::Constc::OF_GNM;
*OF_READONLY = *Geo::GDAL::Constc::OF_READONLY;
*OF_UPDATE = *Geo::GDAL::Constc::OF_UPDATE;
*OF_SHARED = *Geo::GDAL::Constc::OF_SHARED;
*OF_VERBOSE_ERROR = *Geo::GDAL::Constc::OF_VERBOSE_ERROR;
*DMD_LONGNAME = *Geo::GDAL::Constc::DMD_LONGNAME;
*DMD_HELPTOPIC = *Geo::GDAL::Constc::DMD_HELPTOPIC;
*DMD_MIMETYPE = *Geo::GDAL::Constc::DMD_MIMETYPE;
*DMD_EXTENSION = *Geo::GDAL::Constc::DMD_EXTENSION;
*DMD_EXTENSIONS = *Geo::GDAL::Constc::DMD_EXTENSIONS;
*DMD_CONNECTION_PREFIX = *Geo::GDAL::Constc::DMD_CONNECTION_PREFIX;
*DMD_CREATIONOPTIONLIST = *Geo::GDAL::Constc::DMD_CREATIONOPTIONLIST;
*DMD_CREATIONDATATYPES = *Geo::GDAL::Constc::DMD_CREATIONDATATYPES;
*DMD_CREATIONFIELDDATATYPES = *Geo::GDAL::Constc::DMD_CREATIONFIELDDATATYPES;
*DMD_SUBDATASETS = *Geo::GDAL::Constc::DMD_SUBDATASETS;
*DCAP_OPEN = *Geo::GDAL::Constc::DCAP_OPEN;
*DCAP_CREATE = *Geo::GDAL::Constc::DCAP_CREATE;
*DCAP_CREATECOPY = *Geo::GDAL::Constc::DCAP_CREATECOPY;
*DCAP_VIRTUALIO = *Geo::GDAL::Constc::DCAP_VIRTUALIO;
*DCAP_RASTER = *Geo::GDAL::Constc::DCAP_RASTER;
*DCAP_VECTOR = *Geo::GDAL::Constc::DCAP_VECTOR;
*DCAP_NOTNULL_FIELDS = *Geo::GDAL::Constc::DCAP_NOTNULL_FIELDS;
*DCAP_DEFAULT_FIELDS = *Geo::GDAL::Constc::DCAP_DEFAULT_FIELDS;
*DCAP_NOTNULL_GEOMFIELDS = *Geo::GDAL::Constc::DCAP_NOTNULL_GEOMFIELDS;
*CPLES_BackslashQuotable = *Geo::GDAL::Constc::CPLES_BackslashQuotable;
*CPLES_XML = *Geo::GDAL::Constc::CPLES_XML;
*CPLES_URL = *Geo::GDAL::Constc::CPLES_URL;
*CPLES_SQL = *Geo::GDAL::Constc::CPLES_SQL;
*CPLES_CSV = *Geo::GDAL::Constc::CPLES_CSV;
*GFT_Integer = *Geo::GDAL::Constc::GFT_Integer;
*GFT_Real = *Geo::GDAL::Constc::GFT_Real;
*GFT_String = *Geo::GDAL::Constc::GFT_String;
*GFU_Generic = *Geo::GDAL::Constc::GFU_Generic;
*GFU_PixelCount = *Geo::GDAL::Constc::GFU_PixelCount;
*GFU_Name = *Geo::GDAL::Constc::GFU_Name;
*GFU_Min = *Geo::GDAL::Constc::GFU_Min;
*GFU_Max = *Geo::GDAL::Constc::GFU_Max;
*GFU_MinMax = *Geo::GDAL::Constc::GFU_MinMax;
*GFU_Red = *Geo::GDAL::Constc::GFU_Red;
*GFU_Green = *Geo::GDAL::Constc::GFU_Green;
*GFU_Blue = *Geo::GDAL::Constc::GFU_Blue;
*GFU_Alpha = *Geo::GDAL::Constc::GFU_Alpha;
*GFU_RedMin = *Geo::GDAL::Constc::GFU_RedMin;
*GFU_GreenMin = *Geo::GDAL::Constc::GFU_GreenMin;
*GFU_BlueMin = *Geo::GDAL::Constc::GFU_BlueMin;
*GFU_AlphaMin = *Geo::GDAL::Constc::GFU_AlphaMin;
*GFU_RedMax = *Geo::GDAL::Constc::GFU_RedMax;
*GFU_GreenMax = *Geo::GDAL::Constc::GFU_GreenMax;
*GFU_BlueMax = *Geo::GDAL::Constc::GFU_BlueMax;
*GFU_AlphaMax = *Geo::GDAL::Constc::GFU_AlphaMax;
*GFU_MaxCount = *Geo::GDAL::Constc::GFU_MaxCount;
*GMF_ALL_VALID = *Geo::GDAL::Constc::GMF_ALL_VALID;
*GMF_PER_DATASET = *Geo::GDAL::Constc::GMF_PER_DATASET;
*GMF_ALPHA = *Geo::GDAL::Constc::GMF_ALPHA;
*GMF_NODATA = *Geo::GDAL::Constc::GMF_NODATA;
*GARIO_PENDING = *Geo::GDAL::Constc::GARIO_PENDING;
*GARIO_UPDATE = *Geo::GDAL::Constc::GARIO_UPDATE;
*GARIO_ERROR = *Geo::GDAL::Constc::GARIO_ERROR;
*GARIO_COMPLETE = *Geo::GDAL::Constc::GARIO_COMPLETE;
*GTO_TIP = *Geo::GDAL::Constc::GTO_TIP;
*GTO_BIT = *Geo::GDAL::Constc::GTO_BIT;
*GTO_BSQ = *Geo::GDAL::Constc::GTO_BSQ;
1;
