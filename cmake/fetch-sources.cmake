# Copyright (c) 2023 Stephan Linz
# SPDX-License-Identifier: Apache-2.0

include_guard(GLOBAL)

include(FetchContent)

function(CloneRepository repositoryURL branchName projectName sourceDir)
  # Commands are left empty so that we only checkout the source
  # and do not perform any kind of build.
  message("Starting to clone ${projectName} version ${branchName} into ${sourceDir}")
  FetchContent_Declare(
    "${projectName}"
    GIT_REPOSITORY "${repositoryURL}"
    GIT_TAG "${branchName}"
    GIT_SHALLOW true
    GIT_PROGRESS true
    GIT_SUBMODULES_RECURSE true
    GIT_REMOTE_UPDATE_STRATEGY CHECKOUT
    SOURCE_DIR "${sourceDir}"
    CONFIGURE_COMMAND ""
    CMAKE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
  )
# FetchContent_MakeAvailable(${projectName})
  FetchContent_GetProperties(${projectName})
  if(NOT ${projectName}_POPULATED)
    FetchContent_Populate(${projectName})
  endif()
endfunction(CloneRepository)

function(DownloadObject objectName objectHASH objectURL sourceDir)
  # Commands are left empty so that we only checkout the source
  # and do not perform any kind of build.
  message("Starting to download ${objectName} into ${sourceDir}")
  FetchContent_Declare(
    "${objectName}"
    URL "${objectURL}"
    URL_HASH "${objectHASH}"
    DOWNLOAD_NO_EXTRACT true
    SOURCE_DIR "${sourceDir}"
    CONFIGURE_COMMAND ""
    CMAKE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    HTTP_HEADER "User-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1)"
    TLS_VERIFY true
  )
# FetchContent_MakeAvailable(${objectName})
  FetchContent_GetProperties(${objectName})
  if(NOT ${objectName}_POPULATED)
    FetchContent_Populate(${objectName})
  endif()
endfunction(DownloadObject)
