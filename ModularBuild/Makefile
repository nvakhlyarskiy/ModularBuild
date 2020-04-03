
target := some

sources := some.c main.c

CXXFLAGS = -std=gnu++17
CFLAGS = -std=c99
LDFLAGS = 
LDLIBS = 



target_source := $(filter %$(filter $(target).%,$(notdir $(sources))),$(sources))
target_object := $(basename $(target_source)).o
target_depend := $(patsubst %.o,%.d,$(target_object))

sources := $(filter-out $(target_source),$(sources))

objects := $(filter %.cc.o,$(patsubst %.cc,%.cc.o,$(sources)))
objects += $(filter %.c.o,$(patsubst %.c,%.c.o,$(sources)))

depends := $(filter %.cc.d,$(patsubst %.cc,%.cc.d,$(sources)))
depends += $(filter %.c.d,$(patsubst %.c,%.c.d,$(sources)))


all: $(target)

$(target): $(objects) | $(target_depend) $(depends)

DEPGEN_FLAGS = -MM -MF $$@ -MT $$@ -MT $$(patsubst %.d,%.o,$$@) $$^
GET_COMPILER = $(if $(filter $(1),cc cpp .cc .cpp),CXX,$(if $(filter $(1),c .c),CC,ERROR))
GET_FLAGS = $(if $(filter $(1),cc cpp .cc .cpp),CXXFLAGS,$(if $(filter $(1),c .c),CFLAGS,ERROR))

define COMPILE_INSTANTIATION

%.$(1).d: %.$(1)
	$$($(call GET_COMPILER,$(1))) $$($(call GET_FLAGS,$(1))) $(DEPGEN_FLAGS)


%.$(1).o: %.$(1)
	$(COMPILE.$(1)) $$< -o $$@ 
endef
$(foreach i,c cpp cc,$(eval $(call COMPILE_INSTANTIATION,$(i))))


$(target_depend): $(target_source)
	$($(call GET_COMPILER,$(suffix $^))) $($(call GET_FLAGS,$(suffix $^))) -MM -MF $@ -MT $@ -MT $(patsubst %.d,%.o,$@) $^


ifeq ($(MAKE_VERSION),4.1)


DEPEND_INCLUSION = sinclude $(1)
$(foreach i,$(depends),$(eval $(call DEPEND_INCLUSION,$(i))))
sinclude $(target_depend)

else

endif


.PHONY: clean

clean:
	rm -f $(target_object) $(objects) $(target_depend) $(depends)


$(info MAKE_RESTARTS = $(MAKE_RESTARTS))
