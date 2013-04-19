export buildpath=build
export CPLUS_INCLUDE_PATH=src

build: jvmbin

jvmbin: $(buildpath)/static_make $(buildpath)/static.o
	g++ -pg -I /usr/local/boost $(buildpath)/static.o -o jvmbin

.PHONY: $(buildpath)/static_make
$(buildpath)/static_make : | $(buildpath)_folder
	ruby make_generator.rb src $(CPLUS_INCLUDE_PATH) $(buildpath)/static_obj $(buildpath)/static.o 1 $(buildpath)/make_static.mk
	$(MAKE) -f $(buildpath)/make_static.mk


.PHONY: $(buildpath)_folder
$(buildpath)_folder:
	mkdir -p $(buildpath)
	
all: clean build

.PHONY: clean
clean:
	rm -rf $(buildpath)
	rm -f jvmbin
	
	