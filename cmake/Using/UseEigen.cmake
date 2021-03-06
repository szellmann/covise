MACRO(USE_EIGEN)

    FIND_PACKAGE(EIGEN)
    IF ((NOT EIGEN_FOUND)  AND (${ARGC} LESS 1))
        USING_MESSAGE("Skipping because of missing Eigen")
        RETURN()
    ENDIF((NOT EIGEN_FOUND) AND (${ARGC} LESS 1))
    IF(NOT EIGEN_USED AND EIGEN_FOUND)
        SET(EIGEN_USED TRUE)
        INCLUDE_DIRECTORIES(SYSTEM ${EIGEN_INCLUDE_DIR})
    ENDIF()
ENDMACRO(USE_EIGEN)

