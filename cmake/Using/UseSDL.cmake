MACRO(USE_SDL)
  covise_find_package(SDL)
  IF ((NOT SDL_FOUND)  AND (${ARGC} LESS 1))
    USING_MESSAGE("Skipping because of missing SDL")
    RETURN()
  ENDIF ((NOT SDL_FOUND) AND (${ARGC} LESS 1))
     IF(NOT SDL_USED AND SDL_FOUND)
        SET(SDL_USED TRUE)
        INCLUDE_DIRECTORIES(SYSTEM ${SDL_INCLUDE_DIR})
	    ADD_DEFINITIONS(-DHAVE_SDL)
        SET(EXTRA_LIBS ${EXTRA_LIBS} ${SDL_LIBRARIES} ${SDL_LIBRARY})
     ENDIF()
ENDMACRO(USE_SDL)
