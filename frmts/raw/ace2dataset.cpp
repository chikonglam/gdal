/******************************************************************************
 *
 * Project:  ACE2 Driver
 * Purpose:  Implementation of ACE2 elevation format read support.
 *           http://tethys.eaprs.cse.dmu.ac.uk/ACE2/shared/documentation
 * Author:   Even Rouault, <even dot rouault at mines dash paris dot org>
 *
 ******************************************************************************
 * Copyright (c) 2011-2012, Even Rouault <even dot rouault at mines-paris dot org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ****************************************************************************/

#include "gdal_frmts.h"
#include "ogr_spatialref.h"
#include "rawdataset.h"

CPL_CVSID("$Id: ace2dataset.cpp b2723bb9ee29fb36de5c3afec9e9a6b757ef743c 2018-05-10 21:21:26 +0200 Even Rouault $")

static const char * const apszCategorySource[] =
{
    "Pure SRTM (above 60deg N pure GLOBE data, below 60S pure ACE [original] "
    "data)",
    "SRTM voids filled by interpolation and/or altimeter data",
    "SRTM data warped using the ERS-1 Geodetic Mission",
    "SRTM data warped using EnviSat & ERS-2 data",
    "Mean lake level data derived from Altimetry",
    "GLOBE/ACE data warped using combined altimetry (only above 60deg N)",
    "Pure altimetry data (derived from ERS-1 Geodetic Mission, ERS-2 and "
    "EnviSat data using Delaunay Triangulation",
    nullptr
};

static const char * const apszCategoryQuality[] =
{
    "Generic - use base datasets",
    "Accuracy of greater than +/- 16m",
    "Accuracy between +/- 16m - +/- 10m",
    "Accuracy between +/-10m - +/-5m",
    "Accuracy between +/-5m - +/-1m",
    "Accuracy between +/-1m",
    nullptr
};

static const char * const apszCategoryConfidence[] =
{
    "No confidence could be derived due to lack of data",
    "Heights generated by interpolation",
    "Low confidence",
    "Low confidence",
    "Low confidence",
    "Medium confidence",
    "Medium confidence",
    "Medium confidence",
    "Medium confidence",
    "Medium confidence",
    "Medium confidence",
    "Medium confidence",
    "Medium confidence",
    "High confidence",
    "High confidence",
    "High confidence",
    "High confidence",
    "Inland water confidence",
    "Inland water confidence",
    "Inland water confidence",
    "Inland water confidence",
    "Inland water confidence",
    nullptr
};

/************************************************************************/
/* ==================================================================== */
/*                             ACE2Dataset                              */
/* ==================================================================== */
/************************************************************************/

class ACE2Dataset : public GDALPamDataset
{
    friend class ACE2RasterBand;

    double       adfGeoTransform[6];

  public:
    ACE2Dataset();
    ~ACE2Dataset() override {}

    const char *GetProjectionRef(void) override;
    CPLErr GetGeoTransform( double * ) override;

    static GDALDataset *Open( GDALOpenInfo * );
    static int Identify( GDALOpenInfo * );
};

/************************************************************************/
/* ==================================================================== */
/*                            ACE2RasterBand                            */
/* ==================================================================== */
/************************************************************************/

class ACE2RasterBand : public RawRasterBand
{
  public:
    ACE2RasterBand( VSILFILE* fpRaw,
                    GDALDataType eDataType,
                    int nXSize, int nYSize );
    ~ACE2RasterBand() override {}

    const char *GetUnitType() override;
    char **GetCategoryNames() override;
};

/************************************************************************/
/* ==================================================================== */
/*                             ACE2Dataset                              */
/* ==================================================================== */
/************************************************************************/

/************************************************************************/
/*                            ACE2Dataset()                             */
/************************************************************************/

ACE2Dataset::ACE2Dataset()
{
    adfGeoTransform[0] = 0.0;
    adfGeoTransform[1] = 1.0;
    adfGeoTransform[2] = 0.0;
    adfGeoTransform[3] = 0.0;
    adfGeoTransform[4] = 0.0;
    adfGeoTransform[5] = 1.0;
}

/************************************************************************/
/*                          GetGeoTransform()                           */
/************************************************************************/

CPLErr ACE2Dataset::GetGeoTransform( double * padfTransform )

{
    memcpy( padfTransform, adfGeoTransform, sizeof(double)*6 );
    return CE_None;
}

