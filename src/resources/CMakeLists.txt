# Add any new core source files to this list.
SET( APP_SRC ${APP_SRC} 
  ${CMAKE_CURRENT_SOURCE_DIR}/isotope.cpp
  PARENT_SCOPE)

#add include files
SET( APP_INCL ${APP_INCL} 
  ${CMAKE_CURRENT_SOURCE_DIR}/isotope.h
  PARENT_SCOPE)
