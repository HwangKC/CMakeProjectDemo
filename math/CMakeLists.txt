# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)
#set(BUILD_SHARED_LIBS shared)

# 指定生成 MathFunctions 链接库
#add_library (MathFunctions SHARED ${DIR_LIB_SRCS})
add_library (MathFunctions ${DIR_LIB_SRCS})

# 指定 MathFunctions 库的安装路径
install (TARGETS MathFunctions DESTINATION bin)
install (FILES MathFunctions.h DESTINATION include)

target_include_directories(MathFunctions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )