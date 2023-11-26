set(SOURCES
	image_dxt.c
	image_helper.c
	soil.c
	stb_image_aug.c
)

# Create the target.
add_library(soil STATIC ${SOURCES})

# include directories
target_include_directories(soil PRIVATE
	${SHARED_INCLUDES}
	${CMAKE_CURRENT_SOURCE_DIR}
)