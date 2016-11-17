
XCODE_BASE=/Applications/Xcode.app/Contents

PLATFORM_BASE=$(XCODE_BASE)/Developer/Platforms

FRAMEWORKS_IPHONE=$(PLATFORM_BASE)/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk/System/Library/Frameworks/
PLATFORM_INCLUDES_IPHONE=$(PLATFORM_BASE)/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk/usr/include

FRAMEWORKS_SIMULATOR=$(PLATFORM_BASE)/iPhoneSimulator.platform/Developer/SDKs/iPhoneOS.sdk/System/Library/Frameworks/
PLATFORM_INCLUDES_SIMULATOR=$(PLATFORM_BASE)/iPhoneSimulator.platform/Developer/SDKs/iPhoneOS.sdk/usr/include

FRAMEWORKS_OSX=$(PLATFORM_BASE)/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/
PLATFORM_INCLUDES_OSX=$(PLATFORM_BASE)/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include

INCLUDES := ./NE10/Library/headers
COMMON := ./NE10/Library/Common
DSPINCLUDES := ./NE10/Library/Modules/dsp
MATHINCLUDES := ./NE10/Library/Modules/math

CC :=clang

#COMPILE_SOURCES_ARM7_ASM := $(shell find ./build/arm7/sources -name '*.s' | sed s/.*[\/]//g)
#OBJ_ARMV7_ASM := $(addprefix ./build/arm7/sources/, $(subst .s,.o, $(COMPILE_SOURCES_ARM7_ASM)))

