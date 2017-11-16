# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anastasia/tanks-game-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anastasia/tanks-game-master

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/anastasia/tanks-game-master/CMakeFiles /home/anastasia/tanks-game-master/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/anastasia/tanks-game-master/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named miniTanks

# Build rule for target.
miniTanks: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 miniTanks
.PHONY : miniTanks

# fast build rule for target.
miniTanks/fast:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/build
.PHONY : miniTanks/fast

Animation.o: Animation.cpp.o
.PHONY : Animation.o

# target to build an object file
Animation.cpp.o:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Animation.cpp.o
.PHONY : Animation.cpp.o

Animation.i: Animation.cpp.i
.PHONY : Animation.i

# target to preprocess a source file
Animation.cpp.i:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Animation.cpp.i
.PHONY : Animation.cpp.i

Animation.s: Animation.cpp.s
.PHONY : Animation.s

# target to generate assembly for a file
Animation.cpp.s:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Animation.cpp.s
.PHONY : Animation.cpp.s

Application.o: Application.cpp.o
.PHONY : Application.o

# target to build an object file
Application.cpp.o:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Application.cpp.o
.PHONY : Application.cpp.o

Application.i: Application.cpp.i
.PHONY : Application.i

# target to preprocess a source file
Application.cpp.i:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Application.cpp.i
.PHONY : Application.cpp.i

Application.s: Application.cpp.s
.PHONY : Application.s

# target to generate assembly for a file
Application.cpp.s:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Application.cpp.s
.PHONY : Application.cpp.s

CtrlPanel.o: CtrlPanel.cpp.o
.PHONY : CtrlPanel.o

# target to build an object file
CtrlPanel.cpp.o:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/CtrlPanel.cpp.o
.PHONY : CtrlPanel.cpp.o

CtrlPanel.i: CtrlPanel.cpp.i
.PHONY : CtrlPanel.i

# target to preprocess a source file
CtrlPanel.cpp.i:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/CtrlPanel.cpp.i
.PHONY : CtrlPanel.cpp.i

CtrlPanel.s: CtrlPanel.cpp.s
.PHONY : CtrlPanel.s

# target to generate assembly for a file
CtrlPanel.cpp.s:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/CtrlPanel.cpp.s
.PHONY : CtrlPanel.cpp.s

Game.o: Game.cpp.o
.PHONY : Game.o

# target to build an object file
Game.cpp.o:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Game.cpp.o
.PHONY : Game.cpp.o

Game.i: Game.cpp.i
.PHONY : Game.i

# target to preprocess a source file
Game.cpp.i:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Game.cpp.i
.PHONY : Game.cpp.i

Game.s: Game.cpp.s
.PHONY : Game.s

# target to generate assembly for a file
Game.cpp.s:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Game.cpp.s
.PHONY : Game.cpp.s

GameOverScreen.o: GameOverScreen.cpp.o
.PHONY : GameOverScreen.o

# target to build an object file
GameOverScreen.cpp.o:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/GameOverScreen.cpp.o
.PHONY : GameOverScreen.cpp.o

GameOverScreen.i: GameOverScreen.cpp.i
.PHONY : GameOverScreen.i

# target to preprocess a source file
GameOverScreen.cpp.i:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/GameOverScreen.cpp.i
.PHONY : GameOverScreen.cpp.i

GameOverScreen.s: GameOverScreen.cpp.s
.PHONY : GameOverScreen.s

# target to generate assembly for a file
GameOverScreen.cpp.s:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/GameOverScreen.cpp.s
.PHONY : GameOverScreen.cpp.s

GameSetupScreen.o: GameSetupScreen.cpp.o
.PHONY : GameSetupScreen.o

# target to build an object file
GameSetupScreen.cpp.o:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/GameSetupScreen.cpp.o
.PHONY : GameSetupScreen.cpp.o

GameSetupScreen.i: GameSetupScreen.cpp.i
.PHONY : GameSetupScreen.i

# target to preprocess a source file
GameSetupScreen.cpp.i:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/GameSetupScreen.cpp.i
.PHONY : GameSetupScreen.cpp.i

GameSetupScreen.s: GameSetupScreen.cpp.s
.PHONY : GameSetupScreen.s

# target to generate assembly for a file
GameSetupScreen.cpp.s:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/GameSetupScreen.cpp.s
.PHONY : GameSetupScreen.cpp.s

Land.o: Land.cpp.o
.PHONY : Land.o

# target to build an object file
Land.cpp.o:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Land.cpp.o
.PHONY : Land.cpp.o

Land.i: Land.cpp.i
.PHONY : Land.i

