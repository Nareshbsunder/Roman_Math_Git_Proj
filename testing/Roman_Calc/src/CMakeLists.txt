set(LIB_SOURCES
  Roman_Math.c
)

set(MAIN_SOURCES
  main.c
)

set(HEADERS 
  ${CONFIG_HEADER}
  Roman_Math.h
)

add_library(Roman_Math STATIC ${LIB_SOURCES} ${HEADERS})

add_executable(main ${HEADERS} ${MAIN_SOURCES})
target_link_libraries(main Roman_Math)

install(TARGETS Roman_Math
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/Roman_Math.h DESTINATION include)
