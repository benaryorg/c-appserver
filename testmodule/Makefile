SRCPATH := src

SRCS = $(shell find $(SRCPATH) -regextype posix-extended -regex '^.+\.(c)$$')
OBJS = $(addprefix build,$(addsuffix .o,$(basename $(SRCS:$(SRCPATH)%=%))))

LDFLAGS := -shared -undefined dynamic_lookup
CFLAGS := $(addprefix -I,$(SRCPATH)) \
	-Werror -Wall -Wextra -pedantic -std=c89 \
	-fPIC

default: all

all: module.so

module.so: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

build/%.o: $(SRCPATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJS)
	rm -f module

.PHONY: clean all default