# target to preprocess a source file
Land.cpp.i:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Land.cpp.i
.PHONY : Land.cpp.i

Land.s: Land.cpp.s
.PHONY : Land.s

# target to generate assembly for a file
Land.cpp.s:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Land.cpp.s
.PHONY : Land.cpp.s

Menu.o: Menu.cpp.o
.PHONY : Menu.o

# target to build an object file
Menu.cpp.o:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Menu.cpp.o
.PHONY : Menu.cpp.o

Menu.i: Menu.cpp.i
.PHONY : Menu.i

# target to preprocess a source file
Menu.cpp.i:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Menu.cpp.i
.PHONY : Menu.cpp.i

Menu.s: Menu.cpp.s
.PHONY : Menu.s

# target to generate assembly for a file
Menu.cpp.s:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Menu.cpp.s
.PHONY : Menu.cpp.s

MessageStream.o: MessageStream.cpp.o
.PHONY : MessageStream.o

# target to build an object file
MessageStream.cpp.o:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/MessageStream.cpp.o
.PHONY : MessageStream.cpp.o

MessageStream.i: MessageStream.cpp.i
.PHONY : MessageStream.i

# target to preprocess a source file
MessageStream.cpp.i:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/MessageStream.cpp.i
.PHONY : MessageStream.cpp.i

MessageStream.s: MessageStream.cpp.s
.PHONY : MessageStream.s

# target to generate assembly for a file
MessageStream.cpp.s:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/MessageStream.cpp.s
.PHONY : MessageStream.cpp.s

Missile.o: Missile.cpp.o
.PHONY : Missile.o

# target to build an object file
Missile.cpp.o:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Missile.cpp.o
.PHONY : Missile.cpp.o

Missile.i: Missile.cpp.i
.PHONY : Missile.i

# target to preprocess a source file
Missile.cpp.i:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Missile.cpp.i
.PHONY : Missile.cpp.i

Missile.s: Missile.cpp.s
.PHONY : Missile.s

# target to generate assembly for a file
Missile.cpp.s:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Missile.cpp.s
.PHONY : Missile.cpp.s

MsgComponents.o: MsgComponents.cpp.o
.PHONY : MsgComponents.o

# target to build an object file
MsgComponents.cpp.o:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/MsgComponents.cpp.o
.PHONY : MsgComponents.cpp.o

MsgComponents.i: MsgComponents.cpp.i
.PHONY : MsgComponents.i

# target to preprocess a source file
MsgComponents.cpp.i:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/MsgComponents.cpp.i
.PHONY : MsgComponents.cpp.i

MsgComponents.s: MsgComponents.cpp.s
.PHONY : MsgComponents.s

# target to generate assembly for a file
MsgComponents.cpp.s:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/MsgComponents.cpp.s
.PHONY : MsgComponents.cpp.s

Player.o: Player.cpp.o
.PHONY : Player.o

# target to build an object file
Player.cpp.o:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Player.cpp.o
.PHONY : Player.cpp.o

Player.i: Player.cpp.i
.PHONY : Player.i

# target to preprocess a source file
Player.cpp.i:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Player.cpp.i
.PHONY : Player.cpp.i

Player.s: Player.cpp.s
.PHONY : Player.s

# target to generate assembly for a file
Player.cpp.s:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Player.cpp.s
.PHONY : Player.cpp.s

Tank.o: Tank.cpp.o
.PHONY : Tank.o

# target to build an object file
Tank.cpp.o:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Tank.cpp.o
.PHONY : Tank.cpp.o

Tank.i: Tank.cpp.i
.PHONY : Tank.i

# target to preprocess a source file
Tank.cpp.i:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Tank.cpp.i
.PHONY : Tank.cpp.i

Tank.s: Tank.cpp.s
.PHONY : Tank.s

# target to generate assembly for a file
Tank.cpp.s:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/Tank.cpp.s
.PHONY : Tank.cpp.s

TitleScreen.o: TitleScreen.cpp.o
.PHONY : TitleScreen.o

# target to build an object file
TitleScreen.cpp.o:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/TitleScreen.cpp.o
.PHONY : TitleScreen.cpp.o

TitleScreen.i: TitleScreen.cpp.i
.PHONY : TitleScreen.i

# target to preprocess a source file
TitleScreen.cpp.i:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/TitleScreen.cpp.i
.PHONY : TitleScreen.cpp.i

TitleScreen.s: TitleScreen.cpp.s
.PHONY : TitleScreen.s

# target to generate assembly for a file
TitleScreen.cpp.s:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/TitleScreen.cpp.s
.PHONY : TitleScreen.cpp.s

