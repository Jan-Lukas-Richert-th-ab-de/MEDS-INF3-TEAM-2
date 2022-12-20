cmake_minimum_required(VERSION 3.14)

# set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set project name
project(roomlist_test)

# get external library DocTest
include(FetchContent)  
FetchContent_Declare(doctest 
    GIT_REPOSITORY "https://github.com/onqtam/doctest"         
    GIT_TAG "b7c21ec5ceeadb4951b00396fc1e4642dd347e5f" )
FetchContent_MakeAvailable(doctest) 

# add library target
add_library(er STATIC "")
target_sources(er
    PRIVATE
        src/er/ER_Doctor.cpp
        src/er/ER_Patient.cpp
        src/er/ER_Room.cpp
        src/er/ER_Appointment.cpp
    PUBLIC
        src/er/ER_Room.h
        src/er/ER_Doctor.h
        src/er/ER_Patient.h
        src/er/ER_Appointment.h
)

# add library target
add_library(ar STATIC "")
target_sources(ar
    PRIVATE
        src/ar/AR_UCI_Room_Administration.cpp
        src/ar/AR_UCI_Doctor_Administration.cpp
        src/ar/AR_UCI_Patient_Administration.cpp
        src/ar/AR_UCI_Appointment_Administration.cpp
        
        src/ar/AR_UCI_Summary_Statistics_Reporting.cpp
    PUBLIC
        src/ar/AR_UCI_Room_Administration_IB.h
        src/ar/AR_UCI_Room_Administration_OB.h
        src/ar/AR_UCI_Room_Administration.h
        src/ar/AR_DAI_Room_Repository.h
        src/ar/AR_UCI_Doctor_Administration_IB.h
        src/ar/AR_UCI_Doctor_Administration_OB.h
        src/ar/AR_UCI_Doctor_Administration.h
        src/ar/AR_DAI_Doctor_Repository.h
        src/ar/AR_UCI_Patient_Administration_IB.h
        src/ar/AR_UCI_Patient_Administration_OB.h
        src/ar/AR_UCI_Patient_Administration.h
        src/ar/AR_DAI_Patient_Repository.h
        src/ar/AR_UCI_Appointment_Administration_IB.h
        src/ar/AR_UCI_Appointment_Administration_OB.h
        src/ar/AR_UCI_Appointment_Administration.h
        src/ar/AR_DAI_Appointment_Repository.h
       
        src/ar/AR_UCI_Summary_Statistics_Reporting_IB.h
        src/ar/AR_UCI_Summary_Statistics_Reporting_OB.h
        src/ar/AR_UCI_Summary_Statistics_Reporting.h

)
target_include_directories(ar PRIVATE src/er)
target_include_directories(ar PRIVATE src/fd)
target_link_libraries(ar er)
target_link_libraries(ar fd)

# add library target
add_library(ia STATIC "")
target_sources(ia
    PRIVATE
        src/ia/IA_Room_Presenter.cpp
        src/ia/IA_Room_Controller.cpp
        src/ia/IA_Doctor_Presenter.cpp
        src/ia/IA_Doctor_Controller.cpp
        src/ia/IA_Patient_Presenter.cpp
        src/ia/IA_Patient_Controller.cpp
        src/ia/IA_Appointment_Presenter.cpp
        src/ia/IA_Appointment_Controller.cpp
        src/ia/IA_test_Room_Controller.cpp
        src/ia/IA_test_Room_Presenter.cpp
        src/ia/IA_test_Patient_Controller.cpp
        src/ia/IA_test_Doctor_Controller.cpp
        src/ia/IA_test_Appointment_Controller.cpp
        src/ia/IA_Master_Controller_test.cpp
        src/ia/IA_Summary_Statistics_Controller.cpp
        src/ia/IA_Summary_Statistics_Presenter.cpp
        src/ia/IA_test_Summary_Statistics_Controller.cpp
    PUBLIC
        src/ia/IA_Room_Presenter.h
        src/ia/IA_Room_Controller.h
        src/ia/IA_Doctor_Presenter.h
        src/ia/IA_Doctor_Controller.h
        src/ia/IA_Patient_Presenter.h
        src/ia/IA_Patient_Controller.h
        src/ia/IA_Appointment_Presenter.h
        src/ia/IA_Appointment_Controller.h
        src/ia/IA_test_Room_Controller.h
        src/ia/IA_test_Room_Presenter.h
        src/ia/IA_test_Patient_Controller.h
        src/ia/IA_test_Doctor_Controller.h
        src/ia/IA_test_Appointment_Controller.h
        src/ia/IA_Master_Controller_test.h
        src/ia/IA_Summary_Statistics_Controller.h
        src/ia/IA_Summary_Statistics_Presenter.h
        src/ia/IA_test_Summary_Statistics_Controller.h



)
target_include_directories(ia PRIVATE src/ar)
target_include_directories(ia PRIVATE src/fd)
target_link_libraries(ia ar)
target_link_libraries(ia fd)

