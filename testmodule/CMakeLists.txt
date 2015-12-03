add_library(testmodule MODULE module.c)

INSTALL(TARGETS testmodule DESTINATION share/cappserver/modules)

