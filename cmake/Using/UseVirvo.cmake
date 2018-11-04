MACRO(USE_VIRVO)
    set(opt "")
    set(component "virvo")
    foreach(comp ${ARGV})
        set(curcomp ${comp})
        if (curcomp STREQUAL "optional")
            set(opt "optional")
            using_message("Using Virvo: OPTIONAL")
        elseif(NOT curcomp STREQUAL "")
            set(component ${comp})
        endif()
    endforeach(comp ${ARGV})
    using_message("Using Virvo: component=${component}")

    if (COVISE_USE_VIRVO)
        USE_BOOST(${opt})
        covise_find_package(GDCM)
        if (GDCM_FOUND)
          include(${GDCM_USE_FILE})
          add_definitions(-DHAVE_GDCM)
        endif()
        if (component STREQUAL "fileio")
          SET(EXTRA_LIBS ${EXTRA_LIBS} virvo_fileio)
        else()
          USE_GLEW(${opt})
          USE_FFMPEG(optional)
          USE_JPEGTURBO(optional)
          SET(EXTRA_LIBS ${EXTRA_LIBS} virvo)
          if (component STREQUAL "osg")
            SET(EXTRA_LIBS ${EXTRA_LIBS} virvo_osg)
          elseif(NOT component STREQUAL "virvo")
            message("Use_Virvo: unknown component \"${component}\"")
          endif()
        endif()
        IF(NOT VIRVO_USED)
            SET(VIRVO_USED TRUE)
            INCLUDE_DIRECTORIES(${COVISEDIR}/src/3rdparty/deskvox/virvo)
        ENDIF(NOT VIRVO_USED)
    else()
        if (NOT opt STREQUAL "optional")
            return()
        endif()
    endif()
ENDMACRO(USE_VIRVO)