WeaponPostEffects.o: WeaponPostEffects.cpp.o
.PHONY : WeaponPostEffects.o

# target to build an object file
WeaponPostEffects.cpp.o:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/WeaponPostEffects.cpp.o
.PHONY : WeaponPostEffects.cpp.o

WeaponPostEffects.i: WeaponPostEffects.cpp.i
.PHONY : WeaponPostEffects.i

# target to preprocess a source file
WeaponPostEffects.cpp.i:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/WeaponPostEffects.cpp.i
.PHONY : WeaponPostEffects.cpp.i

WeaponPostEffects.s: WeaponPostEffects.cpp.s
.PHONY : WeaponPostEffects.s

# target to generate assembly for a file
WeaponPostEffects.cpp.s:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/WeaponPostEffects.cpp.s
.PHONY : WeaponPostEffects.cpp.s

World.o: World.cpp.o
.PHONY : World.o

# target to build an object file
World.cpp.o:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/World.cpp.o
.PHONY : World.cpp.o

World.i: World.cpp.i
.PHONY : World.i

# target to preprocess a source file
World.cpp.i:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/World.cpp.i
.PHONY : World.cpp.i

World.s: World.cpp.s
.PHONY : World.s

# target to generate assembly for a file
World.cpp.s:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/World.cpp.s
.PHONY : World.cpp.s

simplexnoise.o: simplexnoise.cpp.o
.PHONY : simplexnoise.o

# target to build an object file
simplexnoise.cpp.o:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/simplexnoise.cpp.o
.PHONY : simplexnoise.cpp.o

simplexnoise.i: simplexnoise.cpp.i
.PHONY : simplexnoise.i

# target to preprocess a source file
simplexnoise.cpp.i:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/simplexnoise.cpp.i
.PHONY : simplexnoise.cpp.i

simplexnoise.s: simplexnoise.cpp.s
.PHONY : simplexnoise.s

# target to generate assembly for a file
simplexnoise.cpp.s:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/simplexnoise.cpp.s
.PHONY : simplexnoise.cpp.s

utilities.o: utilities.cpp.o
.PHONY : utilities.o

# target to build an object file
utilities.cpp.o:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/utilities.cpp.o
.PHONY : utilities.cpp.o

utilities.i: utilities.cpp.i
.PHONY : utilities.i

# target to preprocess a source file
utilities.cpp.i:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/utilities.cpp.i
.PHONY : utilities.cpp.i

utilities.s: utilities.cpp.s
.PHONY : utilities.s

# target to generate assembly for a file
utilities.cpp.s:
	$(MAKE) -f CMakeFiles/miniTanks.dir/build.make CMakeFiles/miniTanks.dir/utilities.cpp.s
.PHONY : utilities.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... miniTanks"
	@echo "... Animation.o"
	@echo "... Animation.i"
	@echo "... Animation.s"
	@echo "... Application.o"
	@echo "... Application.i"
	@echo "... Application.s"
	@echo "... CtrlPanel.o"
	@echo "... CtrlPanel.i"
	@echo "... CtrlPanel.s"
	@echo "... Game.o"
	@echo "... Game.i"
	@echo "... Game.s"
	@echo "... GameOverScreen.o"
	@echo "... GameOverScreen.i"
	@echo "... GameOverScreen.s"
	@echo "... GameSetupScreen.o"
	@echo "... GameSetupScreen.i"
	@echo "... GameSetupScreen.s"
	@echo "... Land.o"
	@echo "... Land.i"
	@echo "... Land.s"
	@echo "... Menu.o"
	@echo "... Menu.i"
	@echo "... Menu.s"
	@echo "... MessageStream.o"
	@echo "... MessageStream.i"
	@echo "... MessageStream.s"
	@echo "... Missile.o"
	@echo "... Missile.i"
	@echo "... Missile.s"
	@echo "... MsgComponents.o"
	@echo "... MsgComponents.i"
	@echo "... MsgComponents.s"
	@echo "... Player.o"
	@echo "... Player.i"
	@echo "... Player.s"
	@echo "... Tank.o"
	@echo "... Tank.i"
	@echo "... Tank.s"
	@echo "... TitleScreen.o"
	@echo "... TitleScreen.i"
	@echo "... TitleScreen.s"
	@echo "... WeaponPostEffects.o"
	@echo "... WeaponPostEffects.i"
	@echo "... WeaponPostEffects.s"
	@echo "... World.o"
	@echo "... World.i"
	@echo "... World.s"
	@echo "... simplexnoise.o"
	@echo "... simplexnoise.i"
	@echo "... simplexnoise.s"
	@echo "... utilities.o"
	@echo "... utilities.i"
	@echo "... utilities.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
