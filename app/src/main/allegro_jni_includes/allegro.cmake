get_filename_component(ABI ${CMAKE_BINARY_DIR} NAME)
set(base .)

macro(standard_library NAME)
    string(TOUPPER ${NAME} UNAME)
    find_library(LIB_${UNAME} ${NAME})
    target_link_libraries(${NATIVE_LIB} ${LIB_${UNAME}})
endmacro()

macro(allegro_library NAME)
    string(TOUPPER ${NAME} UNAME)
    set(path ${JNI_FOLDER}/jniLibs/${ABI}/lib${NAME})
    if(EXISTS "${path}-debug.so")
        set(LIB_${UNAME} ${path}-debug.so)
    elseif(EXISTS "${path}.so")
        set(LIB_${UNAME} ${path}.so)
    else()
        message(SEND_ERROR "${path}.so does not exist")
    endif()
    target_link_libraries(${NATIVE_LIB} ${LIB_${UNAME}})
endmacro()

include_directories(${JNI_FOLDER}/jniIncludes)
allegro_library(allegro)
allegro_library(allegro_acodec)
allegro_library(allegro_audio)
allegro_library(allegro_color)
allegro_library(allegro_font)
allegro_library(allegro_image)
allegro_library(allegro_primitives)
allegro_library(allegro_ttf)
standard_library(m)
standard_library(z)
standard_library(log)
standard_library(GLESv2)