/************************************************************************/
/*                          GetProjectionRef()                          */
/************************************************************************/

const char *ACE2Dataset::GetProjectionRef()

{
    return SRS_WKT_WGS84;
}

/************************************************************************/
/*                          ACE2RasterBand()                            */
/************************************************************************/

ACE2RasterBand::ACE2RasterBand( VSILFILE* fpRawIn,
                                GDALDataType eDataTypeIn,
                                int nXSize, int nYSize) :
    RawRasterBand( fpRawIn, 0, GDALGetDataTypeSizeBytes(eDataTypeIn),
                   nXSize * GDALGetDataTypeSizeBytes(eDataTypeIn), eDataTypeIn,
                   CPL_IS_LSB, nXSize, nYSize, RawRasterBand::OwnFP::YES )
{}

/************************************************************************/
/*                             GetUnitType()                            */
/************************************************************************/

const char *ACE2RasterBand::GetUnitType()
{
    if (eDataType == GDT_Float32)
        return "m";

    return "";
}

/************************************************************************/
/*                         GetCategoryNames()                           */
/************************************************************************/

char **ACE2RasterBand::GetCategoryNames()
{
    if (eDataType != GDT_Int16)
        return nullptr;

    const char* pszName = poDS->GetDescription();

    if (strstr(pszName, "_SOURCE_"))
        return const_cast<char **>( apszCategorySource );
    if (strstr(pszName, "_QUALITY_"))
        return const_cast<char **>( apszCategoryQuality );
    if (strstr(pszName, "_CONF_"))
        return const_cast<char **>( apszCategoryConfidence );

    return nullptr;
}

/************************************************************************/
/*                             Identify()                               */
/************************************************************************/

int ACE2Dataset::Identify( GDALOpenInfo * poOpenInfo )

{
    if (! (EQUAL(CPLGetExtension(poOpenInfo->pszFilename), "ACE2") ||
           strstr(poOpenInfo->pszFilename, ".ACE2.gz") ||
           strstr(poOpenInfo->pszFilename, ".ace2.gz")) )
        return FALSE;

    return TRUE;
}

/************************************************************************/
/*                                Open()                                */
/************************************************************************/

GDALDataset *ACE2Dataset::Open( GDALOpenInfo * poOpenInfo )

