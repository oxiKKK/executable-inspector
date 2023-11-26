set(SOURCES
	soil/src/image_dxt.c
	soil/src/image_helper.c
	soil/src/soil.c
	soil/src/stb_image_aug.c
)

# Create the target.
add_library(soil STATIC ${SOURCES})

# include directories
target_include_directories(soil PRIVATE
	${SHARED_INCLUDES}
	${CMAKE_CURRENT_SOURCE_DIR}/soil/include
)