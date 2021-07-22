TARGET = biniax2psp
PSPSDK=$(shell psp-config --pspsdk-path)
PSPBIN = $(PSPSDK)/../bin
SDL_CONFIG = $(PSPBIN)/sdl-config
PSP_EBOOT_PIC1 = PIC1.png
PSP_EBOOT_ICON = ICON0.png

PSP_FW_VERSION=371
BUILD_PRX = 1

OBJS = biniax.o hof.o cfg.o gfx.o snd.o inp.o sys.o hof.o tut.o 
LIBDIR =
LDFLAGS =
CFLAGS = -G0 -O2  -Wall -g 



LIBS = -lstdc++  -lSDL_mixer  -lvorbisidec   -lSDL_image -lpng -lz -ljpeg -lGL -lSDL_gfx -lm $(shell $(SDL_CONFIG) --libs) -lGL  -lpsprtc   -lpspvfpu  -lpsppower
EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = biniax2psp

include $(PSPSDK)/lib/build.mak