{
    if (!Identify(poOpenInfo))
        return nullptr;

    const char* pszBasename = CPLGetBasename(poOpenInfo->pszFilename);

    if (strlen(pszBasename) < 7)
        return nullptr;

    /* Determine southwest coordinates from filename */

    /* e.g. 30S120W_5M.ACE2 */
    char pszLatLonValueString[4] = { '\0' };
    memset(pszLatLonValueString, 0, 4);
    // cppcheck-suppress redundantCopy
    strncpy(pszLatLonValueString, &pszBasename[0], 2);
    int southWestLat = atoi(pszLatLonValueString);
    memset(pszLatLonValueString, 0, 4);
    // cppcheck-suppress redundantCopy
    strncpy(pszLatLonValueString, &pszBasename[3], 3);
    int southWestLon = atoi(pszLatLonValueString);

    if(pszBasename[2] == 'N' || pszBasename[2] == 'n')
        /*southWestLat = southWestLat*/;
    else if(pszBasename[2] == 'S' || pszBasename[2] == 's')
        southWestLat = southWestLat * -1;
    else
        return nullptr;

    if(pszBasename[6] == 'E' || pszBasename[6] == 'e')
        /*southWestLon = southWestLon*/;
    else if(pszBasename[6] == 'W' || pszBasename[6] == 'w')
        southWestLon = southWestLon * -1;
    else
        return nullptr;

    GDALDataType eDT = GDT_Unknown;
    if (strstr(pszBasename, "_CONF_") ||
        strstr(pszBasename, "_QUALITY_") ||
        strstr(pszBasename, "_SOURCE_"))
        eDT = GDT_Int16;
    else
        eDT = GDT_Float32;
    int nWordSize = GDALGetDataTypeSize(eDT) / 8;

    VSIStatBufL sStat;
    if (strstr(pszBasename, "_5M"))
        sStat.st_size = 180 * 180 * nWordSize;
    else if (strstr(pszBasename, "_30S"))
        sStat.st_size = 1800 * 1800 * nWordSize;
    else if (strstr(pszBasename, "_9S"))
        sStat.st_size = 6000 * 6000 * nWordSize;
    else if (strstr(pszBasename, "_3S"))
        sStat.st_size = 18000 * 18000 * nWordSize;
    /* Check file size otherwise */
    else if(VSIStatL(poOpenInfo->pszFilename, &sStat) != 0)
    {
        return nullptr;
    }

    int nXSize = 0;
    int nYSize = 0;

    double dfPixelSize = 0;
    if (sStat.st_size == 180 * 180 * nWordSize)
    {
        /* 5 minute */
        nXSize = 180;
        nYSize = 180;
        dfPixelSize = 5.0 / 60;
    }
    else if (sStat.st_size == 1800 * 1800 * nWordSize)
    {
        /* 30 s */
        nXSize = 1800;
        nYSize = 1800;
        dfPixelSize = 30.0 / 3600;
    }
    else if (sStat.st_size == 6000 * 6000 * nWordSize)
    {
        /* 9 s */
        nXSize = 6000;
        nYSize = 6000;
        dfPixelSize = 9.0 / 3600;
    }
    else if (sStat.st_size == 18000 * 18000 * nWordSize)
    {
        /* 3 s */
        nXSize = 18000;
        nYSize = 18000;
        dfPixelSize = 3.0 / 3600;
    }
    else
        return nullptr;

/* -------------------------------------------------------------------- */
/*      Open file.                                                      */
/* -------------------------------------------------------------------- */

    CPLString osFilename = poOpenInfo->pszFilename;
    if ((strstr(poOpenInfo->pszFilename, ".ACE2.gz") ||
         strstr(poOpenInfo->pszFilename, ".ace2.gz")) &&
        !STARTS_WITH(poOpenInfo->pszFilename, "/vsigzip/"))
        osFilename = "/vsigzip/" + osFilename;

    VSILFILE* fpImage = VSIFOpenL( osFilename, "rb+" );
    if (fpImage == nullptr)
        return nullptr;

/* -------------------------------------------------------------------- */
/*      Create the dataset.                                             */
/* -------------------------------------------------------------------- */
    ACE2Dataset  *poDS = new ACE2Dataset();

    poDS->nRasterXSize = nXSize;
    poDS->nRasterYSize = nYSize;

    poDS->adfGeoTransform[0] = southWestLon;
    poDS->adfGeoTransform[1] = dfPixelSize;
    poDS->adfGeoTransform[2] = 0.0;
    poDS->adfGeoTransform[3] = southWestLat + nYSize * dfPixelSize;
    poDS->adfGeoTransform[4] = 0.0;
    poDS->adfGeoTransform[5] = -dfPixelSize;

/* -------------------------------------------------------------------- */
/*      Create band information objects                                 */
/* -------------------------------------------------------------------- */
    poDS->SetBand( 1, new ACE2RasterBand(fpImage, eDT, nXSize, nYSize ) );

/* -------------------------------------------------------------------- */
/*      Initialize any PAM information.                                 */
/* -------------------------------------------------------------------- */
    poDS->SetDescription( poOpenInfo->pszFilename );
    poDS->TryLoadXML();

/* -------------------------------------------------------------------- */
/*      Check for overviews.                                            */
/* -------------------------------------------------------------------- */
    poDS->oOvManager.Initialize( poDS, poOpenInfo->pszFilename );

    return poDS;
}

/************************************************************************/
/*                          GDALRegister_ACE2()                         */
/************************************************************************/

void GDALRegister_ACE2()

{
    if( GDALGetDriverByName( "ACE2" ) != nullptr )
        return;

    GDALDriver *poDriver = new GDALDriver();

    poDriver->SetDescription( "ACE2" );
    poDriver->SetMetadataItem( GDAL_DCAP_RASTER, "YES" );
    poDriver->SetMetadataItem( GDAL_DMD_LONGNAME, "ACE2" );
    poDriver->SetMetadataItem( GDAL_DMD_HELPTOPIC, "frmt_various.html#ACE2" );
    poDriver->SetMetadataItem( GDAL_DMD_EXTENSION, "ACE2" );
    poDriver->SetMetadataItem( GDAL_DCAP_VIRTUALIO, "YES" );

    poDriver->pfnOpen = ACE2Dataset::Open;
    poDriver->pfnIdentify = ACE2Dataset::Identify;

    GetGDALDriverManager()->RegisterDriver( poDriver );
}
