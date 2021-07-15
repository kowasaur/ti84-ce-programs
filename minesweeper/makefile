# ----------------------------
# Makefile Options
# ----------------------------

NAME ?= MinSwepr
DESCRIPTION ?= "Minesweeper"
COMPRESSED ?= NO
ARCHIVED ?= YES

CFLAGS ?= -Wall -Wextra -Oz
CXXFLAGS ?= -Wall -Wextra -Oz

HAS_PRINTF := NO

# ----------------------------

ifndef CEDEV
$(error CEDEV environment path variable is not set)
endif

include $(CEDEV)/meta/makefile.mk
