cmake_minimum_required (VERSION 2.8)

# This project name is cyclopts.
project (APP)

# Direct any out-of-source builds to this directory
SET( APP_SRC_DIR ${CMAKE_SOURCE_DIR} )

# set module path
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake)

SET(APP_EXECUTABLE_DIR ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# Includes the directories in which there are source files. 
SET(APP_INCLUDE_DIRS
  ${APP_SRC_DIR}
  ${APP_SRC_DIR}/actors
  ${APP_SRC_DIR}/exchange
  ${APP_SRC_DIR}/resources
  )

# Add any new core source files to this list.
SET( APP_SRC app.cpp )

# add subdirectories
ADD_SUBDIRECTORY(actors)
ADD_SUBDIRECTORY(exchange)
ADD_SUBDIRECTORY(resources)

# include all the directories we just found
INCLUDE_DIRECTORIES( ${APP_INCLUDE_DIRS} )

# Build the app library from the APP_SRC source files
ADD_EXECUTABLE( app ${APP_SRC} )
TARGET_LINK_LIBRARIES( app dl ${LIBS} )