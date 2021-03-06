IF(NOT COVISE_BUILD_DRIVINGSIM)
  RETURN()
ENDIF()
if(NOT XENOMAI_FOUND OR NOT COVISE_USE_XENOMAI)
  RETURN()
endif(NOT XENOMAI_FOUND OR NOT COVISE_USE_XENOMAI)

using(VRML)
USING(XERCESC BOOST)
using(VehicleUtil)
using(V8)

SET(HEADERS
 MotionPlatformPlugin.h
 InvertMatrix.hpp
)
SET(SOURCES
 MotionPlatformPlugin.cpp
)
INCLUDE_DIRECTORIES(
)


OPTION (COVISE_USE_XENOMAI "Use Xenomai" ON)
COVISE_FIND_PACKAGE(Xenomai)
if(XENOMAI_FOUND AND COVISE_USE_XENOMAI)
 SET(HEADERS ${HEADERS}
 )
 SET(SOURCES  ${SOURCES}
 )

 ADD_DEFINITIONS(${XENOMAI_DEFINITIONS})

 INCLUDE_DIRECTORIES(
   ${XENOMAI_INCLUDE_DIR}
   ../../../DrivingSim/gaalet/include

 )
endif(XENOMAI_FOUND AND COVISE_USE_XENOMAI)



cover_add_plugin_TARGET(MotionPlatform)

TARGET_LINK_LIBRARIES(MotionPlatform
    ${EXTRA_LIBS}
   coOpenVehicleUtil
)
COVISE_WNOERROR(MotionPlatform)
COVER_INSTALL_PLUGIN(MotionPlatform)

if(XENOMAI_FOUND AND COVISE_USE_XENOMAI)
 TARGET_LINK_LIBRARIES(MotionPlatform
   ${XENOMAI_LIBRARY_NATIVE}
   ${XENOMAI_LIBRARY_RTDM}
 )
endif(XENOMAI_FOUND AND COVISE_USE_XENOMAI)
