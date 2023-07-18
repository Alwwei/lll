cmake_minimum_required(VERSION "3.1")

project("plain"
        VERSION "1.0.0"
        DESCRIPTION "Plain's work"
        )

add_executable(run
        linked_list.c
        hash_table.c
        run.c
        max_heap.c)
