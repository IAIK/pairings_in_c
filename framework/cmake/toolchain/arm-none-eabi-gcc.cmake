# some basic configurations for the target platform
set(CPU   cortex-m0    CACHE STRING "Device name for the compiler and tools (e.g.: cortex-m0)")

include(CMakeForceCompiler)

# specify the cross compiler
set(CMAKE_SYSTEM_NAME Generic)
CMAKE_FORCE_C_COMPILER(arm-none-eabi-gcc GNU)
CMAKE_FORCE_CXX_COMPILER(arm-none-eabi-g++ GNU)

# extend linker invocations so that map files are created
set( CMAKE_C_LINK_EXECUTABLE
     "<CMAKE_C_COMPILER> <FLAGS> <CMAKE_C_LINK_FLAGS> -Wl,-Map,<TARGET>.map <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
set( CMAKE_CXX_LINK_EXECUTABLE
     "<CMAKE_CXX_COMPILER> <FLAGS> <CMAKE_CXX_LINK_FLAGS> -Wl,-Map,<TARGET>.map <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")

# set the ARCHITECTURE for the framework
set(ARCHITECTURE "ARCH_CORTEXM0"
  CACHE STRING "ARCH_X86, ARCH_X86_64, ARCH_CORTEXM0" FORCE)

# set the directory name for the assembler optimizations
set(ASM_ARCH_DIR "cortexm0/asm" CACHE STRING "Name of the folder with the ASM optimizations." FORCE)

# startup code for cortex m0
set(ARCHITECTURE_C_SOURCES    "${PROJECT_SOURCE_DIR}/src/arch/cortexm0/startup.c")

# extend the compile flags with parameters to obtain small code size
set(TOOLCHAIN_ASM_FLAGS    "-std=c99 -mcpu=${CPU} -mthumb -ffunction-sections -fdata-sections")
set(TOOLCHAIN_C_FLAGS      "-std=c99 -mcpu=${CPU} -mthumb -ffunction-sections -fdata-sections")
set(TOOLCHAIN_CXX_FLAGS    "-std=c99 -mcpu=${CPU} -mthumb -ffunction-sections -fdata-sections")
set(TOOLCHAIN_LINKER_FLAGS "-Wl,-static -u _sbrk -Wl,-gc-sections -Wl,-lnosys -Wl,-T${PROJECT_SOURCE_DIR}/linker/cortexm0.ld -nostartfiles --specs=nano.specs")