# add library target
add_library(fd STATIC "")
target_sources(fd
    PRIVATE
        src/fd/FD_View.cpp
        src/fd/FD_View_test.cpp
        src/fd/FD_Room_View.cpp
        src/fd/FD_Resource_View_test.cpp
        src/fd/FD_DA_Room_Repository_FileBasedImpl.cpp
        src/fd/FD_Doctor_View.cpp
        src/fd/FD_DA_Doctor_Repository_FileBasedImpl.cpp
        src/fd/FD_Patient_View.cpp
        src/fd/FD_DA_Patient_Repository_FileBasedImpl.cpp
        src/fd/FD_Appointment_View.cpp
        src/fd/FD_DA_Appointment_Repository_FileBasedImpl.cpp
        src/fd/FD_general_utility_functions.cpp
        src/fd/FD_Text_File_Record_Storage.cpp
        src/fd/FD_Summary_Statistics_View.cpp
    PUBLIC
        src/fd/FD_View.h
        src/fd/FD_View_test.h
        src/fd/FD_Resource_View.h
        src/fd/FD_Resource_View_test.h
        src/fd/FD_Room_View.h
        src/fd/FD_DA_Room_Repository_FileBasedImpl.h
        src/fd/FD_Doctor_View.h
        src/fd/FD_DA_Doctor_Repository_FileBasedImpl.h
        src/fd/FD_Patient_View.h
        src/fd/FD_DA_Patient_Repository_FileBasedImpl.h
        src/fd/FD_Appointment_View.h
        src/fd/FD_DA_Appointment_Repository_FileBasedImpl.h
        src/fd/FD_general_utility_functions.h
        src/fd/FD_Text_File_Record_Storage.h
        src/fd/FD_Summary_Statistics_View.h
)
target_include_directories(fd PRIVATE src/er)
target_include_directories(fd PRIVATE src/ar)
target_link_libraries(fd er)
target_link_libraries(fd ar)

# add main executable target
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE 
                           src/er PRIVATE src/ar PRIVATE src/ia PRIVATE src/fd)
target_link_libraries(${CMAKE_PROJECT_NAME} er)
target_link_libraries(${CMAKE_PROJECT_NAME} ar)
target_link_libraries(${CMAKE_PROJECT_NAME} ia)
target_link_libraries(${CMAKE_PROJECT_NAME} fd)

# add test executable target
add_executable(${CMAKE_PROJECT_NAME}_test)
target_sources(${CMAKE_PROJECT_NAME}_test
    PRIVATE
    src/test/base_config_main_test.cpp
    src/test/FD_DA_Room_Repository_FileBasedImpl_test.cpp
    src/test/ER_Room_test.cpp
)
target_include_directories(${CMAKE_PROJECT_NAME}_test PRIVATE
                           src/er PRIVATE src/ar PRIVATE src/ia PRIVATE src/fd 
                           ${doctest_SOURCE_DIR}/doctest)
target_link_libraries(${CMAKE_PROJECT_NAME}_test er)
target_link_libraries(${CMAKE_PROJECT_NAME}_test ar)
target_link_libraries(${CMAKE_PROJECT_NAME}_test ia)
target_link_libraries(${CMAKE_PROJECT_NAME}_test fd)
target_link_libraries(${CMAKE_PROJECT_NAME}_test doctest)
