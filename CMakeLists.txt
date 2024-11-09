cmake_minimum_required(VERSION 3.6)

project(tcl_audio)

aux_source_directory(.  SRC_FILE)

add_executable(tcl_audio ${SRC_FILE})