# CMAKE VERSION
cmake_minimum_required(VERSION 3.18.0)

include(cmake/udph.cmake)

project_create(libudph_GUI)

PROJECT_SET_NAMESPACE(libudph_GUI libudph)

PROJECT_LOAD_GIT_REPOSITORY(libudph_Class "https://github.com/udPhish/libudph_Class.git" dev)
PROJECT_LOAD_GIT_REPOSITORY(libudph_Math "https://github.com/udPhish/libudph_Math.git" master)
PROJECT_LOAD_GIT_REPOSITORY(wxwidgets "https://github.com/wxWidgets/wxWidgets.git" master)
PROJECT_LOAD_GIT_REPOSITORY(SDL2 "https://github.com/libsdl-org/SDL.git" master)

TARGET_CREATE_LIB(GUI STATIC)
TARGET_APPEND_SRC(
	GUI
	"libudph/GUI/dummy.cpp"
	"libudph/GUI/Application.cpp"
	"libudph/GUI/Window.cpp"
)
TARGET_APPEND_HDR(
	GUI
	"libudph/GUI/Application.h"
	"libudph/GUI/ApplicationTypes.h"
	"libudph/GUI/Window.h"
)

TARGET_APPEND_DEP_PUBLIC(GUI libudph::Class)
TARGET_APPEND_DEP_PUBLIC(GUI libudph::Math)
TARGET_APPEND_DEP_PUBLIC(GUI wx::base)
TARGET_APPEND_DEP_PUBLIC(GUI wx::core)
TARGET_APPEND_DEP_PUBLIC(GUI SDL2::SDL2-static)

TARGET_LINK(GUI)

TARGET_CREATE_EXE(Test_GUI)
TARGET_SET_DIR(Test_GUI "libudph/Test/GUI")
TARGET_APPEND_SRC(
	Test_GUI
	"main.cpp"
)
TARGET_APPEND_DEP(Test_GUI libudph::GUI)

TARGET_LINK(Test_GUI)
FINALIZE()