#COMPILE_SOURCES_ARM7_C := $(shell find ./build/arm7/sources -name '*.c' | sed s/.*[\/]//g)
#COMPILE_SOURCES_ARM64_C := $(shell find ./build/arm64/sources -name '*.c' | sed s/.*[\/]//g)
COMPILE_SOURCES_OSX_C := $(shell find ./build/osx/sources -name '*.c' | sed s/.*[\/]//g)
COMPILE_SOURCES_SIMUL_C := $(shell find ./build/simulator/sources -name '*.c' | sed s/.*[\/]//g)
#OBJ_ARMV7_C := $(addprefix ./build/arm7/sources/, $(subst .c,.o, $(COMPILE_SOURCES_ARM7_C)))
#OBJ_ARM64_C := $(addprefix ./build/arm64/sources/, $(subst .c,.o, $(COMPILE_SOURCES_ARM64_C)))
OBJ_64BIT_C := $(addprefix ./build/osx/sources/, $(subst .c,.o, $(COMPILE_SOURCES_OSX_C)))
OBJ_SIMUL_C := $(addprefix ./build/simulator/sources/, $(subst .c,.o, $(COMPILE_SOURCES_SIMUL_C)))

#COMPILE_SOURCES_ARM7_CPP := $(shell find ./build/arm7/sources -name '*.cpp' | sed s/.*[\/]//g)
#COMPILE_SOURCES_ARM64_CPP := $(shell find ./build/arm64/sources -name '*.cpp' | sed s/.*[\/]//g)
COMPILE_SOURCES_OSX_CPP := $(shell find ./build/osx/sources -name '*.cpp' | sed s/.*[\/]//g)
COMPILE_SOURCES_SIMUL_CPP := $(shell find ./build/simulator/sources -name '*.cpp' | sed s/.*[\/]//g)
#OBJ_ARMV7_CPP := $(addprefix ./build/arm7/sources/, $(subst .cpp,.o, $(COMPILE_SOURCES_ARM7_CPP)))
#OBJ_ARM64_CPP := $(addprefix ./build/arm64/sources/, $(subst .cpp,.o, $(COMPILE_SOURCES_ARM64_CPP)))
OBJ_64BIT_CPP := $(addprefix ./build/osx/sources/, $(subst .cpp,.o, $(COMPILE_SOURCES_OSX_CPP)))
OBJ_SIMUL_CPP := $(addprefix ./build/simulator/sources/, $(subst .cpp,.o, $(COMPILE_SOURCES_SIMUL_CPP)))

all: osx simulator
	lipo -create ./build/osx/product/libNE10.a ./build/simulator/product/libNE10.a -output ./build/all/libNE10.a
#	lipo -create ./build/osx/product/libNE10.a ./build/simulator/product/libNE10.a ./build/arm7/product/libNE10.a ./build/arm64/product/libNE10.a -output ./build/all/libNE10.a

osx: $(OBJ_64BIT_C) $(OBJ_64BIT_CPP)
	ar -rcs ./build/osx/product/libNE10.a $(OBJ_64BIT_C) $(OBJ_64BIT_CPP)

simulator: $(OBJ_SIMUL_C) $(OBJ_SIMUL_CPP)
	ar -rcs ./build/simulator/product/libNE10.a $(OBJ_SIMUL_C) $(OBJ_SIMUL_CPP)

#ios_armv7: $(OBJ_ARMV7_C) $(OBJ_ARMV7_CPP) $(OBJ_ARMV7_ASM)
#	ar -rcs ./build/arm7/product/libNE10.a $(OBJ_ARMV7_C) $(OBJ_ARMV7_CPP) $(OBJ_ARMV7_ASM)

#ios_arm64: $(OBJ_ARM64_C) $(OBJ_ARM64_CPP)
#	ar -rcs ./build/arm64/product/libNE10.a $(OBJ_ARM64_C) $(OBJ_ARM64_CPP)

$(OBJ_SIMUL_C):	%.o: %.c
	$(CC) -c $< -F$(FRAMEWORKS_SIMULATOR) -I$(PLATFORM_INCLUDES_SIMULATOR) -I$(INCLUDES) -I$(DSPINCLUDES) -I$(MATHINCLUDES) -I$(COMMON) -DSTRIP_NEON -DNE10_ENABLE_MATH -DNE10_ENABLE_DSP -arch i386 -Wno-nullability-completeness -o $@

$(OBJ_SIMUL_CPP):	%.o: %.cpp
	$(CC) -c $< -F$(FRAMEWORKS_SIMULATOR) -I$(PLATFORM_INCLUDES_SIMULATOR) -I$(INCLUDES) -I$(DSPINCLUDES) -I$(MATHINCLUDES) -I$(COMMON) -DSTRIP_NEON -DNE10_ENABLE_MATH -DNE10_ENABLE_DSP -arch i386 -Wno-nullability-completeness -o $@

$(OBJ_64BIT_C):	%.o: %.c
	$(CC) -c $< -F$(FRAMEWORKS_OSX) -I$(PLATFORM_INCLUDES_OSX) -I$(INCLUDES) -I$(DSPINCLUDES) -I$(MATHINCLUDES) -I$(COMMON) -DSTRIP_NEON -DNE10_ENABLE_MATH -DNE10_ENABLE_DSP -arch x86_64 -Wno-nullability-completeness -o $@

$(OBJ_64BIT_CPP):	%.o: %.cpp
	$(CC) -c $< -F$(FRAMEWORKS_OSX) -I$(PLATFORM_INCLUDES_OSX) -I$(INCLUDES) -I$(DSPINCLUDES) -I$(MATHINCLUDES) -I$(COMMON) -DSTRIP_NEON -DNE10_ENABLE_MATH -DNE10_ENABLE_DSP -arch x86_64 -Wno-nullability-completeness -o $@

#$(OBJ_ARMV7_ASM): %o : %.s
#	$(CC) -s $< -F$(FRAMEWORKS_IPHONE) -I$(PLATFORM_INCLUDES_IPHONE) -I$(INCLUDES) -I$(DSPINCLUDES) -I$(MATHINCLUDES) -I$(COMMON) -DNE10_ENABLE_MATH -DNE10_ENABLE_DSP -fembed-bitcode -mfpu=neon -arch armv7 -miphoneos-version-min=8.2 -Wno-nullability-completeness -o $@

#$(OBJ_ARMV7_C):	%.o: %.c
#	$(CC) -c $< -F$(FRAMEWORKS_IPHONE) -I$(PLATFORM_INCLUDES_IPHONE) -I$(INCLUDES) -I$(DSPINCLUDES) -I$(MATHINCLUDES) -I$(COMMON) -DNE10_ENABLE_MATH -DNE10_ENABLE_DSP -fembed-bitcode -mfpu=neon -arch armv7 -miphoneos-version-min=8.2 -Wno-nullability-completeness -o $@

#$(OBJ_ARMV7_CPP):	%.o: %.cpp
#	$(CC) -c $< -F$(FRAMEWORKS_IPHONE) -I$(PLATFORM_INCLUDES_IPHONE) -I$(INCLUDES) -I$(DSPINCLUDES) -I$(MATHINCLUDES) -I$(COMMON) -DNE10_ENABLE_MATH -DNE10_ENABLE_DSP -fembed-bitcode -mfpu=neon -arch armv7 -miphoneos-version-min=8.2 -Wno-nullability-completeness -o $@

#$(OBJ_ARM64_C):	%.o: %.c
#	$(CC) -c $< -F$(FRAMEWORKS_IPHONE) -I$(PLATFORM_INCLUDES_IPHONE) -I$(INCLUDES) -I$(DSPINCLUDES) -I$(MATHINCLUDES) -I$(COMMON) -DSTRIP_NEON -DNE10_ENABLE_MATH -DNE10_ENABLE_DSP -fembed-bitcode -arch arm64 -miphoneos-version-min=8.2 -Wno-nullability-completeness -o $@

#$(OBJ_ARM64_CPP):	%.o: %.cpp
#	$(CC) -c $< -F$(FRAMEWORKS_IPHONE) -I$(PLATFORM_INCLUDES_IPHONE) -I$(INCLUDES) -I$(DSPINCLUDES) -I$(MATHINCLUDES) -I$(COMMON) -DSTRIP_NEON -DNE10_ENABLE_MATH -DNE10_ENABLE_DSP -fembed-bitcode -arch arm64 -miphoneos-version-min=8.2 -Wno-nullability-completeness -o $@

clean:
	rm -rf ./build
