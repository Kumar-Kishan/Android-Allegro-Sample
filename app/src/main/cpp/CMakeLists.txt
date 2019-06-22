cmake_minimum_required(VERSION 3.4.1)

add_library( native-lib SHARED main.cpp)


find_library(log-lib log)

target_link_libraries(native-lib ${log-lib})

set(NATIVE_LIB native-lib)
set(JNI_FOLDER ${PROJECT_SOURCE_DIR}/../allegro_jni_includes) # or wherever you put it
include(${JNI_FOLDER}/allegro.cmake)
