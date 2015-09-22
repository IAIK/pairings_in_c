# some basic configurations for the target platform
SET(CPU   cortex-m0    CACHE STRING "Device name for the compiler and tools (e.g.: cortex-m0)")

INCLUDE(CMakeForceCompiler)

# specify the cross compiler
SET(CMAKE_SYSTEM_NAME Generic)
CMAKE_FORCE_C_COMPILER(arm-none-eabi-gcc GNU)
CMAKE_FORCE_CXX_COMPILER(arm-none-eabi-g++ GNU)

# extend linker invocations so that map files are created
SET( CMAKE_C_LINK_EXECUTABLE
     "<CMAKE_C_COMPILER> <FLAGS> <CMAKE_C_LINK_FLAGS> -Wl,-Map,<TARGET>.map <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
SET( CMAKE_CXX_LINK_EXECUTABLE
     "<CMAKE_CXX_COMPILER> <FLAGS> <CMAKE_CXX_LINK_FLAGS> -Wl,-Map,<TARGET>.map <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")

# set the ARCHITECTURE for the framework
SET(ARCHITECTURE "ARCH_CORTEXM0"
  CACHE STRING "ARCH_X86, ARCH_X86_64, ARCH_CORTEXM0" FORCE)

# set the directory name for the assembler optimizations
SET(ASM_ARCH_DIR "arch/cortexm0/asm"
  CACHE STRING "Name of the folder with the ASM optimizations." FORCE)

# extend the compile flags with parameters to obtain small code size
SET(ARCHITECTURE_ASM_FLAGS    "-mcpu=${CPU} -mthumb -ffunction-sections -fdata-sections")
SET(ARCHITECTURE_C_FLAGS      "-mcpu=${CPU} -mthumb -ffunction-sections -fdata-sections")
SET(ARCHITECTURE_CXX_FLAGS    "-mcpu=${CPU} -mthumb -ffunction-sections -fdata-sections")
SET(ARCHITECTURE_LINKER_FLAGS "-mcpu=${CPU} -mthumb -Wl,-static -u _sbrk -Wl,-gc-sections -Wl,-lnosys -Wl,-T../linker/cortexm0.ld -nostartfiles --specs=nano.specs")

# startup code for cortex m0
SET(ARCHITECTURE_C_SOURCES    "../src/arch/cortexm0/startup.c")
