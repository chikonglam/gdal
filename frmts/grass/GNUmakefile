

include ../../GDALmake.opt

#OBJ	=	grassdataset.o

ifeq ($(GRASS_SETTING),libgrass)
OBJ	=	grassdataset.o
else
OBJ	=	grass57dataset.o
endif

CPPFLAGS	:=	 -DGRASS_GISBASE=\"$(GRASS_GISBASE)\" $(GRASS_INCLUDE) $(GDAL_INCLUDE) $(CPPFLAGS)

default:	$(OBJ:.o=.$(OBJ_EXT))

clean:
	rm -f *.o $(O_OBJ) $(OBJ)
	rm -f *~

install-obj:	$(O_OBJ:.o=.$(OBJ_EXT))

dist:
	cp -r pkg libgdal-grass-$(GDAL_VER)
	rm -rf libgdal-grass-$(GDAL_VER)/.svn
	cp grass57dataset.cpp libgdal-grass-$(GDAL_VER)
	cp ../../ogr/ogrsf_frmts/grass/*.cpp libgdal-grass-$(GDAL_VER)
	cp ../../ogr/ogrsf_frmts/grass/*.h libgdal-grass-$(GDAL_VER)
	# Adding VERSION to distribution
	cp ../../VERSION libgdal-grass-$(GDAL_VER)
	tar czvf libgdal-grass-$(GDAL_VER).tar.gz ./libgdal-grass-$(GDAL_VER)
	rm -rf libgdal-grass-$(GDAL_VER)

