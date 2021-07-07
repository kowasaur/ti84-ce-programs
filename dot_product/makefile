# ----------------------------
# Makefile Options
# ----------------------------

NAME ?= DOT
DESCRIPTION ?= "Calculates the dot product of two vectors"
COMPRESSED ?= NO
ARCHIVED ?= NO

CFLAGS ?= -Wall -Wextra -Oz
CXXFLAGS ?= -Wall -Wextra -Oz

HAS_PRINTF := NO

# ----------------------------

ifndef CEDEV
$(error CEDEV environment path variable is not set)
endif

include $(CEDEV)/meta/makefile.mk
