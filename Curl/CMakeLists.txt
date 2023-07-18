cmake_minimum_required(VERSION "3.1")

project("Curl"
        VERSION "1.0.0"
        DESCRIPTION "work"
        )

link_libraries(
    curl
)

add_executable(run
        main.cpp
        fetch.cpp
        POST.cpp
        status_print.cpp
        upload_json.cpp
)
