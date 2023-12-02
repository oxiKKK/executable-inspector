add_subdirectory(${THIRDPARTY_PATH}/fmt)

link_libraries(fmt)

install(TARGETS fmt DESTINATION ${INSTALL_PATH})