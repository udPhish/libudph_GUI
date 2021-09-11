# CMAKE VERSION
cmake_minimum_required(VERSION 3.18.0)

include(cmake/udph.cmake)

project_create(libudph_Graphics)

PROJECT_SET_NAMESPACE(libudph_Graphics libudph)

TARGET_CREATE_LIB(Graphics STATIC)
TARGET_APPEND_SRC(
	Graphics
	"libudph/Graphics/dummy.cpp"
)
TARGET_APPEND_HDR(
	Graphics
	"libudph/Graphics/Event.h"
)

TARGET_LINK(Graphics)

TARGET_PACKAGE(Graphics)

FINALIZE()