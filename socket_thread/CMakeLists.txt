cmake_minimum_required(VERSION "3.1")

project("abc"
        VERSION "1.0.0"
        DESCRIPTION "Plain's work"
        )

        add_executable(main
        main.cpp
        funcs.cpp)

        target_link_libraries(
    main
    curl
)

